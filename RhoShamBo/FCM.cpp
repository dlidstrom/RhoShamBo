
#include "stdafx.h"
#include "FCM.h"

IPlayer::HAND FCM::GetNextHand(const HandsCollection& yourHistory,
                               const HandsCollection& oppHistory)
{
   HAND result = GetRandomHand();

   typedef std::pair<HAND, HAND> HandPair;
   typedef std::vector<HandPair> HandPairCollection;

   typedef std::map<HandPairCollection, std::map<HAND, int> > Dictionary;
   Dictionary sums;

   // before we start, reduce look-back a little
   const std::size_t toStart = yourHistory.size() > lookBack ? yourHistory.size()-lookBack : 0;

   if( !oppHistory.empty() )
   {
      // calculate sums
      for( std::size_t i=toStart;
           i<oppHistory.size()-1;
           ++i )
      {
         for( std::size_t j=i+1;
              j<oppHistory.size();
              ++j )
         {
            // construct substring:
            HandPairCollection handPairCollection;
            for( std::size_t k=i; k<j; ++k )
            {
               handPairCollection.push_back(std::make_pair(oppHistory.at(k),
                                                           yourHistory.at(k)));
            }
            sums[handPairCollection][oppHistory.at(j)] ++;
         }
      }

      // try to match last characters in text to previous
      // characters in text
      // fill prediction with character prediction
      std::map<HAND, int> prediction;
      // used to count predictions
      int total_sum = 0;
      // from last to first
      for( std::size_t i=oppHistory.size()-1; i>=toStart; --i )
      {
         // construct substring:
         HandPairCollection last;
         for( std::size_t k=i; k<oppHistory.size(); ++k )
         {
            last.push_back(std::make_pair(oppHistory.at(k), yourHistory.at(k)));
         }
         Dictionary::iterator It = sums.find(last);
         if( It!=sums.end() )
         {
            //cout << last << " exists somewhere in " << text << endl;
            // update character counts
            for( std::map<HAND, int>::iterator jt=It->second.begin();
                 jt!=It->second.end();
                 ++jt )
            {
               prediction[jt->first] += jt->second;
               total_sum += jt->second;
            }
         }
         else
         {
            break;
         }
      }

      int best = -1;
      for( std::map<HAND, int>::const_iterator it=prediction.begin();
           it!=prediction.end();
           ++it )
      {
         if( it->second > best )
         {
            result = HAND((it->first + 1) % 3);
            best = it->second;
         }
      }
   }

   return result;
}

std::string FCM::Name() const
{
   return "FCM (DL)";
}

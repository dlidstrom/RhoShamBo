
#include "stdafx.h"
#include "Henny.h"

IPlayer::HAND Henny::GetNextHand(const HandsCollection& yourHistory,
                                 const HandsCollection& oppHistory)
{
   //int henny() {

   //  return((*opp_history?opp_history[random()%*opp_history+1]+1:random())%3);

   //}

   HAND result = GetRandomHand();
   if( !oppHistory.empty() )
   {
      std::size_t index = rand() % oppHistory.size();
      std::size_t i = oppHistory.at(index)+1;
      result = HAND(i % 3);
   }

   return result;
}

std::string Henny::Name() const
{
   return "Henny";
}

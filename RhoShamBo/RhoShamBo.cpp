// RhoShamBo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IPlayer.h"
#include "FCM.h"
#include "DeBruijn.h"
#include "Predbot.h"
#include "MixedStrategy.h"
#include "Unbeatable.h"
#include "Predictor.h"
#include "BeatLast.h"
#include "Beat_BeatLast.h"
#include "Only.h"
#include "Rotating.h"
#include "Henny.h"

namespace
{
   // play 1000 hands
   const double n_hands = 1000;
   const int n_rounds = 1;

   struct compare_players
   {
      bool operator()(IPlayerPtr p1, IPlayerPtr p2) const
      {
         return p1->Name() < p2->Name();
      }
   };

   struct sort_on_first
   {
      template<class T, class U>
      bool operator()(std::pair<T, U> p1, std::pair<T, U> p2) const
      {
         return p1.first < p2.first;
      }
   };
}

char rocksOnly[] = "RocksOnly";
char paperOnly[] = "PaperOnly";
char scissorsOnly[] = "ScissorsOnly";

int _tmain(int argc, _TCHAR* argv[])
{
   srand(static_cast<unsigned>(time(0)));

   try
   {
      typedef std::vector<IPlayerPtr> PlayerCollection;

      PlayerCollection players;
      players.push_back(IPlayerPtr(new Unbeatable));
      players.push_back(IPlayerPtr(new Predictor));
      players.push_back(IPlayerPtr(new BeatLast));
      players.push_back(IPlayerPtr(new Beat_BeatLast));
      players.push_back(IPlayerPtr(new Only<IPlayer::ROCK, rocksOnly>));
      players.push_back(IPlayerPtr(new Only<IPlayer::PAPER, paperOnly>));
      players.push_back(IPlayerPtr(new Only<IPlayer::SCISSORS, scissorsOnly>));
      players.push_back(IPlayerPtr(new Rotating));
      players.push_back(IPlayerPtr(new FCM));

      // these are other's bots, taken from RoShamBo computer challenge:
      //players.push_back(IPlayerPtr(new Henny));
      //players.push_back(IPlayerPtr(new DeBruijn));
      //players.push_back(IPlayerPtr(new Predbot));
      //players.push_back(IPlayerPtr(new MixedStrategy));

      std::sort(players.begin(), players.end(), compare_players());

      // find how much to indent
      std::size_t indent = 0;
      for( std::size_t i=0; i<players.size(); i++ )
      {
         indent = (std::max)(indent, players[i]->Name().size());
      }

      // collect results here
      std::map<IPlayerPtr, std::pair<int, int> > results;

      for( int n=0; n<n_rounds; n++ )
      {
         std::cout
             << "Round "
             << n+1
             << " of "
             << n_rounds
             << ":"
             << std::endl
             ;
         for( PlayerCollection::size_type i=0; i<players.size()-1; i++ )
         {
            IPlayerPtr p1 = players.at(i);
            for( PlayerCollection::size_type j=i+1; j<players.size(); j++ )
            {
               IPlayerPtr p2 = players.at(j);
               std::cout
                   << "Game: "
                   << std::setw(indent) << std::left << p1->Name()
                   << " vs "
                   << std::setw(indent) << std::left << p2->Name()
                   << ": "
                   << std::flush
                   ;

               int p1Wins = 0;
               int p2Wins = 0;
               IPlayer::HandsCollection p1Hands;
               IPlayer::HandsCollection p2Hands;

               std::map<std::pair<IPlayer::HAND, IPlayer::HAND>, int> judge;
               judge[std::make_pair(IPlayer::PAPER, IPlayer::ROCK)] = 1;
               judge[std::make_pair(IPlayer::PAPER, IPlayer::SCISSORS)] = 0;
               judge[std::make_pair(IPlayer::PAPER, IPlayer::PAPER)] = 0;
               judge[std::make_pair(IPlayer::ROCK, IPlayer::ROCK)] = 0;
               judge[std::make_pair(IPlayer::ROCK, IPlayer::SCISSORS)] = 1;
               judge[std::make_pair(IPlayer::ROCK, IPlayer::PAPER)] = 0;
               judge[std::make_pair(IPlayer::SCISSORS, IPlayer::ROCK)] = 0;
               judge[std::make_pair(IPlayer::SCISSORS, IPlayer::SCISSORS)] = 0;
               judge[std::make_pair(IPlayer::SCISSORS, IPlayer::PAPER)] = 1;

               for( int h=0; h<n_hands; h++ )
               {
                  IPlayer::HAND p1Hand = p1->GetNextHand(p1Hands, p2Hands);
                  IPlayer::HAND p2Hand = p2->GetNextHand(p2Hands, p1Hands);
                  // find out who won
                  p1Wins += judge[std::make_pair(p1Hand, p2Hand)];
                  p2Wins += judge[std::make_pair(p2Hand, p1Hand)];

                  // update hands
                  p1Hands.push_back(p1Hand);
                  p2Hands.push_back(p2Hand);
               }
               std::cout
                   << std::setw(static_cast<std::streamsize>(std::log10(n_hands)+1)) << std::right << p1Wins
                   << " - "
                   << std::setw(static_cast<std::streamsize>(std::log10(n_hands)+1)) << std::right << p2Wins
                   << std::endl
                   ;
               if( p1Wins>p2Wins )
               {
                  results[p1].first += 2;
               }
               else if( p1Wins<p2Wins )
               {
                  results[p2].first += 2;
               }
               else
               {
                  results[p1].first += 1;
                  results[p2].first += 1;
               }
               // update +/-
               results[p1].second += p1Wins - p2Wins;
               results[p2].second += p2Wins - p1Wins;
            }
            if( i<players.size()-2 )
            {
               std::cout << '-' << std::endl;
            }
         }
      }

      std::vector<std::pair<std::pair<int, int>, IPlayerPtr> > sortedResults;
      for( std::map<IPlayerPtr, std::pair<int, int> >::const_iterator it=results.begin();
           it!=results.end();
           ++ it )
      {
         sortedResults.push_back(std::make_pair(it->second, it->first));
      }

      std::sort(sortedResults.begin(), sortedResults.end(), sort_on_first());
      std::reverse(sortedResults.begin(), sortedResults.end());

      std::cout << std::endl;
      std::cout << "Final rankings:" << std::endl;
      for( std::size_t i=0; i<sortedResults.size(); i++ )
      {
         std::cout
             << std::setw(indent) << sortedResults[i].second->Name()
             << ": "
             << std::setw(3) << sortedResults[i].first.first
             << " ("
             << sortedResults[i].first.second
             << ")"
             << std::endl
             ;
      }

      std::cout
          << std::endl
          << std::endl
          << "And, The Winner is: "
          << sortedResults.front().second->Name()
          << " ("
          << sortedResults.front().first.first
          << "/"
          << n_rounds*(players.size()-1)*2
          << "). Good job!"
          << std::endl
          ;
   }
   catch( std::exception& ex )
   {
      std::cerr << "Caught exception: " << ex.what() << std::endl;
   }
   catch( ... )
   {
      std::cerr << "Unknown exception occurred" << std::endl;
   }

	return 0;
}

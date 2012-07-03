
#include "stdafx.h"
#include "Beat_BeatLast.h"

Beat_BeatLast::Beat_BeatLast()
{
   judge[std::make_pair(IPlayer::PAPER, IPlayer::ROCK)] = 1;
   judge[std::make_pair(IPlayer::PAPER, IPlayer::SCISSORS)] = 0;
   judge[std::make_pair(IPlayer::PAPER, IPlayer::PAPER)] = 0;
   judge[std::make_pair(IPlayer::ROCK, IPlayer::ROCK)] = 0;
   judge[std::make_pair(IPlayer::ROCK, IPlayer::SCISSORS)] = 1;
   judge[std::make_pair(IPlayer::ROCK, IPlayer::PAPER)] = 0;
   judge[std::make_pair(IPlayer::SCISSORS, IPlayer::ROCK)] = 0;
   judge[std::make_pair(IPlayer::SCISSORS, IPlayer::SCISSORS)] = 0;
   judge[std::make_pair(IPlayer::SCISSORS, IPlayer::PAPER)] = 1;
}

IPlayer::HAND Beat_BeatLast::BeatLast(HAND last) const
{
   if( last==PAPER )
      return SCISSORS;
   else if( last==SCISSORS )
      return ROCK;
   else
      return PAPER;
}

bool Beat_BeatLast::Beats(HAND h1, HAND h2) const
{
   return judge.find(std::make_pair(h1, h2))->second != 0;
}

IPlayer::HAND Beat_BeatLast::GetNextHand(const HandsCollection& yourHistory,
                                         const HandsCollection& oppHistory)
{
   HAND result = GetRandomHand();

   if( !oppHistory.empty() )
   {
      HAND oppLast = oppHistory.back();
      result = BeatLast(oppLast);
      // are we playing BeatLast?
      // if so, deviate strategy
      if( oppHistory.size()>1 )
      {
         if( Beats(oppLast, yourHistory.at(yourHistory.size()-2)) )
         {
            HAND myLast = yourHistory.back();
            if( myLast==PAPER )
               result = ROCK;
            else if( myLast==SCISSORS )
               result = PAPER;
            else
               result = SCISSORS;
         }
      }
   }

   return result;
}

std::string Beat_BeatLast::Name() const
{
   return "Beat-BeatLast";
}

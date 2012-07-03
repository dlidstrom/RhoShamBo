
#include "stdafx.h"
#include "BeatLast.h"

IPlayer::HAND BeatLast::GetNextHand(const HandsCollection& yourHistory,
                                    const HandsCollection& oppHistory)
{
   HAND result = GetRandomHand();

   if( !oppHistory.empty() )
   {
      result = HAND((oppHistory.back() + 1) % 3);
   }

   return result;
}

std::string BeatLast::Name() const
{
   return "BeatLast";
}

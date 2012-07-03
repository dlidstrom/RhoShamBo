
#include "stdafx.h"
#include "Rotating.h"

IPlayer::HAND Rotating::GetNextHand(const HandsCollection& yourHistory,
                                    const HandsCollection& oppHistory)
{
   static int index = 0;
   HAND hands[] = { PAPER, ROCK, SCISSORS };
   return hands[index ++ % 3];
}

std::string Rotating::Name() const
{
   return "Rotating";
}

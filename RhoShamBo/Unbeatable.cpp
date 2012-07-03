
#include "stdafx.h"
#include "Unbeatable.h"

IPlayer::HAND Unbeatable::GetNextHand(const HandsCollection& yourHistory,
                                      const HandsCollection& oppHistory)
{
   return GetRandomHand();
}

std::string Unbeatable::Name() const
{
   return "Unbeatable";
}

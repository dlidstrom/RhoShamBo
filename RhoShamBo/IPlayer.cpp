
#include "stdafx.h"
#include "IPlayer.h"
#include <random>

IPlayer::HAND GetRandomHand()
{
   // Uniform distribution using mt19937 generator with 2^19937-1 cycle.
   typedef std::variate_generator<std::mt19937&,
                                  std::uniform_int<unsigned long>> UniformReal6419937;
   static std::uniform_int<unsigned long> distr(0, 2);
   static std::mt19937 mt19937(static_cast<unsigned long>(time(0)));
   static UniformReal6419937 generator(mt19937, distr);

   unsigned long result = generator();
   return IPlayer::HAND(result);
}

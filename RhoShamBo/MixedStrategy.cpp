
#include "stdafx.h"
#include "MixedStrategy.h"

IPlayer::HAND MixedStrategy::GetNextHand(const HandsCollection& yourHistory,
                                         const HandsCollection& oppHistory)
{
   static int strategy_scores[4];
   static int last_strategy;
   int rcount, pcount, scount;
   std::size_t i;

   double t;

   if( oppHistory.empty() ) {
      strategy_scores[0] = 4;     /* watching you watching me */
      strategy_scores[1] = 4;     /* watching you  */
      strategy_scores[2] = 2;     /* freqbot */
      strategy_scores[3] = 1;     /* random */
   }
   else{
      /* remeber success of prev stratigies */
      if (yourHistory.back() == oppHistory.back()){
         strategy_scores[last_strategy] += 1;  /* draw */
      }
      else if ( (yourHistory.back()-oppHistory.back() == 1) ||
                (yourHistory.back()-oppHistory.back() == -2) ) {
         strategy_scores[last_strategy] += 3;  /* win (test from Play_Match) */
      }
      else{
         strategy_scores[last_strategy] =
            (int)((double)strategy_scores[last_strategy]*0.8);
      }
   }

   /* pick based on rate of success for each strategy */
   t = rand()%1000;
   t /= 1000;//maxrandom;
   t *= (strategy_scores[0] + strategy_scores[1] + strategy_scores[2] +
         strategy_scores[3]);

   if (t<strategy_scores[0]){
      last_strategy = 0;
      /* play whatever will beat the opponent's most frequent follow up to
         my last move */

      rcount = 0;  pcount = 0;  scount = 0;
      for (i = 1; !oppHistory.empty() && i < oppHistory.size()-1; i++) {
         if (yourHistory[i-1]==yourHistory.back()){
            if (oppHistory[i] == ROCK)            { rcount++; }
            else if (oppHistory[i] == PAPER)      { pcount++; }
            else /* opp_history[i] == scissors */  { scount++; }
         }
      }
      if ( (rcount > pcount) && (rcount > scount) ) { return(PAPER); }
      else if ( pcount > scount ) { return(SCISSORS); }
      else { return(ROCK); }
   }
   else if (t<strategy_scores[0]+strategy_scores[1]){ /* note change */
      last_strategy = 1;
      /* play whatever will beat the opponent's most frequent follow up to his
         last move */

      rcount = 0;  pcount = 0;  scount = 0;
      for (i = 1; !oppHistory.empty() && i < oppHistory.size()-1; i++) {
         if (oppHistory[i-1]==oppHistory.back()){
            if (oppHistory[i] == ROCK)            { rcount++; }
            else if (oppHistory[i] == PAPER)      { pcount++; }
            else /* opp_history[i] == scissors */  { scount++; }
         }
      }
      if ( (rcount > pcount) && (rcount > scount) ) { return(PAPER); }
      else if ( pcount > scount ) { return(SCISSORS); }
      else { return(ROCK); }

   }
   else if (t<strategy_scores[0]+strategy_scores[1]+strategy_scores[2]){
      last_strategy = 2;
      /* play whatever will beat the opponent's most frequent choice */

      rcount = 0;  pcount = 0;  scount = 0;
      for (i = 0; i < oppHistory.size(); i++) {
         if (oppHistory[i] == ROCK)            { rcount++; }
         else if (oppHistory[i] == PAPER)      { pcount++; }
         else /* opp_history[i] == scissors */  { scount++; }
      }
      if ( (rcount > pcount) && (rcount > scount) ) { return(PAPER); }
      else if ( pcount > scount ) { return(SCISSORS); }
      else { return(ROCK); }
   }
   else{
      last_strategy = 3;
      return HAND( rand() % 3);
   }
}

std::string MixedStrategy::Name() const
{
   return "MixedStrategy";
}


#include "stdafx.h"
#include "Predbot.h"

IPlayer::HAND Predbot::GetNextHand(const HandsCollection& yourHistory,
                                   const HandsCollection& oppHistory)
{
   static double c[64];  int history_length= yourHistory.size();
   int i,j,k,l,m,m1,o,o1, s,mr,mp,ms,mb;
   double q, qi, qj, qk, ql;
   if(history_length==0)
   { for(i=0;i<64;i++) c[i]=0;
      return HAND( rand() % 3 );
   }
   else {
      o = oppHistory.back();
      m = yourHistory.back();
      if(history_length>1)
      { o1 = oppHistory[history_length-2];
         m1 = yourHistory[history_length-2];
         i=o1*16+m1*4+o; j=o1*16+3*4+o; k=3*16+m1*4+o; l=3*16+3*4+o;
         c[i]+=1;  c[j]+=1;  c[k]+=1; c[l]+=1;
         c[i+3-o]+=1;  c[j+3-o]+=1;  c[k+3-o]+=1; c[l+3-o]+=1;
      }
      for(i=0;i<64;i++) c[i]=c[i]*0.98;
      i=o*16+m*4; j=o*16+3*4; k=3*16+m*4; l=3*16+3*4;
      for(qi=c[i],m=1;m<3;m++) if(c[i+m]>qi) qi=c[i+m];  qi=qi/c[i+3];
      for(qj=c[j],m=1;m<3;m++) if(c[j+m]>qj) qj=c[j+m];  qj=qj/c[j+3];
      for(qk=c[k],m=1;m<3;m++) if(c[k+m]>qk) qk=c[k+m];  qk=qk/c[k+3];
      for(ql=c[l],m=1;m<3;m++) if(c[l+m]>ql) ql=c[l+m];  ql=ql/c[l+3];
      q=qi; s=i;
      if(qj>q) { q=qj; s=j; }
      if(qk>q) { q=qk; s=k; }
      if(ql>q) { s=l; }
      mr= static_cast<int>(c[s+2]-c[s+1]);
      mp= static_cast<int>(c[s]-c[s+2]);
      ms= static_cast<int>(c[s+1]-c[s]);
      mb=mr;  m=ROCK;
      if(mp>mb) { mb=mp;  m=PAPER; }
      if(ms>mb) m=SCISSORS;
      return HAND(m);
   }
}

std::string Predbot::Name() const
{
   return "Predbot";
}

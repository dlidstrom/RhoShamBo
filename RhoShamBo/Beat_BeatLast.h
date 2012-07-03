// $Id: Beat_BeatLast.h 87 2009-01-11 19:14:17Z Daniel $
//! @file
//! Brief.
//! @author Daniel Lidstrom <daniel.lidstrom@sbg.se>
//! @date   2009-01-11 19:20
//! @ingroup
//!

#if !defined(BEAT_BEATLAST_H__20090111T1920)
#define BEAT_BEATLAST_H__20090111T1920

#include "IPlayer.h"

//!
//! @author  Daniel Lidstrom <daniel.lidstrom@sbg.se>
//! @date    2009-01-11 19:20
//! @ingroup
//! Brief.
//!
class Beat_BeatLast : public IPlayer
{
   std::map<std::pair<HAND, HAND>, int> judge;

   HAND GetNextHand(const HandsCollection& yourHistory,
                    const HandsCollection& oppHistory);

   std::string Name() const;
   HAND BeatLast(HAND last) const;
   bool Beats(HAND h1, HAND h2) const;

public:
   Beat_BeatLast();
};

#endif

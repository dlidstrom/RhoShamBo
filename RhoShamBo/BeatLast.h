// $Id: BeatLast.h 87 2009-01-11 19:14:17Z Daniel $
//! @file
//! Brief.
//! @author Daniel Lidstrom <daniel.lidstrom@sbg.se>
//! @date   2009-01-11 19:17
//! @ingroup
//!

#if !defined(BEATLAST_H__20090111T1917)
#define BEATLAST_H__20090111T1917

#include "IPlayer.h"

//!
//! @author  Daniel Lidstrom <daniel.lidstrom@sbg.se>
//! @date    2009-01-11 19:17
//! @ingroup
//! Brief.
//!
class BeatLast : public IPlayer
{
   HAND GetNextHand(const HandsCollection& yourHistory,
                    const HandsCollection& oppHistory);

   std::string Name() const;
public:
};

#endif

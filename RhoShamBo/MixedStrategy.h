// $Id: MixedStrategy.h 87 2009-01-11 19:14:17Z Daniel $
//! @file
//! Brief.
//! @author Daniel Lidstrom <daniel.lidstrom@sbg.se>
//! @date   2009-01-11 18:37
//! @ingroup
//!

#if !defined(MIXEDSTRATEGY_H__20090111T1837)
#define MIXEDSTRATEGY_H__20090111T1837

#include "IPlayer.h"

//!
//! @author  Daniel Lidstrom <daniel.lidstrom@sbg.se>
//! @date    2009-01-11 18:37
//! @ingroup
//! Brief.
//!
class MixedStrategy : public IPlayer
{
   HAND GetNextHand(const HandsCollection& yourHistory,
                    const HandsCollection& oppHistory);

   std::string Name() const;
public:
};

#endif

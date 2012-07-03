//! @file
//! Brief.
//! @author Daniel Lidstrom <dlidstrom@gmail.com>
//! @date   2009-01-11 18:37
//! @ingroup
//!

#if !defined(MIXEDSTRATEGY_H__20090111T1837)
#define MIXEDSTRATEGY_H__20090111T1837

#include "IPlayer.h"

//!
//! @author  Daniel Lidstrom <dlidstrom@gmail.com>
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

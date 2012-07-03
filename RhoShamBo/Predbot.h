//! @file
//! Brief.
//! @author Daniel Lidstrom <dlidstrom@gmail.com>
//! @date   2009-01-11 18:24
//! @ingroup
//!

#if !defined(PREDBOT_H__20090111T1824)
#define PREDBOT_H__20090111T1824

#include "IPlayer.h"

//!
//! @author  Daniel Lidstrom <dlidstrom@gmail.com>
//! @date    2009-01-11 18:24
//! @ingroup
//! Brief.
//!
class Predbot : public IPlayer
{
   HAND GetNextHand(const HandsCollection& yourHistory,
                    const HandsCollection& oppHistory);

   std::string Name() const;
public:
};

#endif

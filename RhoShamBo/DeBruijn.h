//! @file
//! Brief.
//! @author Daniel Lidstrom <dlidstrom@gmail.com>
//! @date   2009-01-11 18:13
//! @ingroup
//!

#if !defined(DEBRUIJN_H__20090111T1813)
#define DEBRUIJN_H__20090111T1813

#include "IPlayer.h"

//!
//! @author  Daniel Lidstrom <dlidstrom@gmail.com>
//! @date    2009-01-11 18:13
//! @ingroup
//! Brief.
//!
class DeBruijn : public IPlayer
{
   HAND GetNextHand(const HandsCollection& yourHistory,
                    const HandsCollection& oppHistory);

   std::string Name() const;
public:
};

#endif

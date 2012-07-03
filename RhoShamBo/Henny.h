//! @file
//! Brief.
//! @author Daniel Lidstrom <dlidstrom@gmail.com>
//! @date   2009-01-11 19:28
//! @ingroup
//!

#if !defined(HENNY_H__20090111T1928)
#define HENNY_H__20090111T1928

#include "IPlayer.h"

//!
//! @author  Daniel Lidstrom <dlidstrom@gmail.com>
//! @date    2009-01-11 19:28
//! @ingroup
//! Brief.
//!
class Henny : public IPlayer
{
   HAND GetNextHand(const HandsCollection& yourHistory,
                    const HandsCollection& oppHistory);

   std::string Name() const;
public:
};

#endif

//! @file
//! Brief.
//! @author Daniel Lidstrom <dlidstrom@gmail.com>
//! @date   2009-01-11 19:14
//! @ingroup
//!

#if !defined(UNBEATABLE_H__20090111T1914)
#define UNBEATABLE_H__20090111T1914

#include "IPlayer.h"

//!
//! @author  Daniel Lidstrom <dlidstrom@gmail.com>
//! @date    2009-01-11 19:14
//! @ingroup
//! Brief.
//!
class Unbeatable : public IPlayer
{
   HAND GetNextHand(const HandsCollection& yourHistory,
                    const HandsCollection& oppHistory);

   std::string Name() const;
public:
};

#endif

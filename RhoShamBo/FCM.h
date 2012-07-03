//! @file
//! Brief.
//! @author Daniel Lidstrom <dlidstrom@gmail.com>
//! @date   2009-01-10 20:27
//! @ingroup
//!

#if !defined(FCM_H__20090110T2027)
#define FCM_H__20090110T2027

#include "IPlayer.h"

//!
//! @author  Daniel Lidstrom <dlidstrom@gmail.com>
//! @date    2009-01-10 20:27
//! @ingroup
//! Brief.
//!
class FCM : public IPlayer
{
   HAND GetNextHand(const HandsCollection& yourHistory,
                    const HandsCollection& oppHistory);

   std::string Name() const;

   static const std::size_t lookBack = 20;

public:
};

#endif

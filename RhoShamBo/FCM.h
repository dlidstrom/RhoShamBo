// $Id: FCM.h 87 2009-01-11 19:14:17Z Daniel $
//! @file
//! Brief.
//! @author Daniel Lidstrom <daniel.lidstrom@sbg.se>
//! @date   2009-01-10 20:27
//! @ingroup
//!

#if !defined(FCM_H__20090110T2027)
#define FCM_H__20090110T2027

#include "IPlayer.h"

//!
//! @author  Daniel Lidstrom <daniel.lidstrom@sbg.se>
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

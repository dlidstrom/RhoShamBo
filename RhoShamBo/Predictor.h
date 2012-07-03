//! @file
//! Brief.
//! @author Daniel Lidstrom <dlidstrom@gmail.com>
//! @date   2009-01-11 19:25
//! @ingroup
//!

#if !defined(PREDICTOR_H__20090111T1925)
#define PREDICTOR_H__20090111T1925

#include "IPlayer.h"

//!
//! @author  Daniel Lidstrom <dlidstrom@gmail.com>
//! @date    2009-01-11 19:25
//! @ingroup
//! Brief.
//!
class Predictor : public IPlayer
{
   static const int lookBack = 40;
   HAND GetNextHand(const HandsCollection& yourHistory,
                    const HandsCollection& oppHistory);

   std::string Name() const;
public:
};

#endif

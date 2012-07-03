// $Id: Rotating.h 87 2009-01-11 19:14:17Z Daniel $
//! @file
//! Brief.
//! @author Daniel Lidstrom <daniel.lidstrom@sbg.se>
//! @date   2009-01-11 19:16
//! @ingroup
//!

#if !defined(ROTATING_H__20090111T1916)
#define ROTATING_H__20090111T1916

#include "IPlayer.h"

//!
//! @author  Daniel Lidstrom <daniel.lidstrom@sbg.se>
//! @date    2009-01-11 19:16
//! @ingroup
//! Brief.
//!
class Rotating : public IPlayer
{
   HAND GetNextHand(const HandsCollection& yourHistory,
                    const HandsCollection& oppHistory);

   std::string Name() const;
public:
};

#endif

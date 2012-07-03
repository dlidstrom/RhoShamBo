// $Id: Only.h 87 2009-01-11 19:14:17Z Daniel $
//! @file
//! Brief.
//! @author Daniel Lidstrom <daniel.lidstrom@sbg.se>
//! @date   2009-01-11 19:23
//! @ingroup
//!

#if !defined(ONLY_H__20090111T1923)
#define ONLY_H__20090111T1923

#include "IPlayer.h"

//!
//! @author  Daniel Lidstrom <daniel.lidstrom@sbg.se>
//! @date    2009-01-11 19:23
//! @ingroup
//! Brief.
//!
template<IPlayer::HAND h, const char* name>
class Only : public IPlayer
{
   HAND GetNextHand(const HandsCollection& yourHistory,
                    const HandsCollection& oppHistory)
   {
      return h;
   }
   std::string Name() const
   {
      return name;
   }

public:
};

#endif

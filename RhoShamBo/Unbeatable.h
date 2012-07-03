// $Id: Unbeatable.h 87 2009-01-11 19:14:17Z Daniel $
//! @file
//! Brief.
//! @author Daniel Lidstrom <daniel.lidstrom@sbg.se>
//! @date   2009-01-11 19:14
//! @ingroup
//!

#if !defined(UNBEATABLE_H__20090111T1914)
#define UNBEATABLE_H__20090111T1914

#include "IPlayer.h"

//!
//! @author  Daniel Lidstrom <daniel.lidstrom@sbg.se>
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

// $Id: IPlayer.h 87 2009-01-11 19:14:17Z Daniel $
//! @file
//! Brief.
//! @author Daniel Lidstrom <daniel.lidstrom@sbg.se>
//! @date   2009-01-10 09:48
//! @ingroup
//!

#if !defined(IPLAYER_H__20090110T0948)
#define IPLAYER_H__20090110T0948

//!
//! @author  Daniel Lidstrom <daniel.lidstrom@sbg.se>
//! @date    2009-01-10 09:48
//! @ingroup
//! Brief.
//!
struct IPlayer
{
   virtual ~IPlayer() {}

   enum HAND
   {
      ROCK,
      PAPER,
      SCISSORS
   };

   typedef std::vector<HAND> HandsCollection;

   virtual HAND GetNextHand(const HandsCollection& yourHistory,
                            const HandsCollection& oppHistory) = 0;

   virtual std::string Name() const = 0;
};

typedef std::tr1::shared_ptr<IPlayer> IPlayerPtr;

IPlayer::HAND GetRandomHand();

#endif

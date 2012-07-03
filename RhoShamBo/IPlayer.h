//! @file
//! Brief.
//! @author Daniel Lidstrom <dlidstrom@gmail.com>
//! @date   2009-01-10 09:48
//! @ingroup
//!

#if !defined(IPLAYER_H__20090110T0948)
#define IPLAYER_H__20090110T0948

//!
//! @author  Daniel Lidstrom <dlidstrom@gmail.com>
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

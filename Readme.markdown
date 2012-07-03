# RhoShamBo competition #

> &minus; Can you beat the predictor? <br>
> Copyright &copy; 2009-2012 Daniel Lidström. <br>
> Licensed under The MIT License (MIT)

## Description ##
Here is a program that conducts tournaments for bots that play RhoShamBo (paper/rock/scissors). It is written in C++ and you need to implement the following interface:

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

See the existing bots in the `Bots` folder for examples.

Now, can you beat the `FCM` predictor? Get in touch with me if you do!

Daniel Lidström,
Stockholm 2012-07-03
#ifndef REFEREE_H
#define REFEREE_H

#include "Player.h"

class Referee {
    public:
        Referee();
        Player* refGame(Player* p1, Player* p2);    // return winner or nullptr on tie
};

#endif
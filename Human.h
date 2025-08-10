#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"

class Human : public Player {
    public:
        Human();
        explicit Human(std::string name);
        Move* makeMove() override; // prompts exactly the "Enter Move: "
};

#endif
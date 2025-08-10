#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Move;     // forward declaration

class Player {
    public:
        virtual Move* makeMove() = 0;   // return a freh 'Move'. Referee will own and delete it
        virtual std::string getName();  // virtual function to get player name
        virtual ~Player() = default;    // virtual destructor

    protected:
        std::string name;

};

#endif
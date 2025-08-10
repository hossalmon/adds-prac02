#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <unordered_set>

class Move {
    public:
        virtual std::string getName() const = 0;    // name of move, e.g. 'rock', 'ninja'
        virtual bool beats(const Move& other) const = 0;    // return true if this move defeats other move - keeps rule logicout of Referee class
        virtual ~Move() = default;  // destructor
};


// Class stores its own move name and store set of move name it defeats
class NamedMove : public Move {
    private:
        std::string name_;
        std::unordered_set<std::string> winsAgainst_;

    
    public:
        NamedMove(const std::string& name, const std::unordered_set<std::string>& winsAgainst);

        std::string getName() const override;
        bool beats(const Move& other) const override;

};

// Class for creating Move instances from user input
class MoveFactory {
    public:
        static Move* fromString(const std::string& userInput);
};

#endif
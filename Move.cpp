#include "Move.h"
#include <unordered_map>
#include <string>

// NamedMove implementation
NamedMove::NamedMove(const std::string& name,
                     const std::unordered_set<std::string>& winsAgainst)
    : name_(name), winsAgainst_(winsAgainst) {}

std::string NamedMove::getName() const {
    return name_; // returns name of the move made
}

bool NamedMove::beats(const Move& other) const {
    return winsAgainst_.count(other.getName()) > 0;
}

// MoveFactory implementation
Move* MoveFactory::fromString(const std::string& userInput) {
    // each value lists who that move beats
    static const std::unordered_map<std::string, std::unordered_set<std::string>> wins = {
        // Rock–Paper–Scissors rules
        {"Rock",     {"Scissors"}},
        {"Paper",    {"Rock"}},
        {"Scissors", {"Paper"}},

        // Monkey–Robot–Pirate–Ninja–Zombie rules
        {"Monkey",   {"Ninja", "Robot"}},
        {"Robot",    {"Ninja", "Zombie"}},
        {"Pirate",   {"Robot", "Monkey"}},
        {"Ninja",    {"Pirate", "Zombie"}},
        {"Zombie",   {"Pirate", "Monkey"}},
    };

    auto it = wins.find(userInput);
    if (it != wins.end()) {
        return new NamedMove(userInput, it->second); // caller (Referee) deletes
    }
    
}

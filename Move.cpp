#include "Move.h"
#include <unordered_map>
#include <string>
#include <cctype>

// NamedMove implementation
NamedMove::NamedMove(const std::string& name, const std::unordered_set<std::string>& winsAgainst) :
    name_(name), winsAgainst_(winsAgainst) {}

std::string NamedMove::getName() const {
    return name_;
}

bool NamedMove::beats(const Move& other) const {
    return winsAgainst_.count(other.getName()) > 0;
}

// MoveFactory implementation

// Normalise to UPPERCASE for input case sensitivity
static std::string norm(std::string s) {
    for (char& c : s) c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    return s;
}

Move* MoveFactory::fromString(const std::string& userInput) {
    const std::string key= norm(userInput);

    // each key lists who that move beats
    static const std::unordered_map<std::string, std::unordered_set<std::string>> wins = {
        // rock paper scissors
        {"ROCK",    {"SCISSORS"}},
        {"PAPER",   {"ROCK"}},
        {"SCISSORS",    {"PAPER"}},

        // monkey, robot, ninja, zombie rules
        {"MONKEY",  {"NINJA", "ROBOT"}},
        {"ROBOT",   {"NINJA", "ZOMBIE"}},
        {"PIRATE",  {"ROBOT", "MONKEY"}},
        {"NINJA",   {"PIRATE", "ZOMBIE"}},
        {"ZOMBIE",  {"PIRATE", "MONKEY"}},
    };

    auto it = wins.find(key);
    if (it != wins.end()) {
        return new NamedMove(key, it->second);
    }
  
}
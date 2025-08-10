#include "Human.h"
#include "Move.h"
#include <iostream>

using namespace std;

Human::Human() {name = "Human";}
Human::Human(string n) {name = std::move(n);}

Move* Human::makeMove() {
    string input;
    cout << "Enter Move: ";
    cin >> input;   // reads input from user - full words
    return MoveFactory::fromString(input);  // caller (referee) will delete
}
#include "Computer.h"
#include "Move.h"

Computer::Computer() {name = "Computer";}

Move* Computer::makeMove() {
    return MoveFactory::fromString("Rock"); // let computer play rock
}
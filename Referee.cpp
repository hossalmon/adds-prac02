#include "Referee.h"
#include "Move.h"

Referee::Referee() {}

Player* Referee::refGame(Player* p1, Player* p2) {
    Move* m1 = p1->makeMove();
    Move* m2 = p2->makeMove();

    Player* winner = nullptr;
    const bool p1Wins = m1->beats(*m2);
    const bool p2Wins = m2->beats(*m1);

    if (p1Wins && !p2Wins) 
        winner = p1;
    else if (p2Wins && !p1Wins) 
        winner = p2;
    else                        
        winner = nullptr;   // draw

    // delete to prevent memory leaks
    delete m1;
    delete m2;
    
    return winner;
}
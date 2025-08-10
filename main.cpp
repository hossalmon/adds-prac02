#include <iostream>
#include "Human.h"
#include "Computer.h"
#include "Referee.h"

using namespace std;

int main() {
    Human human("Mei");
    Computer cpu;
    Referee ref;

    Player* winner = ref.refGame(&human, &cpu);
    if (!winner)
        cout << "It's a Tie" << endl;
    else
        cout << winner->getName() << " Wins" << endl;
    
    return 0;
}
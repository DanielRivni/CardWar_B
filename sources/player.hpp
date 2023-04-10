#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "card.hpp"

using namespace std;
namespace ariel
{
    class Player
    {
    private:
        string name;
        vector<Card *> stack;
        vector<Card *> taken;

    public:
        Player(string name);
        string getName() const;
        void setStack(vector<Card *> vcards);
        void addTaken(vector<Card *> vcards);
        int stacksize();
        int cardesTaken();
        Card *pullCard();
    };
}

#endif
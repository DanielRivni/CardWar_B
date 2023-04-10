#include "player.hpp"
using namespace ariel;

Player::Player(string name)
{
    this->name = name;
}

string Player::getName() const { return name; }
int Player::stacksize() { return (int)this->stack.size(); }
int Player::cardesTaken() { return (int)this->taken.size(); }
void Player::setStack(vector<Card *> vcards)
{
    this->stack = vcards;
}
void Player::addTaken(vector<Card *> vcards)
{
    for (unsigned long i = 0; i < vcards.size(); i++)
    {
        this->taken.push_back(vcards[i]);
    }
}

Card *Player::pullCard()
{
    Card *c = this->stack.back();
    this->stack.pop_back();
    return c;
}

bool operator==(const Player player1, const Player player2)
{
    return player1 == player2 || player1.getName() == player2.getName();
}

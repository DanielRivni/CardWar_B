#include "card.hpp"
using namespace ariel;

Card::Card(int num, Shape shape)
{
    this->num = num;
    this->shape = shape;
}

int Card::getNum() { return this->num; }

string Card::getNumString()
{

    switch (this->num)
    {
    case 1:
        return "Ace";
    case 11:
        return "Jack";
    case 12:
        return "Queen";
    case 13:
        return "King";
    default:
        return std::to_string(this->num);
    }
}

string Card::getShape()
{
    switch (this->shape)
    {
    case Hearts:
        return "Hearts";
    case Spades:
        return "Spades";
    case Diamonds:
        return "Diamonds";
    case Clubs:
        return "Clubs";
    }
}

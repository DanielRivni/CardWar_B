#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;
namespace ariel
{
    enum Shape
    {
        Hearts = 1,
        Diamonds = 2,
        Spades = 3,
        Clubs = 4
    };

    class Card
    {
    private:
        int num;
        Shape shape;

    public:
        Card(int num, Shape shape);
        int getNum();
        string getShape();
        string getNumString();
    };
}

#endif
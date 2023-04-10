#ifndef DECK_H
#define DECK_H
#include <vector>
#include "card.hpp"
namespace ariel
{
    class Deck
    {
    private:
        std::vector<Card *> deck;
        void shuffle();

    public:
        Deck();
        int getSize();
        vector<Card *> getCards(int begin, int end);
    };
}

#endif
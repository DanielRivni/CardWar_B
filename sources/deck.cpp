#include "deck.hpp"

#include <cstdlib>
#include <ctime>

using namespace ariel;

Deck::Deck()
{
    for (int i = 1; i <= 13; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            this->deck.push_back(new Card(i, (Shape)j));
        }
    }

    // reshuffle deck
    shuffle();
}

void Deck::shuffle()
{
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        // generate a random number between 0 and deck size (=52)
        unsigned long random_card = (unsigned long)rand() % this->deck.size();
        // move random card to the end
        std::swap(this->deck[random_card], this->deck.back());
    }
}

int Deck::getSize()
{
    return (int)this->deck.size();
}
vector<Card *> Deck::getCards(int begin, int end)
{

    // make sure begin&end are valid
    begin = begin > 0 ? begin : 0;
    end = end <= this->deck.size() ? end : this->deck.size();

    vector<Card *> subvector = {this->deck.begin() + begin, this->deck.begin() + end};
    return subvector;
}

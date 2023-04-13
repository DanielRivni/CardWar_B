#include <string>
#include <iostream>
#include <stdexcept>
#include "game.hpp"
using namespace ariel;

// concat 2 vectors to a new vector
template <typename T>
std::vector<T> operator+(const std::vector<T> &v1, const std::vector<T> &v2)
{
    std::vector<T> result = v1;
    result.insert(result.end(), v2.begin(), v2.end());
    return result;
}

Game::Game(Player &player1, Player &player2)
{
    this->p1 = &player1;
    this->p2 = &player2;
    this->deck = new Deck();

    // set each player with half the cards in deck (26)
    this->p1->setStack(this->deck->getCards(0, 26));
    this->p2->setStack(this->deck->getCards(26, 52));

    // initialize statistics
    this->p1Wins = 0;
    this->p2Wins = 0;
    this->draws = 0;
}

void Game::playTurn()
{

    // check edge cases
    if (this->p1 == this->p2)
    {
        throw std::logic_error("Game cannot initialized with a single player. need 2 for Tango :).");
    }
    if (this->p1->stacksize() == 0 || this->p2->stacksize() == 0)
    {
        throw std::logic_error("players have no cards left.");
    }

    std::vector<Card *> p1Cards;
    std::vector<Card *> p2Cards;
    string turn = "";

    while (true)
    {
        Card *c1 = p1->pullCard();
        Card *c2 = p2->pullCard();
        p1Cards.push_back(c1);
        p2Cards.push_back(c2);

        turn += p1->getName() + " played " + c1->getNumString() + " of " + c1->getShape() + " " +
                p2->getName() + " played " + c2->getNumString() + " of " + c2->getShape() + ". ";

        if (c1->getNum() == 1 && c2->getNum() > 2)
        {
            //  if p1 has an ACE
            p1Wins++;
            p1->addTaken(p1Cards + p2Cards);
            turn += p1->getName() + " wins.";
            turns.push_back(turn);
            turn = "";
            break;
        }
        else if (c2->getNum() == 1 && c1->getNum() > 2)
        {
            //  if p2 has an ACE
            p2Wins++;
            p2->addTaken(p1Cards + p2Cards);
            turn += p2->getName() + " wins.";
            turns.push_back(turn);
            turn = "";
            break;
        }
        else if (c1->getNum() > c2->getNum())
        {
            p1Wins++;
            p1->addTaken(p1Cards + p2Cards);
            turn += p1->getName() + " wins.";
            turns.push_back(turn);
            turn = "";
            break;
        }
        else if (c2->getNum() > c1->getNum())
        {
            p2Wins++;
            p2->addTaken(p1Cards + p2Cards);
            turn += p2->getName() + " wins.";
            turns.push_back(turn);
            turn = "";
            break;
        }
        else
        {
            turn += "Draw. ";
            this->draws++;

            if (this->p1->stacksize() > 0 && this->p2->stacksize() > 0)
            {
                // pull an upside card
                Card *dc1 = p1->pullCard();
                Card *dc2 = p2->pullCard();

                p1Cards.push_back(dc1);
                p2Cards.push_back(dc2);
            }

            // if players don't have enough cards for the actual Draw,
            // return each player his cards, and finish turn.
            if (this->p1->stacksize() == 0 || this->p2->stacksize() == 0)
            {
                p1->addTaken(p1Cards);
                p2->addTaken(p2Cards);
                turns.push_back(turn);
                turn = "";
                break;
            }
        }
    }
}
void Game::printLastTurn()
{
    cout << this->turns.back() << endl;
}

void Game::playAll()
{

    while (this->p1->stacksize() > 0 || this->p2->stacksize() > 0)
    {
        playTurn();
    }
}

string Game::getWinner()
{
    if (this->p1->cardesTaken() > this->p2->cardesTaken())
    {
        return this->p1->getName();
    }
    else if (this->p2->cardesTaken() > this->p1->cardesTaken())
    {
        return this->p2->getName();
    }
    else
    {
        return "Tie";
    }
}
void Game::printWiner()
{
    string winner = getWinner();
    if (winner == "Tie")
    {
        throw std::logic_error("None of the players won. it's a Tie.");
    }

    cout << getWinner() << endl;
}
void Game::printLog()
{
    for (unsigned long i = 0; i < this->turns.size(); i++)
    {
        cout << this->turns[i] << endl;
    }
}
void Game::printStats()
{
    cout << "Game Stats: " << endl;
    cout << "-----------" << endl;
    cout << " Winner: **" << getWinner() << "**" << endl;
    cout << " Draw rate: " << this->draws / (int)this->turns.size() << endl;
    cout << " Players Stats: " << endl;
    cout << "  " << this->p1->getName() << ":" << endl;
    cout << "   wins: " << this->p1Wins << endl;
    cout << "   wins rate: " << this->p1Wins / (int)this->turns.size() << endl;
    cout << "   cards won: " << this->p1->cardesTaken() << endl;
    cout << "  " << this->p2->getName() << ":" << endl;
    cout << "   wins: " << this->p2Wins << endl;
    cout << "   wins rate: " << this->p2Wins / (int)this->turns.size() << endl;
    cout << "   cards won: " << this->p2->cardesTaken() << endl;
}
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define ROCK2 u8"\U0001F5FB"
#define PAPER2 u8"\U0001F4C3"
#define SCISSORS2 u8"\U0001F52A"
#define LIZARD2 u8"\U0001F438"
#define SPOCK2 u8"\U0001F596"

/**
 * Hands
 * 
 * Description:
 *      Creates references to emojis for RPSLS.
 *      Generates random hands for both players.
 * 
 * Public Methods:
 *      - Rock, Paper, Scissors, Lizzard, Spock
 *           - returns emoji
 *      - RandHand
 *           - returns random hands
 *      
 *  Usage: 
 * 
 *      - Mainly a parent class for 'Player'
 *      
 */
class Hands
{
public:
    const string rock = ROCK2; 
    const string paper = PAPER2;
    const string scissors = SCISSORS2;
    const string lizard = LIZARD2;
    const string spock = SPOCK2;

    string arr[5] = {ROCK2, PAPER2, SCISSORS2, LIZARD2, SPOCK2};

    static string Rock()
    {
        return ROCK2;
    }
    static string Paper()
    {
        return PAPER2;
    }
    static string Scissors()
    {
        return SCISSORS2;
    }
    static string Lizard()
    {
        return LIZARD2;
    }
    static string Spock()
    {
        return SPOCK2;
    }
    string RandHand()
    {
      srand(time(NULL));
      return arr[rand() % 5];
    }
};

/**
 * Player
 * 
 * Description:
 *      Creates a player 
 * 
 * Public Methods:
 *      - Constructor creats players with random weapons
 *      - Overloaded '>' op 
 *            - basically creates the rules for RPSLS
 * 
 * Usage: 
 * 
 *      - Create Players and use op to battle.
 *      
 */
class Player : public Hands
{
public:
    string weapon1;
    string weapon2;
    /**
     * Constructor guarantees a player has two different "weapons"
     */
    Player()
    {
        weapon1 = RandHand();
        weapon2 = RandHand();

        while (weapon2 == weapon1)
        {
            weapon2 = Hands::RandHand();
        }
    }

    bool operator>(const Player rhs)
    {
        // rock crushes lizard and scissors     
        if (this->weapon1 == ROCK2)
        {
            if (rhs.weapon1 == SCISSORS2 || rhs.weapon1 == LIZARD2)
            {
                return true;
            }
        }
        // paper covers rock and disproves spock
        else if (this->weapon1 == PAPER2)
        {
            if (rhs.weapon1 == ROCK2 || rhs.weapon1 == SPOCK2)
            {

                return true;
            }
        }
        // scissors cuts paper and decapitates lizard
        else if (this->weapon1 == SCISSORS2)
        {
            if (rhs.weapon1 == PAPER2 || rhs.weapon1 == LIZARD2)
            {
                return true;
            }
        }
        // lizard poisons spock and eats paper
        else if (this->weapon1 == LIZARD2)
        {
            if (rhs.weapon1 == SPOCK2 || rhs.weapon1 == PAPER2)
            {
                return true;
            }
        }
        // spock smashes scissors and vaporizes rock
        else if (this->weapon1 == SPOCK2)
        {
            if (rhs.weapon1 == ROCK2 || rhs.weapon1 == SCISSORS2)
            {
                return true;
            }
        }
        // if weapon1 fails, check weapon2
        // rock crushes lizard and scissors 
        if (this->weapon2 == ROCK2)
        {
            if (rhs.weapon2 == SCISSORS2 || rhs.weapon2 == LIZARD2)
            {
                return true;
            }
        }
        // paper covers rock and disproves spock
        else if (this->weapon2 == PAPER2)
        {
            if (rhs.weapon2 == ROCK2 || rhs.weapon2 == SPOCK2)
            {
                return true;
            }
        }
        // scissors cuts paper and decapitates lizard
        else if (this->weapon2 == SCISSORS2)
        {
            if (rhs.weapon2 == PAPER2 || rhs.weapon2 == LIZARD2)
            {
                return true;
            }
        }
        // lizard poisons spock and eats paper
        else if (this->weapon2 == LIZARD2)
        {
            if (rhs.weapon2 == SPOCK2 || rhs.weapon2 == PAPER2)
            {

                return true;
            }
        }
        // spock smashes scissors and vaporizes rock
        else if (this->weapon2 == SPOCK2)
        {
            if (rhs.weapon2 == ROCK2 || rhs.weapon2 == SCISSORS2)
            {
                return true;
            }
        }
        // no one wins, tie
        return false;
    }
};
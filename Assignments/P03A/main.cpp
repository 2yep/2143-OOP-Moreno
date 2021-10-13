/*****************************************************************************
 *                    
 *  Author:           Miklos Moreno
 *  Title:            RPSLS
 *  Course:           2143
 *  Semester:         Fall 2021
 * 
 *  Description:
 *        Program that has 2 characters battle in the art of RPSLS.
 *        weapons are used for the hell of it.
 *   
 * 
 * 
 *  Usage:
 *        Part 1 of bigger project. Run program for simples battles.
 *        
 * 
 *  Files: output.txt, RPSLS.hpp
 *****************************************************************************/

#include "RPSLS.hpp"

void Battle(Player, Player);

ofstream of;

int main()
{
  of.open("output.txt");
    
  of << "Rock Paper Scissors Lizard Spock" << endl;
  of << "********************************" << endl;

  Player p1;
  Player p2;

  Player p3;
  Player p4;

  Player p5;
  Player p6;
  
  Battle(p1, p2);
  Battle(p3, p4);
  Battle(p5, p6);

  of.close();
  return 0;
}

/**
     * Battle
     * 
     * Description:
     *      Evals who wins and prints results
     * 
     * Params:
     *      - Player 1 and 2
     * 
     * Returns:
     *      - void
     */
void Battle(Player p1, Player p2)
{
    // check if weapon(s)1 are equal
    if (p1.weapon1 != p2.weapon1)
    {
        if (p1 > p2)
        {
            of << "Player 1's " << p1.weapon1 << " or " << p1.weapon2 << " beats Player 2's " << p2.weapon1 << " or " << p2.weapon2 << endl;
        }
        else if (p2 > p1)
        {
            of << "Player 2's " << p2.weapon1 << " or " << p2.weapon2 << " beats Player 1's " << p1.weapon1 << " or " << p1.weapon2 << endl;
        }
    }
    // weapon(s)1 was equal go to weapon2
    else
    {
        if (p1.weapon2 != p2.weapon2)
        {
            if (p1 > p2)
            {
                of << "Player 1's " << p1.weapon2 << " beats Player 2's " << p2.weapon2 << endl;
            }
            else if (p2 > p1)
            {
                of << "Player 2's " << p2.weapon2 << " beats Player 1's " << p1.weapon2 << endl;
            }
        }
        else
        {
            // both players have same weapons
            of << "It's a tie!" << endl;
        }
    }
}
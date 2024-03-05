/*
File: Number scrabble -- CS112_A1_T5_20230113.cpp
Game 2
Purpose: Each player takes turns picking a number from the list
If a player has picked three numbers that add up to 15, that player wins the game
Author: Hazem ahmed mohamed
ID: 20230113
version : 1.0
 */

#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    // Set the sum of card values, as if the sum of any player reaches 30 (45-15), the player wins
    int n_cards_first = 45;
    int n_cards_second = 45;

    // for checking if the player will not pick the same value again
    // These are empty sets to store the cards that every player choose
    unordered_set<int> chosen_values_first;
    unordered_set<int> chosen_values_second;

    // Welcome message and display status
    cout << "Welcome to Number Scrabble game\n";
    cout << "Number of cards = 9\n";
    cout << "Each player should take cards that add up to 15\n";
    cout << "Once a card has been picked, it cannot be picked again\n";
    cout << "First player who reaches 15 wins !!\n";


    // Game playing
    while ( 30 <= n_cards_first && n_cards_first <= 45 && 30 <= n_cards_second && n_cards_second <= 45)
    {
        // First player's turn
        int first_player;
        cout << "Player 1, Please take a card: \n";
        cin >> first_player;

        // Check if the player chooses a number from 1 to 9 and hasn't chosen it before
        while (1 <= first_player && first_player <= 9 && chosen_values_first.count(first_player) == 1)
        {
            cout << "You already chose this card. Please choose a different one.\n";
            cout << "Player 1, please take a card: \n";
            cin >> first_player;
        }


        // Check if the player chooses a number from 1 to 9
        if (1 <= first_player && first_player <= 9)
        {
            chosen_values_first.insert(first_player);
            n_cards_first -= first_player;
        }
        else
        {
            cout << "Invalid input. Please choose a card from 1 to 9\n";
            continue;
        }

        if (n_cards_first == 30)
        {
            cout << "First player wins!\n" ;
            break;
        }
        // Check for a draw if the player's chosen values exceed 15
        else if (n_cards_first < 30)
        {
            cout << "The game is a draw! , player 1 exceeded the limit ( 15 )\n" ;
            break;
        }

        // Second player's turn
        int second_player;
        cout << "Player 2, Please take a card: \n";
        cin >> second_player;

        // Check that the card isn't picked again
        while ((second_player == first_player) || (chosen_values_second.count(second_player) == 1))
        {
            cout << "The other player has chosen the same card or it's already picked. Please choose another one.\n";
            cout << "Player 2, Please take a card: \n";
            cin >> second_player;
        }


        // Check if the player chooses a number from 1 to 9
        if (1 <= second_player && second_player <= 9)
        {
            chosen_values_second.insert(second_player);
            n_cards_second -= second_player;
        }
        else
        {
            cout << "Invalid input. Please choose a card from 1 to 9.\n" ;
            continue;
        }

        if (n_cards_second == 30)
        {
            cout << "Second player wins!\n";
            break;
        }
        // Check for a draw if the player's chosen values exceed 15
        else if (n_cards_second < 30)
        {
            cout << "The game is a draw! , player 2 exceeded the limit ( 15 )\n" ;
        }
    }

    return 0;
}

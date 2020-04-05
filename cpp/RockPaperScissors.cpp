#include <iostream>
using namespace std;

enum objectType {ROCK, PAPER, SCISSORS};

// Function prototypes
void displayRules();
objectType retrievePlay(char selection);
bool validSelection(char selection);
void convertEnum(objectType object);
objectType winningObject(objectType play1, objectType play2);
void gameResult(objectType play1, objectType play2, int& winner);
void displayResults(int gCount, int wCount1, int wCount2);

int main(){

  //Step 1
  int gameCount; // variable to store the number of games played
  int winCount1; // variable to store the number of games won by player 1
  int winCount2; // variable to store the number of games won by player 2
  int gameWinner;
  char response; // variable to get the user's response to play the game
  char selection1;
  char selection2;
  objectType play1; // player1's selection
  objectType play2; // player2's selection
}

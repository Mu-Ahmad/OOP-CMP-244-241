#include <iostream>
#include "Connect4Game.h"

using namespace std;

void printLastMsg(){
  cout << "\t\t\t************************************\n"
       << "\t\t\t*      Thank you for playing       *\n"
       << "\t\t\t************************************\n";
  system("pause");
}
int main(){
  Connect4Game game;
  int pos, choice; bool win=false;
  game.initBoard(BOARD_SIZE);
  game.start();
  cout << '\n';
  int i=0;
  while(!(game.isBoardFull() || win)){
    cout << "Player:" << game.getTurn() << '\n';
    cout << "Enter Column No (0-6): ";
    cin >> pos;
    if(game.rowsLeft(pos) <= 0 || (pos < 0 || pos > 6)){
      cout << "Invalid choice.\n";
      continue;
    }
    game.insertValue(pos);
    win = game.isWin(game.getTurn());
    system("cls");
    game.showBoard();
    game.switchTurn(game.getTurn());
  }
  if(game.isWin(PLAYER1))
    cout << "\n"
         << "Player 1 has won the game.\n";
  else
    cout << "\n"
         << "Player 2 has won the game.\n";
  cout << "Ener 1 to play again: ";
  cin >> choice;
  if(choice==1)  main();
  printLastMsg();
  return 0;
}

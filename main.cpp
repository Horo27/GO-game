#include <algorithm>

#include "Board.h"
#include "Player.h"
#include "Menu.h"
#include "Game.h"
#include <iostream>
#include <conio.h>
#include <conio.h>

using namespace std;

void wait();

int main() {
   /* Board board1(3);
    board1.displayBoard();

    Player player1("Smecher","WHITE");
    Player player2("Fraier", "BLACK");
    player1.displayStats();
    player2.displayStats();

    player1.placeStone(board1,0,0);
    player2.placeStone(board1,1,0);

    board1.displayBoard();

    Menu menu(true);

    Board board1 = menu.declareBoard();

    board1.displayBoard();

    Player player1 = menu.declarePlayer("WHITE");
    Player player2 = menu.declarePlayer("BLACK");

    player1.displayStats();
    player2.displayStats();

    player1.placeStone(board1,0,0);

    board1.displayBoard();*/

    //Menu menu(true);


    Game game; ///DECLAR JOCUL

    ///DECLAR TABLA SI JUCATORII

    Menu menu;

    Board board = menu.declareBoard();
    Player player0 = menu.declarePlayer("WHITE");
    Player player1 = menu.declarePlayer("BLACK");

    wait();

    game.changeState(true); ///Incep jocul
    std::cout<<"JOCUL A INCEPUT !!!"<<std::endl;

    int contor=0;
    while(game.currState() && contor<5) {
        if(contor) system("cls");

        contor++;
        std::cout<<"TURA CU NUMARUL "<<contor<<std::endl;
        std::cout<<endl;

        int x, y;

        std::cout<<player0.getName()<<" muta in pozitia: ";
        cin>>x>>y;
        player0.placeStone(board, x, y);

        std::cout<<endl;

        std::cout<<player1.getName()<<" muta in pozitia: ";
        cin>>x>>y;
        player1.placeStone(board, x, y);

        wait();
    }
    board.displayBoard();
}

void wait() {

    std::cout << "Press Enter to continue...";
    getch();
}
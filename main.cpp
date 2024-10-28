#include <algorithm>

#include "Board.h"
#include "Player.h"
#include "Menu.h"
#include "Game.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main() {

    Game game; ///DECLAR JOCUL

    ///DECLAR TABLA SI JUCATORII

    Menu menu;

    Board board = menu.declareBoard();
    Player player1 = menu.declarePlayer(WHITE);
    Player player2 = menu.declarePlayer(BLACK);

    game.changeState(true); ///Incep jocul
    std::cout<<"JOCUL A INCEPUT !!!"<<std::endl;

    menu.decisionMenu(player1,player2,board);

}
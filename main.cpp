//#include "./Headers/Board.h"
//#include "./Headers/Player.h"
//#include "./Headers/Menu.h"
#include "./Headers/Game.h"
#include <iostream>
#include <fstream>
#include <memory>
//#include "Factory.h"
#include "Commands.h"

int main() {

    std::ifstream fin("tastatura.txt");
    if(!fin.is_open()) {
        std::cout << "File could not be opened\n";
        return 1;
    }

    Game game; ///DECLAR JOCUL

    ///FOLOSITI menu(fin) PENTRU CITIREA DIN FISIERUL TASTATURA.TXT
    ///FOLOSITI menu PENTRU CITIREA DE LA TASTATURA

    //
    // Menu menu(fin);
    //Menu menu;

    //DE INLOCUIT X Y CU LIN COL

    ///DECLAR TABLA SI JUCATORII
    /*Board board = menu.declareBoard();

    Player player1 = menu.declarePlayer(WHITE);
    Player player2 = menu.declarePlayer(BLACK);*/

    //std::unique_ptr<Creator> playerCreator = std::make_unique<PlayerCreator>();

    /*Factory factory;

    Product* player1 = factory.create(PLAYER);
    Product* player2 = factory.create(PLAYER);*/

    Receiver res;

    Command* startCommand = new playerDecalration(&res);

    auto* invoker = new Invoker();
    invoker->SetOnStart(startCommand);

    invoker->startGame();

    /*auto *derviedPtr = dynamic_cast<PlayerProduct*>(player1);
    derviedPtr->getName();
    derviedPtr->getColor();*/

    delete startCommand;
    delete invoker;

    ///INCEP JOCUL
    game.changeState(true);
    std::cout<<"JOCUL A INCEPUT !!!"<<std::endl;

    //menu.decisionMenu(player1,player2,board);

    fin.close();
}

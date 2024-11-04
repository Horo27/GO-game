#include <algorithm>

#include "./Headers/Board.h"
#include "./Headers/Player.h"
#include "./Headers/Menu.h"
#include "./Headers/Game.h"
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

void processInput(std::istream& input) {

    int a;
    input>>a;

    std::cout<<a;
}

int main() {

    std::ifstream fin("tastatura.txt");
    if(!fin.is_open()) {
        cout << "File could not be opened" << endl;
        return 1;
    }

    Game game; ///DECLAR JOCUL



    ///FOLOSITI menu(fin) PENTRU CITIREA DIN FISIERUL TASTATURA.TXT
    ///FOLOSITI menu PENTRU CITIREA DE LA TASTATURA

    Menu menu(fin);
    //Menu menu;

    ///DECLAR TABLA SI JUCATORII
    Board board = menu.declareBoard();
    Player player1 = menu.declarePlayer(WHITE);
    Player player2 = menu.declarePlayer(BLACK);

    ///INCEP JOCUL
    game.changeState(true);
    std::cout<<"JOCUL A INCEPUT !!!"<<std::endl;

    menu.decisionMenu(player1,player2,board);

    fin.close();
}
//
// Created by Horo on 10/26/2024.
//
#include "../Headers/Menu.h"
#include "../Headers/Board.h"
#include "../Headers/Player.h"
#include <iostream>
#include <fstream>
#include <ostream>

std::ostream& operator<<(std::ostream& out, const Menu& m) {

    //out<<"Input Method: "<<m.inputMethod<<"\n";
    out<<"Turn Number: "<<m.turnNumber<<"\n";
    return out;
}

Board Menu::declareBoard(){
    int size;
    std::cout<<"Select the board size: ";
    inputMethod>>size;
    if(checkInputMethod())
        std::cout<<size<<"\n";
    Board board(size);
    return {board};
}

Player Menu::declarePlayer(Color color){
    std::string name;
    std::cout<<"Select the name of the player with the "<< colorToString(color) << " pieces: ";
    inputMethod>> name;
    if(checkInputMethod())
        std::cout<<name<<"\n";
    return Player {name, color};
}

void Menu::playersMove(Player &player1, Player &player2, Board &board) {
    turnNumber++;
    std::cout<<"TURA CU NUMARUL "<<turnNumber<<std::endl;
    std::cout<<std::endl;

    int x, y;

    std::cout<<player1.getName()<<" muta in pozitia: ";
    inputMethod>>x>>y;
    if(checkInputMethod())
        std::cout<<x<<" "<<y<<"\n";
    board.placeStone(x,y,WHITE);

    std::cout<<player2.getName()<<" muta in pozitia: ";
    inputMethod>>x>>y;
    if(checkInputMethod())
        std::cout<<x<<" "<<y<<"\n";
    board.placeStone(x,y,BLACK);

}

void showMenu();

void Menu::decisionMenu(Player &player1, Player &player2, Board &board) {

    bool running = true;
    int choice;

    while (running) {

        showMenu();
        inputMethod>>choice;
        if(checkInputMethod())
            std::cout<<choice<<"\n";

        switch (choice) {
            case 1:
                playersMove(player1, player2,board);
                std::cout<<"=============\n\n";
                break;

            case 2:
                std::cout<<board;
                std::cout<<"=============\n\n";
                break;
            ///
            default:
                board.clearBoard();
                running = false;
                std::cout<<"\nTHANK YOU FOR PLAYING!!\n";
        }
    }

}

void showMenu() {
    std::cout<<"=============\n";
    std::cout<<"!!!MENU!!!   \n\n";
    //std::cout<<"=============\n";

    std::cout<<"1. Continue\n";
    std::cout<<"2. Display Board\n";
    std::cout<<"3. End\n";
    std::cout<<"Please choose an option: ";
}

bool Menu::checkInputMethod() const {
    return &inputMethod != &std::cin;
}
//
// Created by Horo on 10/26/2024.
//
#include "Menu.h"
#include "Board.h"
#include "Player.h"
#include <iostream>
#include <ostream>
#include <conio.h>

Board Menu::declareBoard() {
    int size;
    std::cout<<"Select the board size: ";
    std::cin>>size;
    Board board(size);
    return {board};
}

Player Menu::declarePlayer(Color color) {
    std::string name;
    std::cout<<"Select the name of the player with the "<< colorToString(color) << " pieces: ";
    std::cin>> name;
    return {name, color};
}

void wait();

void Menu::playersMove(Player &player1, Player &player2, Board &board) {
    turnNumber++;
    std::cout<<"TURA CU NUMARUL "<<turnNumber<<std::endl;
    std::cout<<std::endl;

    int x, y;

    std::cout<<player1.getName()<<" muta in pozitia: ";
    std::cin>>x>>y;
    board.placeStone(x,y,WHITE);

    std::cout<<player2.getName()<<" muta in pozitia: ";
    std::cin>>x>>y;
    board.placeStone(x,y,BLACK);

    //wait();
}

void showMenu();

void Menu::decisionMenu(Player &player1, Player &player2, Board &board) {

    bool running = true;
    int choice;

    while (running) {

        showMenu();
        std::cin>>choice;

        switch (choice) {
            case 1:
                playersMove(player1, player2,board);
                break;

            case 2:
                board.displayBoard();
                break;
            ///
            default:
                running = false;
        }
    }

}


void wait() {
    std::cout << "Press Enter to continue...";
    std::cout<<std::endl;
    getch();
}

void showMenu() {
    std::cout<<"=============\n";
    std::cout<<"     MENU    \n";
    std::cout<<"=============\n";

    std::cout<<"1. Continue\n";
    std::cout<<"2. Display Board\n";
    std::cout<<"3. End\n";
    std::cout<<"Please choose an option: ";
}
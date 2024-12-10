//
// Created by Horo on 10/26/2024.
//
#include "../Headers/Menu.h"
#include "../Headers/Board.h"
#include "../Headers/Player.h"
#include "../Headers/PlaceRule.h"
#include "../Headers/Exceptions.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <memory>

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

void Menu::untilValidMove(Player &player, Board &board) {

    std::shared_ptr<Rules> ptrBase = std::make_shared<Rules>(board);


    int ok =1;
    int lin;
    int col;

    std::cout<<player.getName()<<" muta in pozitia: ";
    inputMethod>>lin>>col;
    if(checkInputMethod())
        std::cout<<lin<<" "<<col<<"\n";

    while(ok) {
        try {
            if(!ptrBase->basicRule(lin,col)) {
                throw customException("There's already a stone there, choose another spot");
            }
            throw std::exception();
        }
        catch(customException &e) {
            std::cout<<e.what()<<"\n";

            std::cout<<player.getName()<<" muta in pozitia: ";
            inputMethod>>lin>>col;
            if(checkInputMethod())
                std::cout<<lin<<" "<<col<<"\n";
        }
        catch(...) {
            ok=0;
        }
    }

    PlaceRule rule(board);
    CaptureRule capture(board);

    Rules::setColor(player.getColor());
    rule.PlaceStone(lin, col);

}


void Menu::playersMove(Player &player1, Player &player2, Board &board) {
    turnNumber++;
    std::cout<<"TURA CU NUMARUL "<<turnNumber<<std::endl;
    std::cout<<std::endl;

    untilValidMove(player1,board);
    untilValidMove(player2,board);

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

Menu &Menu::operator=(const Menu &other) {
    if(this == &other)
        return *this;
    this->turnNumber = other.turnNumber;
    return *this;
}


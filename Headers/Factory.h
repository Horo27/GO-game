#include <iostream>
#include "Color.h"
#include "vector"

enum type {BOARD, PLAYER};

class Product {
public:
    virtual ~Product() {}
    virtual std::string Operation() = 0;
};

class PlayerProduct : public Product {
    std::string name;
    Color color; //1 for white 2 for black
    int captures;
    int territoryPoints;

public:
    std::string Operation() override {
        std::cout<<this->name<<" "<<this->color<<"\n";
        return "{Result of the PlayerProduct}";
    }
    explicit PlayerProduct (std::string name = "NULL", Color color = WHITE, int captures = 0, int territoryPoints = 0):
    name(std::move(name)), color(color), captures(captures), territoryPoints(territoryPoints) {
        std::cout<<"Player product constructor"<<std::endl;
    };
    ~PlayerProduct()=default;
    void setNameColor(std::string name, Color color);
    friend std::ostream& operator<<(std::ostream& out, const PlayerProduct& player);
    std::string getName();
    Color getColor(){return color;};

    //PlayerProduct(const Player &other) : name(other.name), color(other.color), captures(other.captures), territoryPoints(other.territoryPoints) {};
    //PlayerProduct& operator=(const PlayerProduct& other);
};

class BoardProduct : public Product {
    int size;
    std::vector<std::vector<int>> board;
public:
    std::string Operation() override {
        int x,y;
        std::cout<<"place stone: ";
        std::cin>>x>>y;
        placeStone(x,y,WHITE);
        return "{Result of the BoardProduct}\n";
    }
    explicit BoardProduct (int size = 19): size(size),board(size, std::vector<int>(size, EMPTY)) {}
    friend std::ostream& operator<<(std::ostream& os, const BoardProduct& b);
    ~BoardProduct()=default;
    void placeStone(int x, int y, Color color);
    void clearBoard();

    //bool isCaptured(int x, int y, Color color);
    //void removeStones(int x,int y, Color color);

    BoardProduct (BoardProduct& other): size(other.size), board(other.board) {}
    BoardProduct& operator=(const BoardProduct& other);
};

class Factory {
public:
     ~Factory() = default;

     Product* create(type t) {
        switch (t) {
            case PLAYER: {
                return new PlayerProduct();
            }
            case BOARD: {
                return new BoardProduct();
            }
        }

    }
};




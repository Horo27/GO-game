#pragma once
#include <memory>

#include "Factory.h"
#include "Player.h"

class Command {
 public:
  virtual ~Command() {
  }
  virtual void Execute() const = 0;
};

class SimpleCommand : public Command {
 private:
  std::string pay_load_;

 public:
  explicit SimpleCommand(std::string pay_load) : pay_load_(pay_load) {
  }
  void Execute() const override {
  }
};

class Receiver {
 public:
  void declarePlayers(Product *player1, Product *player2) {
      std::string name;
      std::cout<<"Declaring Players!!!\n";
      std::cout<<"Player with the WHITE pieces name: ";
      std::cin>> name;

      Factory f;

      player1 = f.create(PLAYER);
      auto *derviedPtr = dynamic_cast<PlayerProduct*>(player1);
      derviedPtr->setNameColor(name, WHITE);

      std::cout<<"\nPlayer with the BLACK pieces name: ";
      std::cin>> name;

      player2 = f.create(PLAYER);
      auto *derviedPtr2 = dynamic_cast<PlayerProduct*>(player2);
      derviedPtr2->setNameColor(name, BLACK);
  }

  void showPlayers(Product* player1, Product* player2) {
      player1->Operation();
      player2->Operation();
  }
};

class playerDecalration : public Command {
 private:
  Receiver *receiver_;
  Product* player1;
  Product* player2;

 public:
    ~playerDecalration() {
        delete receiver_;
        delete player1;
        delete player2;
    }
  playerDecalration(Receiver *receiver,Product* player1, Product* player2) :
  receiver_(receiver), player1(player1), player2(player2) {}

    void declarePlayers() {
        std::string name;
        std::cout<<"Declaring Players!!!\n";
        std::cout<<"Player with the WHITE pieces name: ";
        std::cin>> name;

        Factory f;

        player1 = f.create(PLAYER);
        auto *derviedPtr = dynamic_cast<PlayerProduct*>(player1);
        derviedPtr->setNameColor(name, WHITE);

        std::cout<<"\nPlayer with the BLACK pieces name: ";
        std::cin>> name;

        player2 = f.create(PLAYER);
        auto *derviedPtr2 = dynamic_cast<PlayerProduct*>(player2);
        derviedPtr2->setNameColor(name, BLACK);
    }

    void showPlayers() {
        player1->Operation();
        player2->Operation();
    }
  void Execute() const override {
      declarePlayers();
      this->receiver_->showPlayers(player1, player2);
  }
};

class Invoker {
 private:
  Command *on_start_;
  //Command *on_finish_;
public:
  Invoker(Command *on_start = nullptr)
    : on_start_(on_start){
  }

  ~Invoker() {
    delete on_start_;
  }

  void SetOnStart(Command *command) {
    this->on_start_ = command;
  }

  void startGame() {
    if (this->on_start_ != nullptr) {
      this->on_start_->Execute();
    }
  }
};
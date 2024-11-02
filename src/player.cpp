// include the header file here
#include "../include/player.h"
#include <iostream>


// add all your player functions in here.
Player *newPlayer(std::string name, int num_goals){
    Player *new_player = new Player;
    new_player->name = name;
    new_player->num_goals = num_goals;
    return new_player;
}

Player *copyPlayer(const Player *p){
    if (p == nullptr){
        return nullptr;
    }
    Player *copy_player = new Player;
    copy_player->name = p->name;
    copy_player->num_goals = p->num_goals;
    return copy_player;
}

void printPlayer(const Player *p){
    if (p == nullptr){
        std::cout << "No player found!" << std::endl;
    }else{
        std::cout << "Player name: " << p->name << std::endl;
        std::cout << "Total goals: " << p->num_goals << std::endl;
    }
    return;
}

void deletePlayer(Player *p){
    delete p;
    p = nullptr;
    return;
}
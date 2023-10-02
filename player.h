// Made by Justin Nguyen and Andrew Best
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

class Player{
    private:
    string private_playerName;
    int private_fuelCount = 200000;
    int private_suitLvl = 1;
    int private_money = 100000;
    int private_health = 100;
    int totalHealthChange;
    int private_SpaceSuitHealth = 100;
    vector<int> private_crewMates;


    public:
    Player();
    Player(int fuelCount, int suitLvl, int spaceSuitHealth, int money, string name , vector<int> crewMates, int health);
    int getFuelCount();
    void setFuelCount(int fuelCount);
    int getSuitLvl();
    void setSuitLvl(int suitLvl);
    int getSpaceSuitHealth();
    void setSpaceSuitHealth(int spaceSuitHealth);
    int getMoney();
    void setMoney(int money);
    string getName();
    void setName(string name);
    void setHealth(int health);
    int getHealth();
    void question();
};
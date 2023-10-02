// Made by Justin Nguyen and Andrew Best
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>
using namespace std;

class Battle{
    private:
    string private_alienName;
    int private_fight;
    int private_weaponChoice;
    int private_weapon;

    public:
    //Player player1PlayerBattle;
    //Store player1StoreBattle;
    //planetGeneration player1PGBattle;
    Battle();
    Battle(string alienName, int fight, int weaponChoice, int weapon);
    void setAlienName(string fileName);
    string getAlienName();
    void setWeaponChoice(vector<string> getWeaponChoice);
    int getWeaponChoice();
    void fight(int weaponChoice, int planetNum);

};
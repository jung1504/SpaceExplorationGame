// Made by Justin Nguyen and Andrew Best
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Store{
    private:
    int numMedKits = 0;
    bool translator;
    int private_weapons[3];
    int private_numSaber;
    int private_numBlaster;
    int private_numBeam;


    public:
    Store();
    int getMedKits();
    void setMedKits(int _numMedKits);
    bool getTranslator();
    void setTranslator(bool _translator);
    int getWeapons();
    void setSaber(int weapons);
    void setBlaster(int weapons);
    void setBeam(int weapons);
    int getSaber();
    int getBlaster();
    int getBeam();
    void setWeapons(int weapon[], int tempWeapon, int type);
    void removeWeapon(int weapons[], int weaponType);







};
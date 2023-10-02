// Made by Justin Nguyen and Andrew Best
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class planetGeneration{
    private:
    string private_planetName;
    float private_size;
    int private_fuelRequired;
    int private_planetNum;
    int private_popSize;

    public:
    planetGeneration();
    planetGeneration(string planetName, float size, int fuelRequired, int planetNum);
    string getPlanetName();
    void setPlanetName(string filename);
    float getPlanetSize();
    void setPlanetSize();
    int getFuelRequired();
    void setFuelRequired(int planetNum);
    void setPlanetNum(int planetNum);
    int getPlanetNum();
    void setPopSize(float size);
    int getPopSize();
    
};
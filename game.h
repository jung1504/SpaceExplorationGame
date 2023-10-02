// Made by Justin Nguyen and Andrew Best
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>
#include "player.h"
#include "battle.h"
#include "planetGeneration.h"
#include "store.h"
#include "map.h"
using namespace std;

class Game{
    private:
    int private_fightChoice;
    int fuel[19];
    int private_TotalPopSaved;
    int private_TotalPopKilled;
    int private_popChange;
    int private_gameEndType;
    int private_numPlanetsAcc;
    int private_numPlanetsWrong;
    int private_AlienRes;
    string private_siteTrait; 
    int private_traitsFound[7];  
    int private_alienResponses[19]; 
    string private_playerName;
    vector<int> private_crewMates;
    int private_hasFighter;
    string private_singleTrait;
    int private_index;
    int private_pageNum;
    int private_popLeft;
    int private_hasDoctor;
    int private_hasCIA;

    public:
    Player player1Player;
    Store player1Store;
    planetGeneration player1PG;
    Map player1M;
    Battle player1Battle;
    //logBook player1Logbook;
    Game();
    void setName(string name);
    string getName();
    void storeMenu();
    void phase1();
    void phase2();
    void phase3();
    void spaceSuitMenu(int money);
    void weaponMenu(int money);
    void question();
    void setFightChoice();
    void setWeaponChoice(int weaponChoice[], int fighter);
    int getFightChoice();
    void newPlanet();
    void setPopChange(int pop, bool habitable);
    int getPopChange();
    int getPopSaved();
    int getPopKilled();
    void setGameEndType(int gameEndType);
    int getGameEndType();
    void giveUp();
    void numPlanetsAcc();
    void numPlanetsWrong();
    int getnumPlanetsAcc();
    int getnumPlanetsWrong();
    void reportPlanet();
    void setSiteTrait(int type[7]);
    string getSiteTrait();
    void setTraitsFound(int index);
    int getTraitsFound(int index);
    vector<int> getCrewMates();
    void setCrewMates(int crewMate1, int crewMate2 );
    int checkFighter(int fighter);
    void logBook();
    void setAlienRes(int response, int planetNum);
    int getAlienRes();
    void setSingleTrait(int type);
    string getSingleTrait();
    void increasePageNum();
    int getPageNum();
    string nameArr(string nameArr[]);
    int doctorCheck(int doctor);
    int ciaCheck(int cia);
    int weaponMenuFight(int money);

    };
// Made by Justin Nguyen and Andrew Best
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <climits>
#include <random>
#include "game.h"
//cspell: ignore Elon Cybertruck fout


void Game::weaponMenu(int money){
    int choice;
    int saberCount = 1; // starts off with 1 light saber
    int blasterCount = 0;
    int beamCount = 0; 
    int weapons [3];
    cout << "Which weapon type do you wish to buy? \n 1. Light Saber \n 2. Blaster \n 3. Beam Gun \n 4. Go back to menu" <<endl;
    cin >> choice; // users choice of weapon
    int weaponCount = 0;
    do{ // do while loop to keep looping until user chooses to exit 
        switch(choice){ // switch case to go through each option
            case 1: 
            {
            cout << "How many Light Sabers would you like ($1000 each)" <<endl;
            cin >> saberCount;
            weaponCount = weaponCount + saberCount;
            if (weaponCount > 2){ // checks number of weapons 
                cout << weaponCount <<endl;
                cout << "You cannot have more than two weapons at the same time."<< endl;
                choice = 4;
                storeMenu(); // recalls store menu
            }
            else if (money < 1000){ // checks if user has enough money
                cout << "You do not have enough money for that." <<endl;
                choice = 4;
                storeMenu();

            }
            else if ((money > 1000) and (weaponCount < 2)){ // if user has enough money and less than 2 weapons then they can buy weapon
                cout << weaponCount << endl;
                money = money - (saberCount * 1000);
                cout << "You have $" << money << "left." <<endl;
                player1Store.setWeapons(weapons, saberCount, 0);
                choice = 4;
                storeMenu();
            }
            }
            break;
            
            case 2:
            cout << "How many Blasters would you like ($2000 each)" <<endl;
            cin >> blasterCount;
            if (weaponCount > 2){
                cout << "You cannot have more than two weapons at the same time."<< endl;
                choice = 4;
                storeMenu();
            }
            else if (money < 2000){
                cout << "You do not have enough money for that." <<endl;
                choice = 4;
                storeMenu();
            }
            else if ((money > 2000) and (blasterCount <= 2)){
                money = money - (blasterCount * 2000);
                cout << "You have $" << money << "left." <<endl;
               weapons[1] = blasterCount;
               weaponCount = weaponCount + blasterCount;
               player1Store.setWeapons(weapons, blasterCount, 1);
               choice = 4;
               storeMenu();
            }
            break;
            
            case 3:
            cout << "How many Beam Guns would you like ($5000 each)" <<endl;
            cin >> beamCount;
            if (weaponCount > 2){
                cout << "You cannot have more than two weapons at the same time."<< endl;
                choice = 4;
            }
            else if (money < 5000){
                cout << "You do not have enough money for that." <<endl;
                choice = 4;
                storeMenu();
            }
            else if ((money > 5000) and (beamCount <= 2)){
                money = money - (beamCount * 5000);
                cout << "You have $" << money << "left." <<endl;
                player1Store.setWeapons(weapons, beamCount, 2);
                weaponCount = weaponCount + beamCount;
                choice = 4;
                storeMenu();
            }
            storeMenu();
            break;
            
            case 4:
            storeMenu();
        }
    }while(choice != 4); // stops when user enters 4
}


Player::Player(){ 
    private_fuelCount = 200000;
    private_health = 100;
    private_suitLvl = 1;
    private_money = 100000;
    private_playerName = "";
    vector<int> private_crewMates;
    totalHealthChange = 0;
}

Player::Player(int fuelCount, int suitLvl, int spaceSuitHealth, int money, string name , vector<int> _crewMates, int health){
    private_fuelCount = fuelCount;
    private_suitLvl = suitLvl;
    private_SpaceSuitHealth = spaceSuitHealth;
    private_money = money;
    private_playerName = name;
    private_crewMates = _crewMates;
    private_health = health;

}

int Player::getFuelCount(){
    return private_fuelCount;
}

void Player::setFuelCount(int fuelCount){
    private_fuelCount = fuelCount;
}

int Player::getMoney(){
    return private_money;
}

void Player::setMoney(int money){
    private_money = money;
}

int Player::getSuitLvl(){
    return private_suitLvl;
}

void Player::setSuitLvl(int suitLvl){
    private_suitLvl = suitLvl;
}

int Player::getSpaceSuitHealth(){
    return private_SpaceSuitHealth;
}
void Player::setSpaceSuitHealth(int spaceSuitHealth){
    private_SpaceSuitHealth = spaceSuitHealth;
}
string Game::getName(){
    return private_playerName;
}
void Game::setName(string name){
    cout << "Enter your name: "<<endl;
    cin >> name;
    private_playerName = name;
}

vector<int> Game::getCrewMates(){
    // for (int i = 0; i < private_crewMates.size(); i++){
    //     cout << private_crewMates[i];
    //     switch (private_crewMates[i]){
    //         case 1:
    //         cout << "1.Lola Doctor (+5% health each time you lose health after battle) ";
    //         break;
    //         case 2:
    //         cout << "2.Nerys Fighter (+10% change win battle) ";
    //         break;
    //         case 3:
    //         cout << "3.Millie Tycoon (Double fuel) ";
    //         break;
    //         case 4:
    //         cout << "4.Chuck Intimidator (+10% chance aliens tell truth) ";
    //         break;
    //         default:
    //         return private_crewMates;
    //         break;
    //     }
    // }
    return private_crewMates;
}

/* 
Function: sets crew mates to crewmates vector
checks invalid inputs 
if crewmates are the same invalid
if crewmates are valid then we add them into vector
return: void
*/
void Game::setCrewMates(int crewMate1, int crewMate2){ 
    cin >> crewMate1;
    while((crewMate1 > 4) or (crewMate1 < 1)){ // invalid inputs
        cout << "Invalid input" <<endl;
        cin >> crewMate1;
    }
    cin >> crewMate2;
    while(crewMate1 == crewMate2){
        cout << "Can not pick same crewmate, re-enter answer." <<endl; // same crewmates
        cin >> crewMate2;
    }
    while ((crewMate2 > 4) or (crewMate2 < 1)){ // invalid inputs
        cout << "Invalid input, re-enter answer" <<endl;
        cin >> crewMate2;
    }
    private_crewMates.push_back(crewMate1); // uses pushback to add to end of vector
    private_crewMates.push_back(crewMate2);
    if (crewMate1 == 3 or crewMate2 == 3){
        player1Player.setFuelCount(400000);
    }
    
}

void Player::setHealth(int healthChange){ //make sure to make total health change 0 at start.
    totalHealthChange = totalHealthChange + healthChange;
    private_health = totalHealthChange + healthChange;
}

int Player::getHealth(){
    return private_health;
}


//Store


void Store::setSaber(int saberCount){
    saberCount = private_weapons[0];
    private_numSaber = saberCount;
}

void Store::setBlaster(int blasterCount){
    blasterCount = private_weapons[1];
    private_numBlaster = blasterCount;
}

void Store::setBeam(int beamCount){
    beamCount = private_weapons[2];
    private_numBeam = beamCount;
}

int Store::getBeam(){
    return private_numBeam;
}

int Store::getBlaster(){
    return private_numBlaster;
}

int Store::getSaber(){
    return private_numSaber;
}

Store::Store()
{
    numMedKits = 0;
    translator = false;
    private_numBeam = 0;
    private_numBlaster = 0;
    private_numSaber = 1;
    
}

int Store::getMedKits()
{
    return numMedKits;
}

void Store:: setMedKits(int _numMedKits)
{
   numMedKits = _numMedKits;
}

bool Store::getTranslator()
{
    return translator;
}

void Store::setTranslator(bool _translator)
{
   translator = _translator;
}

// int* Store::getWeapons()
// {
//     cout << "You have: \n Light sabers:" << private_weapons[0] << "\n Blasters:" << private_weapons[1] << "\n Beam Guns:" << private_weapons[2] << endl;
//     return private_weapons;
// }

void Store::setWeapons(int weapons[2], int tempWeapon, int weaponType )
{
    if (weapons[weaponType] > 2){
        weapons[weaponType] = weapons[weaponType] + tempWeapon;
    }
    else{
        cout << "You have too many of this weapon."<<endl;
    }
    for (int i = 0; i < 3; i++){
        private_weapons[i] = weapons[i];
    }
}


void Store::removeWeapon(int weapons[], int weaponType)
{
    weapons[weaponType] = weapons[weaponType] - 1;
    for (int i = 0; i < 3; i++){
        private_weapons[i] = weapons[i];
    }
}


//Phase 2:

Map::Map()
{
    resetMap();
}


/*
 * Algorithm: Resets positions of player, NPC, misfortunes, sites to -1 and clears mapData  
 * Set Player position coordinates to 0
 * Set NPC position coordinates to -1
 * Set npc_on_map to false
 * Set misfortune_count to 0
 * Set site_count to 0
 * loop i from 0 to num_misfortunes
 *      Set row, col and type of misfortune location to -1
 * loop i from 0 to num_sites
 *      Set row, col and type of site location to -1
 * loop i from 0 to num_rows
 *      loop i from 0 to num_cols
 *          Set (x,y) location on mapData to '-'
 * Parameters: none
 * Return: nothing (void)
 */
void Map::resetMap() {
    // resets player position, count values, and initializes values in position arrays to -1
    playerPosition[0] = 0; 
    playerPosition[1] = 0;

    npcPosition[0] = -1;
    npcPosition[1] = -1;

    npc_on_map = false;
    misfortune_count = 0;
    site_count = 0;

    for (int i = 0; i < num_misfortunes; i++) {
        misfortunes[i][0] = -1;
        misfortunes[i][1] = -1;
        misfortunes[i][2] = -1;
    }

    for (int i = 0; i < num_sites; i++) {
        sites[i][0] = -1;
        sites[i][1] = -1;
        sites[i][2] = -1;
    }

    npcPosition[0] = -1;
    npcPosition[1] = -1;

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            mapData[i][j] = '-';
        }
    }
}

// return player's row position
int Map::getPlayerRowPosition() {
    return playerPosition[0];
}

// return player's column position
int Map::getPlayerColPosition() {
    return playerPosition[1];
}

int Map::getSiteCount() {
    return site_count;
}

int Map::getMisfortuneType(){
    for(int i = 0; i < misfortune_count; i++){
        if (playerPosition[0] == misfortunes[i][0] && playerPosition[1] == misfortunes[i][1]){
            if (misfortunes[i][2] != -1){
                return misfortunes[i][2];
            }
        }
    }
    return 0;
}

int Map::getMisfortuneCount() {
    return misfortune_count;
}

int Map::getSiteTrait() {
    for(int i = 0; i < num_sites; i++){
        if (playerPosition[0] == sites[i][0] && playerPosition[1] == sites[i][1]){
            if (sites[i][2] != -1){
                return sites[i][2];
            }
        }
    }
    return 0;
}

/*
 * Algorithm: Checks if the location is an NPC location  
 * if player position is NPC location and npc_on_map is true
 *      return true
 * return false
 * Parameters: none
 * Return: boolean (bool)
 */
bool Map::isNPCLocation(){
    if (playerPosition[0] == npcPosition[0] && playerPosition[1] == npcPosition[1] && npc_on_map == true){
        return true;
    }
    return false;
}

/*
 * Algorithm: Checks if the location is misfortune  
 * loop i from 0 to misfortune_count
 *      if player position is a misfortune location
 *          if misfortune type is -1
 *              return false
 *          return true  
 * return false
 * Parameters: none
 * Return: boolean (bool)
 */
bool Map::isMisfortuneLocaton(){
    for(int i = 0; i < misfortune_count; i++){
        if (playerPosition[0] == misfortunes[i][0] && playerPosition[1] == misfortunes[i][1]){
            if (misfortunes[i][2] == -1){
                return false;
            }
            return true;
        }
    }
    return false;
}

/*
 * Algorithm: Checks if the location is site  
 * loop i from 0 to num_sites
 *      if player position is a site location
 *          if site type is -1
 *              return false
 *          return true  
 * return false
 * Parameters: none
 * Return: boolean (bool)
 */
bool Map::isSiteLocation(){
    for(int i = 0; i < num_sites; i++){
        if (playerPosition[0] == sites[i][0] && playerPosition[1] == sites[i][1]){
            if (sites[i][2] == -1){
                return false;
            }
            return true;
        }
    }
    return false;
}

/*
 * Algorithm: Checks if a planet is habitable or not
 * Set water, oxygen and fertile_soil to false
 * Set non_habitable_traits to 0 
 * loop i from 0 to num_sites
 *      if site type is 1
 *          Set water to true
 *      else if site type is 2
 *          Set oxygen to true
 *      else if site type is 3
 *          Set fertile_soil to true 
 *      else if site type is between 4 and 6
 *          Increment non_habitable_traits 
 * if water, oxygen, fertile_soil are true and non_habitable_traits <=1
 *      set habitable to true
 * else
 *      set habitable to false
 * return habitable
 * Parameters: none
 * Return: boolean (bool)
 */
bool Map::isHabitable(){
    bool water = false;
    bool oxygen = false;
    bool fertile_soil = false;
    int non_habitable_traits = 0;
    for (int i = 0; i < num_sites; i++){
        if (sites[i][2] == 1){
            water = true;
        } 
        else if (sites[i][2] == 2){
            oxygen = true;
        }
        else if (sites[i][2] == 3){
            fertile_soil = true;
        }
        else if (sites[i][2] >= 4 && sites[i][2] <= 6){
            non_habitable_traits++;
        }
    }
    if (water && oxygen && fertile_soil && (non_habitable_traits <= 1)){
        habitable = true;
    }
    else{
        habitable = false;
    }
    return habitable;
}

/*
 * Algorithm: Checks if the given row and column on map is a free space 
 * if row and column is not within the map boundaries
 *      return false
 * loop i from 0 to misfortune_count
 *      if (row,col) is a misfortune location
 *          return false
 * loop i from 0 to num_sites
 *      if (row,col) is a site location
 *          return false
 * if (row,col) is a npc position
 *      return false
 * return true
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 */
bool Map::isFreeSpace(int row, int col){
    if (!(row >= 0 && row < num_rows && col >= 0 && col < num_cols)) {
        return false;
    }
    for(int i = 0; i < misfortune_count; i++){
        if (row == misfortunes[i][0] && col == misfortunes[i][1]){
            return false;
        }
    }
    for(int i = 0; i < num_sites; i++){
        if (row == sites[i][0] && col == sites[i][1]){
            return false;
        }
    }
    if (row == npcPosition[0] && col == npcPosition[1]){
        return false;
    }
    return true;
}

void Map::setMisfortuneCount(int num_misfortunes){
    misfortune_count = num_misfortunes;
}

void Map::setNPC(bool isNpc){
    npc_on_map = isNpc;
}


void Map::setPlayerRowPosition(int row) {
    playerPosition[0] = row;
}


void Map::setPlayerColPosition(int col) {
    playerPosition[1] = col;
}

/*
 * Algorithm: Create an NPC on the map 
 * if npc is present on map
 *      return false
 * if (row,col) is not a free space
 *      return false
 * store row and col values in npcPosition array
 * set (row,col) value in mapData to 'A'
 * set npc_on_map to true
 * return true
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 */
bool Map::spawnNPC(int row, int col) {
    if (npc_on_map) {
        return false;
    }

    if (!isFreeSpace(row, col)) {
        return false;
    }

    npcPosition[0] = row;
    npcPosition[1] = col;
    mapData[row][col] = 'A';
    npc_on_map = true;
    return true;
}

/*
 * Algorithm: Create a misfortune on the map 
 * if misfortune_count is more than or equal to number of misfortunes
 *      return false
 * if (row,col) is not a free space
 *      return false
 * if next row in misfortunes matrix is -1 -1
 *      store row, col and type values in the current row of misfortunes matrix
 *      increment misfortune_count
 *      return true
 * Parameters: row (int), col (int), type (int)
 * Return: boolean (bool)
 */
bool Map::spawnMisfortune(int row, int col, int type) {

    if (misfortune_count >= num_misfortunes) {
        return false;
    }

    // location must be blank to spawn
    if (!isFreeSpace(row, col)) {
        return false;
    }

    //if (misfortunes[misfortune_count][0] == -1 && misfortunes[misfortune_count][1] == -1) {
        misfortunes[misfortune_count][0] = row;
        misfortunes[misfortune_count][1] = col;
        misfortunes[misfortune_count][2] = type;
        misfortune_count++;
        return true;
    //}

    return false;
}

/*
 * Algorithm: Create a site on the map 
 * if site_count is more than or equal to number of sites
 *      return false
 * if (row,col) is not a free space
 *      return false
 * if next row in sites matrix is -1 -1
 *      store row, col and type values in the current row of sites matrix
 *      increment site_count
 *      Set (row,col) value in mapData to 'S'
 *      return true
 * Parameters: row (int), col (int), type (int)
 * Return: boolean (bool)
 */
bool Map::spawnSite(int row, int col, int type) {

    if (site_count >= num_sites) {
        return false;
    }

    // location must be blank to spawn
    if (!isFreeSpace(row, col)) {
        return false;
    }

    if (sites[site_count][0] == -1 && sites[site_count][1] == -1) {
        sites[site_count][0] = row;
        sites[site_count][1] = col;
        sites[site_count][2] = type;
        site_count++;
        mapData[row][col] = 'S';
        return true;
    }

    return false;
}

/*
 * Algorithm: This function prints "*" to reveal a position of misfortune
 * Set the value of (row, col) in mapData to '*'
 * Parameters: row (int), col (int)
 * Return: nothing (void)
 */
void Map::revealMisfortune(int row, int col) {
    mapData[row][col] = '*';
}

/*
 * Algorithm: Make the player move based on the given command 
 * if user inputs w and if its not the top row of the map
 *      Move the player up by one row
 *      return true
 * if user inputs s and if its not the bottom row of the map
 *      Move the player down by one row
 *      return true
 * if user inputs a and if its not the leftmost column
 *      Move the player left by one column
 *      return true
 * if user inputs d and if its not the rightmost column
 *      Move the player right by one column
 *      return true
 * Parameters: move (char)
 * Return: boolean (bool)
 */
bool Map::executeMove(char move){
    // if user inputs w, move up if it is an allowed move
    if(!(playerPosition[0] == 0) && (tolower(move) == 'w')){
        playerPosition[0] -= 1;
        return true; 
    }
    // if user inputs s, move down if it is an allowed move
    else if(!(playerPosition[0] == (num_rows - 1))&& (tolower(move) == 's')){
        playerPosition[0] += 1;
        return true; 
    }
    // if user inputs a, move left if it is an allowed move
    else if(!(playerPosition[1] == 0)&& (tolower(move) == 'a')){
        playerPosition[1] -= 1;
        return true; 
    }
    // if user inputs d, move right if it is an allowed move
    else if(!(playerPosition[1] == (num_cols - 1))&& (tolower(move) == 'd')){
        playerPosition[1] += 1;
        return true; 
    }
    else{
        cout << "Invalid Move" << endl; 
        return false; 
    }
}

/*
 * Algorithm: This function prints a 2D map in the terminal.
 * Loop i from 0 to number of rows
 *      Loop j from 0 to number of columns
 *          if player position is at (i,j)
 *              print "x"
 *          else if player is at (i,j)
 *              print "-"
 *          else
 *              print the value of (i,j) in mapData
 * Parameters: none
 * Return: nothing (void)
 */
void Map::displayMap() {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (playerPosition[0] == i && playerPosition[1] == j) {
                cout << "x";
            } else if (mapData[i][j] == 'H') {  // don't show player on the map
                cout << "-";
            }
            else {
                cout << mapData[i][j];
            }
        }
        cout << endl;
    }
}

//planetGeneration

planetGeneration::planetGeneration(){
    private_planetName = "";
    private_fuelRequired = 0;
    private_size = 0;
    private_planetNum = 0;
    private_popSize = 0;
}

planetGeneration::planetGeneration(string planetName, float size, int fuelRequired, int planetNum){
    private_planetName = planetName;
    private_fuelRequired = fuelRequired;
    private_size = size;
    private_planetNum = planetNum;
}
/*
Function: creates planet name
uses random number generator to create a random planet name
1. Open ifstream to four word text file
2. Make alphanumeric array
3. Create random number using sys clock as seed
Method of randomization found from https://www.cplusplus.com/reference/random/default_random_engine/.
4. If random number is greater than array length, take first two digits and check if they are array length or less
5. If not divide by two, make number small enough
6. Make string of those characters to hold first part of name
7. Make name uppercase
8.Generate another random number, this time smaller than 3125
9. Get the 4 letter word from that line, add to string
10. private_planetName = combined string of name and four letter word
*/

void planetGeneration::setPlanetName(string filename){ //will make planet name with random 6 random letter/numbers and the 4 letter words.
    ifstream fin("fourWords.txt");
    char alphanum[36] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9'}; 
    string name;
    string line;
    int lineNum = 0;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count(); 
    minstd_rand0 generator (seed);
    for (int i = 0; i < 6; i++){
        int random = generator();
        while (random > 36){
            random = random % 100;
            if (random > 36){
                random = random / 2;
            }
        }
        //cout << random <<endl;
        name = name + alphanum[random];
    }
    for (int j = 0; j < name.length(); j++){
    name[j] = toupper(name[j]);
    int ran1 = generator();
    if (ran1 > 3125){
        ran1 = ran1 % 1000;
        if (ran1 == 0){
            ran1++;
        }
    }
    
    while(getline(fin, line)){
        if (lineNum == ran1){
            //std::cout << ran1 <<endl;
            name = name + "-" + line;    
        }
        lineNum++;
    }
    private_planetName = name;
    } 
}  

string planetGeneration::getPlanetName(){
    return private_planetName;
}

/*
1. Calculate fuel usage and put in array
Note: It is basically impossible to make it that far, I've done the math, so it is unnecessary to be able to calculate to an infinite n value
*/

void planetGeneration::setFuelRequired(int planetNum){ 
   //static const int size = 19;
   int foo [22] = {0,50000,52500, 55256, 58306, 61709, 65517, 69810, 74683, 80261, 86703, 94220, 103098, 113727, 126661, 142704, 163069, 189660, 225631, 276540, 353014};
   private_fuelRequired = foo[planetNum];
   // if (planetNum == 0){
    //     private_fuelRequired = 50000;
    // }a
    // else{
    // fuelReq[planetNum] = fuelReq[planetNum - 1] * (fuelReq[planetNum - 1] / 1000000) + fuelReq[planetNum - 1];
    // private_fuelRequired = fuelReq[planetNum];
    
    // }

}

int planetGeneration::getFuelRequired(){
    return private_fuelRequired;
}
//generates random number to fit array length, sets size to whatever value is at the random index (bigger planets are rarer as they should be)
void planetGeneration::setPlanetSize(){
    float size[16] = {1,1.5,2,2.5,3,3.5,4,4.5,5,5.5,6,6.5,7,7.5,8};
    unsigned seed = chrono::system_clock::now().time_since_epoch().count(); 
    minstd_rand0 generator (seed);
    int random = generator();
    if (random > 16){
        random = random % 100;
        if (random > 16){
            random = random % 10;
        }
    }
    private_size = size[random];
}

float planetGeneration::getPlanetSize(){
    return private_size;
}

void planetGeneration::setPlanetNum(int planetNum){
    planetNum++;
    private_planetNum = planetNum;
}

int planetGeneration::getPlanetNum(){
    return private_planetNum;
}

void planetGeneration::setPopSize(float size){
    private_popSize = size * 615;
}

int planetGeneration::getPopSize(){
    return private_popSize;
}


 //phase 1 functions
 
 /*
Function: Store menu for user to buy stuff from resource center
displays menu
switch statement to run through each case 
 */
 void Game::storeMenu(){
    int input;
    int money = player1Player.getMoney(); // use getters and setters to retrieve values
    bool translator = player1Store.getTranslator();
    int numMedKits;
    int currentMedKits = player1Store.getMedKits();
    do{ // do while loop to let user exit whenever they would like
        std::cout << "Which item do you wish to buy?" << endl;
        cout << "1. Weapon" << endl;
        cout << "2. Translator" << endl;
        cout << "3. Space suit" << endl;
        cout << "4. Medical Kits" << endl;
        cout << "5. Fuel" << endl;
        cout << "6. Purchase and Leave" << endl;
        cin >> input;
        switch(input){
            case 1:
            money = player1Player.getMoney();
            weaponMenu(money); // calling weapon menu function 
            break; // break out of switch
            case 2:
            int option;
            cout << "Would you like to purchase a translator device ($5,000)? 1 for yes, 0 for no." << endl;
            cin >> option;
            if(option != 1 and option != 0) // invalid inputs
            {
                cout << "Invalid Option" << endl;
            }
            else if(translator == true){ // if user already has a translator
                cout << "You already have a translator!" << endl;
            }
            else{
                if(option == 1) // if user buys a translator 
                {
                    translator = true;
                    money = money - 5000; 
                    player1Store.setTranslator(translator); //update money
                    player1Player.setMoney(money);
                    cout << "You have $" << money << "left" << endl;
                    cout << "You not have a translator!" << endl;
                }
            }
            break;

            case 3:
            spaceSuitMenu(player1Player.getMoney()); // calls spacesuit menu
            break;

            case 4:
            cout << "How many medical kits would you like to purchase ($2,000 each)? You currently have " << player1Store.getMedKits() << endl;
            cout << "Medical kits improve health by 40% only buy needed amount, buy medical kits 1 at a time to increase health by 40% each time with a max of 100" << endl;
            cin >> numMedKits;

            if(numMedKits <= 0) // checks for invalid inputs
            {
                cout << "Invalid Input" << endl;
            }
            else
            {
                money = (money - (numMedKits * 2000));
                player1Player.setMoney(money);
                currentMedKits = numMedKits + currentMedKits;
                player1Store.setMedKits(currentMedKits);
                int currentHealth= player1Player.getHealth();
                currentHealth = currentHealth + 40;
                if (currentHealth > 100) // stops health from being over 100%
                {
                    int difference = currentHealth - 100;
                    currentHealth = currentHealth - difference;
                    player1Player.setHealth(currentHealth);
                    cout << "Current Health: " << currentHealth << endl;
                }

                else{ // sets health after buying med kits 
                    player1Player.setHealth(currentHealth);
                    cout << "Current Health: " << currentHealth << endl;
                }
                
                
            }
            
            break;

            case 5: // fuel menu
            {
            int amountRequested;
            int fuelCount = player1Player.getFuelCount();
            cout << "You have " << player1Player.getFuelCount() << "gallons of fuel. Your spacecraft can hold 300,000 gallons of fuel. How many gallons would you like to purchase ($1,000 per 10,000 gallons)? Input must be in multiples of 10000s."<<endl;
            cin >> amountRequested;
            if (amountRequested % 10000 != 0){ // checks that requested amount is a multiple of 10,000
                cout << "Input must be in multiples of 10,000s. Re-enter a valid quantity."<<endl;
                cin >> amountRequested;
            }
            if (amountRequested % 10000 == 0){ // if it is a multiple of 10,000
                fuelCount = fuelCount + amountRequested;
                if (fuelCount > 300000) // max fuel count is 300,000
                {
                    cout << "Thats too much fuel! Your spacecraft can only have 300,000 gallons" << endl;
                }
                else{
                player1Player.setFuelCount(fuelCount); // sets fuel count 
                int money = money - (amountRequested / 10000) * 1000; // updates money
                player1Player.setMoney(money);
                cout << "You have " << fuelCount << " gallons of fuel" << endl;
                }
                
            }
            break;
            }
            default: // default condition
            if (input != 6){
            cout << "Please enter a valid input." <<endl;
            }
            break;
        }

    }while(input != 6);
    // if (input == 6){
    //     // cout << "Great purchases. Elon is sending a space capable flying cybertruck to you!"<<endl;
    //     // cout << "Hit enter when you are ready to enter space and go to your first planet." << endl;
    //     // cin.ignore();
    //     // cin.get();
        
        
    // }
}

/*
Function: Space Suit Menu for user to upgrade spacesuit
menu that goes through each type of spacesuit
checks for invalid inputs and if the user has the spacesuit already. 
subtracts amount owed if already owned a upgraded suit level 2 or above
*/
void Game::spaceSuitMenu(int money){
    int option;
    int currentSuitLvl = player1Player.getSuitLvl();
do { // do while loop to keep going until user is done
    cout << "Would you like to upgrade your spacesuit to any of these? The space suit health will be set to 100%." << endl;
    cout << "1. Space suit grade 2 is $5,000" << endl;
    cout << "2. Space suit grade 3 is $10,000" << endl;
    cout << "3. Space suit grade 4 is $15,000" << endl;
    cout << "4. Space suit grade 5 is $20,000" << endl;
    cout << "5. Go back to menu" << endl;
    cin >> option;
    if (option < 1 || option > 5 ) // checks for invalid input
    {
        cout << "invalid input" << endl;
        cin >> option;
    }
    else if((option + 1) == currentSuitLvl) // option + 1 because user option is 1 below actual suit level 
    {
        cout << "Your suit is already grade " << currentSuitLvl << endl;
    }
    else 
    {
        switch(option)
        {
            case 1:
        {
            if (currentSuitLvl == 3 || currentSuitLvl == 4 || currentSuitLvl == 5) // checks if suit is already level 2  
            {
                cout << "your suit level is already higher than level 2" << endl;
            }
            else if (currentSuitLvl <= 1)
            {
                if (money >= 5000) // checks if user has enough money
                {
                    cout << "Your spacesuit is now a grade 2." << endl;
                    player1Player.setSuitLvl(option + 1);
                    money = money - 5000; // updates money
                    player1Player.setMoney(money);
                    cout << "You have $" << money << "left" << endl;
                    option = 0;
                }
                else{
                    cout << "You do not have enough money to upgrade" << endl;
                }
            }
            else{
                cout << "your suit level is already higher than level 2" << endl;
            }
                break;
        }
            case 2:
            {
            if (currentSuitLvl == 4 || currentSuitLvl == 5) // checks if suit is already level 3
            {
                cout << "your suit level is already higher than level 3" << endl;
            }
            else if (currentSuitLvl == 2)
            {
                if(money >= 5000)
                {
                    cout << "Your spacesuit is now a grade 3." << endl;
                    player1Player.setSuitLvl(option + 1);
                    money = money - 5000;
                    player1Player.setMoney(money);
                    cout << "You have $" << money << "left" << endl;
                    option = 0;
                }
                else
                {
                    cout << "You do not have enough money to upgrade" << endl;
                }
            }
            else if (currentSuitLvl == 1)
            {
                if(money >= 10000)
                {
                    cout << "Your spacesuit is now a grade 3." << endl;
                    player1Player.setSuitLvl(option + 1);
                    money = money - 10000;
                    player1Player.setMoney(money);
                    cout << "You have $" << money << "left" << endl;
                    option = 0;
                }
                else
                {
                    cout << "You do not have enough money to upgrade" << endl;
                }
            }
        }
            break;
            case 3:
            {
            if (currentSuitLvl == 5) // checks if suit is already level 3
            {
                cout << "your suit level is already higher than level 4" << endl;
            }
            else if (currentSuitLvl == 1)
            {
                if(money >= 15000)
                {
                    cout << "Your spacesuit is now a grade 4." << endl;
                    player1Player.setSuitLvl(option + 1);
                    money = money - 15000;
                    player1Player.setMoney(money);
                    cout << "You have $" << money << "left" << endl;
                    option = 0;
                }
                else 
                {
                    cout << "You do not have enough money to upgrade" << endl;
                }
            }
            else if (currentSuitLvl == 2)
            {
                if(money >= 10000)
                {
                    cout << "Your spacesuit is now a grade 4." << endl;
                    player1Player.setSuitLvl(option + 1);
                    money = money - 10000;
                    player1Player.setMoney(money);
                    cout << "You have $" << money << "left" << endl;
                    option = 0;
                }
                else 
                {
                    cout << "You do not have enough money to upgrade" << endl;
                }
            }
            else if (currentSuitLvl == 3)
            {
                if(money >= 5000)
                {
                    cout << "Your spacesuit is now a grade 4." << endl;
                    player1Player.setSuitLvl(option + 1);
                    money = money - 5000;
                    player1Player.setMoney(money);
                    cout << "You have $" << money << "left" << endl;
                    option = 0;
                }
                else 
                {
                    cout << "You do not have enough money to upgrade" << endl;
                }
            }
        }
            break;
            case 4:
            {
            if (currentSuitLvl == 1)
            {
                if(money >= 20000)
                {
                    cout << "Your spacesuit is now a grade 5." << endl;
                    player1Player.setSuitLvl(option + 1);
                    money = money - 20000;
                    player1Player.setMoney(money);
                    cout << "You have $" << money << "left" << endl;
                    option = 0;
                }
                else{
                    cout << "You do not have enough money to upgrade" << endl;
                }
            }
            else if (currentSuitLvl == 2)
            {
                if(money >= 15000)
                {
                    cout << "Your spacesuit is now a grade 5." << endl;
                    player1Player.setSuitLvl(option + 1);
                    money = money - 15000;
                    player1Player.setMoney(money);
                    cout << "You have $" << money << "left" << endl;
                    option = 0;
                }
                else{
                    cout << "You do not have enough money to upgrade" << endl;
                }
            }
            if (currentSuitLvl == 3)
            {
                if(money >= 10000)
                {
                    cout << "Your spacesuit is now a grade 5." << endl;
                    player1Player.setSuitLvl(option + 1);
                    money = money - 10000;
                    player1Player.setMoney(money);
                    cout << "You have $" << money << "left" << endl;
                    option = 0;
                }
                else{
                    cout << "You do not have enough money to upgrade" << endl;
                }
            }
            if (currentSuitLvl == 4)
            {
                if(money >= 5000)
                {
                    cout << "Your spacesuit is now a grade 5." << endl;
                    player1Player.setSuitLvl(option + 1);
                    money = money - 5000;
                    player1Player.setMoney(money);
                    cout << "You have $" << money << "left" << endl;
                    option = 0;
                }
                else{
                    cout << "You do not have enough money to upgrade" << endl;
                }
            }
            break;

        }
        }
    }
}while (option != 5);
cout << " You have $" << player1Player.getMoney() << "left" << endl;
storeMenu();
}





int Game::weaponMenuFight(int money){ // same as weapon menu
    int choice;
    int saberCount = 1; // starts off with 1 light saber
    int blasterCount = 0;
    int beamCount = 0; 
    int weapons [3];
    cout << "Which weapon type do you wish to buy? \n 1. Light Saber \n 2. Blaster \n 3. Beam Gun \n 4. Go back to menu" <<endl;
    cin >> choice; // users choice of weapon
    int weaponCount = 0;
    while(weaponCount == 0){ // do while loop to keep looping until user chooses to exit 
        switch(choice){ // switch case to go through each option
            case 1: 
            {
            cout << "How many Light Sabers would you like ($1000 each)" <<endl;
            cin >> saberCount;
            weaponCount = weaponCount + saberCount;
            if (weaponCount > 2){ // checks number of weapons 
                cout << weaponCount <<endl;
                cout << "You cannot have more than two weapons at the same time."<< endl;
                choice = 4;
            }
            else if (money < 1000){ // checks if user has enough money
                cout << "You do not have enough money for that." <<endl;
                choice = 4;


            }
            else if ((money > 1000) and (weaponCount < 2)){ // if user has enough money and less than 2 weapons then they can buy weapon
                cout << weaponCount << endl;
                money = money - (saberCount * 1000);
                cout << "You have $" << money << "left." <<endl;
                player1Store.setWeapons(weapons, saberCount, 0);
                choice = 4;
            }
            }
            break;
            
            case 2:
            cout << "How many Blasters would you like ($2000 each)" <<endl;
            cin >> blasterCount;
            if (weaponCount > 2){
                cout << "You cannot have more than two weapons at the same time."<< endl;
                choice = 4;
            }
            else if (money < 2000){
                cout << "You do not have enough money for that." <<endl;
                choice = 4;
            }
            else if ((money > 2000) and (blasterCount <= 2)){
                money = money - (blasterCount * 2000);
                cout << "You have $" << money << "left." <<endl;
               weapons[1] = blasterCount;
               weaponCount = weaponCount + blasterCount;
               player1Store.setWeapons(weapons, blasterCount, 1);
               choice = 4;
            }
            break;
            
            case 3:
            cout << "How many Beam Guns would you like ($5000 each)" <<endl;
            cin >> beamCount;
            if (weaponCount > 2){
                cout << "You cannot have more than two weapons at the same time."<< endl;
                choice = 4;
            }
            else if (money < 5000){
                cout << "You do not have enough money for that." <<endl;
                choice = 4;
            }
            else if ((money > 5000) and (beamCount <= 2)){
                money = money - (beamCount * 5000);
                cout << "You have $" << money << "left." <<endl;
                player1Store.setWeapons(weapons, beamCount, 2);
                weaponCount = weaponCount + beamCount;
                choice = 4;
            }
            break;   
        }
    }
    return money;
}


int split(string inputString, char delim, string arr[], int size){
    string temp = "";
    int num = 0;
    if (inputString == ""){
        return num;
        }
    for ( int i = 0; i < inputString.length();i++){
        if (inputString[i] != delim)
        {
            temp = temp + inputString[i];
            }
        else {
            num++;
            if (num > size)
            {
                num = -1;
                return num;
            }
            else 
            {
                arr[num - 1] = temp;
                temp = "";
            }
        }
    }
    num++;
    if (num > size){
        return -1;
    }
    else {
        arr[num - 1]= temp;
    }
    return num;
}

//phase 2

Game::Game(){
    private_fightChoice = 0;
    private_TotalPopSaved = 0;
    private_TotalPopKilled = 0;
    private_popChange = 8000;
    private_gameEndType = 0;
    private_numPlanetsAcc = 0;
    private_numPlanetsWrong = 0;
    private_siteTrait = "";
    for (int i = 0; i < 6; i++){
    private_traitsFound[i] = 0;
    }   
    private_playerName = "";
    private_hasFighter = 0;
    private_pageNum = 0;
    private_hasCIA = 0;
    private_hasDoctor = 0;
}
//phase 2 driver function
void Game::phase2(){
    int input;
    bool npcFound;
    int currHealth = player1Player.getHealth();
    int spaceSuitHealth = player1Player.getSpaceSuitHealth();
    int currFuel = player1Player.getFuelCount();
    int planetNum= player1PG.getPlanetNum();
    //int habitablePlanets = player1M.
    do{ //loops menu, switches inputs
        cout << player1PG.getPlanetName()<<endl;
        player1M.displayMap();
        cout << "Select one: \n 1. Move \n 2. View status \n 3. View log book \n 4. Resource center \n 5. Report planet as habitable \n 6. Enter wormhole to next planet \n 7. Give up" <<endl;
        cin >> input;
        switch(input){
            case 1:
            {
            char key;
            cout << "Select one: w. up s. down d. right a. left m. menu" <<endl;
            while (key != 'm'){
                cin >> key;
                player1M.executeMove(key);
                cout << player1PG.getPlanetName()<<endl;
                player1M.displayMap();
                int row = player1M.getPlayerRowPosition();
                int col = player1M.getPlayerColPosition();
                if (player1M.isFreeSpace(row,col) == false){
                    if (player1M.isSiteLocation() == true){
                        cout << "Good job, you have found a site that may have some useful information about this planet. If you get this question right, the information will be revealed. If you answer incorrectly though, you’ll become more frustrated and lose 1% health due to stress."<<endl;
                        question();

                    }
                    cout << "above" <<endl;
                    if (player1M.isNPCLocation() == true){
                        cout << "You have encountered a friendly alien!" <<endl;
                        if (player1Store.getTranslator() == true){
                            char input;
                            cout << "You can communicate with this alien. You can defeat them in rock, paper, scissors three times and gain $200 (enter z). \nIf you do not want to fight, enter any key besides z. \nThe chance of the alien telling the truth is 70%." <<endl; 
                            //creative liberty, the alien should always give an opinion the game is already hard enough
                            cin >> input; 
                            if (input == 'z'){ //a made you move too since it's in the move function, yes we could have made a function for this but this works too.
                                int winCount = 0;
                                int loseCount = 0;
                                while ((winCount < 2) and (loseCount < 2)){
                                    char option;
                                    cout << "Choose: rock(r), paper(p), scissors(s)" <<endl;
                                    cin >> option;
                                    unsigned seed = chrono::system_clock::now().time_since_epoch().count(); //read setPlanetName() for details
                                    minstd_rand0 generator (seed);
                                    int random = generator();
                                    if (random < 3){ //randomizes alien option
                                        random = random % 10;
                                        if (random < 3 ){
                                            random = random / 3;
                                        }
                                        if (random == 0){
                                            random++;
                                        }
                                    }
                                    switch(option){
                                        case 'r':
                                        if (random == 1){
                                            cout << "Draw, go again!" <<endl;
                                            break;
                                        }
                                        else if (random == 3){
                                            cout << "You win this round!" <<endl;
                                            winCount++;  
                                            break;  
                                        }
                                        else{
                                            cout <<  "You lose this round." <<endl;
                                            loseCount++;
                                            break;
                                        }
                                        
                                        case 'p':
                                        if (random == 1){
                                            cout << "You lose this round." <<endl;
                                            loseCount++;
                                            break;
                                        }
                                        else if (random == 2){
                                            cout << "Draw, go again!" <<endl;
                                            break;
                                        }
                                        else{
                                            cout << "You win this round!"<<endl;
                                            winCount++;
                                            break;
                                        }

                                        case 's':
                                        if (random == 2){
                                            cout << "You win this round!" <<endl;
                                            winCount++;
                                            break;
                                        }
                                        else if (random == 1){
                                            cout << "You lose this round." <<endl;
                                            loseCount++;
                                            break;
                                        }
                                        else{
                                            cout << "Draw. Go again" <<endl;
                                            break;
                                        }
                                        default:
                                        if (option != 'r' and option != 'p' and option != 's')  {
                                            cout << "Invalid input." <<endl;
                                        }
                                        break;
                                    }
                                }
                                if (winCount == 2){
                                    cout << "Congratulations! You defeated the alien and won $200" <<endl;
                                    int money = player1Player.getMoney();
                                    money = money + 200;
                                    player1Player.setMoney(money);
                                    }
                                if(loseCount == 2){
                                    cout << "You failed to deafeat the alien! You don't get any money."<<endl;
                                }
                            }
                                int planNum = player1PG.getPlanetNum();
                                npcFound = true; 
                                int alienResponse;
                                bool habitable = player1M.isHabitable();
                                unsigned seed = chrono::system_clock::now().time_since_epoch().count(); 
                                minstd_rand0 generator (seed);
                                int random = generator();
                                random = random % 100;
                                if (private_hasCIA == 0){
                                    if (random >= 30){
                                        if (habitable == true){
                                            cout << "Hello human! I have looked around this planet and think this would make a great home for you."<<endl;
                                            alienResponse = 1;
                                            setAlienRes(1, planNum);
                                        
                                        }
                                        else if (habitable == false){
                                            cout << "Hello human! I have looked around this planet and think this would be a terrible choice for a home. Your fragile species could not handle these conditions, I would suggest finding someplace else." <<endl;
                                            alienResponse = 2;
                                            setAlienRes(2, planNum);

                                        }   
                                    }
                                    if (random < 30){
                                        if (habitable == true){
                                            cout << "Hello human! I have looked around this planet and think this would be a terrible choice for a home. Your fragile species could not handle these conditions, I would suggest finding someplace else." <<endl;
                                            bool fake = false;
                                            setAlienRes(2, planNum);
                                            alienResponse = 2;
                                        }
                                        else{
                                            cout << "Hello human! I have looked around this planet and think this would make a great home for you." <<endl;
                                            bool fake = true;
                                            setAlienRes(1, planNum);

                                        }
                                    }
                                else if (private_hasCIA == 1){
                                    if (random >= 20){
                                        if (habitable == true){
                                            cout << "Hello human! I have looked around this planet and think this would make a great home for you."<<endl;
                                            alienResponse = 1;
                                            setAlienRes(1, planNum);
                                        
                                        }
                                        else if (habitable == false){
                                            cout << "Hello human! I have looked around this planet and think this would be a terrible choice for a home. Your fragile species could not handle these conditions, I would suggest finding someplace else." <<endl;
                                            alienResponse = 2;
                                            setAlienRes(2, planNum);

                                        }   
                                    }
                                    if (random < 20){
                                        if (habitable == true){
                                            cout << "Hello human! I have looked around this planet and think this would be a terrible choice for a home. Your fragile species could not handle these conditions, I would suggest finding someplace else." <<endl;
                                            bool fake = false;
                                            setAlienRes(2, planNum);
                                            alienResponse = 2;
                                        }
                                        else{
                                            cout << "Hello human! I have looked around this planet and think this would make a great home for you." <<endl;
                                            bool fake = true;
                                            setAlienRes(1, planNum);

                                        }
                                    }
                                }
                                // string line;
                                // string arr[6];
                                // int lineNum;
                                // vector<string> responsesH;
                                // vector<string> responsesN;
                                // ifstream fin("alien.txt");
                                // while(getline(fin,line)){
                                //     split(line,',',arr,50);
                                //     if(alienResponse == 1){
                                //         if (arr[0] == "h"){
                                //                 for (int i = 0; i < 3; i++){
                                //                 responsesH[lineNum] = responsesH[lineNum] + " " + arr[i];
                                //                 }
                                //             lineNum++;
                                //         }
                                //     }
                                //     else if (alienResponse == 2){
                                //         if (arr[0] == "n"){
                                //                 for (int i = 0; i < 3; i++){
                                //                 responsesN[lineNum] = responsesN[lineNum] + " " + arr[i];
                                //                 }
                                //             lineNum++;
                                //         }
                                //     }
                                // }
                                // int alienChoice;
                                // if (alienResponse == 1){
                                //     for (int i = 1; i < 5; i++){
                                //         cout << "How would you like to respond"<<endl; 
                                //         cout << i << "." << responsesH[i] <<endl;
                                //     }
                                //     cin >> alienChoice;
                                //     cout << responsesH[alienChoice];
                                //     break;
                                // }
                                // else if (alienResponse == 2){
                                //     for (int i = 1; i < 5; i++){
                                //         cout << "How would you like to respond"<<endl; 
                                //         cout << i << "." << responsesN[i] <<endl;
                                //     }
                                //     cin >> alienChoice;
                                //     cout << responsesN[alienChoice];
                                //     break;
                                //}
                                break;
                                
                                //sorry we spent hours trying to figure this out we cannot  
                            }
                        }
                        else if (player1Store.getTranslator() == false){ // checks if you have a translator 
                            cout << "You do not have a translator and cannot communicate with this alien. This alien may have useful information for you or money to offer, you can purchase a translator from the store if you would like to talk to them." <<endl;
                            break;
                        }
                        cout << "Enter a move." <<endl;
                    }
                    else if(player1M.isMisfortuneLocaton() == true){ // if user has a translator then they can talk to alien
                        player1M.revealMisfortune(player1M.getPlayerRowPosition(), player1M.getPlayerColPosition());
                        unsigned seed = chrono::system_clock::now().time_since_epoch().count();  // random number generator 
                        minstd_rand0 generator (seed);
                        int random = generator(); 
                        if (random > 100){
                            random = random % 100;
                        }
                        if (random == 0){
                            random++;
                        }
                        if (random <= 50){
                            setFightChoice();
                        }
                        else if ((random > 50) and (random <= 65)){ //chance of misfortune
                            cout << "Oh no! A weather event hurts you, and you lose 10% 0f your health and some suit health."<<endl;       
                            int health = player1Player.getHealth() / 10;
                            player1Player.setHealth(health);
                            if (player1Player.getHealth() <= 0){
                                setGameEndType(1);
                                phase3();
                            }
                            int damagePercent = (50 - 10 * player1Player.getSuitLvl());
                            int newHealth = player1Player.getSpaceSuitHealth() * (damagePercent / 100);
                            player1Player.setSpaceSuitHealth(newHealth);
                            if (player1Player.getSpaceSuitHealth() <= 0){
                                setGameEndType(1);
                                phase3();
                            }
                        }
                        else if ((random > 65) and (random <= 80)){
                            cout << "Oh no! You fell into a crater while messing around; lose 50% of your health and some suit health."<<endl;
                            int health = player1Player.getHealth() / 2;
                            player1Player.setHealth(health);
                            if (player1Player.getHealth() <= 0){
                                setGameEndType(1);
                                phase3();
                            }
                            int damagePercent = (50 - 10 * player1Player.getSuitLvl());
                            int newHealth = player1Player.getSpaceSuitHealth() * (damagePercent / 100);
                            player1Player.setSpaceSuitHealth(newHealth);
                            if (player1Player.getSpaceSuitHealth() <= 0){
                                setGameEndType(1);
                                phase3();
                            }
                        }
                        else{
                            cout << "You are overcome with space sickness; lose 30% of your health." <<endl;
                            int health = player1Player.getHealth() / 3;
                            player1Player.setHealth(health);
                            if (player1Player.getHealth() <= 0){
                                setGameEndType(1);
                                phase3();
                            }
                        }
                        if (player1Player.getHealth() <= 0){
                            return;
                        }
                    }
                }
            }
            int add = player1Player.getMoney(); //add $50 per move
            add = add + 50;
            player1Player.setMoney(add);
            if (key == 'm'){
                break;
                }
            }
            break;
            
            case 2: // displays stats 
            {
            cout << "Health:" << endl;
            for (int i = 0; i <= currHealth / 5 ; i++) // displays health bar 
            {
                cout << "-";
            }
            cout << "   " << currHealth << "%" << endl;
            
            cout << "Space Suit Health:" << endl; // health bar
            for (int x= 0; x <= spaceSuitHealth / 5; x++)
            {
                cout << "-";
            }
            cout << "   " << spaceSuitHealth << "%" << endl;
            
            cout << "Fuel tank:" << endl;
            cout <<"You have "<< currFuel << " gallons of fuel left " << endl;
            
            cout << "Planets explored:" << " " << planetNum << endl;
            
            cout << "Planets accurately reported habitable: " << getnumPlanetsAcc() <<endl;
            
            cout << "Planets inaccurately reported habitable: " << getnumPlanetsWrong() <<endl;

            cout << "Humans saved (in millions): " << getPopSaved() <<endl;
            
            cout << "Humans perished because of your recklessness (in millions): " << getPopKilled() <<endl;

            cout << "- Money: $" << player1Player.getMoney() <<endl;
            int temp[3];
            temp[0] = player1Store.getSaber();
            temp[1] = player1Store.getBlaster();
            temp[2] = player1Store.getBeam();
            int weaponCount = 0;
            for (int i = 0; i < 3; i++){
                weaponCount = weaponCount + temp[i];
            }
            cout << "- WEAPONS - " << weaponCount <<endl; // displays number of weapons 
            cout << " 1. Light Saber: " << temp[0] <<endl;
            cout << " 2. Blaster: " << temp[1] <<endl;
            cout << " 3. Beam Gun: " << temp[2] <<endl;
            int transCheck = 0;
            if (player1Store.getTranslator() == true){
                transCheck = 1;
            }
            cout << "- TRANSLATOR - " << transCheck <<endl;
            cout << "- SPACE SUIT GRADE #" << player1Player.getSuitLvl() <<endl;
            cout << "- MEDICAL KITS - " << player1Store.getMedKits() <<endl;
            cout << "- FUEL - " << player1Player.getFuelCount() << "Gallons" <<endl;
            }
            break;
            
            case 3:{ // displays current planets logbook information 
            string name = getName();
    string planetName = player1PG.getPlanetName(); // getters to get all information about the planet
    int planetSize = player1PG.getPlanetSize();
    player1PG.setPopSize(planetSize);
    int populationSize = player1PG.getPopSize();
    string traits = getSiteTrait();
    private_index = player1PG.getPlanetNum();
    int alienResponse = getAlienRes();
    string alienDecision;
    if(alienResponse == 1){
        alienDecision = "habitable";
    }
    else if(alienResponse == 2){
        alienDecision = "inhabitable";
    }
    else{
        alienDecision = "none";
    } // displays planet information 
    cout << name << "'s Log Book: \nPlanet: " << planetName <<endl;
    cout << "Planet size (in diameter of 1000 km): " << planetSize << endl;
    cout << "Planet's carrying capacity (in millions): " << populationSize <<endl;
    cout << "Planet's traits: " << traits <<endl;
    cout << "Friendly alien assessment: " << alienDecision << endl;
    cout << "Page Number: " << getPageNum() << endl;
    cout << "             " << endl;
            }
            break;

            case 4:
            {
            storeMenu();
            }
            break;
            
            case 5:
            {
            reportPlanet();
            }
            break;

            case 6: // to enter a wormhole
            {
            cout << "Are you sure you want to enter this wormhole? You will not be able to return and use fuel." <<endl;
            char wormChoice = 'n';
            cout << "Enter wormhole? [y/n]" <<endl;
            cin >> wormChoice;
            if (wormChoice == 'y'){
                if (npcFound == false){
                    setAlienRes(0,planetNum);
                }
                logBook(); // calls logbook function to write into logbook 
                newPlanet(); // creates too planet after going through wormhole 
            }
            else{
                phase2(); // recalls phase2 function 
                }
            }
            break;

            default:
            {
            if (input != 7){
                cout << "Please enter a valid input." <<endl;
                }
            }
            break;
        }
    }while(input != 7);
         giveUp();
        setGameEndType(2); // if user gives up 
}

/*
Function: reports planet to see if its habitable or not
checks alien response and gets planet information using getters and setters 
if chosen to report function calculates how many people saved/died and how many more needed to be saved. 

*/ 


void Game::reportPlanet(){
    cout << "Are you sure you want to report back to mission control that this planet is habitable? As a reminder, here is your log book:"<<endl;
    string name = getName(); //gets planet info
    string planetName1 = player1PG.getPlanetName();
    float planetSize = player1PG.getPlanetSize();
    player1PG.setPopSize(planetSize);
    int populationSize = player1PG.getPopSize();
    string traits = getSiteTrait();
    private_index = player1PG.getPlanetNum();
    int alienResponse = getAlienRes();
    string alienDecision;
    bool isHabitable = player1M.isHabitable();
    setPopChange(populationSize, isHabitable);
    if(alienResponse == 1){ //checks alien response
        alienDecision = "habitable";
    }
    else if(alienResponse == 2){
        alienDecision = "inhabitable";
    }
    else{
        alienDecision = "none";
    }
    cout << name << "'s Log Book: \nPlanet " << planetName1 <<endl; //prints all logbook info, just not from logbook file as it is much easier to do this (at least with our logbook implementation)
    cout << "Planet size (in diameter of 1000 km): " << planetSize << endl;
    cout << "Planet's carrying capacity (in millions): " << populationSize <<endl;
    cout << "Planet's traits: " << traits <<endl;
    cout << "Friendly alien assessment: " << alienDecision << endl;
    cout << endl;
    cout << "Reporting this planet is irreversible. If the planet is in fact habitable, you will save " << populationSize << " million people! If it’s not, the people sent to this planet will die."<<endl;
    cout << endl;
    cout << "Ready to report? [y/n]"<<endl;
    char input;
    cin >> input;
    if (input == 'y'){ 
        if (player1M.isHabitable() == true){
            string planetName = player1PG.getPlanetName(); 
            cout << "Congratulations! You have saved ";
            cout << player1PG.getPopSize();
            cout << " million people!" <<endl;
            cout << "Planet ";
            cout << planetName;
            cout << "This planet is their new home. Press Enter to continue!"<<endl;
            numPlanetsAcc();
        }
        else if (player1M.isHabitable() == false){
            cout << "Your choice has led to tragedy. " << player1PG.getPopSize() << " million people died!" <<endl;
            numPlanetsWrong();
        }
    }
    else{
        phase2(); 
    }
    
    cout << "You will be going to a new planet now... Press enter to continue"<<endl;
    int popGone = getPopKilled() + getPopSaved(); //checks if total earth population has been saved
    if (popGone >= 8000){
        setGameEndType(3);
        phase3();
    }
    cin.ignore(); // click enter to continue 
    cin.get();
    newPlanet();
}

void Game::numPlanetsAcc(){
    private_numPlanetsAcc++;
}

void Game::numPlanetsWrong(){
    private_numPlanetsWrong++;
}

int Game::getnumPlanetsAcc(){
    return private_numPlanetsAcc;
}

int Game::getnumPlanetsWrong(){
    return private_numPlanetsWrong;
}

void Game::setAlienRes(int alienRes, int planetNum){
    private_AlienRes = alienRes;
    int private_index = planetNum;
    private_alienResponses[planetNum] = private_AlienRes;
}

int Game::getAlienRes(){
    return private_alienResponses[private_index];
}


// void Game::setAlienRes(int alienRes){
//     private_AlienRes = alienRes;
// }

// int Game::getAlienRes(){
//     return private_AlienRes;
// }



/*
1. Open ifstream to questions file
2. Generate random number less that 86
3. Count line number in while loop, print question that is selected
4. split question so each elemenet is on different line
5. answer is always a
6. If wrong, lose one health, if right, give trait
7. Triats can repeat as there are a lot of sites
*/
void Game::question(){
    string line;
    int lineNum = 0;
    ifstream fin("questions.txt");
    while (getline(fin,line)){
        unsigned seed = chrono::system_clock::now().time_since_epoch().count(); 
        minstd_rand0 generator (seed);
        int random = generator();
        if (random > 86){
            random = random % 100;
            if (random > 86){
                random = random / 2;
            }
        }
        if (lineNum == random){
            char input;
            string arr[2];
            split(line,';',arr,1000);
            cout << arr[0] <<endl;
            string answers[4];
            split(arr[1], ',',answers,100); 
            cout << "a. " << answers[0] << "\nb. " << answers[1] << "\nc. " << answers[2] << "\nd. " << answers[3] <<endl;
            cin >> input;
            while(input != 'a'){
                cout << "Incorrect... you lose 1 hp due to stress :(" <<endl;
                player1Player.setHealth(1);
                if (player1Player.getHealth() <= 0){
                    setGameEndType(1); 
                    phase3();
                }
                cout << "Your health is now: " << player1Player.getHealth() <<endl;
                cout << "Retry the question"<<endl;
                cout << "a. " << answers[0] << "\n b. " << answers[1] << "\n c. " << answers[2] << "\n d. " << answers[3] <<endl;
                cin >> input;
            }
            if(input == 'a'){
                int type = player1M.getSiteTrait();
                setSingleTrait(type);
                cout << "Correct answers! \n" << "Planet trait discovered: " << getSingleTrait() << ". Added to log book." <<endl;
                phase2();
            }
        }
        lineNum++;
    }
}

void Game::setTraitsFound(int index){
    private_traitsFound[index] = 1; //make index 1 - 6 based on the github DO NOT PUT 0 
}


int Game::getTraitsFound(int index){
    // for (int i = 0; i < 7; i++){
    //     if (private_traitsFound[i] == 1){
    //         setSiteTrait(i);
    //     }
    // }
    return private_traitsFound[index];
}

//battle functions 

Battle::Battle(){
    private_alienName = "";
    private_fight = 0;
    private_weaponChoice = 0;
    private_weapon = 0;
}

Battle::Battle(string alienName, int fightChoice, int weaponChoice, int weapon){
    private_alienName = alienName;
    private_fight = fightChoice;
    private_weapon = weaponChoice;
    private_weapon = weapon;
}
/*
Function: sets alien names 
uses random number generator to create a name for alien

*/
void Battle::setAlienName(string fileName){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count(); //uses random number generator to create a name for alien
    minstd_rand0 generator (seed);
    int randomLine = generator();
    int lineNum = 0;
    string alienName;
    if (randomLine > 20){
        randomLine = randomLine % 100;
        if (randomLine > 20){
            randomLine = randomLine / 5;
        }
    }
    string line;
    ifstream fin(fileName);
    while(getline(fin, line)){
        lineNum++;
        if (lineNum == randomLine){
            alienName = line;
            private_alienName = alienName;
        }
    }
}

string Battle::getAlienName(){
    return private_alienName;
}

int Game::checkFighter(int fighter){
    if(fighter == 1){
        private_hasFighter = 1;
    }
    return private_hasFighter;
}
/*
Function: lets user decide what to do if they run into an alien 
if user attacks, calls set function to pick weapon to fight alien 
if forfeit user loses 10000 and if they do not have enough they lose a weapon 
*/
void Game::setFightChoice(){
    int fightChoice;
    player1Battle.setAlienName("alienNames.txt");
    string alienName = player1Battle.getAlienName();
    cout << "You just ran into " << alienName <<" ! Think you can beat this dangerous alien for helping save humanity?"<<endl;
    cout << "Do you want to attack(1) or do you want to forfeit(2)" << endl;
    cin >> fightChoice;
    while ((fightChoice != 1) and (fightChoice != 2)){ // invalid inputs
        cout << "Invalid input."<<endl;
        cin >> fightChoice;
    }
    private_fightChoice = fightChoice; 
    int money = player1Player.getMoney();
    int health = player1Player.getHealth();
    int suitHealth= player1Player.getSpaceSuitHealth();
    int currSuitlvl = player1Player.getSuitLvl();
    int temp [3];
    temp[0] = player1Store.getSaber();
    temp[1] = player1Store.getBlaster();
    temp[2] = player1Store.getBeam();
    int total = temp[0] + temp[1] + temp[2]; // total weapons 
    if (fightChoice == 1) // if attacks
    {
        setWeaponChoice(temp,private_hasFighter);
    }
    else if (fightChoice == 2) // if forfeit
    {
        if (total == 0){ // no weapons 
            if (money >= 10000) // lose 10000
            {
                money = money - 10000;
                player1Player.setMoney(money);
                int lostHealth = health * .3;
                health = health - lostHealth;
                player1Player.setHealth(health);
                if (player1Player.getHealth() <= 0){
                    setGameEndType(1); // sets game end type
                    phase3();
                }
                int lostSuithealth = (100 - (20 * currSuitlvl));
                suitHealth = suitHealth - lostSuithealth;
                player1Player.setSpaceSuitHealth(suitHealth);
                if (player1Player.getSpaceSuitHealth() <= 0){ // no health game ends
                                setGameEndType(1);
                                phase3();
                            }
                cout << "Really?! You chose to forfeit the battle? This is disappointing! Since you do not have a weapon, you just lost a huge chunk of money from your account. Hopefully, you git gud before you encounter the next alien." << endl;
            }
            else 
            {
                money = 0;
                player1Player.setMoney(money);
                int lostHealth = (health * .3);
                health = health - lostHealth;
                player1Player.setHealth(health);
                if (player1Player.getHealth() <= 0){
                    setGameEndType(1);
                    phase3();
                }
                int lostSuithealth = (100 - (20 * currSuitlvl));
                suitHealth = suitHealth - lostSuithealth;
                player1Player.setSpaceSuitHealth(suitHealth);
                if (player1Player.getSpaceSuitHealth() <= 0){
                                setGameEndType(1);
                                phase3();
                            }
            }
        }
        else { // removes random weapon from inventory 
             unsigned seed = chrono::system_clock::now().time_since_epoch().count(); 
                minstd_rand0 generator (seed); // random number generator 
                int ran = generator();
                if (ran > 3){
                    ran = ran % 10;
                    if (ran > 3){
                       ran = ran / 3;
                    }
                }
            player1Store.removeWeapon(temp,ran); // calls remove weapon 
            cout << "Really?! You chose to forfeit the battle? This is disappointing! You lost a weapon due to this decision. Hopefully, you git gud before you encounter the next alien." << endl;
            int lostHealth = health * .3;
            health = health - lostHealth;
            player1Player.setHealth(health);
            if (player1Player.getHealth() <= 0){
                setGameEndType(1);
                phase3();
                }
            int lostSuithealth = (100 - (20 * currSuitlvl)); // losing space suit health 
            suitHealth = suitHealth - lostSuithealth;
            player1Player.setSpaceSuitHealth(suitHealth);
            if (player1Player.getSpaceSuitHealth() <= 0){
                                setGameEndType(1);
                                phase3();
                            }
        } 
    }
    else
    {
        cout<< "Invalid Input" << endl;
        cin >> fightChoice;
    }
    
}
//weapons[random] = weapon[random] - 1; making sure the player has a weapon in the slot and random => 3 and 0.
int Game::getFightChoice(){
    return private_fightChoice;
}

// same as fight function 
void Game::setWeaponChoice(int weaponChoice[], int fighter){
    int money = player1Player.getMoney();
    bool empty = true;
    for (int i = 0; i < 3; i++){
        if (weaponChoice[i] != 0){
            empty = false;
        }
    }
    if ((money < 1000) and (empty == true)){
        cout << "You neither have a weapon nor enough money to buy a weapon. Consequently, the alien attacked and defeated you could not retreat :(" <<endl;
        return;
    }
    if ((money > 1000) and (empty == true)){
        cout << "You do not have a weapon to fight! Lets visit the resource center and buy a weapon!" <<endl;
        weaponMenuFight(player1Player.getMoney());
    }
    if (empty == false){
        int temp[3];
        temp[0] = player1Store.getSaber();
        temp[1] = player1Store.getBlaster();
        temp[2] = player1Store.getBeam();
        int total = temp[0] + temp[1] + temp[2];
        int weapon;
        vector<int> crew;
        cout << "Let’s attack! Choose a weapon from your arsenal quickly and attack before the enemy advances!" <<endl;
        cin >> weapon;
        while ((weapon > 3) or (weapon < 1)){
            cout << "Invalid input."<<endl;
            cin >> weapon;
        }
        while ((weapon == 1) and (temp[0] == 0)){
            cout << "Invalid input." <<endl;
            cin >> weapon;
        }
        while ((weapon == 2) and (temp[1] == 0)){
            cout << "Invalid input." <<endl;
            cin >> weapon;
        }
        while ((weapon == 3) and (temp[2] == 0)){
            cout << "Invalid input."<<endl;
            cin >> weapon;
        }
        if (weapon < 4){
            unsigned seed = chrono::system_clock::now().time_since_epoch().count(); 
            minstd_rand0 generator (seed);
            int r1 = generator();
            int r2 = generator();
            int result = (r1 * weapon) * (1 + fighter) - (r2 * player1PG.getPlanetNum());
            if ((result > 0) and (total < 2)){
                unsigned seed = chrono::system_clock::now().time_since_epoch().count(); 
                minstd_rand0 generator (seed);
                int ran = generator();
                bool give = false;
                if (ran > 3){
                    ran = ran % 10;
                    if (ran > 3){
                        ran = ran / 3;
                    }
                }
                player1Store.setWeapons(temp,1,ran);
                cout << "You defeated " << player1Battle.getAlienName() << " , good job. You won a random weapon! You also lost 10% spacesuit health" << endl;
                int health = player1Player.getSpaceSuitHealth();
                if (private_hasDoctor == 1){
                     int newHealth = health - (health * .1) + 5;
                }
                int newHealth = health - (health * .1);
                player1Player.setSpaceSuitHealth(newHealth);
                if (player1Player.getSpaceSuitHealth() <= 0){
                                setGameEndType(1);
                                phase3();
                            }
            }
            else if ((result > 0) and (total >= 2)){
                cout << "You defeated " << player1Battle.getAlienName() << " , good job!  You saw the enemy's weapon lying down but you cannot carry with you as you already have 2 weapons. Unfortunately, you lost 10% of space suit health while fighting."<<endl;
                int health = player1Player.getSpaceSuitHealth();
                int newHealth = 0;
                if (private_hasDoctor == 1){
                    newHealth = health - (health * .1) + 5;
                }
                else{
                    newHealth = health - (health * .1);
                }
                player1Player.setSpaceSuitHealth(newHealth); 
                if (player1Player.getSpaceSuitHealth() <= 0){
                                setGameEndType(1);
                                phase3();
                            }
            }
            else if (result < 0){
            int health = player1Player.getHealth();
            int suitHealth= player1Player.getSpaceSuitHealth();
            int currSuitlvl = player1Player.getSuitLvl();
            int lostHealth = 0;
            if (private_hasDoctor == 1){
                lostHealth = health * .3 + 5;
            }
            else{
                lostHealth = health * .3;
            }
            health = health - lostHealth;
            player1Player.setHealth(health);
            if (player1Player.getHealth() <= 0){
                setGameEndType(1);
                phase3();
                }
            int lostSuithealth = (100 - (20 * currSuitlvl));
            suitHealth = suitHealth - lostSuithealth;
            player1Player.setSpaceSuitHealth(suitHealth);
            if (player1Player.getSpaceSuitHealth() <= 0){
                                setGameEndType(1);
                                phase3();
                            }
            player1Store.removeWeapon(temp,weapon);
            cout << "Tough Luck! You lost the battle!" << player1Battle.getAlienName() << "seems to be hard for you! Tough times. Unfortunately, you experience the following due to this loss:"<<endl;
            cout << "1. Your health was decreased by 30% \n 2. Your suit health decreased by 40%. \n 3. You lost Light Saber, the weapon you used for attacking the alien." <<endl;
            }
        }
    }
}


/*
Function: updates saved and killed people 
if planet is habitable then updates saved people
if planet is not habitable updates killed people 
*/
void Game::setPopChange(int pop, bool habitable){
    if (habitable == true){ // if true 
        int popSaved = pop;
        private_TotalPopSaved = private_TotalPopSaved + popSaved; // updates private functions 
    }
    else if (habitable == false){ // if false
        int popKilled = pop;
        private_TotalPopKilled = private_TotalPopKilled + popKilled;
    }
}

int Game::getPopKilled(){
    return private_TotalPopKilled;
}

int Game::getPopSaved(){
    return private_TotalPopSaved;
}




void Game::newPlanet(){
    planetGeneration(); //resets planet traits 
    int planetNum = player1PG.getPlanetNum();
    player1PG.setPlanetNum(planetNum);
    int newPlanetNum = player1PG.getPlanetNum();
    player1PG.setFuelRequired(newPlanetNum);
    int fuelReq = player1PG.getFuelRequired();
    cout << "Fuel you have: " << player1Player.getFuelCount()<<endl;
    if (fuelReq <= player1Player.getFuelCount()){
        cout << "You are entering the wormhole in 3...2...1..." <<endl;
        int fuelCount = player1Player.getFuelCount();
        int fuelChange = fuelCount - fuelReq;
        player1Player.setFuelCount(fuelChange);
        for (int i = 0; i < 7; i++){
            private_traitsFound[i] = 0;
        }

        player1PG.setPlanetName("fourWords.txt"); // uses extra txt file to get four letter words
        player1PG.setPlanetSize();
        player1M.resetMap(); // resets map for next planet
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();  // random number generator 
        minstd_rand0 generator (seed);
        int row = generator();
        int col = generator();
        if (row > 11){
            row = row % 100;
            if ((row > 11) and (row != 0)){
                row = row / 10;
            }
            else if (row == 0){
                row++;
            }
        }
        if (col > 11){
            col = col % 100;
            if ((col > 11) and (col != 0)){
                col = col / 10;
            }
            else if (col == 0){
                col++;
            }
        }
        player1M.spawnNPC(row,col); // calls in map function to spawn npcs randomly throughout map 
        int misfortuneNum = generator();
        if (misfortuneNum > 8){
            misfortuneNum = misfortuneNum % 10;
            if (misfortuneNum < 4){
                misfortuneNum = misfortuneNum + 4;
            }
            else if (misfortuneNum > 8){
                misfortuneNum = misfortuneNum - 4;
            }
        }
        int i = 0;
        while(i < 1){//misfortuneNum - 2){
            //cout <<"loop"<<endl; 
            int row = generator();
            int col = generator();
            int type = generator();
            if (row > 11){
                row = row % 10;
                if ((row > 11) and (row != 0)){
                    row = row / 10;
                }
                else if (row == 0){
                    row++;
                }
            }
            if (col > 11){
                col = col % 10;
                if ((col > 11) and (col != 0)){
                    col = col / 10;
                }
                else if (col == 0){
                    col++;
                }
            }
            if (type > 4){
                type = type % 10;
                if (type > 4){
                    type = type / 2;

                }
            }
            if (type == 0){
                type++;
            }
            cout << type <<endl;
            bool spawnCheck = player1M.spawnMisfortune(5,3,type); // spawns misfortunes around map 
            cout << spawnCheck <<endl;
            if(spawnCheck == true){
                i++; // keep track of how many to add 
            }
        }
        int l = 0;
        while(l < 2){
            //cout << "loop2"<<endl;
            int row = generator();
            int col = generator();
            if (row > 12){
                row = row % 100;
                if ((row > 12) and (row != 0)){
                    row = row / 10;
                }
                else if (row == 0){
                    row++;
                }
            }
            if (col > 12){
                col = col % 100;
                if ((col > 12) and (col != 0)){
                    col = col / 10;
                }
                else if (col == 0){
                    col++;
                }
            }
            bool check = player1M.spawnMisfortune(row,col,1);
            if(check == true){
                l++;
            }
        }
        for (int i = 0; i < 7; i++){
            int cords[3];
            cords[0] = generator();
            cords[1] = generator();
            cords[2] = generator();
            for (int k = 0; k < 2; k++){
                if((cords[k] > 12)){
                    cords[k] = cords[k] % 100;
                    if ((cords[k] > 12) and (cords[k] != 0)){
                        cords[k] = cords[k] / 10;
                    }
                    else if (cords[k] == 0){
                        cords[k]++;
                    }
                }
            }
            if (cords[2] > 4){
                cords[2] = cords[2] % 10;
                if ((cords[2] > 4) and (cords[2] != 0)){
                    cords[2] = cords[2] / 3;
                }
                else if(cords[2] == 0){
                    cords[2]++;
                }
            }
            player1M.spawnSite(cords[0], cords[1],cords[2]); // spawns sites around map 
        }
        phase2();
    }
    else{
        int fuelNeeded = fuelReq - player1Player.getFuelCount();
        char fuelChoice;
        cout << "You need " << fuelNeeded << " more gallons of fuel, which costs $" << fuelNeeded / 10 << " Go ahead and make purchase? [y/n]"<<endl;
        cin >> fuelChoice;
        if (fuelChoice == 'y'){
            int money = player1Player.getMoney();
            int needMoney = fuelNeeded / 10;
            if (money >= (needMoney)){
                money = money - (needMoney);
                player1Player.setMoney(money);
                int currFuel = player1Player.getFuelCount();
                currFuel = currFuel + fuelNeeded;
                player1Player.setFuelCount(currFuel);
                fuelNeeded = 0;
                planetNum = planetNum - 1;
                player1PG.setPlanetNum(planetNum);
            }
            else{ // not enough money to move
                cout << "You do not have enough money... Redirecting to current planet."<<endl;
                phase2();
            }
        }
        else if (fuelChoice == 'n'){ // fuel payment declined stay on planet
            cout << "You are not moving to the next planet as you have declined the payment. Redirecting you to the current planet…"<<endl;
            phase2();
        }
    }
}

void Game::setGameEndType(int gameEndType){
    private_gameEndType = gameEndType;
}

int Game::getGameEndType(){
    return private_gameEndType;
}

void Game::giveUp(){
    char giveUpChoice;
    cout << "Are you sure you want to give up? [y/n]"<<endl;
    cin >> giveUpChoice;
    if (giveUpChoice == 'y'){
        setGameEndType(2);
        phase3();
    }
    else if (giveUpChoice == 'n'){
        cout << "Redirecting to current planet..."<<endl;
        phase2();
    }
    else{
        cout << "Invalid input."<<endl;
        giveUp();
    }
}

/*
1. Check game end type
2. Switch game end type, display appropriate message
3. Display logbook (not sorted )
4. Print score
5. Show other stats
6. Say goodbye and end program
*/
void Game::phase3(){
    int gameEndType = getGameEndType();
    int score = 0;
    ifstream fin;
    string line;
    switch(gameEndType){
        case 1:
        cout << "You have died due to health loss. Had you planned better with more sophisticated materials, you may have been able to prevent this. You can no longer explore more of space."<<endl;
        fin.open("results.txt");
        while(getline(fin,line)){
            cout << line << endl;
        }
        fin.close();
        score = (getPopSaved() - getPopKilled()) / 8000 * (getnumPlanetsAcc() + (((player1PG.getPlanetNum() - getnumPlanetsAcc()) - getnumPlanetsWrong()) / player1PG.getPlanetNum())) * 100;
        cout << "Here's a summary of how you did: "<<endl;
        cout << "Planets explored: " << player1PG.getPlanetNum();
        cout << "Planets accurately reported habitable: " << getnumPlanetsAcc() <<endl;
        cout << "Planets inaccurately reported: " << getnumPlanetsWrong() << endl;
        cout << "Humans saved (in millions): " << getPopSaved() <<endl;
        cout << "Humans perished (in milions): " << getPopKilled() << endl;
        cout << "TOTAL SCORE: " << score << endl;
        break;

        case 2:
        cout << "It is disappointing to hear that you have quit, humanity was depending on you."<<endl;
        fin.open("results.txt");
        while(getline(fin,line)){
            cout << line << endl;
        }
        fin.close();
        score = (getPopSaved() - getPopKilled()) / 8000 * (getnumPlanetsAcc() + (((player1PG.getPlanetNum() - getnumPlanetsAcc()) - getnumPlanetsWrong()) / player1PG.getPlanetNum())) * 100;
        cout << "Here's a summary of how you did: "<<endl;
        cout << "Planets explored: " << player1PG.getPlanetNum() <<endl;
        cout << "Planets accurately reported habitable: " << getnumPlanetsAcc() <<endl;
        cout << "Planets inaccurately reported: " << getnumPlanetsWrong() << endl;
        cout << "Humans saved (in millions): " << getPopSaved() <<endl;
        cout << "Humans perished (in milions): " << getPopKilled() << endl; 
        cout << "TOTAL SCORE: " << score << endl;
        break;
        
        case 3:
        cout << "All of humanity has left Earth! Your mission is over."<<endl;
        fin.open("results.txt");
        while(getline(fin,line)){
            cout << line << endl;
        }
        fin.close();
        score = (getPopSaved() - getPopKilled()) / 8000 * (getnumPlanetsAcc() + (((player1PG.getPlanetNum() - getnumPlanetsAcc()) - getnumPlanetsWrong()) / player1PG.getPlanetNum())) * 100;
        cout << "Here's a summary of how you did: "<<endl;
        cout << "Planets explored: " << player1PG.getPlanetNum();
        cout << "Planets accurately reported habitable: " << getnumPlanetsAcc() <<endl;
        cout << "Planets inaccurately reported: " << getnumPlanetsWrong() << endl;
        cout << "Humans saved (in millions): " << getPopSaved() <<endl;
        cout << "Humans perished (in milions): " << getPopKilled() << endl;
        cout << "TOTAL SCORE: " << score << endl;
        break;

        default:
        cout << "Something is wrong with the gameEndType function :D"<<endl;
        break;
    }
    if (score != 100){
        cout << "Thank you for playing! Try again to achieve a higher score!"<<endl;
    }
    else if(score == 100){
        cout << "Humanity is greatfull for your perfect exploration of the cosmos! See if you can do it again!"<<endl;
    }
    
    exit(0);
}

/* 
Function: puts traits into an array 
combines strings to diplay arrays 
*/
void Game::setSiteTrait(int type[]){
    string trait;
    for(int i = 0; i < 7;i++){
        type[i] = getTraitsFound(i);
        switch(type[i]){
        case 0:
        cout << "";
        break;
        case 1: // adds traits into array 
        trait = trait + "water ";
        break;
        case 2:
        trait = trait + "oxygen ";
        break;
        case 3:
        trait = trait + "fertile soil ";
        break;
        case 4:
        trait = trait + "bad atmosphere ";
        break;
        case 5:
        trait = trait + "toxic gas ";
        break;
        case 6:
        trait = trait + "extreme temperatures ";
        break;
        default:
        trait = trait + "the setSiteTrait function doesn't work :D";
        break;
        }
    private_siteTrait = trait; // sets private function 
    }
}


// same as above but sets one index of array 
void Game::setSingleTrait(int type){
    string trait;
        switch(type){
        case 0:
        cout << "";
        break;
        case 1:
        trait = trait + "water ";
        break;
        case 2:
        trait = trait + "oxygen ";
        break;
        case 3:
        trait = trait + "fertile soil ";
        break;
        case 4:
        trait = trait + "bad atmosphere ";
        break;
        case 5:
        trait = trait + "toxic gas ";
        break;
        case 6:
        trait = trait + "extreme temperatures ";
        break;
        default:
        trait = trait + "the setSiteTrait function doesn't work :D";
        break;
        }
    private_singleTrait = trait;
}

string Game::getSingleTrait(){
    return private_singleTrait;
}


string Game::getSiteTrait(){
    return private_siteTrait;
}

void Game::increasePageNum(){
    private_pageNum++;
}

int Game::getPageNum(){
    return private_pageNum;
}

int Game::doctorCheck(int doctor){ //for crewmates
    if(doctor == 1){
        private_hasDoctor = 1;
    }
    return private_hasDoctor;
}

int Game::ciaCheck(int cia){
    if(cia == 1){
        private_hasCIA = 1;
    }
    return private_hasCIA;
}


/*
Function: Writes into file information of each planet
*/
void Game::logBook(){
    increasePageNum(); // increases page number
    string name = getName(); 
    string planetName = player1PG.getPlanetName();
    int planetSize = player1PG.getPlanetSize();
    int populationSize = player1PG.getPopSize();
    string traits = getSiteTrait();
    private_index = player1PG.getPlanetNum();
    int alienResponse = getAlienRes();
    string alienDecision; // checks alien decisions about planet 
    if(alienResponse == 1){
        alienDecision = "habitable";
    }
    else if(alienResponse == 2){
        alienDecision = "inhabitable";
    }
    else{
        alienDecision = "none";
    }
    ofstream fout;
    fout.open("results.txt",ofstream::app); // uses appended fout to write into files 
    fout << name << "'s Log Book: \nPlanet: " << planetName <<endl;
    fout << "Planet size (in diameter of 1000 km): " << planetSize << endl;
    fout << "Planet's carrying capacity (in millions): " << populationSize <<endl;
    fout << "Planet's traits: " << traits <<endl;
    fout << "Friendly alien assessment: " << alienDecision << endl;
    fout << "Page Number: " << getPageNum() << endl;
    fout << "             " << endl;
    fout.close();
    
}


int main(){
    Game(); 
    Player();
    Map();
    planetGeneration();
    Battle();
    string name;
    Game player1;
    ofstream fin34321;
    fin34321.open("results.txt"); //clears previous logbooks
    cout << " " <<endl;
    fin34321.close();
    cout << "Welcome to the Interstellar Space Adventure!!"<<endl;
    player1.setName(name);
    cout << "Hello, " << player1.getName() << ", my name is Elon Musk, and I have selected you to join SpaceX in the search for a new planet."<<endl;
    cout << "Earth is rapidly becoming inhabitable, and it is up to you and TWO others to save humanity.\nYou have been given 200,000 gallons of fuel, a Level 1 Space Suit, and a Lightsaber. \nBefore we leave, you'll need to get some upgrades." <<endl;
    int crewMate1;
    int crewMate2;
    string line;
    string line2;
    int lineNum = 1;
    cout << "Pick 2 crewmates to help you on your journey (hope they are not sus)"<<endl;
    ifstream fin("crewmates.txt"); //shows crewmates and allows for selection
    if (fin.is_open()){
        while(getline(fin,line)){
            cout << lineNum << ". " << line <<endl;
            lineNum++;
        }
    }
    fin.close();
    int fighter = 0;
    player1.setCrewMates(crewMate1, crewMate2); // sets crewmates to vector 
    vector<int> temp = player1.getCrewMates();

    for (int i = 0; i < 2;i++){ //checks for specific crewmate choices to apply buffs
        if (temp[i] == 2){
            fighter = 1;
        }
    }
    int doctor = 0;
    for (int j = 0; j < 2; j++){
        if (temp[j] == 1){
            doctor = 1;
        }
    }
    int cia = 0;
    for (int k = 0; k < 2; k++){
        if (temp[k] == 4){
            cia = 1;
        }
    }
    cout << "Now lets go to the Resource Center! \nHere you can purchase materials in order to help you on your Adventure. \nYou have $100,000 to spend on materials." << endl;
    ifstream fin2("resource_center_info.txt");
    if (fin2.is_open()){ // prints resource center information on what to buy 
        while(getline(fin2,line2)){
            cout << line2 << endl;
        }
    }
    player1.storeMenu(); // calls store menu function 
    cout << "3,2,1 . . . LIFTOFF! You are now in space. Hit enter to start exploring your first planet." << endl;
    cin.ignore();
    cin.get();
    player1.newPlanet(); // calls new planet function to create new planet after lift off
    player1.phase2();// calls phase 2 function 
    player1.phase3();// calls phase 3 functions
    return 0;
}


#ifndef MAP_H
#define MAP_H

#include <iostream>

using namespace std; 

class Map
{
     private:
          static const int num_rows = 12;
          static const int num_cols = 12;
          static const int num_misfortunes = 8; // max misfortunes
          static const int num_sites = 7; // max sites

          bool habitable; // stores whether planet is habitable or not
          int playerPosition[2]; // player position (x,y)
          int npcPosition[2]; // position of NPC (x,y)
          int misfortunes[num_misfortunes][3]; // stores the misfortunes present on map, at a misfortune number there will be three values of (x,y,type)
          int sites[num_sites][3]; // stores the sites present on map, at a site number there will be three values of (x,y,type)
          char mapData[num_rows][num_cols]; // stores the character that will be shown at a given (x,y)

          bool npc_on_map; // stores whether this is an NPC on the map
          int misfortune_count; // stores number of misfortunes currently on map
          int site_count; // stores number of sites currently on map

     public :
          Map();

          void resetMap();

          // getters
          int getPlayerRowPosition();
          int getPlayerColPosition();
          int getSiteCount();
          int getMisfortuneType();
          int getMisfortuneCount();
          int getSiteTrait();
          bool isNPCLocation();
          bool isMisfortuneLocaton();
          bool isSiteLocation();
          bool isHabitable();
          bool isFreeSpace(int, int);

          // setters
          void setMisfortuneCount(int);
          void setNPC(bool);
          void setPlayerRowPosition(int);
          void setPlayerColPosition(int);

          // other
          void displayMap();
          bool executeMove(char);
          bool spawnNPC(int, int);
          bool spawnMisfortune(int, int, int);
          bool spawnSite(int, int, int);
          void revealMisfortune(int, int);

};
 
#endif
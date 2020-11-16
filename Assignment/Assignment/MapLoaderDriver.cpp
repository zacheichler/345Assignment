//  main.cpp
//  Part 2
//  Emilie Mines & Zach Eichler.

#include <iostream>
#include <list>
#include "MapLoader.hpp"
#include "Map.hpp"


using namespace std;

//reads from file and returns borders as strings for each territory
vector<string> sBorderList = makeBorderListString("europe.map");
//gets continents for each territory
vector<int> continents = getContinents("europe.map");
//takes string inputs and creates an int vector of int vectors for the borders
vector<vector<int>> iBorderList = makeBorderListInt(sBorderList);


int main(int argc, const char * argv[]) {
    //makes new map based on the number of territories
    Map gameMap((int)iBorderList.size());
    
    //for all the territories, add an edge to their bordering territories
    for(int i = 0; i < iBorderList.size(); i++){
        int numBorders = (int)iBorderList[i].size();
        
        for(int j = 0; j < numBorders; j++){
            //adds an edge for each border connected to i
            gameMap.addEdge(i,(iBorderList[i][j]-1),continents[i],4,20);
            
        }
    }
    
    //this just creates a second map (not implemented as nodes) to make it easier for traversal
    for(int i= 0; i<iBorderList.size();i++){
        int numBorders = (int)iBorderList[i].size();
        for(int j = 0; j < numBorders; j++){
            gameMap.addEdge2(i,iBorderList[i][j]-1);
        }
    }
    
    gameMap.printMap();
    
    gameMap.validate(0);
    
}

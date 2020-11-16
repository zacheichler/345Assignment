//
//  main.cpp
//  Part 1
//
//  Created by Zach Eichler on 2020-11-10.
//

#include <iostream>
#include <string>
#include "GameEngine.hpp"
//#include "Map.hpp"
//#include "MapLoader.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    int mapChoice = 0;
    string mapChoiceString = "";
  
    cout << "What Map would you like to play with?" << endl;
    cout << " " << endl;
    
    //Lists out available map options
    
    cout << "1. Europe" << endl;
    cout << "2. Google" << endl;
    cout << "3. Big Europe" << endl;
    
    //User selects a map with valid selection
    
    while(mapChoice < 1 || mapChoice > 3){
        cout << "Enter number associated with your map of choice: ";
        cin >> mapChoice;
        cout << endl;
    }
    
    //chooses map
    
    switch (mapChoice){
        case 1:
            mapChoiceString = "europe.map";
            break;
        case 2:
            mapChoiceString = "google.map";
            break;
        case 3:
            mapChoiceString = "bigeurope.map";
            break;
            
    }
    
    cout << "Playing with: " << mapChoiceString << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    
    vector<string> sBorderList = makeBorderListString(mapChoiceString);
    //gets continents for each territory
    vector<int> continents = getContinents(mapChoiceString);
    //takes string inputs and creates an int vector of int vectors for the borders
    vector<vector<int>> iBorderList = makeBorderListInt(sBorderList);
    
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

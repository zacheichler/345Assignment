//  Main.cpp
//  Part 1
//  Emilie Mines & Zach Eichler.


#include "Map.hpp"
#include <iostream>
#include <list>


using namespace std;



vector<int> continents = {1,2,3,4,2,5};
//Valid Map hard coded, file input example in part 2
vector<vector<int>> iBorderList = {{3},{3,5},{1,2,4},{3,5,6},{2,4},{4}};

//Invalid Map hard coded, file input example in part 2
//vector<vector<int>> iBorderList = {{2,3},{1,3},{1,2},{5,6},{4},{4}};


int main(int argc, const char * argv[]) {
    
    //initializes a game map
    Map gameMap((int)iBorderList.size());
    
    for(int i = 0; i < iBorderList.size(); i++){
        int numBorders = (int)iBorderList[i].size();
        //cout << "Territory(" << i + 1 << "): ";
        for(int j = 0; j < numBorders; j++){
            gameMap.addEdge(i,(iBorderList[i][j]-1),continents[i],4,20);
            //cout << iBorderList[i][j] << " -> ";
        }
        cout << endl;
        cout << " ";
        cout << endl;
    }
    
    for(int i= 0; i<iBorderList.size();i++){
        int numBorders = (int)iBorderList[i].size();
        for(int j = 0; j < numBorders; j++){
            gameMap.addEdge2(i,iBorderList[i][j]-1);
        }
    }
    
    gameMap.printMap();
    
    gameMap.validate(0);
    
}


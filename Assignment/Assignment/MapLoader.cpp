//  MapLoader.cpp
//  Part 2
//  Emilie Mines & Zach Eichler.

#include "MapLoader.hpp"
#include "Map.cpp"



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <list>

using namespace std;

/*


//Create map of int v
Map::Map(int V){
    //initializes adjacency list for each node
    adjList2 = new list <int>[V];
    this->V = V;
    this -> arr = new AdjList[V];
    //make the head of each one NULL
    for(int i = 0; i <V;i++){
        arr[i].head = NULL;
    }
}

void Map::addEdge(int src, int dest, int cont, int ownedBy, int armies){
    
    Territory *n = new Territory(dest,cont,ownedBy,armies);
    n -> next = this ->arr[src].head;
    this->arr[src].head = n;

    
}

void Map::addEdge2(int src, int dest){
    adjList2[src].push_back(dest);
}



void Map::DFS(int v, bool visited[]){
    visited[v] = true;
    cout << "visited: " << v+1 << endl;
    list<int>::iterator i;
    for(i = adjList2[v].begin();i!=adjList2[v].end();i++)
    if(!visited[*i]){
        DFS(*i,visited);
    }
}

void Map::validate(int v){
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    DFS(v,visited);
    int count = 0;
    vector<int>notConnected;
    for(int i = 0; i < V; i++){
        if(visited[i] == true){
            count++;
        }else{
            notConnected.push_back(i);
        }
        
    }
    
    cout << endl;
    
    if(count == V){
        cout << "This map IS valid!" << endl;
        cout << "" << endl;
    }else{
        cout << "This map is NOT valid!" << endl;
        cout << "" << endl;
        
        cout << "When starting from node 0, Territory(ies) ";
        for(int i = 0; i < notConnected.size(); i ++){
            cout << notConnected[i] + 1 << ", ";
        }
        cout << "are (is) not connected" << endl;
    }
    
}







void Map::printMap(){
    for(int i = 0; i < V; i++){
        Territory *root = arr[i].head;
        cout << "Territory(" << i + 1 << ") is part of continent "<< root->getContient() << ", is owned by player "<< root->getOwnedBy()<< ", has "<< root->getNumArmies()<< " armies, and has borders: " ;
        while(root!=NULL){
            cout << root->destination+1 << "->";
            root= root->next;
        }
        cout<< endl;
    }
}

Territory::Territory(int destination, int continent,int ownedBy,int numArmies){
    this->destination = destination;
    this->continent = continent;
    this->ownedBy = ownedBy;
    this->numArmies = numArmies;
    Territory *next = NULL;
}
    
int Territory::getContient(){
    return continent;
}
int Territory::getOwnedBy(){
    return ownedBy;
}
int Territory::getNumArmies(){
    return numArmies;
}

Territory Territory::getNext(){
    return *next;
}

void Territory::printStuff(){
    cout << continent << " " << ownedBy << " " << numArmies << endl;
}
 
 */
    



//Gets vector of borders as string from file

vector<string> makeBorderListString(string filename){
    vector<string>borderListString;
    string line;
    ifstream mapfile (filename);
    if (mapfile.is_open())
    {
        while ( getline (mapfile,line)){
            //when it reads "borders", start reading line and store borders in string vector
            if (line.find("[borders]") != string::npos) {
                while(getline (mapfile,line)){
                    borderListString.push_back(line);
                }
            }
        };
        mapfile.close();
    }
    else cout << "File not found";
    return borderListString;
}

//this takes in the vector of strings and converts it to a vector of int vectors by splitting the strings on " "
vector<vector<int>>makeBorderListInt(vector<string> borderList){
    vector<vector<int>> borderListInt;
    for(int j = 0; j < borderList.size(); j++){
        string s = borderList[j];
        string start ="";
        vector<int> test;
        for(int i = 0; i < s.size(); ++i){
            if(s[i]!= ' '){
                if(i == s.size()-1){
                    test.push_back(stoi(start));
                }
                start += s[i];
            }else if(s[i] == ' '){
                test.push_back(stoi(start));
                start = "";
            }
        }
        borderListInt.push_back(test);
    }
    //remove first vector from list as it's just itself
    vector<vector<int>>borderListIntTemp;
    for(int i = 0; i<borderListInt.size(); i++){
        vector<int> temp;
        for(int j = 1; j < borderListInt[i].size();j++){
            temp.push_back(borderListInt[i][j]);
        }
        borderListIntTemp.push_back(temp);
    }
    borderListInt = borderListIntTemp;
    return borderListInt;
}

//gets continents by reading the value after the second " " which corresponds to territory
vector<int> getContinents(string filename){
    
    vector<int>continents;
    string line;
    ifstream mapfile (filename);
    if (mapfile.is_open())
    {
        while ( getline (mapfile,line)){
            if (line.find("[coun") != string::npos || line.find("[terr") != string::npos) {
                while(getline (mapfile,line)){
                    
                    string s = line;
                    string theCont ="";
                    int spaceCount = 0;
                    
                    
                    for(int i = 0; i < s.size()-1;i++){
                        if(s[i] == ' '){
                            spaceCount ++;
    
                            if(spaceCount == 2){
                                i++;
                                while(s[i]!= ' '){
                                    theCont += s[i];
                                    i++;
                                }
                                continents.push_back(stoi(theCont));
                            }
                        }
                    }
                    
                    
                    
                    
                    if(line.length() == 1)
                        break;
                    
                }
            }
        };
        
        mapfile.close();
            
    }
    

    else cout << "File not found";
    
    return continents;
    
}


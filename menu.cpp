/*
 Adilbek Momunaliev U08859686

 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include "Graph.h"

int main() {
        Graph* myGraph;
        string start;
        string end;
        char loop = 'r';
        bool result;
        do{
            try{
                delete myGraph;
                myGraph = new Graph();
                cout << "Building graph, please wait few secs!" << endl;
                myGraph->build();
            }
            catch(string param){
                cout << "cannot open dictionary file!";
            }
            cout << "Please, enter two words to form word ledder! (lower case only)" << endl;
            cout << "Start word: ";
            cin >> start;
            cout << "End word: ";
            cin >> end;
            if (!myGraph->exist(start, end)){
                cout << "Word is not in the dictionary try other words!" << endl;
                continue;
            }
            myGraph->BFS(start, end); 
            cout << "Enter \"q\" to quit (terminate), or \"r\" to repeat: ";
            cin >> loop;
        } while (loop != 'q' && loop == 'r');

    return 0;
}










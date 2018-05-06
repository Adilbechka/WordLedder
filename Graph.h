/*
Adilbek Momunaliev
*/
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <vector>
#include <queue>
#include <stack>
#include <array>
#include "WordNode.h"
#ifndef GRAPH_H
#define GRAPH_H
using namespace std;
/*
class WordNode{
public:
    string word;
    WordNode* next;
    int number;
    bool visited;
    WordNode(){
        word = "";
        next = NULL;
        visited = false;
    }
};
*/
//compare function to sort strings
	bool compare(const string& a, const string& b){
		return (a.size() < b.size());
	}

	class Graph{
		friend class WordNode;
	public:
		fstream inputFile;
		string temp;
		string file = "dictionary.txt";
		vector<string> dictionary;
		vector<WordNode *> graph;
		WordNode* Node = NULL;
		//index represents lengh of the word and content represents  
		//it's number. This array will be used to know words of which
		//range as to have edges.
		int size[16];
		int length;
		WordNode* current;
		int startIndex;
		int endIndex;

		void build(){
			inputFile.open(file);
			if (!inputFile){
				throw "error";
			}
			for (int i = 0; i < 16; i++){
				size[i] = -1;
			}
			while (inputFile >> temp)
				dictionary.push_back(temp);
			//sorting dictionary in order to reduce number of edges in
			//the grpah and building process doesn't take too long
			sort(dictionary.begin(), dictionary.end(), compare);

			for (int i = 0; i < dictionary.size(); i++){
				Node = new WordNode();
				Node->number = i;
				Node->word = dictionary[i];
				graph.push_back(Node);
			}
			for (int i = 0; i < graph.size(); i++){
				length = graph[i]->word.size();
				if (size[length] == -1)
					size[length] = graph[i]->number;
			}
			for (int i = 0; i < dictionary.size(); i++){
				if (size[graph[i]->word.size()] != 0)
					startIndex = size[(graph[i]->word.size() - 1)];
				else 
					startIndex = size[graph[i]->word.size()] ;
				if (size[graph[i]->word.size() + 2] != -1)
					endIndex = size[graph[i]->word.size() + 2] - 1;
				else
					endIndex = 4296;
				current = graph[i];

				for (int j = 0; j < dictionary.size(); j++){
					if (i == j)
						continue;
					if (j >= startIndex && j<=endIndex){
					Node = new WordNode();
					Node->word = dictionary[j];
					Node->number = j;
					Node->prev = current;
					current->next = Node;
					current = current->next;
				}
					
				}

			}
			
		}
		void BFS(string word, string end) {
			queue<WordNode *> myQueue;
			//initialize all backtraking values to -1
			int backtrack[dictionary.size()];
			for (int i = 0; i < dictionary.size(); i++){
				backtrack[i] = -1;
			}
			WordNode* temp;
			WordNode* temp4;
			int i = 0;
			while (graph[i]->word != word){
				i++;
			}
			temp = graph[i];
			myQueue.push(graph[i]);
			temp->visited = true;
			bool value = false;
			bool final = false;
			bool print = true;
			WordNode* tempFinal;
			while (!myQueue.empty()) {
				int index;
				temp = myQueue.front();
				temp4 = myQueue.front();
				myQueue.pop();
					tempFinal = temp;
					word = tempFinal->word;
					while (tempFinal != NULL){
						value = ledder(word, tempFinal->word);
						if (!tempFinal->word.compare(end) && (value == true)) {
							tempFinal->visited = true;
							graph[tempFinal->number]->visited = true;
							backtrack[tempFinal->number] = temp4->number;
							final = true;
							break;
						}
						tempFinal = tempFinal->next;
					}
					if (final == true)
						break;
					temp4 = temp;
					while(temp != NULL) {
						value = ledder(word, temp->word);
						if ((value == true) && (graph[temp->number]->visited == false)) {
							myQueue.push(graph[temp->number]);
							temp->visited = true;
							graph[temp->number]->visited = true;
							backtrack[temp->number] = temp4->number;
						}
						temp = temp->next;
					}
					if (myQueue.empty()){
						cout << "WordLetter not foud in the 4295 word dictionary!" << endl;
						cout << "Try different words" << endl;
						print = false;
						break;
					}
			}
			if (print)
			printLedder(backtrack, tempFinal->number);
		}

	void printLedder(int name[], int indexFinal){
		cout << "---  ---  ---  ---  ---  ---  ---  ---  ---  ---  ---  ---" << endl;
		stack<string> print;
		while (indexFinal != -1){
			print.push(graph[indexFinal]->word);
			indexFinal = name[indexFinal];
		}
		while(!print.empty()){
			if (print.size() == 1){
				cout << print.top() << endl;
				print.pop();
				continue;
			}
			cout << print.top() << " ->";
			print.pop();
		}
	}
	//check if the entered words exist
	bool exist(string one, string two){
		bool valueOne = false;
		bool valueTwo = false;
		for (int i = 0; i < dictionary.size(); i++){
			if (dictionary[i] == one)
				valueOne = !valueOne;
		}
		for (int i = 0; i < dictionary.size(); i++){
			if (dictionary[i] == two)
				valueTwo = !valueTwo;
		}
		if (valueOne == true && valueTwo == true)
			return true;
		else
			return false;
	}

	bool ledder(string s1, string s2) {	
		bool reb = false;	
    	int m = s1.length();
 		int n = s2.length();
    	if (abs(m - n) > 1)
    	    return false;
    	int count = 0; 
    	int i = 0, j = 0;
    	while (i < m && j < n)
    	{
    	    if (s1[i] != s2[j])
    	    {
    	        if (count == 1)
    	            return false;

     	       	if (m > n)
           	    	i++;
            	else if (m < n)
                	j++;
            	else 
            	{
                	i++;
                	j++;
            	}
            	count++;
        	}
        	else
        	{
            	i++;
            	j++;
        	}
    	}
    	if (i < m || j < n)
        	count++;
        if (count == 1)
        	reb = true;
    	return reb;
	}
};

#endif














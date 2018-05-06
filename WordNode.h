#ifndef WORDNODE_H	
#define WORDNODE_H
#include <string>
using namespace std;
class WordNode{
public:
    string word;
    WordNode* next;
    WordNode* prev;
    int number;
    bool visited;
    WordNode(){
        word = "";
        next = NULL;
        prev = NULL;
        visited = false;
    }
};

#endif
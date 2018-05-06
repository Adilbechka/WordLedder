This is a command line "Word Ledder" program. To compile:$ g++ menu.cpp
dictionary.txt file must be in the same directory as executable

	"Word Ledder" - is when you given two words(start and final words)
and you,stating with the start word, continuously change one letter of the word to create 
another word until you morphed into final word.


This program modules a ~4000 word 
dictionary as a graph and performs BFS search to find WordLetter

Implications:
1. Moduling a 4000 word graph where each word has an edge to every single
other word yields exponentioal time. To avoid this, followoing step 
has been taken: Sord dictionaly and have an edges only to words that are only one letter 
longer or one letter shorter. Such graph builds in 2-3 secs on my machine

2. Using BFS always gives you shortest path. Meaning WordLedder fould contains least
number of words possible.

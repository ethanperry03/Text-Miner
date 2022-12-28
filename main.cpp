#include <iostream>
#include <string>
#include "TextMiner.h"
using namespace std;

/*
Date Modified:
 10/29: The current work in progress of this function is that it can create alltext, get number of words,
 create a list of words (AllWords), and  prints stats. I then added the getters for all the functions of the project.
 I finished the methods for removing capitals and punctionation and then the linear search for longest word.
 I then toiled over the bool return of isPalindrome but forgot the TextMiner:: at the start.
 10/30: I finished up my comments for the functions I wrote yesterday and continued on the palindrome ones. I created
 more object variables to store things like list of pals, a string of pals, and number of pals.
11/1: Finished writing all the remaining functions and including my own and my partners functions from lab.
 I cleaned up some formatting stuff but other than that it is all set and tests have been passing.
11/3: Cleaned up all last comments and files that needed some writing. submitted.
 */


int main() {

    string fileToTry = "text1.txt";

    // making a new object calls the CTOR
   TextMiner T(fileToTry);

    long numLinesRead;

    // call object T's method called "---"()
   numLinesRead = T.readFileIntoOneString();

   if (numLinesRead > 0) {
       // LOAD FILE
       cout << ".... LOADING " << T.getFilename() << " .............." << endl;
       cout << "   " << T.getFilename() << " READ with " << numLinesRead << " lines read." << endl;

       // TOKENIZE
       T.splitTextIntoWords();
       // at this point we have a full list of words and allText string

       cout << "   " << T.getFilename() << " TOKENIZED and has " << T.getNumberOfWords() << " words." << endl;


       // LONGEST WORD
       string longestWord;
       longestWord = T.findLongestWord();
       cout << "   " << T.getFilename() << " longest word: " << longestWord << " (length = " << longestWord.length() << ")." << endl;


       // LOOKING FOR PALINDROMES
       string aWord = "racecar";
       T.isPalindrome(aWord);

       T.primeLength();


       if (T.isPalindrome(aWord)) {
           cout << "   " << "YES " << aWord << " is a PALindrome." << endl;
       }
       else {
           cout << "   " << "NO " << aWord << " is NOT a PALindrome." << endl;
       }

       long  nPals;
       nPals = T.findNumberOfPalindromes( );
       cout << "   "  << T.getFilename() << " has " << nPals << " palindromes." << endl;

        T.getPals();

       T.howManyWordsOfLength_N();
       T.howManySubstringMatch();
       T.wordsStartingVowels();

       // PRINT THE FILE STATS
       T.printStats();

   } // end file opened OK

   else {
        cout << T.getFilename() << ": NO LINES from the file were READ." << endl;
   }

    cout << endl << endl << "Done." << endl;
    return 0;
} // end main()

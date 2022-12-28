//
// Created by Mark LeBlanc on 10/17/21.
//

#ifndef SOLUTION_TEXTMINER_H
#define SOLUTION_TEXTMINER_H

using namespace std;

#include <string>

const long MAX_WORDS = 10000; // ten thousand
const char DELIMITER = ' ';   // words separated by a space ' '

class TextMiner {
  public:
    TextMiner(string filename);

    long   readFileIntoOneString();
    void   splitTextIntoWords();
    string   allLowerCase(string line);
    string   removeAllPunctuation(string line);
    string findLongestWord();
    long   findNumberOfPalindromes();
    bool   isPalindrome(string aWord) const;
    long howManySubstringMatch();
    long howManyWordsOfLength_N();
    long primeLength();
    long wordsStartingVowels();
    const char substringOutput();

    // getters
    string getFilename() const;
    string getAllText() const;
    long   getNumberOfLines() const;
    long   getNumberOfWords() const;
    string getLongestWord() const;
    string getPals();

    void   printStats() const;


  private:
    bool   filenameKnown;        // true if we know the name of the filename
    bool   fileIsLoaded;         // true if we've read the lines in the file

    string filename;             // actual text filename opened, e.g., "mobyDick.txt"

    string allText;              // the entire text file stored as one string
    long   numberOfLines;        // number of lines in the original file

    string allWords[MAX_WORDS];  // allText (the entire file) stored as an array of words
    long   numberOfWords;        // 0 <= total number of words in the file <= MAX_WORDS

    long   numberOfPalindromes;  // number of palindromes found in the file
    string longestWord;          // the word with the most letters in the entire text

    string allPals[MAX_WORDS];   // list of all palindromes (max case is they all are)
    string listofPals;           // an output string of listed palindromes

    long wordsOfLength_N = 0;    // amount of words of desired length
    short N = 0;                 // length of searched words

    string substring;            // the desired substring to be located in text
    long wordsWithSubstring = 0; // amount of words that contain the substring

    long primeLengthWords = 0;   // the amount of words with a prime length
    long vowelWords = 0;         // The amount of words that begin with a vowel

}; // end class TextMiner


#endif //SOLUTION_TEXTMINER_H

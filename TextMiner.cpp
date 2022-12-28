//
// Created by Mark LeBlanc on 10/17/21.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>
#include <algorithm>

#include "TextMiner.h"

// CTOR
TextMiner::TextMiner(string newFilename) {
    filename      = newFilename;
    filenameKnown = true;
    fileIsLoaded  = false;

    longestWord         = "";
    allText             = "";
    listofPals          = "";
    numberOfLines       = 0;
    numberOfPalindromes = 0;
    numberOfWords       = 0;
    string allPals[MAX_WORDS];
}


// ------- OBJECT's can do: ACTIONS/BEHAVIORS ----------------------------
// -----------------------------------------------------------------------------------------
long TextMiner::readFileIntoOneString() {
    // SUMMARY: open and read lines from a file of text; save in one big string, allText
    // PRE: filenameKnown is true (we know the filename to open)
    // POST: private member allText stores the entire file as one string,
    //       private member numberOfLines set to number of successfully read input lines,
    //       private member fileIsLoaded set to true on success, false otherwise,
    //       and RETURNS the number of lines in the original file
    assert(filenameKnown == true);

    numberOfLines = 0;

    ifstream FIN;
    FIN.open( filename.c_str() );

    if ( FIN.is_open() ) {
        string theText;
        string line;

        getline(FIN, line);
        theText = line;
        while (FIN) // while we are NOT at the End Of the File (EOF)
        {

            if (numberOfLines == 0) {
                theText = removeAllPunctuation(line);
                theText = allLowerCase(theText);
            }
            else {
                line = removeAllPunctuation(line);
                line = allLowerCase(line);
                theText = theText + DELIMITER + line;
            }
            numberOfLines++;

            // get the next line, if any more
            getline(FIN, line);
        }
        FIN.close();

        // save the entire text into the object
        allText = theText;

    }
    else {
        cout << "File" << filename << " did NOT open." << endl;
        fileIsLoaded = false;
    }

    if (numberOfLines > 0)
        fileIsLoaded = true;

    return numberOfLines;
} // end method: TextMiner::readFileIntoOneString()

/*
Summary: This function takes the line that is being read in by the readFile function and removes any punct using the
 ispunct function that is essentially a list of all characters that are considered punct.
Pre: a line is read in using the file reader
Post: it returns the same line but all punct removed.
 */
string TextMiner::removeAllPunctuation(string line) {
    for (int i = line.size() - 1; i >= 0; i--) {
        if (ispunct(line[i]))
            line.erase(i, 1); }
    return line;
} // end of remove punc

/*
Summary: Similar to above, this function takes a line from input reader (in this case the one without punct)
 and uses the tolower function to remove all uppercase letters.
Pre: line written in normal capitalization style.
Post: all lowercase line.
 */
string TextMiner::allLowerCase(string line) {
    for(short i = 0; i < line.length(); i++){
        line[i] = tolower(line[i]);}
    return line;
} // end of all lower case

/* PRE: fileIsLoaded is true (we have read the file lines into one string already)
  POST: private member array allWords[] holds each individual word */
void TextMiner::splitTextIntoWords() {

    assert(fileIsLoaded == true);

    string nextWord;

    long i=0;

    istringstream wordsAsStream(allText);
    while (getline(wordsAsStream, nextWord, DELIMITER)) {
        //cout << nextWord << endl;
        // trap empty length "words"
        if (nextWord.length() != 0) {
            allWords[i] = nextWord;
            i++;
        }
    } // while more words to split up
    numberOfWords = i; // that is stored in a list allWords
}

/*
Summary: A linear search through all the words to find the current longest and returns the final 'winner'.
Pre: nothing is entered, method uses private array allWords to do linear search to find longest word.
Post: This function returns the string which is the longest word.
*/
string TextMiner::findLongestWord() {
    short i = 0;
    while(allWords[i].length() > 0){
        if(longestWord.length() < allWords[i].length())
            longestWord = allWords[i];
        i ++;                      }
    return longestWord;
}

/*
Summary: takes a word, reverses the word using for loop, and if the comparison is valid, returns bool true, else false.
Pre: A word being tested if it is a palindrome or not.
Post: true or false depending on if it passed the test. constant function so not updated values
 */
bool TextMiner::isPalindrome(string aWord) const{
    string newWord = aWord;
    for(short i = 1; i <= aWord.length(); i++){
        newWord[i - 1] = aWord[aWord.length() - i];
    }
    if(newWord == aWord) {
        return true;
    }
    else{
        return false;}
}

/*
Summary: This function uses the previous to see if the value was a palindrome, if it was the word gets appended to a
 object variable array called allPals. This all pals will be used in later output functions but the iterated counter
 numberOfPalindromes is an object variable and that is what is returned.
Pre: Nothing is entered but the object list of all words is used like an input because that is what is being
 operated on. Since the object variable number of palindromes is being updated, the method is not constant.
Post: The number of palindromes is returned and updated in the object.
 */
long TextMiner::findNumberOfPalindromes() {
    short i, k = 0;
    bool isPal;

    while(allWords[i] != ""){
        isPal = isPalindrome(allWords[i]);
        if (isPal == true) {
            numberOfPalindromes++;
            allPals[k] = allWords[i];
            k++;      }
        i++;                }
    return numberOfPalindromes;
}

/*
Summary: User inputs a number from keyboard and the function finds how many words of that length are in the text.
PRE: Nothing is going in or being read in.
Post: Variable wordsOfLength_N is updated with the appropriate value.
 */
long TextMiner::howManyWordsOfLength_N() {
    cout << "Search amount of words length: " << endl;
    cin >> N;
    short lengthOfWord;

    for (short i = 0; i < numberOfWords; i++){
        lengthOfWord = allWords[i].length();
        if (lengthOfWord == N)
            wordsOfLength_N++;
    }
    cout << wordsOfLength_N << endl;
    return wordsOfLength_N;
}

/*
Summary: A substring is entered by the users keyboard and the amount of times it occurs in the text is returned.
Pre: Nothing is entered, just user stdin once function is called.
Post: wordsWithSubstring variable is updated to store the number of occurrences of the substring throughput the text.
 */
long TextMiner::howManySubstringMatch() {

    cout << "String to search: " << endl;
    cin >> substring;

    short j = substring.length();
    short i = 0;

    while(i <= allText.length() - j){
        if (allText.substr(i,j) == substring){
            wordsWithSubstring ++;}
        i ++;}
    return wordsWithSubstring;
}

/*
Summary: Finds the amount of words that have a prime length.
Pre: Nothing goes in.
Post: Variable primeLengthWords is updated to store the appropriate values
 */
long TextMiner::primeLength(){
    short i = 0;

    while(allWords[i] != ""){
        if(allWords[i].length() < 3)
            primeLengthWords ++;
        else if(allWords[i].length() % 2 != 0)
            primeLengthWords ++;
        i++;
    }
    return primeLengthWords;
}

/*
Summary: Counts the amount of words that start with a vowel
Pre: nothing goes in
Post: vowelWords variable is updated to store number of words starting with a vowel.
 */
long TextMiner::wordsStartingVowels(){
    short i = 0;
    string list[5] = {"a", "e", "i", "o", "u"};
    while(allWords[i] != ""){
        short k = 0;
        while(k < 5){
            if(allWords[i].substr(0,1) == list[k])
                vowelWords ++;
            k ++; }
        i ++; }
    return vowelWords;
}

/*
This function prints out important stats and is a nicely formatted summary of the analysis done by
textminer. It is a constant function and all that was changed were new lines added to update output.
 */
void TextMiner::printStats() const {
    if (fileIsLoaded) {
        cout << endl;
        cout << "---- File STATS -----------------------------------------------" << endl;
        cout << "Filename:                  " << filename << endl;
        cout << "Number of lines:           " << numberOfLines << endl;
        cout << "Number of words:           " << numberOfWords << endl;
        cout << "Longest word:              " << longestWord << " (" << longestWord.length() << " letters)" << endl;
        cout << "Palindromes:               " << numberOfPalindromes << " (" << listofPals << ")" << endl;
        cout << "Occurrences of " << "'" + substring + "'";
        printf("%8ld", wordsWithSubstring);
        cout << endl << "Number of words length " << N << ":  " << wordsOfLength_N << endl;
        cout << "Prime length words:        " << primeLengthWords << endl;
        cout << "Words starting with vowel: " << vowelWords << endl;
        cout << "---------------------------------------------------------------" << endl;
    } else {
        cout << "No Stats yet; file: " << filename << " has not been loaded. (call readFileIntoOneString() )." << endl;
    }

} // end printStats()

// ------- GETTERS ----------------------------
string TextMiner::getFilename() const {
    return filename;
}

string TextMiner::getAllText() const {
    return allText;
}

long TextMiner::getNumberOfLines() const {
    return numberOfLines;
}

long TextMiner::getNumberOfWords() const {
    return numberOfWords;
}

string TextMiner::getLongestWord() const{
    return longestWord;
}

string TextMiner::getPals(){

    string output = allPals[0];
    for (short i = 1; i < numberOfPalindromes; i++){
        output = output + ", " + allPals[i];
    }

    listofPals = output;
    return output;
}

Programmer: Ethan Perry
Program 4: Text Miner
Due 11/4 @ 4:00am


Summary: This project reads in a file that is in the executable and creates an object with its contents.
         From this point, several methods were written to first process this text into something manageable
         ie. (an array of the words seperated (allWords) and a string of all the text (allText). It then processes
         the text with the functions written, getting quantitative measures about the input file text Finally, it calls
         the printStats() method to give the user useful information about the file they inputted from stdout on
         the console. 

Files Included:
README.txt    - This file explaining the zipped project
main.cpp      - In this project, it acts as a test suite almost since in actual application we wrote the API
              and a user would be using our public methods. In this main the line TextMiner T(fileToTry); creates
              an object called T by reading in text1.txt. Now T.method() will call each public method by the user
              of this API and store values in the private data variables. main.cpp should be client.cpp realistically.
TextMiner.cpp - This is where all the methods are actually written and defined. The top of the file is the CTOR
              which creates an object (in this case T). Then all of the private and public methods are written
              to be used by a client. Since the methods are defined as public, the user would be able to access them
              in theory but the file would be encrypted so that they couldn't make their own.
TextMiner.h   - This is where everything is defined within our class template. Methods and data are either public or
              private in this case. Most of the data variables are private and cannot be reached by the user, whereas
              the methods are meant to be used to store values in those private variables.
text1.txt     - This is the test file I used. I used the substring finder of 'ab' as well as my other functions such as
              find number of words that start with a vowel.

Status: Everything works great, no bugs detected, proud of my word. The only expection is the output for the substring
        counts will not be lined up unless the substring length is 3. I tried making a function that casted const char
        onto "%lengthld" but it was too complicated and I didn't want to over-concern myself with one outputting flaw.



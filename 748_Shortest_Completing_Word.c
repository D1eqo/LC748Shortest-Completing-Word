//Diego Aquino Montero, Turma M1

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

/*
====================
GetLetters
Will separate letters from numbers in a given array named 'licensePlate', then the letters are all converted into their respective lower case versions.
====================
*/

char* GetLetters(const char* licensePlate){
    int j = 0;
    char* filtered;
    for (int i = 0; licensePlate[i]  != '\0'; i++) {
        if (isalpha(licensePlate[i])) {
            filtered[j] = tolower(licensePlate[i]);
            j++;
        }
    }
    filtered[j]='\0';
    return filtered;
}

/*
====================
CheckForWords
This function receives two strings named 'words' and 'freePlate'. It will then count how many times a specific letter shows up in freePlate using 'counter'.
If 'words' has a letter which also appears in freePlate then the counter will decrease for that specific letter.
If the counter for all letters equals to zero, then the function returns true.
====================
*/

bool CheckForWords(char* words, char* freePlate) {
    const char* alphabet = "abcdefghijklmnopqrstuvwxyz";
    int counter[26] = {0};
    int wordSize = strlen(words);
    int freePlateSize = strlen(freePlate);

    for (int i = 0; i < freePlateSize; i++) {
        for (int j = 0; j < 26; j++) {
            if (freePlate[i] == alphabet[j]) {
                counter[j]++;
            }
        }
    }
    for (int i = 0; i < wordSize; i++) {
        for (int j = 0; j < 26; j++) {
            if (words[i] == alphabet[j]) {
                counter[j]--;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if (counter[i] > 0) {
            return false;
        }
    }
    return true;
}

char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize){
    char* freePlate;
    char* shortest = NULL;

    freePlate = GetLetters(licensePlate);

    for (int i = 0; i < wordsSize; i++) {
        if (CheckForWords(words[i], freePlate) == true) {
            if (shortest == NULL || strlen(words[i]) < strlen(shortest)){
                shortest = words[i];
            }
        }
    }
   return shortest;
}


int main() {
    
    char* licensePlate = "123aBcdEe456f";
    char* words[] = {"abade", "aabbccddeeff", "abcdeef", "abcdeeff"};
    int wordsSize = sizeof(words) / sizeof(words[0]);

    char* result = shortestCompletingWord(licensePlate, words, wordsSize);

    printf("Shortest Completing Word: %s\n", result);

    return 0;
}

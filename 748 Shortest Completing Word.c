//Diego Aquino Montero

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

char* GetLetters(const char* licensePlate){
    int j = 0;
    char* filtered = (char*)malloc(strlen(licensePlate) + 1);
    for (int i = 0; licensePlate[i]  != '\0'; i++) {
        if (isalpha(licensePlate[i])) {
            filtered[j] = tolower(licensePlate[i]);
            j++;
        }
    }
    filtered[j]='\0';
    return filtered;
}

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

    free(freePlate);

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

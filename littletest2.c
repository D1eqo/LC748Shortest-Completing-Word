#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char* getsmall(const char* licensePlate){
    int j=0;
    char* filtered = (char*)malloc(strlen(licensePlate) + 1);
    for (int i=0; licensePlate[i] !='\0'; i++){
        if (isalpha(licensePlate[i])) {
            filtered[j]=tolower(licensePlate[i]);
            j++;
        }
    }
    filtered[j]='\0';
    return filtered;
}

bool checkForWords(char* words, char* oua){
    const char* alphabet[26]={"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    int counter[26] = {0};
    int wordsS = strlen(words);
    int ouaS = strlen(oua);

    for (int i = 0; i < ouaS; i++) {
        for (int j = 0; j < 26; j++) {
            if (oua[i] == alphabet[j][0]) {
                counter[j]++;
            }
        }
    }
    for (int i = 0; i < wordsS; i++) {
        for (int j = 0; j < 26; j++) {
            if (words[i] == alphabet[j][0]) {
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

int main() {
    const char* licensePlate = "aB22cDeF";
    char* oua;
    char* words[5] = {"abajur", "abcdef", "abcddef", "fifa", "feedabc"};
    char* palibra[]={NULL};

    oua = getsmall(licensePlate);

    for (int i = 0; i < 5; i++) {
        if (checkForWords(words[i], oua) == true) {
            if (palibra[0] == NULL || strlen(words[i])<strlen(palibra[0])){
                palibra[0] = words[i];
            }
        }
    }
    if (palibra[0] != NULL) { 
   printf("The word is: %s\n", palibra[0]);
   }

    free(oua);
    return 0;
}

char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize){

    char w[7];
    char cw[15];
    int p=1;

    for (int i=0; i<strlen(licensePlate); i++){
        for (int i=0; i<10; i++){
            licensePlate[i]==w[i];
        }
    }

    for (int i=0; i<wordsSize; i++){
        strcpy(cw[0], words[i]);
        if (p!=0){
            p=strlen(w);
        }
        if (p==0){
            return words[i-1];
        }
        for (int j=0; j<strlen(words[i]); j++){
            for (int k=0; k<strlen(w)-1; k++){
                if (w[k]==cw[j]){
                    p--;
                }
            }
        }
    }
}
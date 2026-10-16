# include <stdio.h>

char findTheDifference(char* s, char* t) {
    char aux = 0;
    
    for(int i = 0; s[i] != '\0'; i++){ aux ^= s[i]; }
    for(int j = 0; t[j] != '\0'; j++){ aux ^= t[j]; }

    return aux;
}

int main(){
    char text1[] = "abcd";
    char text2[] = "abcde";

    char extra = findTheDifference(text1, text2);

    printf("Extra: %c", extra);

    return 0;
}

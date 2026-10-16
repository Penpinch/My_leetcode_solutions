# include <stdio.h>
# include <string.h>

int lengthOfLastWord(char* s){
    int length = strlen(s);
    int length_last_word = 0;

    for(int j = length; s[j - 1] == ' '; j-- ){ length--; }

    for(int i = length; i > 0 && s[i - 1] != ' '; i--){
        length_last_word++;
    }

    return length_last_word;
}

int main(){
    char s[] = "";

    int len = lengthOfLastWord(s);
    printf("lenght: %d", len);

    return 0;
}

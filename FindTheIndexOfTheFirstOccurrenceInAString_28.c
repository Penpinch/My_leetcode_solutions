# include <stdio.h>

int strStr(char* haystack, char* needle){
    int index = 0;
   
    for(int i = 0; haystack[i] != '\0'; i++){
        if(haystack[i] == needle[0]){
            index = i;
            int k = 0;

            while(needle[k] != '\0'){
                if(needle[k] != haystack[index + k]){
                    index = -1; break;
                }
                k++;
            }
            if(index != -1){ return index; }
        }
    }
    return -1;
}

int main(){
    char haystack[] = "leetcode";
    char needle[] = "leeto";

    int result = strStr(haystack, needle);

    printf("%d", result);

    return 0;
}

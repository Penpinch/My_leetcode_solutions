/* 28
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
    Output: 0
    Explanation: "sad" occurs at index 0 and 6.
    The first occurrence is at index 0, so we return 0.

Example 2:

    Input: haystack = "leetcode", needle = "leeto"
    Output: -1
    Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints:

    - 1 <= haystack.length, needle.length <= 10^4
    - haystack and needle consist of only lowercase English characters.
*/

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

// 131 ms of runtime.
// 8.94 MB of memory.

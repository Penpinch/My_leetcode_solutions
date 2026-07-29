/* 58
Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal consisting of non-space characters only.

Example 1:

    Input: s = "Hello World"
    Output: 5
    Explanation: The last word is "World" with length 5.

Example 2:

    Input: s = "   fly me   to   the moon  "
    Output: 4
    Explanation: The last word is "moon" with length 4.

Example 3:

    Input: s = "luffy is still joyboy"
    Output: 6
    Explanation: The last word is "joyboy" with length 6.

Constraints:

    1 <= s.length <= 10^4   
    s consists of only English letters and spaces ' '.
    There will be at least one word in s.
 */

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

// 0 ms of runtime.
// 8.80 MB of memory.

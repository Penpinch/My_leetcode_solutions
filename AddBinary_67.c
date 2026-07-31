/* 67
Given two binary strings a and b, return their sum as a binary string.

Example 1:

    Input: a = "11", b = "1"
    Output: "100"

Example 2:

    Input: a = "1010", b = "1011"
    Output: "10101"

Constraints:
    - 1 <= a.length, b.length <= 10^4
    - a and b consist only of '0' or '1' characters.
    - Each string does not contain leading zeros except for the zero itself.
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char* addBinary(char* a, char* b){
    int length_a = strlen(a), length_b = strlen(b);
    int max_length = (length_a > length_b) ? length_a : length_b;
    
    char* result = (char*)malloc(max_length + 2);

    int i = length_a - 1, j = length_b - 1;
    int k = 0, carry = 0;

    while(i >= 0 || j >= 0 || carry > 0){
        int sum = carry;
        if(i >= 0){ sum += a[i--] - '0'; }
        if(j >= 0){ sum += b[j--] - '0'; }
        
        result[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }
    result[k] = '\0';

    for(int l = 0; l < k / 2; l++){
        char temp = result[l];
        result[l] = result[k - 1 - l];
        result[k - 1 - l] = temp;
    }

    return result;
}

int main() {
    char a[] = "1010";
    char b[] = "1011";

    char* result = addBinary(a, b);

    printf("Resultado: %s\n", result);
    free(result);

    return 0;
}

// 0 ms of runtime.
// 8.82 MB of memory.

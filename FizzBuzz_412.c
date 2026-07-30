/* 412
Given an integer n, return a string array answer (1-indexed) where:

    answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
    answer[i] == "Fizz" if i is divisible by 3.
    answer[i] == "Buzz" if i is divisible by 5.
    answer[i] == i (as a string) if none of the above conditions are true.

Example 1:

    Input: n = 3
    Output: ["1","2","Fizz"]

Example 2:

    Input: n = 5
    Output: ["1","2","Fizz","4","Buzz"]

Example 3:

    Input: n = 15
    Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

Constraints:
    1 <= n <= 10^4
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Note: The returned array must be malloced, assume caller calls free().
char** fizzBuzz(int n, int* returnSize){
    char **arr = (char**)malloc(n * sizeof(char*));
    for(int i = 0; i < n; i++){
        *(arr + i) = (char*)malloc(10 * sizeof(char));
    }
    
    for(int i = 1; i <= n; i++){
        if(i % 3 == 0 && i % 5 == 0){ strcpy(*(arr + (i - 1)), "FizzBuzz"); }//*(arr + (i - 1)) = "FizzBuzz"; }
        else if(i % 3 == 0){ strcpy(*(arr + (i - 1)), "Fizz"); }// *(arr + (i - 1)) = "Fizz"; }
        else if(i % 5 == 0){ strcpy(*(arr + (i - 1)), "Buzz"); }//*(arr + (i - 1)) = "Buzz"; }
        else { sprintf(*(arr + (i - 1)), "%d", i); }
    }
    *returnSize = n;
    return arr;
}

int main(){
    int n = 10000, returnSize = 0;

    char **arr = fizzBuzz(n, &returnSize);

    for(int i = 0; i < returnSize; i++){  printf("%s, ", arr[i]); }
    free(arr);


    return 0;
}

// 3 ms of runtime.
// 11.14 MB of memory.

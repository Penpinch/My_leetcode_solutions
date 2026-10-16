# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char** fizzBuzz(int n, int* returnSize){
    char **arr = (char**)malloc(n * sizeof(char*));

    for(int i = 1; i <= n; i++){
        if(i % 3 == 0 && i % 5 == 0){ *(arr + (i - 1)) = strdup("FizzBuzz"); }
        else if(i % 3 == 0){ *(arr + (i - 1)) = strdup("Fizz"); }
        else if(i % 5 == 0){ *(arr + (i - 1)) = strdup("Buzz"); }
        else {
            *(arr + (i - 1)) = (char*)malloc(10*sizeof(char));
            sprintf(*(arr + (i - 1)), "%d", i);
        }
    }

    *returnSize = n;
    return arr;
}

int main(){
    int n = 15, returnSize = 0;

    char **arr = fizzBuzz(n, &returnSize);

    for(int i = 0; i < returnSize; i++){  printf("%s, ", arr[i]); }
    free(arr);

    return 0;
}

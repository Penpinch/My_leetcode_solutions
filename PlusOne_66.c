# include <stdio.h>
# include <stdlib.h>

// Note: The returned array must be malloced, assume caller calls free().
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *result = (int*)malloc(digitsSize * sizeof(int));

    for(int i = 0; i < digitsSize; i++){ result[i] = digits[i]; }
    for(int i = digitsSize - 1; i >= 0; i--){
        if(result[i] < 9){
            result[i] = result[i] + 1;
            *returnSize = digitsSize;
            return result;
        }
        result[i] = 0;
    }
    free(result);

    result = (int*)malloc((digitsSize + 1) * sizeof(int));
    result[0] = 1;

    for(int i = 1; i <= digitsSize; i++){ result[i] = 0; }

    *returnSize = digitsSize + 1;
    return result;
}

int main(){
    int digits[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int digitsSize = sizeof(digits) / sizeof(digits[0]);
    int returnSize = 0;

    int *new_arr = plusOne(digits, digitsSize, &returnSize);
    
    printf("\nreturnSize = %d\n", returnSize);
    for(int i = 0; i < returnSize; i++){ printf("%d", new_arr[i]); }
    free(new_arr);

    return 0;
}

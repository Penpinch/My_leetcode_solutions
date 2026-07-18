# include <stdio.h>
# include <stdlib.h>

int *addition(int *arr, int arr_size, int target, int *return_size){
    int *solution = (int*)malloc(2 * sizeof(int));

    for(int i = 0; i < arr_size; i++){
        for(int j = 0; j < arr_size; j++){
            if(j != i && target == arr[i] + arr[j]){ 
                solution[0] = j; 
                solution[1] = i; 
                *return_size = sizeof(solution) / sizeof(solution[0]);
                return solution; 
            }
        }
    }
    return NULL;
}

int main(){
    int arr[] = {2, 7, 11, 15};
    int target = 9;
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int return_size = 0;

    int *solution = addition(arr, arr_size, target, &return_size);

    printf("Sol: [%d, %d]", solution[0], solution[1]);
    free(solution); printf("\nFreed successfully\n");

    return 0;
}

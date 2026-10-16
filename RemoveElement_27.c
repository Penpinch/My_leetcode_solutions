# include <stdio.h>

int removeElement(int* nums, int numsSize, int val){
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == val){
            for(int j = i; j < numsSize - 1; j++){ nums[j] = nums[j + 1]; }
            numsSize--;
            i--;
        }
    }
    return numsSize;
}

int main(){
    int nums[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int val = 2;

    int k = removeElement(nums, numsSize, val);
    
    printf("k: %d\n", k);
    for(int i = 0; i < k; i++){ printf("%d ", nums[i]); }

    return 0;
}

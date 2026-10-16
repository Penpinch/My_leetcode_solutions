
# include <stdio.h>

int searchInsert(int* nums, int numsSize, int target){
    if(nums[numsSize - 1] < target){ return numsSize; }

    for(int i = 0; i < numsSize; i++){
        if(nums[i] == target || nums[i] > target){ return i; }

    }
    return -1;
}

int main(){
    int nums[] = {1, 3, 5, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 7;

    int result = searchInsert(nums, numsSize, target);
    printf("%d", result);

    return 0;
}

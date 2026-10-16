# include <stdio.h>

int removeDuplicates(int *nums, int numsSize){
    for(int i = 0; i < numsSize - 1; i++){
        if(nums[i] == nums[i + 1]){
            for(int j = i; j < numsSize - 1; j++){ nums[j] = nums[j + 1]; }
            numsSize--;
            i--;
        }
    }
    return numsSize;
}

int main(){
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int len = (sizeof nums / sizeof nums[0]);
    int expectedNums[5];
    int k = removeDuplicates(nums, len);

    printf("%d\n", k);
    for(int i = 0; i < k; i++){ printf("%d ", nums[i]); }

    return 0;
}

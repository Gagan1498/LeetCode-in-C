/* Trick: In such questions where set is given in the form of [1,n]..they can be used to self index. For example, to find the duplicate 
number I can somehow point the duplicate number to the same (previous identified number), this will allow me to catch the duplicated number. 
And to find the lost number - trick is "to go to any index, you should have (i+1) number, where i is the index....why? Because I was never 
able to reach that index "nums[abs(nums[i])-1]". More exaplanation at: https://www.youtube.com/watch?v=j89Yzq3IwVY&t=918s&ab_channel=codestorywithMIK */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* ptr = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        if (nums[abs(nums[i]) - 1] < 0) {
            *ptr = abs(nums[i]);
        } else {
            nums[abs(nums[i]) - 1] = nums[abs(nums[i]) - 1] * (-1);
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            *(ptr + 1) = i + 1;
        }
    }

    *returnSize = 2;
    return ptr;
}

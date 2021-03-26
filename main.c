#include <stdlib.h>
#include <stdio.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    int left, right;
    int *res = NULL;

    for (left = 0; left < numsSize; left++) {
        for (right = left + 1; right < numsSize; right++) {
            if (nums[left] + nums[right] == target) {
                res = malloc(2 * sizeof(int));
                *returnSize = 2;
                res[0] = left;
                res[1] = right;
                return res;
            }
        }
    };
    *returnSize = 0;
    return res;
};

void printList(int *list, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", list[i]);
    }
};

void runTest() {
    {
        int nums[] = {2, 7, 11, 15};
        int numsSize = 4;
        int target = 9;
        int wantSize = 2;
        int want[] = {0, 1};
        int returnSize;
        int *res = twoSum(nums, numsSize, target, &returnSize);
        if (returnSize == wantSize && ((wantSize == 2 && res[0] == want[0] && res[1] == want[1]) || wantSize == 0)) {
            printf("ok\n");
        } else {
            printf("want: ");
            printList(want, 2);
            printf(", got: ");
            printList(res, returnSize);
            printf("\n");
        }
        free(res);
    }
    {
        int nums[] = {2, 7, 11, 15};
        int numsSize = 4;
        int target = 100;
        int wantSize = 0;
        int want[] = {-1, -1};
        int returnSize;
        int *res = twoSum(nums, numsSize, target, &returnSize);
        if (returnSize == wantSize && ((wantSize == 2 && res[0] == want[0] && res[1] == want[1]) || wantSize == 0)) {
            printf("ok\n");
        } else {
            printf("want: ");
            printList(want, 2);
            printf(", got: ");
            printList(res, returnSize);
            printf("\n");
        }
        free(res);
    }
};


int main() {
    runTest();
};

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

double findMaxAverage(int* nums, int numsSize, int k){
    double ret = INT_MIN;
    double tmp = 0;

    if (k > numsSize)
        return ret;
    for (int i = 0; i < k; i++) {
        tmp += nums[i];
    }
    ret = tmp;
    for (int i = k; i < numsSize; i++) {
        tmp -= nums[i-k];
        tmp += nums[i];
        ret = ret > tmp ? ret : tmp;
    }
    return ret / k;
}

int main() {
    int nums[] = {-1};
    int numsSize = 1;
    int k = 1;
    double ret = 0;

    ret = findMaxAverage(nums, numsSize, k);
    printf("ret: %f\n", ret);
    return 0;
}

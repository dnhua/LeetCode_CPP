#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

double findMaxAverage(int* nums, int numsSize, int k){
    double ret = INT_MIN;

    if (k > numsSize)
        return ret;
    for (int i = 0; i < numsSize - k + 1; i++) {
        double tmp = 0;
        for (int j = i; j < i + k; j++) {
            tmp += nums[j];
        }
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

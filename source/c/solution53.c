int maxSubArray(int *nums, int numsSize){
    int *dp;
    int ret;

    dp = (int *)malloc(sizeof(int) * numsSize);
    dp[0] = nums[0];
    ret = dp[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i] + dp[i-1]) {
            dp[i] = nums[i];
        } else {
            dp[i] = dp[i-1] + nums[i];
        }
        ret = ret > dp[i] ? ret : dp[i];
    }
    return ret;
}


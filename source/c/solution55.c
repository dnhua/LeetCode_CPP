bool canJump(int *nums, int numsSize){
    int max_right;

    max_right = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i <= max_right)
            max_right = max_right > i + nums[i] ? max_right : i + nums[i];
        if (max_right >= numsSize - 1)
            return true;
    }
    return false;
}

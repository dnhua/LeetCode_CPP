/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static int sum(int *nums, int size) {
    int ret = 0;

    for (int i = 0; i < size; i++) {
        ret += nums[i];
    }
    return ret;
}

int* fairCandySwap(int *A, int ASize, int *B, int BSize, int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * 2);
    int sumA = 0;
    int sumB = 0;
    int diff = 0;
    int delta = 0;

    if (A == NULL || B == NULL) {
        return ret;
    }
    *returnSize = 2;
    sumA = sum(A, ASize);
    sumB = sum(B, BSize);
    for (int i = 0; i < ASize; i++) {
        diff = sumB - sumA;
        delta = diff / 2;
        int tmp = A[i] + delta;
        for (int j = 0; j < BSize; j++) {
            if (tmp == B[j]) {
                ret[0] = A[i];
                ret[1] = B[j];
                return ret;
            }
        }
    }
    return ret;
}

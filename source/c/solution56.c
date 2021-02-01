/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
static int cmp(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int **ret = (int **)malloc(sizeof(int *) * intervalsSize);
    int *pstart = (int *)malloc(sizeof(int) * intervalsSize);
    int *pend = (int *)malloc(sizeof(int) * intervalsSize);
    int k = 0;

    for (int i = 0; i < intervalsSize; i++) {
        pstart[i] = intervals[i][0];
        pend[i] = intervals[i][1];
    }
    qsort(pstart, intervalsSize, sizeof(int), cmp);
    qsort(pend, intervalsSize, sizeof(int), cmp);

    *returnSize = 0;
    *returnColumnSize = (int *)malloc(intervalsSize * sizeof(int));
    for (int i = 0; i < intervalsSize; i++) {
        int j;
        for (j = i; j < intervalsSize-1; j++) {
            if (pstart[j+1] > pend[j]) {
                break;
            }
        }
        ret[*returnSize] = (int *)malloc(sizeof(int) * 2);
        ret[*returnSize][0] = pstart[i];
        ret[*returnSize][1] = pend[j];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
        i = j;
    }
    free(pstart);
    free(pend);
    return ret;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    int len;
    int sorted;
} MedianFinder;

int cmp(const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

MedianFinder* medianFinderCreate() {
    MedianFinder *obj = (MedianFinder *)malloc(sizeof(MedianFinder));
    obj->data = NULL;
    obj->len = 0;
    obj->sorted = 0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->data == NULL) {
        obj->data = (int *)malloc(sizeof(int) * 1);
        obj->data[0] = num;
        obj->len++;
    } else {
        int *tmp = (int *)malloc(sizeof(int) * (obj->len + 1));
        memcpy(tmp, obj->data, sizeof(int) * obj->len);
        tmp[obj->len] = num;
        free(obj->data);
        obj->data = tmp;
        obj->len++;
        obj->sorted = 0;
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->sorted == 1)
        goto out;

    qsort(obj->data, obj->len, sizeof(int), cmp);
    obj->sorted = 1;

out:
    if (obj->len % 2 == 0) {
        return 1.0 * (obj->data[obj->len / 2] + obj->data[obj->len / 2 - 1]) / 2;
    } else {
        return obj->data[obj->len / 2];
    }
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->data);
    free(obj);
}

int main() {
    double mid = 0;

    MedianFinder* obj = medianFinderCreate();
    medianFinderAddNum(obj, 1);
    medianFinderAddNum(obj, 2);
    mid = medianFinderFindMedian(obj);
    printf("mid = %f\n", mid);
    free(obj->data);
    free(obj);
    return 0;
}

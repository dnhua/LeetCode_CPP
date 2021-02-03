#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    int len; 
} MedianFinder;

int cmp(const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

/** initialize your data structure here. */
MedianFinder* medianFinderCreate() {
    MedianFinder *obj = (MedianFinder *)malloc(sizeof(MedianFinder));
    obj->data = NULL;
    obj->len = 0;
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
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    qsort(obj->data, obj->len, sizeof(int), cmp);
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

    MedianFinder* objs = medianFinderCreate();
    medianFinderAddNum(objs, 1);
    medianFinderAddNum(objs, 2);
    mid = medianFinderFindMedian(objs);
    printf("mid = %f\n", mid);
    free(objs->data);
    free(objs);
    return 0;
}

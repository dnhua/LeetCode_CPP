#include <string.h>
int equalSubstring(char *s, char *t, int maxCost){
    int ret = 0;
    int len = 0;
    int *diff;
    int l = 0, r = 0;
    int max = maxCost;

    len = strlen(s);
    diff = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        diff[i] = s[i] > t[i] ? s[i] - t[i] : t[i] - s[i];
        printf("%d ", diff[i]);
    }
    while (l <= r && r < len) {
        if (maxCost >= diff[r]) {
            ret = ret > r - l + 1 ? ret : r - l + 1;
            maxCost -= diff[r];
            r++;
        } else {
            maxCost += diff[l];
            maxCost -= diff[r];
            maxCost = maxCost > max ? max : maxCost;
            l++;
            r++;
        }
    }
    return ret;
}

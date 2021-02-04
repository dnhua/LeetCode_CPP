#include <string.h>

int maxLengthBetweenEqualCharacters(char * s){
    int ret = -1;
    int len = 0;
    int chash[26];

    len = strlen(s);
    for (int i = 0; i < 26; i++) {
        chash[i] = -1;
    }
    for (int i = 0; i < len; i++) {
        int idx = s[i] - 'a';
        if (chash[idx] == -1) {
            chash[idx] = i;
        } else {
            int diff = i - chash[idx] - 1;
            ret = ret > diff ? ret : diff;
        }
    }
    return ret;
}

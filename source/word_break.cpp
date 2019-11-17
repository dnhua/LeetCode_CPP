#include <string>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, unordered_set<string> &dict) {
    int len = s.size();
    if (len == 0 || dict.size() == 0)
        return false;
    bool *local = new bool[len+1];
    for (int i=1; i<=len; i++)
	*(local + i) = false;
    *local = true;
    for (int i=1; i<=len; i++) {
        for (int j=0; j<i; j++) {
	    if (*(local + j) && dict.find(s.substr(j, i-j)) != dict.end()) {
	        *(local + i) = true;
		break;
	    }
	}
    }
    return *(local + len);
}

#include <vector>
#include <unordered_map>
using namespace std;
//以下解法在牛客上只能通过60%
int singleNumber(int A[], int n) {
    unordered_map<int, int> map;
    for (int i=0; i<n; i++) {
        if (map.find(A[i]) == map.end()) {
	    map.insert(pair<int, int>(A[i], 1));
	} else {
	    map.insert(pair<int, int>(A[i], map.at(A[i])+1));
	}
    }

    for (auto it=map.begin(); it!=map.end(); it++) {
        if (it->second == 1) 
	    return it->first;
    }
    
    return -1;
}

//找到的解法
int singleNumber2(int A[], int n) {
    int ones = 0;//记录只出现过1次的bits
    int twos = 0;//记录只出现过2次的bits
    int threes = 0;//记录出现过3次的bits
    for (int i=0; i<n; i++) {
        twos |= ones&A[i];
	ones ^= A[i];
	threes = ones&twos;
	ones &= ~threes;
	twos &= ~threes;
    }
    return ones;
}

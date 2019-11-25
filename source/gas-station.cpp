#include <istream>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    //vector<int> gasc(gas.size() * 2), costc(cost.size() * 2);  //gasc:考虑循环
    int n = gas.size();
    for(int i=0; i<n; i++) {  //外层循环考虑所有出发点
        //内层循环:针对每个出发点
	int sum = 0;
	for (int j=i, num=0; num<n; j++, num++) {
	    sum += gas[j%n];
	    if (sum < cost[j%n]) {
	        break;
	    }
	    sum -= cost[j%n];
	    if (num == n-1) {
	        return i;
	    }
	}
    }
    return -1;
}

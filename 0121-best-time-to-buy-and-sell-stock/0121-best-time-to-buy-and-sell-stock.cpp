#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &Arr){
    // Write your code here.
	int maxProfit = 0;
	int mini = Arr[0];
	
	for(int i=1;i<Arr.size();i++){
        int curProfit = Arr[i] - mini;
        maxProfit = max(maxProfit,curProfit);
        mini = min(mini,Arr[i]);
        }
	return maxProfit;
}
};



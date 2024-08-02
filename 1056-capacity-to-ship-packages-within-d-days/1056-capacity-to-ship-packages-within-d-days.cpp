class Solution {
public:
    int solve(vector<int>& wt, int cap){
        int dayno=1,load=0;
        for(int i = 0;i<wt.size();i++){
            if(load+wt[i]>cap){
                dayno=dayno+1;
                load=wt[i];
            }else{
                load+=wt[i];
            }
        }
        return dayno;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = *max_element(weights.begin(), weights.end());
        int sum = accumulate(weights.begin(), weights.end(), 0);
        int low =maxi,high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            int d=solve(weights,mid);
            if(d<=days){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
        
    }
};
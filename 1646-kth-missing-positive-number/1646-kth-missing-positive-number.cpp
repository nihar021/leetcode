class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0 ,high=n-1;
        int missing,mid;
        while(low<=high){
            
          mid=high+(low-high)/2;
          missing=arr[mid]-(mid+1);

          if(missing<k) low=mid+1;
          else high=mid-1;
        }
        return (high+1+k);//low+k
    }
};
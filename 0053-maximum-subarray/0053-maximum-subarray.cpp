//*********______KADANE'S ALGORITHM=DO NOT CARRY NEGATIVE SUM_____**********
class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        int maxi=nums[0];
        int sum=0;
        for(int i=0;i<nums.size();i++){
          sum+=nums[i];

          if(sum>maxi){
            maxi=sum;
          }
          
          //do not carry negative sum
          if(sum<0)
            sum=0;
          
        }

        //if array contain all negative number then it will return last elemnt so we return 0;
        // if(maxi<0)
        //   maxi=0;

        return maxi;

        
    }
};
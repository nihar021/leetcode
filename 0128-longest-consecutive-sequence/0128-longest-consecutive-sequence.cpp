class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        if(n==0) return 0;
        for(auto num:nums){
            st.insert(num);
        }
        int longest=1;
        
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int ind=it;
                while(st.find(ind+1)!=st.end()){
                    cnt++;
                    ind++;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};
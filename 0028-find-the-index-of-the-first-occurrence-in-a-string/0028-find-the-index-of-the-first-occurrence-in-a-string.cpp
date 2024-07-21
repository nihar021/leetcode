class Solution {
public:
    int strStr(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        //after i>m-n :length of string will be less than n so there is no cahnce of getting n
        for(int i=0;i<=m-n;i++){
           for(int j=0;j<n;j++){
            if(s1[i+j]!=s2[j]){
               break; 
            }
            if(j==n-1){
                return i;
            }
           }
        }
        return -1;
    }
};
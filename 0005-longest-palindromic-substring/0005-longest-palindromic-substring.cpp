class Solution {
public:
    bool solve(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }


    string longestPalindrome(string s) {
        int maxlen=INT_MIN;
        int startPoint=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)==true){
                    if(j-i+1>maxlen){
                        maxlen=j-i+1;
                        startPoint=i;
                 }
            }
          }
        }
        return s.substr(startPoint,maxlen);
    }
};
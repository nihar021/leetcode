class Solution {
public:
    string longestPrefix(string s) {
         int m=s.length();
	    vector<int> LPS(m);
	    int len=0;
	    LPS[0]=0;
	    int i=1;
	    while(i<m){
	        if(s[i]==s[len]){
	            len++;
	            LPS[i]=len;
	            i++;
	        }else{
	            if(len != 0){
	                len=LPS[len-1];
	            }else{
	                LPS[i]=0;
	                i++;
	            }
	        }
	    }
	    return s.substr(0,LPS[m-1]);
    }
};
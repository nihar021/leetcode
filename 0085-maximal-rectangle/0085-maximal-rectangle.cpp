class Solution {
public:
    int lhist(vector<int> &arr){
        stack<int> st;
        int maxArea=0;
        int nse,pse;

        int n=arr.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int element=st.top();
                st.pop();
                nse = i;
                pse =st.empty()?-1:st.top();

                maxArea=max(maxArea, arr[element]*(nse-pse-1));
            }
            st.push(i);
        }

        //if element left over in the stack
        while(!st.empty()){
            int element=st.top();
            st.pop();
            nse=n;
            pse =st.empty()?-1:st.top();
            maxArea=max(maxArea, arr[element]*(nse-pse-1));
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxArea=0;

        //Determine PrefixSumMatrix
        vector<vector<int>> psum(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++) {
                for(int i = 0; i < n; i++) {
                    if(matrix[i][j] == '1') {
                    psum[i][j] = (i == 0 ? 1 : psum[i - 1][j] + 1);
                } else {
                    psum[i][j] = 0;
                }
            }
        }

        //calculate maximum area
        for(int i=0;i<n;i++){
            maxArea=max(maxArea,lhist(psum[i]));
        }
        return maxArea;
    }
};
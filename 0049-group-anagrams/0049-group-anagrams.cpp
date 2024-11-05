class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> umap;
        for(auto str:strs){
            string copy=str;
            sort(copy.begin(),copy.end());
            umap[copy].push_back(str);
        }

        for(auto it:umap){
            vector<string> temp=it.second;
            ans.push_back(temp);
        }

        return ans;
    }
};
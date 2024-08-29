class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.find(endWord) == st.end()) return 0; // If endWord is not in wordList, no solution exists

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()){
            string qword = q.front().first;
            int cnt = q.front().second;
            q.pop();

            for(int j = 0; j < qword.size(); j++){
                string word = qword;
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[j] = ch;
                    if(word == endWord) return cnt + 1; // If the transformed word is the endWord, return the length

                    if(st.find(word) != st.end()){
                        q.push({word, cnt + 1});
                        st.erase(word); // Remove from the set to avoid revisiting
                    }
                }
            }
        }
        return 0; // If no transformation is possible
    }
};

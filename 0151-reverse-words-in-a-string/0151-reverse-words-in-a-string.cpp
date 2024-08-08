#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result;
        int i = 0;
        int n = s.length();
        
        while (i < n) {
            // Skip leading spaces
            while (i < n && s[i] == ' ') i++;
            if (i >= n) break;

            // Find the end of the word
            int j = i + 1;
            while (j < n && s[j] != ' ') j++;

            // Extract the word
            string sub = s.substr(i, j - i);
            if (result.length() == 0)
                result = sub;
            else
                result = sub + " " + result;

            // Move to the next word
            i = j;
        }
        return result;
    }
};

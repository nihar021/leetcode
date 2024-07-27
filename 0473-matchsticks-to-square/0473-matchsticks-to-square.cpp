#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool backtrack(const vector<int>& matchsticks, vector<int>& sides, int index, int target) {
        if (index == matchsticks.size()) {
            // Check if all sides are exactly equal to the target length
            return sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target;
        }
        
        int matchstick = matchsticks[index];
        
        for (int i = 0; i < 4; ++i) {
            if (sides[i] + matchstick <= target) {
                sides[i] += matchstick;
                
                // Recur to place the next matchstick
                if (backtrack(matchsticks, sides, index + 1, target)) return true;
                
                // Backtrack
                sides[i] -= matchstick;
            }
            
            // If current matchstick could not fit in an empty side, no need to try it in other empty sides
            if (sides[i] == 0) break;
        }
        
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int totalLength = 0;
        for (int matchstick : matchsticks) {
            totalLength += matchstick;
        }
        
        // Check if total length is divisible by 4
        if ((totalLength % 4 != 0 )&& (matchsticks.size()<4)) 
          return false;
        
        int target = totalLength / 4;
        
        // Sort matchsticks in descending order to improve efficiency
        sort(matchsticks.rbegin(), matchsticks.rend());
    
        //Check if any of the stick has length more than target,we can"t make square
        if(matchsticks[0]>target)
          return false;
        
        vector<int> sides(4, 0);  // To keep track of the lengths of the 4 sides
        
        return backtrack(matchsticks, sides, 0, target);
    }
    

};

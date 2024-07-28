#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap; // To store the number and its index

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            // Check if the complement is already in the map
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }

            // If not found, add the current number and its index to the map
            numMap[nums[i]] = i;
        }

        // In case no solution is found, though the problem guarantees one
        return {};
    }
};
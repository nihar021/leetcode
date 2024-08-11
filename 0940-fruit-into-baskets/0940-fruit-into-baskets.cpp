class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0, maxlen = 0;
        unordered_map<int, int> fruitCount;

        while (right < fruits.size()) {
            fruitCount[fruits[right]]++;   

            // Game changer
            if (fruitCount.size() > 2) {
                fruitCount[fruits[left]]--;
                if(fruitCount[fruits[left]] == 0)
                    fruitCount.erase(fruits[left]);
                left++;
            }

            if (fruitCount.size() <= 2) {
                // Update the maximum length
                maxlen = max(maxlen, right - left + 1);
            }
            right++;
        }

        return maxlen;
    }
};

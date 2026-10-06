#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Count the frequency of each element
        std::unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        // Step 2: Group numbers by their frequency using buckets
        std::vector<std::vector<int>> freq(n + 1);
        for (auto& pair : count) {
            freq[pair.second].push_back(pair.first);
        }
        
        // Step 3: Collect the top k frequent elements from highest frequency buckets
        std::vector<int> result;
        for (int i = n; i >= 0; --i) {
            for (int num : freq[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        
        return result;
    }
};
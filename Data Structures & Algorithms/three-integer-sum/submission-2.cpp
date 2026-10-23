class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // 1. Sort the array

        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicate elements for i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    
                    // Skip duplicates for j and k
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;

                    j++;
                    k--;
                } 
                else if (sum < 0) {
                    j++; // We need a larger sum, move left pointer right
                } 
                else {
                    k--; // We need a smaller sum, move right pointer left
                }
            }
        }
        return result;
    }
};
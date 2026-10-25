
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        // CHANGED: We need the closest SUM, not a vector of triplets
        // vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());

        // ADDED: Initialize with a valid sum of three elements
        int closestSum = nums[0] + nums[1] + nums[2];

        // CHANGED: i < n - 2, because we need two more elements
        for (int i = 0; i < n - 2; i++) {

            // You can remove duplicate skipping; it is not required
            // if (i > 0 && nums[i] == nums[i - 1])
            //     continue;

            int j = i + 1, k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                // ADDED: Update closestSum if current sum is closer
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }

                // CHANGED: Compare sum with target, NOT zero
                if (sum < target) {
                    j++;
                } 
                else if (sum > target) {
                    k--;
                } 
                else {
                    // ADDED: Exact match found
                    return sum;
                }

                // REMOVED: No need to store triplets in ans
                // ans.push_back({nums[i], nums[j], nums[k]});
            }
        }

        // CHANGED: Return the closest sum, not ans
        return closestSum;
    }
};

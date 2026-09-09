class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int l = 0, r = nums.size() - 1;       // Search boundaries
        int first = -1, last = -1;            // Store first and last positions

        // Find first occurrence
        while (l <= r) {
            int m = l + (r - l) / 2;           // Calculate middle safely

            if (nums[m] == target) {           // Target found
                first = m;                     // Save current index
                r = m - 1;                     // Search further left
            }
            else if (nums[m] < target)         // Target is on the right
                l = m + 1;                     // Move left boundary
            else                               // Target is on the left
                r = m - 1;                     // Move right boundary
        }

        l = 0;                                 // Reset left boundary
        r = nums.size() - 1;                   // Reset right boundary

        // Find last occurrence
        while (l <= r) {
            int m = l + (r - l) / 2;            // Calculate middle safely

            if (nums[m] == target) {            // Target found
                last = m;                      // Save current index
                l = m + 1;                     // Search further right
            }
            else if (nums[m] < target)          // Target is on the right
                l = m + 1;                      // Move left boundary
            else                                // Target is on the left
                r = m - 1;                      // Move right boundary
        }

        return {first, last};                  // Return both positions
    }
};
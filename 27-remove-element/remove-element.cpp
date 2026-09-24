class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int k = nums.size();   // FIX 1: sizeof(nums) → nums.size()
        int index = 0;

        while (index < nums.size()) {   // FIX 2: Don't use range-based for
                                       // because we are erasing elements

            if (nums[index] == val) {
                nums.erase(nums.begin() + index);

                k--;             // Number of valid elements decreases
                // FIX 3: Do NOT increment index here
                // because after erase(), the next element shifts into index
            }
            else {
                index++;          // FIX 4: Move forward only if nothing was erased
            }
        }

        return k;
    }
};
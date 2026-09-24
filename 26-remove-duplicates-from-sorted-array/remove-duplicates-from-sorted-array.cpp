class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write = 0;

        for (int x : nums) {
            if (write == 0 || nums[write - 1] != x) {
                nums[write++] = x;
            }
        }

        return write;
    }
};

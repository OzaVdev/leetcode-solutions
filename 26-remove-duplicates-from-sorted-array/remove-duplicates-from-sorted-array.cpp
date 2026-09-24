class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // write tells us where the next unique element should be placed
        int write = 1;

        // Start from index 1 because nums[0] is always unique
        for (int read = 1; read < nums.size(); read++) {

            // If current element is different from the previous unique element
            if (nums[read] != nums[write - 1]) {

                // Copy the new unique element to the write position
                nums[write] = nums[read];

                // Move write to the next empty position
                write++;
            }
        }

        // write = total number of unique elements
        return write;
    }
};
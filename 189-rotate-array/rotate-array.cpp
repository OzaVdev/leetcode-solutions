class Solution {
public:
    void rotate(vector<int>& nums, int k) {
           int n = nums.size();
        k = k % n;

        int count = 0;
        int start = 0;

        while (count < n) {
            int current = start;
            int prev = nums[start];

            do {
                int next = (current + k) % n;

                int temp = nums[next];
                nums[next] = prev;
                prev = temp;

                current = next;
                count++;

            } while (current != start);

            start++;
        }
    }
};
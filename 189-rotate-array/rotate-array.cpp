class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if (n <= 1) return;

        k %= n;
        if (k == 0) return;

        int count = 0;
        int start = 0;

        while (count < n) {
            int current = start;
            int temp = nums[current];

            do {
                int next = (current + k) % n;

                swap(temp, nums[next]);

                current = next;
                count++;

            } while (current != start);

            start++;
        }
    }
};
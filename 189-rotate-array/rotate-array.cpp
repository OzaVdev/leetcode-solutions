class Solution {
public:
   void rotate(vector<int>& nums, int k) {
    int n = nums.size();
        if (n <= 1) return;

        k %= n;
        if (k == 0) return;

        int cycles = gcd(n, k);

        for (int start = 0; start < cycles; start++) {
            int current = start;
            int temp = nums[current];

            do {
                int next = current + k;

                // Wrap around without using % every time
                if (next >= n)
                    next -= n;

                swap(temp, nums[next]);
                current = next;

            } while (current != start);
        }
    }
};
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n=nums.size();
//         k=k%n;
//         reverse(nums.begin(),nums.end());
//         reverse(nums.begin(),nums.begin()+k);
//         reverse(nums.begin()+k,nums.end());
//     }
// };
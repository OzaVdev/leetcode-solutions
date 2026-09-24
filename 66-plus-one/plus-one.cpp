class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int last = digits.size() - 1;

        // Start from the last digit
        while (last >= 0) {

            // If digit is less than 9, simply add 1
            if (digits[last] < 9) {
                digits[last] += 1;
                return digits;
            }

            // If digit is 9, it becomes 0
            digits[last] = 0;
            last--;
        }

        // If we reach here, all digits were 9
        // Example: 999 -> 1000

        vector<int> result(digits.size() + 1, 0);
        result[0] = 1;

        return result;
    }
};

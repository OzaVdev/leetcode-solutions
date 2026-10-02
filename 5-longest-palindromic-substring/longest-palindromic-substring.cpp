class Solution {
public:

    // Expand from the center and return palindrome length
    int expand(string &s, int left, int right) {

        while (left >= 0 && right < s.length() &&
               s[left] == s[right]) {

            left--;
            right++;
        }

        // Length of palindrome
        return right - left - 1;
    }

    string longestPalindrome(string s) {

        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < s.length(); i++) {

            // Odd length palindrome
            int len1 = expand(s, i, i);

            // Even length palindrome
            int len2 = expand(s, i, i + 1);

            int len = max(len1, len2);

            // Update longest palindrome
            if (len > maxLength) {

                maxLength = len;

                // Find starting index
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }
};
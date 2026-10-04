class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check sign
        int sign = 1;

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        // 3. Convert digits
        long long number = 0;

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            number = number * 10 + digit;

            // 4. Check overflow
            if (sign == 1 && number > INT_MAX) {
                return INT_MAX;
            }

            if (sign == -1 && number > 2147483648LL) {
                return INT_MIN;
            }

            i++;
        }

        // 5. Apply sign
        return number * sign;
    }
};
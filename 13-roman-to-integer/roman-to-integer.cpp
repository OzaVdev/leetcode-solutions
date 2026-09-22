class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> value = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int number = 0;

        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && value[s[i]] < value[s[i + 1]]) {
                number -= value[s[i]];
            } else {
                number += value[s[i]];
            }
        }

        return number;
    }
};
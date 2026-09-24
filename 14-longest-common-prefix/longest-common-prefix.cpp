class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }

        // Result can never be longer than the first string
        int first_length = strs[0].size();

        string result = "";

        int result_index = 0;

        // i = character position
        for (int i = 0; i < first_length; i++) {

            // Take current character from first string
            char current_chr = strs[0][i];

            // j = string number
            for (int j = 1; j < strs.size(); j++) {

                // String ended OR character doesn't match
                if (i >= strs[j].size() || strs[j][i] != current_chr) {
                    return result;
                }
            }

            // All strings had the same character
            result += current_chr;
            result_index++;
        }

        return result;
    }
};

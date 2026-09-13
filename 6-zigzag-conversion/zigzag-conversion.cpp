class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();

        // No zigzag needed
        if (numRows == 1 || numRows >= n)
            return s;

        string result;
        int cycle = 2 * numRows - 2;

        // Process each row of the zigzag
        for (int row = 0; row < numRows; row++) {

            // Add vertical characters
            for (int j = row; j < n; j += cycle) {
                result += s[j];

                // Add diagonal character for middle rows
                int diagonal = j + cycle - 2 * row;

                if (row != 0 && row != numRows - 1 && diagonal < n)
                    result += s[diagonal];
            }
        }

        return result;
    }
};
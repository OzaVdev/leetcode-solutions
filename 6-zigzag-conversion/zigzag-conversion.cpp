class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.length())
            return s;

        vector<string> rows(numRows);

        int row = 0;
        int direction = 1;

        for(int i = 0; i < s.length(); i++) {
            rows[row] += s[i];

            if(row == 0)
                direction = 1;

            if(row == numRows - 1)
                direction = -1;

            row += direction;
        }

        string answer = "";

        for(int i = 0; i < numRows; i++) {
            answer += rows[i];
        }

        return answer;
    }
};
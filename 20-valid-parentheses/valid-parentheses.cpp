class Solution {
public:
    bool isValid(string s) {
        // Stack stores opening brackets
        stack<char> st;

        for (char c : s) {

            // If it's an opening bracket, push it onto the stack
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            else {
                // If there is no opening bracket to match
                if (st.empty()) {
                    return false;
                }

                // Get the most recent opening bracket
                char top = st.top();
                st.pop();

                // Check if the brackets match
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }
            }
        }

        // Valid only if all opening brackets were closed
        return st.empty();
    }
};
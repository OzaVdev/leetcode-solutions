class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0, 0};

        // Count how many students want 0 and 1
        for (int student : students) {
            count[student]++;
        }

        // Process sandwiches
        for (int sandwich : sandwiches) {
            if (count[sandwich] == 0)
                break;

            count[sandwich]--;
        }

        return count[0] + count[1];
    }
};
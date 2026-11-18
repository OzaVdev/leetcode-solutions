class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //First Pair 
        int a = edges[0][0];

        // Second Element 
        int c = edges[1][0];
        int d= edges[1][1];

        if(a==c || a==d)
            return a;
    
    return edges[0][1];
    }
};
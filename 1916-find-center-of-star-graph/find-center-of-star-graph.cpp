class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //First Pair 
        int a = edges[0][0];

        if(a==edges[1][0] || a==edges[1][1])
            return a;
    
    return edges[0][1];
    }
};
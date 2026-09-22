class Solution {
public:
    int value(char n)
    {
        if(n == 'I') return 1;
        if(n == 'V') return 5;
        if(n == 'X') return 10;
        if(n == 'L') return 50;
        if(n == 'C') return 100;
        if(n == 'D') return 500;
        if(n == 'M') return 1000;
        return 0;
    }
    int romanToInt(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if( i+1 < n && value(s[i+1]) > value(s[i]))
            {
                ans += (value(s[i+1]) - value(s[i]));
                i++;
            }
            else
            {
                ans += value(s[i]);
            }
        }
        return ans;
    }
};
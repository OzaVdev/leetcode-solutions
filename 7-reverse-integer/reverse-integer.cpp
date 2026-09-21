class Solution {
public:
    int reverse(int x) {
        double reminder;
    int rev=0;
    while(x!=0){
        if (rev > 214748364 || (rev == 214748364 && reminder > 7))
            return 0;

        if (rev < -214748364 || (rev == -214748364 && reminder < -8))
            return 0;
        reminder=x%10;
        rev=(rev*10)+reminder;
        x=x/10;
    }
    return rev;
    }
};
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        long long power=n;
        bool neg=false;
        if(power<0){
            neg=true;
            power=-power;
        }
        double ans=1.0;
        while(power>0){
            if(power%2==1) ans=ans*x;
            x=x*x;
            power/=2;
        }
        if(neg) return 1.0/ans;
        return ans;
    }
};
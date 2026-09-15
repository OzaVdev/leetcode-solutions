class Solution {
public:
    bool isPalindrome(int x) {
        // Handle invalid cases 
        if (x < 0 || (x % 10 == 0 && x != 0)) 
            return false;
        int reverseHalf = 0; 
        // Reverse half of the number 
        while (x > reverseHalf) {
            reverseHalf = reverseHalf * 10 + x % 10; 
            x /= 10; 
        } 
        // Check even and odd digit cases 
        return x == reverseHalf || x == reverseHalf / 10; 
        }
};
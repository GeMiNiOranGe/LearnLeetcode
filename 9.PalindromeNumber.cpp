class Solution {
public:
    bool isPalindrome(int x) {
        long reversed = 0, original = x;
        while (x > 0) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        return (reversed == original);
    }
};

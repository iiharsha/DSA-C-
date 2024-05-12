#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    bool isPalindrome (long long x) {
        if (x < 0 || x !=0 && x%10 == 0) {
            return false;
        }
        long long temp = x;
        long long reversed = 0;
        while (temp > 0) {
            long long y =  temp %10;
            reversed = reversed * 10 + y;
            temp = temp/10;
        }
        return x == reversed;

    }
};

int main() {
Solution sol;
cout<<sol.isPalindrome(121212121212121);
}
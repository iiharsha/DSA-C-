#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
int romanToInt (string s) {
    int ans = 0;
    unordered_map<char,int> symbolval {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int n = s.size();
    for (int i = 0; i <=n;i++) {
        int val1 = symbolval[s[i]];
        int val2 = symbolval[s[i  + 1]];
        if(val1 < val2) {
            ans = ans + val2 - val1;
            i++;
        }else {
            ans = ans + val1;
        }
    }
return ans;

}

};



int main() {
Solution sol;
string s = "III";
cout<<sol.romanToInt(s);
return 0;
}
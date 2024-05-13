#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";//return empty string if empty string found
        int i = 0;

        sort(strs.begin(), strs.end());//sort the input string elements lexicographically

        string first = strs.front();//take the first element after sorting 
        string last =  strs.back();//take the last element after sorting 

        while (i<first.size() && first[i] == last[i]) {
            i++;
        }
        return first.substr(0, i);// return the substring of first iterated in the while loop buffer
    }   
};

int main() {
    Solution sol;
    vector<string>strs = {"flower","flow","flight"};
    cout<<sol.longestCommonPrefix(strs);
    return 0;
}
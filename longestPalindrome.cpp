#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  static int longestPalindrome(string s) {
    if (s.length() == 1)
      return s.length();

    unordered_map<char, int> freq;
    for (char c : s) {
      freq[c]++;
    }

    int len = 0;
    bool isOdd = false;

    for (const auto &pair : freq) {
      int count = pair.second;
      if (count % 2 == 0) {
        len += count;
      } else {
        len += count - 1;
        isOdd = true;
      }
    }
    return len + isOdd;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;
  string s = "abccccdd";
  cout << sol.longestPalindrome(s) << endl;

  return 0;
}

/*A word is considered valid if:

It contains a minimum of 3 characters.
It contains only digits (0-9), and English letters (uppercase and lowercase).
It includes at least one vowel.
It includes at least one consonant.
You are given a string word.

Return true if word is valid, otherwise, return false.
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValid(string word) {
    bool num = 0, vowel = 0, conso = 0;
    for (int i = 0; i < word.size(); i++) {
      char lw = tolower(word[i]);
      if (!isalnum(word[i]))
        return false;
      else if (word[i] >= '0' && word[i] <= '9')
        num = 1;
      else if (lw == 'a' || lw == 'e' || lw == 'i' || lw == 'o' || lw == 'u')
        vowel = 1;
      else
        conso = 1;
    }
    return (conso && vowel);
  }
};

int main() {
  Solution sol;
  string word;
  cout << "Enter a word: ";
  cin >> word;
  bool exec = sol.isValid(word);
  cout << exec << "\n";
  return 0;
}

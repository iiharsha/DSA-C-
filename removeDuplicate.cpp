#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicate(vector<int> &nums) {
    int l = 1;
    int n = nums.size();

    for (int r = 1; r < n; r++) {
      if (nums[r] != nums[r - 1]) {
        nums[l] = nums[r];
        l++;
      }
    }
    return l;
  }
};

int main() {
  Solution sol;

  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

  int newLength = sol.removeDuplicate(nums);

  cout << "Length of the new array is : " << newLength << endl;
  cout << "Modified Array: ";

  for (int i = 0; i < newLength; i++) {
    cout << nums[i] << " ";
  }

  cout << endl;
  return 0;
}

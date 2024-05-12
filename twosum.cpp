#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public: 
    vector<int>twosum(vector<int>&nums,int target) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                }
                return res;
            }
        }
        return res;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> result = solution.twosum(nums, target);
    for (int num : result) {
        cout<<num<<" ";
    }
}
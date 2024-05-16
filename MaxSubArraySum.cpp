#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArraySum(int arr[], int size) {
        int max_sum = INT_MIN;
        int curr = 0;

        for (int i = 0; i < size; i++) {
            curr += arr[i];
            if (max_sum < curr) {
                max_sum = curr;
            }

            if (curr < 0) {
                curr = 0;
            }
        }
        return max_sum;
    }
};


int main() {
Solution sol;
int arr[] = {-2,7,-3,4};
int n = sizeof(arr) / sizeof(arr[0]);
int res =  sol.maxSubArraySum(arr, n);
cout<<"Maximum SubArray Sum is "<<res;
return 0;
}
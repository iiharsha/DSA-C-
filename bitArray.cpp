#include <bits/stdc++.h>
using namespace std;

int main() {
  unsigned long long n, s, p, q, v, i;
  cin >> n >> s >> p >> q;
  v = pow(2, 31);
  int count;
  vector<int> arr(n);
  arr[0] = s % v;

  for (i = 1; i < n; i++) {
    arr[i] = (arr[i - 1] * p) + q;
    arr[i] = arr[i] % v;

    if (arr[i] == arr[0] || arr[i] == arr[i - 1] && arr[i] != 0) {
      count++;
      break;
    }
  }
  if (i == n) {
    count = i;
  }
  cout << count << "\n";
  return 0;
}

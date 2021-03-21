#include <limits.h>

#include <iostream>
#include <vector>

int max(int a, int b) { return (a > b) ? a : b; }
int max(int a, int b, int c) { return max(max(a, b), c); }

int maxCrossingSum(const std::vector<int>& arr, int l, int m, int h) {
  int sum = 0;
  int left_sum = INT_MIN;
  for (int i = m; i >= l; i--) {
    sum = sum + arr[i];
    if (sum > left_sum) left_sum = sum;
  }

  sum = 0;
  int right_sum = INT_MIN;
  for (int i = m + 1; i <= h; i++) {
    sum = sum + arr[i];
    if (sum > right_sum) right_sum = sum;
  }

  return max(left_sum + right_sum, left_sum, right_sum);
}

int maxSubArraySum(const std::vector<int>& arr, int l, int h) {
  if (l == h) return arr[l];

  int m = (l + h) / 2;
  return max(maxSubArraySum(arr, l, m), maxSubArraySum(arr, m + 1, h),
             maxCrossingSum(arr, l, m, h));
}

int main(int argc, char** argv) {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    std::cin >> n;
    std::vector<int> arr;
    arr.resize(n);

    for (int j = 0; j < n; j++) {
      std::cin >> arr[j];
    }
    std::cout << maxSubArraySum(arr, 0, n - 1) << std::endl;
  }

  return 0;
}
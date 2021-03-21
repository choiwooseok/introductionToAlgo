#include <limits.h>

#include <iostream>
#include <vector>

int max(int a, int b) { return (a > b) ? a : b; }

int dp[1001];

int main(int argc, char** argv) {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    std::cin >> n;

    std::vector<int> arr;
    arr.resize(n + 1);

    int ret = INT_MIN;

    for (int j = 1; j <= n; j++) {
      std::cin >> arr[j];
    }

    for (int j = 1; j <= n; j++) {
      // j 번째 원소로 끝나는 부분 합의 최대
      // 음수면 제거
      dp[j] = max(0, dp[j - 1]) + arr[j];
      ret = max(ret, dp[j]);
    }

    std::cout << ret << std::endl;
  }

  return 0;
}
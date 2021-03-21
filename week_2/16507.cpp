#include <iostream>
#include <vector>

long long sum[1001][1001];

int main(int argc, char** argv) {
  int r, c, q;

  std::cin >> r >> c >> q;
  std::vector<std::vector<int> > RC(r, std::vector<int>(c));

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      std::cin >> RC[i][j];
      sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + RC[i][j];
    }
  }

  for (int i = 0; i < q; i++) {
    int r1, c1, r2, c2;
    std::cin >> r1 >> c1 >> r2 >> c2;

    long long ret =
        sum[r2][c2] - sum[r1 - 1][c2] - sum[r2][c1 - 1] + sum[r1 - 1][c1 - 1];

    std::cout << ret / ((r2 - r1 + 1) * (c2 - c1 + 1)) << std::endl;
  }

  return 0;
}
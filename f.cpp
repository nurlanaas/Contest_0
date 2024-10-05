#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  int m;
  int l;
  int ans = 0;
  std::cin >> n >> m >> l;
  std::vector<std::vector<int>> a(n, std::vector<int>(l, 0));
  std::vector<std::vector<int>> b(m, std::vector<int>(l, 0));
  for (int w = 0; w < n; w++) {
    for (int j = 0; j < l; j++) {
      std::cin >> a[w][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < l; j++) {
      std::cin >> b[i][j];
    }
  }
  int q;
  std::cin >> q;
  const int cInf = 1000000;
  for (int p = 0; p < q; p++) {
    int i;
    int j;
    std::cin >> i >> j;
    j--;
    i--;
    int mid;
    int mx = cInf;
    int le = -1;
    int r = l;
    while (r - le > 1) {
      mid = (r + le) / 2;
      if (std::max(a[i][mid], b[j][mid]) < mx) {
        mx = std::max(a[i][mid], b[j][mid]);
        ans = mid + 1;
      }
      if (a[i][mid] >= b[j][mid]) {
        r = mid;
      } else {
        le = mid;
      }
    }
    std::cout << ans << "\n";
  }
}
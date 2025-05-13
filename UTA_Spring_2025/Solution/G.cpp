#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1000, inf = 1e9;
int n, m, arr[mxN][mxN], cnt[10][mxN], dp[mxN][10];

int f(int row, int last) {
  if (row == n) return 0;
  if (last != -1 and dp[row][last] != -1) return dp[row][last];
  int x = inf;
  for (int i = 0; i < 10; ++i) {
    if (i != last) x = min(x, m - cnt[i][row] + f(row + 1, i));
  }
  return dp[row][last] = x;
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
      cnt[arr[i][j]][i]++;
    }
  }  
  memset(dp, -1, sizeof(dp));
  cout << f(0, -1) << "\n";
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // int tc; cin >> tc;
  // while (tc--)
    solve();

  return 0;
}

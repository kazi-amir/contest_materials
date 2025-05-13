#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 1e9;
int X[] = {-1, 0, 1, 0};
int Y[] = {0, -1, 0, 1};
int n, m;

bool valid (int x, int y) {
  return (x >= 0 and x < n and y >= 0 and y < m);
};

void solve() {
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) cin >> grid[i];
  vector<vector<int>> dist(n, vector<int>(m, inf));
  queue<pair<int, int>> q;
  q.push({n - 1, m - 1});
  dist[n- 1][m - 1] = 0;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = x + X[i];
      int ny = y + Y[i];
      if (valid(nx, ny) and grid[nx][ny] != '#' and dist[nx][ny] == inf) {
        dist[nx][ny] = dist[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }
  int k; cin >> k;
  vector<int> all(k), pf(k), sf(k);
  for (int i = 0; i < k; ++i) {
    int x, y; cin >> x >> y, --x, --y;
    all[i] = dist[x][y], pf[i] = ((i == 0) ? all[i] : min(all[i], pf[i-1]));
  }
  sf[k - 1] = all[k - 1];
  for (int i = k - 2; i >= 0; --i) sf[i] = min(all[i], sf[i + 1]);
  int Q; cin >> Q;
  while (Q--) {
    int x; cin >> x, --x;
    if (k == 1) {
      cout << -1 << "\n";
      continue;
    }
    int mn = inf;
    if (x == 0) mn = sf[x + 1];
    else if (x == k - 1) mn = pf[x - 1];
    else mn = min(pf[x - 1], sf[x + 1]);
    cout << ((mn == inf) ? -1 : mn) << "\n";
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // int tc; cin >> tc;
  // while (tc--)
    solve();

  return 0;
}

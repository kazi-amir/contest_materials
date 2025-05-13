#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int children[N], par[N];
vector<int> adj[N];

void dfs(int u, int p = 0) {
  int cnt = 0;
  for (auto v: adj[u]) {
    if (v == p) continue;
    cnt++;
    par[v] = u;
    dfs(v, u);
  }
  children[u] = cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1);

  for (int i = 2; i <= n; ++i) {
    int p = par[i];
    cout << children[p] - 1 << " ";
  }
  cout << '\n';

  return 0;
}
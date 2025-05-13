#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
  ll a, b, x; cin >> a >> b >> x;
  assert(a >= 1 and a <= 1e9 and b >= 1 and b <= 1e9 and x >= 1 and x <= 1e18);
  cout << a * b + 2 * x << "\n";
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  // int tc; cin >> tc;
  // while(tc--)
    solve();

  return 0;
}
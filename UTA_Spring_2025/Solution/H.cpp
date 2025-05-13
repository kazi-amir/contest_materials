#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>&a, pair<int, int>&b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main() {
    int n, k; cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    vector<pair<int, int>> v;
    for (auto x : mp) {
        v.push_back({x.second, x.first});
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < min((int)v.size(), k); i++) {
        cout << v[i].second << ' ';
    }
    cout << '\n';
    return 0;
}
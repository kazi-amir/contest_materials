#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    int mn = INT_MAX;
    for(int i = 2; i<n; i++){
      mn = min(mn, v[i]-v[i-2]);
    }
    cout<<mn<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tcase = 1; 
    //cin>>tcase;
    for(int tc = 1; tc<=tcase; tc++){
        // cout<<"Case #"<<tc<<": ";
        solve();
    }
}
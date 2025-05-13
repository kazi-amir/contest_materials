#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int X = 1e6+5;
int timeline[X];

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i<n; i++){
      cin>>a[i];
    }
    for(int i = 0; i<n; i++){
      cin>>b[i];
    }
    for(int i = 0; i<n; i++){
      timeline[a[i]]++;
      timeline[b[i]+1]--;
    }
    int mx = 0;
    for(int i = 1; i < X; i++){
      timeline[i] += timeline[i-1];
      mx = max(mx, timeline[i]);
    }
    cout<<max(0, mx-1)<<endl;
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
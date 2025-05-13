#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define endl '\n'
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
using namespace std;



void solve() {
    int64_t a,b;
    cin>>a>>b;
    int64_t cnt=0,consume=0;
    while(a>0){
        consume+=b;
        if(consume<=50) a-=(10*b);
        else if(consume>=51 and consume<=80) a-=(15*b);
        else if(consume>=81 and consume<=100) a-=(20*b);
        else {
            cnt+=(a/(25*b));
            break;
        }
        cnt++;
    }
    cout<<cnt<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
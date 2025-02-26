#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
set<int> vis1,vis2;
void solve()
{
    vis1.clear();
    vis2.clear();
    int n;
    cin>>n;
    inc(i,1,n)
    {
        int tmp;
        cin>>tmp;
        vis1.insert(tmp);
    }
    inc(i,1,n)
    {
        int tmp;
        cin>>tmp;
        vis2.insert(tmp);
    }
    if(vis1.size()*vis2.size()>=3&&n>=3)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    cin>>_;
    while(_--)solve();
    system("pause");
}
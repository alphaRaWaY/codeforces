#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
int n,m;
void solve()
{
    cin>>n>>m;
    if(n==m)
    {
        if(n==1)cout<<1<<endl;
        else cout<<0<<endl;
    }
    else
    {
        cout<<m-n<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    cin>>_;
    while(_--)solve();
    system("pause");
}
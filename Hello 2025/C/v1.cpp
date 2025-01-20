#include<bits/stdc++.h>
using namespace std;
// #define DEBUG
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
int m,n;
int a,b,c;
void solve()
{
    cin>>m>>n;
    int len(0),counter(n);
    while(counter)
    {
        counter>>=1;
        len++;
    }
    // cout<<len<<endl;
    int mod1((1<<len)-2),mod2(mod1-1);
    dec(i,n,m)
    {
        a=i;
        b=(a^mod1);
        c=(a^mod2);
        if(m<=b&&b<=n&&
        m<=c&&c<=n)break;
    }
    cout<<a<<" "<<b<<" "<<c<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    cin>>_;
    while(_--)solve();
    system("pause");
}


/*
8
0 2
0 8
1 3
6 22
128 137
69 98
115 127
0 1073741823

*/
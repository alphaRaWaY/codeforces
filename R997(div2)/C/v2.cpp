#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int INF(0x3f3f3f3f);
int ls(int a){return a<<1;}
int rs(int a){return a<<1|1;}
const int MAXN(1e3+3);
int n;
void solve()
{
    cin>>n;
    if(n==6)
    {
        cout<<"1 1 2 3 1 2";
    }
    else if(n&1)
    {
        inc(i,1,n/2+1)cout<<i<<" ";
        inc(i,1,n/2)cout<<i<<" ";
    }
    else
    {
        inc(i,1,n/2)cout<<i<<" ";
        inc(i,1,n/2)cout<<i<<" ";
    }
    cout<<endl;
}
signed main()
{
    // ios::sync_with_stdio(false);
    int _;
    cin>>_;
    while(_--)solve();
    system("pause");
}
/*
10
6
7
8
9
12
13
15
20
23
30
*/
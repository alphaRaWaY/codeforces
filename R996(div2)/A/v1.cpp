#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
int n,a,b;
void solve()
{
    cin>>n>>a>>b;
    cout<<((abs(a-b)&1)?"NO":"YES")<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    cin>>_;
    while(_--)solve();
}
/*
5
2 1 2
3 3 1
4 2 3
5 2 4
7 6 2

*/
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
vector<int> ans[3]={{1,1,2,3,1,2,2,3},{1,3,3,1,2,3,1,1,3},{1,2,2,2,1,3,2,4,1,3,2,1,1,1,2}};
void solve()
{
    cin>>n;
    if(n<9)
    {
        inc(i,0,n-1)
        {
            cout<<ans[0][i]<<" ";
        }
        cout<<endl;
    }
    else if(9<=n&&n<15)
    {
        inc(i,0,n-1)
        {
            if(i<ans[1].size())cout<<ans[1][i]<<" ";
            else cout<<i<<" ";
        }
        cout<<endl;
    }
    else 
    {
        inc(i,0,n-1)
        {
            if(i<ans[2].size())cout<<ans[2][i]<<" ";
            else cout<<i<<" ";
        }        
        cout<<endl;
    }
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
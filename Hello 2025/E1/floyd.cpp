#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(5e2+5),INF(0x3f3f3f3f);
int n,m;
int dis[MAXN][MAXN],tmp[MAXN][MAXN];
int g[MAXN][MAXN];
void solve()
{
    memset(g,0,sizeof(g));
    cin>>n>>m;
    inc(i,1,m)
    {
        int a,b,w;
        cin>>a>>b>>w;
        g[a][b]=g[b][a]=w;
    }
    inc(i,1,n)
    {
        inc(j,1,n)
        {
            if(g[i][j])dis[i][j]=g[i][j];
            else if(i==j)dis[i][j]=0;
            else dis[i][j]=INF;
        }
    }
    inc(i,1,n)
    {
        inc(j,1,n)inc(k,1,n)tmp[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
        inc(j,1,n)inc(k,1,n)dis[j][k]=tmp[j][k];
    }
    inc(i,1,n)
    {
        inc(j,1,n)cout<<dis[i][j]<<" ";cout<<endl;
    }
}
signed main()
{
    // ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--)solve();
    system("pause");
}
/*
6 10
1 2 4
1 3 6
1 4 8
1 6 1
2 3 3
2 4 2
2 6 2
3 6 6
4 5 7
5 6 1
*/
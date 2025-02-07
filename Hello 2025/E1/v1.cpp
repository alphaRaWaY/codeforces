#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(405),INF(0x3f3f3f3f);
int n,m,q;
struct node{
    int a,b,w;
    bool operator < (const node& e) const{
        return w<e.w;
    }
}g[MAXN*MAXN];
/*
dp[k][a][b]含义：
在边g按权重不减排序的情况下
存在一条从a到b的路径P
使得e[k]在P上为dp[k][a][b]+1大的边
*/
int dp[MAXN][MAXN][MAXN];
int initialW[MAXN];
void solve()
{
    cin>>n>>m>>q;
    inc(i,1,m)
    {
        cin>>g[i].a>>g[i].b>>g[i].w;
        if(g[i].a>g[i].b)swap(g[i].a,g[i].b);
    }
    sort(g+1,g+m+1);
    inc(i,1,m)initialW[i]=g[i].w,g[i].w=1;
    inc(i,1,n)
    {
        inc(j,1,n)
        if(i==j)dp[0][i][j]=0;
        else dp[0][i][j]=INF;
    }
    inc(i,1,m)
    {
        auto[u,v,weight] = g[i];
        dp[0][u][v]=dp[0][v][u]=weight;
    }
    inc(i,1,n)inc(j,1,n)inc(k,1,n)dp[0][j][k]=min(dp[0][j][k],dp[0][j][i]+dp[0][i][k]);
    inc(i,1,m)
    {
        auto[u,v,weight]=g[i];
        inc(j,1,n)
        inc(k,1,n)
        dp[i][j][k]=min(dp[i-1][j][k],min(dp[i-1][j][u]+dp[i-1][v][k],dp[i-1][j][v]+dp[i-1][u][k]));
    }
    // inc(i,0,m)cout<<dp[i][1][4]<<" ";cout<<endl;
    while(q--)
    {
        int v,u,k;
        cin>>u>>v>>k;
        if(v<u)swap(u,v);
        int l(0),r(m);
        while(r-l>1)
        {
            int mid(((r-l)>>1)+l);
            if(dp[mid][u][v]<=k-1)r=mid;
            else l=mid;
        }
        cout<<initialW[r]<<" ";
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
    system("pause");
}
/*
3
4 4 2
1 2 2
2 4 2
1 3 4
3 4 1
1 4 2
2 3 1
6 7 3
1 2 10
2 3 3
3 4 9
4 5 2
5 6 1
2 4 10
4 6 10
1 6 3
1 6 2
2 4 1
11 17 10
1 4 5
1 3 19
1 2 10
3 2 13
4 5 1
4 6 11
3 5 9
3 6 18
2 7 17
5 8 15
5 10 8
6 9 4
7 10 20
7 8 16
8 11 3
9 11 6
10 11 14
3 11 1
3 11 3
1 11 1
1 11 4
1 11 3
8 2 2
10 4 1
3 9 2
3 9 1
6 7 3

*/
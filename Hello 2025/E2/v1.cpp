//dp只需要一层用于滚动数组，三维会 
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
vector<int>dp[MAXN][MAXN],ans[MAXN][MAXN];
int initialW[MAXN*MAXN];
void solve()
{
    cin>>n>>m>>q;
    inc(i,1,n)inc(j,1,n)dp[i][j].clear(),ans[i][j].clear();
    inc(i,1,m)cin>>g[i].a>>g[i].b>>g[i].w;
    sort(g+1,g+m+1);
    inc(i,1,m)initialW[i]=g[i].w,g[i].w=1;
    inc(i,1,n)
    {
        inc(j,1,n)
        {
            ans[i][j].push_back(1);
            if(i==j)dp[i][j].push_back(0);
            else dp[i][j].push_back(INF);
        }
    }
    inc(i,1,m)
    {
        auto[u,v,weight] = g[i];
        dp[u][v][0]=dp[v][u][0]=weight;
    }
    inc(i,1,n)inc(j,1,n)inc(k,1,n)dp[j][k][0]=min(dp[j][k][0],dp[j][i][0]+dp[i][k][0]);
    inc(i,1,m)
    {
        auto[u,v,weight]=g[i];
        if(dp[u][v].back()&&dp[v][u].back())
        {
            inc(j,1,n)
            inc(k,1,n)
            {
                int tmp=min(dp[j][k].back(),min(dp[j][u].back()+dp[v][k].back(),dp[j][v].back()+dp[u][k].back()));
                if(tmp!=dp[j][k].back())dp[j][k].push_back(tmp),ans[j][k].push_back(i);
            }
        }
    }
    while(q--)
    {
        int v,u,k;
        cin>>u>>v>>k;
        if(ans[u][v].size()<k)cout<<initialW[1]<<" ";
        else cout<<initialW[ans[u][v][ans[u][v].size()-k]]<<" ";
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
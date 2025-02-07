#include<bits/stdc++.h>
using namespace std;
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
struct node{
    int a,b,w;
    bool operator< (const node & n) const {
        return w<n.w;
    }
};
const int MAXN(405),INF(0x3f3f3f3f);
int fa[MAXN];
int fd(int a){return fa[a]==a?a:fa[a]=fd(fa[a]);}
int n,m,q;
int dp[MAXN][MAXN];
vector<int> ans[MAXN][MAXN];
node g[MAXN*MAXN];
void solve()
{
    cin>>n>>m>>q;
    inc(i,1,n)fa[i]=i;
    inc(i,1,n)inc(j,1,n)ans[i][j].clear();
    inc(i,1,m)
    {
        cin>>g[i].a>>g[i].b>>g[i].w;
    }
    sort(g+1,g+1+m);
    inc(i,1,n)inc(j,1,n)dp[i][j]=INF*(i!=j);
    inc(i,1,m)
    {
        auto[p1,p2,w]=g[i];
        dp[p1][p2]=dp[p2][p1]=1;
    }
    inc(i,1,n)inc(j,1,n)inc(k,1,n)dp[j][k]=min(dp[j][i]+dp[i][k],dp[j][k]);
    inc(i,1,m)
    {
        auto[p1,p2,w]=g[i];
        if(fd(p1)==fd(p2))continue;
        fa[fd(p1)]=fa[fd(p2)];
        inc(j,1,n)
        inc(k,1,n)
        {
            int tmp(min(dp[j][p1]+dp[p2][k],dp[j][p2]+dp[p1][k]));
            if(tmp<dp[j][k])ans[j][k].push_back(g[i].w);
            dp[j][k]=min(tmp,dp[j][k]);
        }
    }
    while(q--)
    {
        int a,b,k;
        cin>>a>>b>>k;
        if(ans[a][b].size()>=k)cout<<ans[a][b][ans[a][b].size()-k]<<" ";
        else cout<<0<<" ";
    }
    cout<<endl;
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
*/
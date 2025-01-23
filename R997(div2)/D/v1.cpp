#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int INF(0x3f3f3f3f);
int ls(int a){return a<<1;}
int rs(int a){return a<<1|1;}
const int MAXN(1e5+5);
int n;
bool isOdd;
int nums[MAXN],weight[MAXN][20];
int ans(0);
map<int,int> cnt[20];
set<int> s[20];
void solve()
{
    inc(i,1,10)
    {
        s[i].clear();
        cnt[i].clear();
    }
    ans=0;
    cin>>n;
    inc(i,1,n)
    {
        inc(j,1,10)weight[i][j]=0;
        cin>>nums[i];
    }
    inc(i,1,n)
    {
        inc(j,1,10)
        {
            weight[i][j]=weight[i-1][j];
        }
        inc(j,1,nums[i])weight[i][j]++;
        dec(j,10,nums[i]+1)weight[i][j]--;
    }
    inc(i,0,n)
    {
        inc(j,1,10)
        {
            cnt[j][weight[i][j]]++;
            if(cnt[j][weight[i][j]]==2)s[j].insert(weight[i][j]);
        }
    }
    inc(i,1,10)
    {
        for(int tmp:s[i])
        {
            int a=cnt[i][tmp];
            ans+=a*(a-1)/2;
        }
    }
    ans=(n+1)*n/2-ans;
    cout<<ans<<endl;
    
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
3
4
1 1 1 1
5
1 10 2 3 3
10
6 3 2 3 5 3 4 2 3 5

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(305);
int n;
int nums[MAXN][MAXN],cnt[MAXN];
void solve()
{
    cin>>n;
    inc(i,1,n)cnt[i]=0;
    inc(i,1,n)inc(j,1,n)cin>>nums[i][j];
    inc(i,1,n)
    {
        dec(j,n,1)
        {
            if(nums[i][j]!=1)break;
            cnt[i]++;
        }
    }
    sort(cnt+1,cnt+1+n);
    int jud(0);
    inc(i,1,n)
    {
        if(cnt[i]>=jud)
        {   
            jud++;
        }
    }
    cout<<jud<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    cin>>_;
    while(_--)solve();
}
/*
100
5
1 1 1 1 1
23 1 1 1 1
2 4 1 1 1
6 34 3 1 1
2 1 1 5 1
1
12
*/
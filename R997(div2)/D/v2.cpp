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
int n,ans;
int nums[MAXN],b[MAXN];
map<int,int>cnt;
void solve()
{
    ans=0;
    cin>>n;
    inc(i,1,n)cin>>nums[i];
    inc(x,1,11)
    {
        cnt.clear();
        inc(i,1,n)b[i]=nums[i]<=x?1:-1;
        partial_sum(b+1,b+1+n,b+1);
        int pos(0);
        inc(i,1,n)
        {
            //保证统计的区间里面包含x
            if(nums[i]==x)
            {
                while(pos<i)
                {
                    cnt[b[pos]]++;
                    pos++;
                }
            }
            ans+=cnt[b[i]];
        }
    }
    ans=n*(n+1)/2-ans;
    cout<<ans<<endl;
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
3
4
1 1 1 1
5
1 10 2 3 3
10
6 3 2 3 5 3 4 2 3 5

*/
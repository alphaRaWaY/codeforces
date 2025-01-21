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
int nums[MAXN];
map<int,int> cnt[2];
void solve()
{
    cnt[0].clear();
    cnt[1].clear();
    cin>>n;
    isOdd=(n&1);
    inc(i,1,n)cin>>nums[i];

}
signed main()
{
    // ios::sync_with_stdio(false);
    int _;
    cin>>_;
    while(_--)solve();
    system("pause");
}
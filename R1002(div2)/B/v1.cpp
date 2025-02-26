#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
set<int> vis1,vis2;
const int MAXN(2e5+5);
int n,k;
int nums[MAXN];
void solve()
{
    cin>>n>>k;
    inc(i,1,n)
    {
        cin>>nums[i];
    }
    nums[n+1]=0;
    if(n==k)
    {
        inc(i,1,(n/2))
        {
            if(nums[i*2]!=i)
            {
                cout<<i<<endl;
                return;
            }
        }
        cout<<n/2+1<<endl;
        return;
    }
    else
    {
        inc(i,2,n-k+2)
        {
            if(nums[i]!=1)
            {
                cout<<1<<endl;
                return;
            }
        }
        cout<<2<<endl;
        return;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    cin>>_;
    while(_--)solve();
    system("pause");
}
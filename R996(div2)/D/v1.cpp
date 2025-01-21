
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(2e5+5);
int n,k,l;
int pos[MAXN],dis[MAXN];
vector<int> need,pre,suf;
void solve()
{
    pre.clear();
    suf.clear();
    need.clear();
    cin>>n>>k>>l;
    inc(i,1,n)cin>>pos[i];
    inc(i,1,n)dis[i]=pos[i]-pos[i-1];
    dis[n+1]=l-pos[n];
    // inc(i,1,n+1)cout<<dis[i]<<" ";cout<<endl;
    // cout<<"need#"<<dis[1]<<" ";
    // inc(i,2,n+1)cout<<dis[i]-k<<" ";cout<<endl;
    int tmp(dis[1]);
    inc(i,2,n+1)
    {
        if(tmp*(dis[i]-k)<0)
        {
            need.push_back(tmp);
            tmp=dis[i]-k;
        }
        else
        {
            tmp+=dis[i]-k;
        }
    }
    need.push_back(tmp);
    // cout<<"need#";for(int t:need)cout<<t<<" ";cout<<endl;
    int total(0);
    for(int tmp:need)total+=tmp;
    if(tmp>0)
    {
        cout<<"type1"<<endl;
    }
    else
    {
        pre.resize(need.size());
        partial_sum(need.begin(),need.end(),pre.begin());
        suf.resize(need.size());
        suf[suf.size()-1]=need.back();
        dec(i,suf.size()-2,0)
        {
            suf[i]=suf[i+1]+need[i];
        }
        int ans=2*max(need.front(),need.back()-k);
        int size=need.size();
        inc(j,1,size-2)
        {
            if(need[j]<=0)continue;
            else 
            {
                ans=max(max(need[j],2*need[j]+max(pre[j-1],suf[j+1])),ans);
            }
        }
        cout<<"need#";for(int t:need)cout<<t<<" ";cout<<endl;
        cout<<"pre#";for(int t:pre)cout<<t<<" ";cout<<endl;
        cout<<"suf#";for(int t:suf)cout<<t<<" ";cout<<endl;
        cout<<ans<<endl;
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

9
1 3 5
0
3 2 5
2 5 5
1 10 10
10
10 1 10
0 1 2 3 4 5 6 7 8 9
2 1 2
0 0
2 1 2
0 2
2 1 3
0 2
2 2 4
1 1
9 12 54
3 3 8 24 25 27 29 34 53
*/
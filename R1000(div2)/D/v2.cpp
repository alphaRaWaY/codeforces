#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(2e5+5);
int n,m;
int pos1[MAXN],pos2[MAXN],len1[MAXN],len2[MAXN],res[MAXN];
void solve()
{
    memset(res,0,sizeof(res));
    cin>>n>>m;
    inc(i,1,n)cin>>pos1[i];
    inc(i,1,m)cin>>pos2[i];
    sort(pos1+1,pos1+1+n);
    sort(pos2+1,pos2+1+m);
    inc(i,1,n)len1[i]=pos1[n-i+1]-pos1[i];
    inc(i,1,m)len2[i]=pos2[m-i+1]-pos2[i];
    inc(i,1,n)
    {
        if(len1[i]<=0)break;
        len1[i]=len1[i-1]+len1[i];
    }
    inc(i,1,m)
    {
        if(len2[i]<=0)break;
        len2[i]=len2[i-1]+len2[i];
    }
    int ans(0);
    inc(a,0,n)
    {
        inc(b,0,m)
        {
            if(2*a+b>n||a+2*b>m)break;
            ans=max(ans,a+b);
            res[a+b]=max(res[a+b],len1[a]+len2[b]);
        }   
    }
    cout<<ans<<endl;
    inc(i,1,ans)cout<<res[i]<<" ";cout<<endl;
    // cout<<"=DEBUG="<<endl;
    // cout<<ans<<endl;
    // inc(i,1,maxa)cout<<len1[i]<<" ";cout<<endl;
    // inc(i,1,maxb)cout<<len2[i]<<" ";cout<<endl;
    // cout<<"============================"<<endl;
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


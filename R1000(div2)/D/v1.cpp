#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(2e5+5);
int n,m,maxa,maxb;
int pos1[MAXN],pos2[MAXN],len1[MAXN],len2[MAXN];
int g(int a,int b)
{
    return len1[a]+len2[b];
}
void solve()
{
    cin>>n>>m;
    inc(i,1,n)cin>>pos1[i];
    inc(i,1,m)cin>>pos2[i];
    sort(pos1+1,pos1+1+n);
    sort(pos2+1,pos2+1+m);
    maxa=min(n/2,m);
    maxb=min(n,m/2);
    inc(i,1,maxa)len1[i]=pos1[n-i+1]-pos1[i];
    inc(i,1,maxb)len2[i]=pos2[m-i+1]-pos2[i];
    partial_sum(len1,len1+maxa+1,len1);
    partial_sum(len2,len2+maxb+1,len2);
    int ans(min(n,m));
    ans=min(ans,(m+n)/3);
    cout<<ans<<endl;
    inc(i,1,ans)
    {
        int l=max(0ll,2*i-m);
        int r=min(i,n-i);
        while(r-l>1)
        {
            int mid(((r-l)>>1)+l);
            if(g(mid,i-mid)>=g(mid+1,i-mid-1))r=mid;
            else l=mid;
        }
        cout<<max(g(r,i-r),g(l,i-l))<<" ";
        // inc(j,l,r)cout<<g(j,i-j)<<" ";cout<<endl;
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


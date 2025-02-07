#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(2e5+5);
int n;
double l,k;
double a[MAXN],b[MAXN],t[MAXN];
void solve()
{
    cin>>n>>k>>l;
    inc(i,1,n)cin>>a[i];
    if(n==1)
    {          
        // cout<<2*(a[1]+max((double)0,l-k))<<endl;
        printf("%d\n",(int)(2*(a[1]+max((double)0,l-k))));
        return;
    }
    b[1]=0;
    t[1]=a[1];
    inc(i,2,n)
    {
        double left=max((double)0,a[i]-t[i-1]);
        double r=min(l,a[i]+t[i-1]);
        if(b[i-1]+k<left)
        {
            b[i]=(left+b[i-1]+k)/2;
            t[i]=b[i]-k-b[i-1]+t[i-1];
            // cout<<"case 1"<<endl;
        }
        else if(left<=b[i-1]+k&&b[i-1]+k<=r)
        {
            b[i]=b[i-1]+k;
            t[i]=t[i-1];
            // cout<<"case 2"<<endl;
        }
        else if(b[i-1]+k>r)
        {
            b[i]=r;
            t[i]=t[i-1];
            // cout<<"case 3"<<endl;
        }
    }
    // cout<<"=DEBUG="<<endl;
    // inc(i,1,n)cout<<t[i]<<" ";cout<<endl;
    // inc(i,1,n)cout<<b[i]<<" ";cout<<endl;
    // cout<<"======================="<<endl;
    inc(i,1,n)
    {
        if(b[i]+k>=l)
        {
            // cout<<2*t[i]<<endl;
            printf("%d\n",(int)(2*t[i]));
            return;
        }
    }
    // cout<<2*(t[n]+l-b[n]-k)<<endl;
    printf("%d\n",(int)(2*(t[n]+l-b[n]-k)));
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
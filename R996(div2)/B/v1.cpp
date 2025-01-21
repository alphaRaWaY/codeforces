#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(2e5+5);
int n;
int a[MAXN],b[MAXN];
void solve()
{
    cin>>n;
    inc(i,1,n)cin>>a[i];
    inc(i,1,n)cin>>b[i];
    int pos(0);
    inc(i,1,n)
    {
        if(b[i]>a[i])
        {
            if(pos)
            {
                cout<<"NO"<<endl;
                return;
            }
            else pos=i;
        }
    }
    inc(i,1,n)
    {
        if(i==pos)continue;
        if(a[i]-b[i]<b[pos]-a[pos])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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
0 5 5 1
1 4 4 0
3
1 1 3
2 2 1
2
1 10
3 3
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
#define endl '\n'

int n,m,a,b,c;
void solve()
{
    cin>>n>>m;
    a=b=c=0;
    c=n;
    dec(i,30,0)
    {
        if(((m>>i)%2)!=((n>>i))%2)
        {
            a|=(1<<i);
            b|=a-1;
            break;
        }
        else
        {
            a|=(m&(1<<i));
            b|=(m&(1<<i));
        }
    }
    while(c==a||c==b)
    {
        c++;
    }
    cout<<a<<" "<<b<<" "<<c<<endl;
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
8
0 2
0 8
1 3
6 22
128 137
69 98
115 127
0 1073741823

*/
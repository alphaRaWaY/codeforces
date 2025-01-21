#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int INF(0x3f3f3f3f);
int ls(int a){return a<<1;}
int rs(int a){return a<<1|1;}
const int MAXN(1e3+3);
int n;
int ans[MAXN];
void solve()
{
    cin>>n;
    inc(i,1,n)
    {
        int pos(1);
        string s;
        cin>>s;
        s="#"+s;
        inc(j,1,n)
        {
            if((j<i&&s[j]=='1')||(j>i&&s[j]=='0'))
            {
                pos++;
            }
        }
        ans[pos]=i;
    }
    inc(i,1,n)cout<<ans[i]<<" ";cout<<endl;
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
1
0
5
00101
00101
11001
00001
11110
6
000000
000000
000000
000000
000000
000000
*/
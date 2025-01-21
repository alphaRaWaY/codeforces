#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(5e3+5);
int n,m;
int grid[MAXN][MAXN];
int tx[MAXN],ty[MAXN];
string pa;
void fill(int xx,int yy,int val)
{
    tx[xx]+=val-grid[xx][yy];
    ty[yy]+=val-grid[xx][yy];
    grid[xx][yy]=val;
}
void solve()
{
    cin>>n>>m>>pa;
    inc(i,1,n)tx[i]=0;
    inc(i,1,m)ty[i]=0;
    inc(i,1,n)
    inc(j,1,m)
    {
        cin>>grid[i][j];
        tx[i]+=grid[i][j];
        ty[j]+=grid[i][j];
    }
    int xx(1),yy(1);
    inc(i,0,pa.length()-1)
    {
        if(pa[i]=='D')
        {
            fill(xx,yy,-tx[xx]);
            xx++;
        }
        else
        {
            fill(xx,yy,-ty[yy]);
            yy++;
        }
    }    
    fill(n,m,-tx[n]);
    inc(i,1,n)
    {
        inc(j,1,m)cout<<grid[i][j]<<" ";cout<<endl;
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
/*
4
3 3
DRRD
0 2 3
0 0 0
3 1 0
4 5
DRRRRDD
0 1 0 2 3
0 0 0 0 0
-1 0 -3 -3 0
0 0 0 -1 0
2 3
RRD
0 0 0
0 1 0
5 5
DDDDRRRR
0 25 2 9 11
0 6 13 20 22
0 17 24 1 8
0 3 10 12 19
0 0 0 0 0
*/
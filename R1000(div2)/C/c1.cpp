#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(2e5+5);
using pii = pair<int,int>;
int degree[MAXN];
pii nodes[MAXN];
set<pii> vis;
vector<int> ed[MAXN];
bool isAdj(int a,int b)
{
    if(a>b)swap(a,b);
    return vis.count({a,b});
}
void solve()
{
    vis.clear();
    int n;
    cin>>n;
    inc(i,1,n)
    {
        ed[i].clear();
        degree[i]=0;
    }
    inc(i,1,n-1)
    {
        int a,b;
        cin>>a>>b;        
        vis.insert({min(a,b),max(a,b)});
        degree[a]++;
        degree[b]++;
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    switch (n)
    {
    case 1:
        cout<<0<<endl;
        return;
        break;
    case 2:
        cout<<0<<endl;
        return;
        break;
    case 3:
        cout<<1<<endl;
        return;
        break;
    case 4:
        cout<<2<<endl;
        return;
        break;
    default:
        break;
    }
    inc(i,1,n)
    {
        nodes[i]={degree[i],i};
    }
    sort(nodes+1,nodes+1+n);
    if(!isAdj(nodes[n].second,nodes[n-1].second))
    {
        cout<<nodes[n].first+nodes[n-1].first-1<<endl;
        return;
    }    
    else
    {
        int ans(0);
        dec(i,n,n-2)
        {
            int tmp(0);
            dec(j,n,1)
            {
                if(j==i)continue;
                if(nodes[i].first<tmp)break;
                {
                    tmp=max(tmp,isAdj(nodes[i].second,nodes[j].second)?nodes[j].first-1:nodes[j].first);
                }
            }
            ans=max(ans,tmp+nodes[i].first);
        }
        cout<<ans-1<<endl; 
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
2
1 2
4
1 2
2 3
2 4
7
1 2
1 3
2 4
4 5
5 6
5 7
8
1 2
1 3
1 4
2 6
2 7
4 5
4 8
*/
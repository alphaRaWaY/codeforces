/*
若i>j,a[i]>a[j]
val=a[i]-a[i]-(i-j)=(a[i]-i)-(a[j]-j);
否则
val=a[j]-a[i]-[i-j]=(-a[i]-i)-(-a[j]-j);
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
int ls(int a){return a<<1;}
int rs(int a){return a<<1|1;}
const int MAXN(2e5+5);
int n,m;
int nums[MAXN];
struct ndoe
{
    int l,r,maxn,minn,val;
    int len(){return r-l+1;}
}tree[4*MAXN][2];
void us(int i,int tag)
{
    tree[i][tag].maxn=max(tree[ls(i)][tag].maxn,tree[rs(i)][tag].maxn);
    tree[i][tag].minn=min(tree[ls(i)][tag].minn,tree[rs(i)][tag].minn);
    tree[i][tag].val=max(max(tree[ls(i)][tag].val,tree[rs(i)][tag].val),tree[rs(i)][tag].maxn-tree[ls(i)][tag].minn);
}
void bt(int i,int l,int r)
{
    tree[i][0].l=tree[i][1].l=l;
    tree[i][0].r=tree[i][1].r=r;
    if(l==r)
    {
        tree[i][0].val=0;
        tree[i][0].maxn=tree[i][0].minn=-nums[l]-l;
        tree[i][1].val=0;
        tree[i][1].maxn=tree[i][1].minn=nums[l]-l;
        return;
    }
    int mid(((r-l)>>1)+l);
    bt(ls(i),l,mid);
    bt(rs(i),mid+1,r);
    us(i,0);
    us(i,1);
}
void update(int i,int pos,int val,int tag)
{
    if(tree[i][tag].l>pos||tree[i][tag].r<pos)return;
    if(tree[i][tag].l==pos&&tree[i][tag].r==pos)
    {
        tree[i][tag].maxn=tree[i][tag].minn=val;
        return;
    }
    update(ls(i),pos,val,tag);
    update(rs(i),pos,val,tag);
    us(i,tag);
}
void solve()
{
    cin>>n>>m;
    inc(i,1,n)cin>>nums[i];
    bt(1,1,n);
    cout<<max(tree[1][0].val,tree[1][1].val)<<endl;
    while(m--)
    {
        int pos,val;
        cin>>pos>>val;
        update(1,pos,-val-pos,0);
        update(1,pos,val-pos,1);
        // cout<<"#"<<tree[1][0].val<<","<<tree[1][1].val<<endl;
        cout<<max(tree[1][0].val,tree[1][1].val)<<endl;
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
3
2 2
1 10
1 10
2 2
5 3
1 2 3 4 5
3 7
1 4
5 2
8 5
7 4 2 4 8 2 1 4
5 4
1 10
3 2
8 11
7 7
*/

/*
1
8 5
7 4 2 4 8 2 1 4
5 4
1 10
3 2
8 11
7 7
*/
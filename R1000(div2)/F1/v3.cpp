//更快的版本
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
#define ALL(x) x.begin(),x.end()
using pii = pair<int,int>;
const int mod = 998244353;
const int MAX = 3e5+43;
int fact[MAX], inv[MAX], inv_fact[MAX];
int C(int n, int k) {
    if(n < k || k < 0) return 0;
    return (long long) fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
}
int Cat(int n) {
    return (long long) C(2 * n, n) * inv[n + 1] % mod;
}
int binpow(int x, int n) {
    int ans = 1;
    while(n) {
        if(n & 1) ans = (long long) ans * x % mod;
        n >>= 1;
        x = (long long) x * x % mod;
    }
    return ans;
}
struct node
{
    int l,r,val,space;
    vector<node> child;
    int len(){return r-l+1;}
    node(int l,int r)
    {
        this->l=l;
        this->r=r;
        space=len()/2-1;
        val=Cat(space);
        child.clear();
    }
    void cal()
    {
        int nv(1),ns(len()/2-1);
        for(node c:child)
        {
            ns-=c.len()/2;
            nv=(nv*c.val)%mod;
        }
        nv=(nv*Cat(ns))%mod;
        space=ns;
        val=nv;
    }
    bool contain(node n)
    {
        return l<=n.l&&r>=n.r;
    }
};
void insertNode(node& n,node& r)
{
    bool shouldInsert(true);
    for(node& c:r.child)
    {
        if(c.contain(n))
        {
            insertNode(n,c);
            shouldInsert=false;
            break;
        }
    }
    if(shouldInsert)
    {
        vector<node> s;
        s.swap(r.child);
        for(node c:s)
        {
            if(n.contain(c))n.child.push_back(c);
            else r.child.push_back(c);
        }
        n.cal();
        r.child.push_back(n);
    }
    r.cal();
}
map<pii,bool> vis;
int n;
void solve() {
    vis.clear();
    cin>>n;
    node root=node(0,n*2+1);
    cout<<root.val<<" ";
    inc(i,1,n)
    {
        int l,r;
        cin>>l>>r;
        if(root.val==1)
        {
            cout<<1<<" ";
            continue;
        }
        if(vis[{l,r}])
        {
            cout<<root.val<<" ";
            continue;
        }
        vis[{l,r}]=true;
        node newnode(l,r);
        insertNode(newnode,root);
        root.cal();
        cout<<root.val<<" ";
        // bfs(root);
    }
    cout<<endl;
}
signed main() {
    fact[0] = 1;
    inc(i,1,MAX)fact[i]=(long long)fact[i-1]*i%mod;
    inv_fact[MAX - 1] = binpow(fact[MAX - 1], mod - 2);
    for(int i = MAX - 1; i; i--) inv_fact[i-1]=(long long)inv_fact[i]*i%mod;
    assert(inv_fact[0] == 1);
    inc(i,1,MAX)inv[i] = (long long) inv_fact[i] * fact[i - 1] % mod;
    ios_base::sync_with_stdio(0);
    int _;
    cin>>_;
    while(_--) {
        solve();
    }
    system("pause");
}
/*
3
3
2 5
1 6
3 4
4
1 6
7 8
2 3
4 5
6
2 3
1 6
7 8
9 12
10 11
4 5

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
using pii = pair<int,int>;
const int mod = 998244353;
const int MAX = 5000 + 42;
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
    int val,space;
    int l,r;
    vector<node> child;
    int len(){return r-l+1;}
    void cal()
    {
        int np(len());
        int nv=1;
        for(node c:child)
        {
            np-=c.len();
            nv=(nv*c.val)%mod;
        }
        np=np/2-1;
        space=np;
        nv=nv*Cat(space)%mod;
        val=nv;
    }
    node(int l,int r)
    {
        this->l=l;
        this->r=r;
        child.clear();
        this->cal();
    }
    bool contain(node n)
    {
        return l<n.l&&r>n.r;
    }
};
bool vis[MAX][MAX];
void insert(node n,node r)
{
    bool shouldInsert(true);
    for(node c:r.child)
    {
        if(c.contain(n))
        {
            shouldInsert=false;
            insert(n,c);
            break;
        }
    }
    if(shouldInsert)
    {
        n.cal();
        r.child.push_back(n);
    }
    r.cal();
}
int n;
void solve() {
    cin>>n;
    node root=node(0,n*2+1);
    inc(i,1,n)
    {
        int l,r;
        cin>>l>>r;
        if(vis[l][r])
        {
            cout<<root.val<<" ";
            continue;
        }
        vis[l][r]=true;
        node newnode(l,r);
        cout<<newnode.val<<"#"<<endl;
        insert(newnode,root);
        cout<<root.val<<" ";
    }
    cout<<endl;
}
signed main() {
    fact[0] = 1;
    for(int i = 1; i < MAX; i++) fact[i] = (long long) fact[i - 1] * i % mod;
    inv_fact[MAX - 1] = binpow(fact[MAX - 1], mod - 2);
    for(int i = MAX - 1; i; i--) inv_fact[i - 1] = (long long) inv_fact[i] * i % mod;
    assert(inv_fact[0] == 1);
    for(int i = 1; i < MAX; i++) inv[i] = (long long) inv_fact[i] * fact[i - 1] % mod;
    // ios_base::sync_with_stdio(0);
    int ttt = 1;
    cin >> ttt;
    while(ttt--) {
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
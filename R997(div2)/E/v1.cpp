//数论好题（逆元、组合数、卡特兰数）
//组合数中逆元的新求法
/**
 * 获取阶乘
 * fac[i]=fac[i-1]*i%mod;
 * 获取阶乘逆元
 * fac_inv[i-1]=fac_inv[i]*i%mod;
 * 获取逆元
 * inv[i]=fac[i-1]*fac_inv[i]%mod;
 */
//卡特兰数： f(n)=序列个数为n的出栈序列种数。
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
using pii = pair<int,int>;
const int mod = 998244353;
const int MAXN = 4e5 + 42;
/**
 * 输出int128
 * n：要输出的数
 */
void print128(__int128 a)
{
    vector<int> s;
    string isneg;
    isneg=a<0?"-":"";
    while(a)
    {
        s.push_back(a%10);
        a/=10;
    }
    if(s.empty())cout<<0;
    else
    {
        reverse(s.begin(),s.end());
        cout<<isneg;
        for(int tmp:s)cout<<tmp;
    }
}
/**
 * 快速幂
 * a：底数
 * b：指数
 */
int fast_pow(int a,int b)
{
    int ans(1);
    while(b)
    {   
        if(b&1)
        {
            ans=(1ll*a*ans)%mod;
        }
        a=(1ll*a*a)%mod;
        b>>=1;
    }
    return ans%mod;
}
int fac[MAXN],inv_fac[MAXN],inv[MAXN];
/**
 * 组合数
 * a：在上
 * b：在下
 */
int getC(int a,int b)
{
    if(a<=0||b<a)return 1;
    return (fac[b]*inv_fac[a])%mod*(inv_fac[b-a]%mod)%mod;
}
/**
 * 获取阶乘
 * n：获取的最大范围
 */
void getfac(int n)
{
    fac[0]=fac[1]=1;
    inc(i,2,n)
    {
        fac[i]=fac[i-1]*i%mod;
    }
}
/**
 * 获取分母中阶乘的逆元
 * n：获取的最大范围
 */
void getInvfac(int n)
{
    inv_fac[n]=fast_pow(fac[n],mod-2);
    dec(i,n,2)
    {
        inv_fac[i-1]=inv_fac[i]*i%mod;
    }
}
/**
 * 获取逆元
 * n：获取逆元的范围
 */
void getInv(int n)
{
    inc(i,1,n)
    {
        inv[i]=fac[i-1]*inv_fac[i]%mod;
    }
}
/**
 * 获取卡特兰数
 * n：参数
 */
int cat(int n)
{
    return getC(n,2*n)*inv[n+1]%mod;
}
struct node
{
    int l,r;
    bool operator < (const node n) const {
        if(l==n.l)return r>n.r;
        else return l<n.l;
    }
    node(int l,int r)
    {
        this->l=l;
        this->r=r;
    }
};
int n,m;
set<node> nums;
vector<node> nodes;
int child[MAXN*2];
int ans(1);
void solve()
{
    nums.clear();
    nodes.clear();
    memset(child,0,sizeof(child));
    ans=1;
    cin>>n>>m;
    inc(i,1,m)
    {
        int a,b;
        cin>>a>>b;
        nums.insert({a,b});
    }
    inc(i,1,n)nums.insert({i,i});
    nums.insert({1,n});
    for(auto p:nums)nodes.push_back(p);
    inc(i,0,nodes.size()-1)
    {   
        int j(i+1);
        while(j<nodes.size())
        {
            if(nodes[i].r<nodes[j].l)break;
            child[i]++;
            j=upper_bound(nodes.begin(),nodes.end(),node(nodes[j].r,1ll))-nodes.begin();
        }
    }
    inc(i,0,nodes.size())
    {
        if(child[i]>=2)
        {
            ans=ans*cat(child[i]-1)%mod;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    getfac(MAXN-5);
    getInvfac(MAXN-5);
    getInv(MAXN-5);
    ios::sync_with_stdio(false);
    int _;
    cin>>_;
    while(_--)solve();
    system("pause");
}
/*
6
1 0
2 3
1 1
2 2
1 2
5 2
1 3
2 3
4 1
1 1
6 2
1 3
4 6
2300 0
*/
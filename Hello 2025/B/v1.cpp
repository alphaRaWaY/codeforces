#include<bits/stdc++.h>
using namespace std;
// #define DEBUG
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(1e5+5);
int nums[MaxN];
map<int,int> cnt;
int n,k;
void solve()
{
    cnt.clear();
    cin>>n>>k;
    inc(i,1,n)
    {
        int tmp;
        cin>>tmp;
        cnt[tmp]++;
    }
    int size(0);
    for(auto[x,y]:cnt)
    {
        size++;
        nums[size]=y;
    }
    sort(nums+1,nums+1+size);
    partial_sum(nums+1,nums+1+size,nums+1);
    #ifdef DEBUG
    cout<<"#"<<endl;
    inc(i,1,size)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    #endif
    int ans = upper_bound(nums,nums+1+size,k)-nums-1;
    cout<<max(size-ans,1ll)<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    cin>>_;
    while(_--)solve();
    //system("pause");
}

/*
6
1 0
48843
3 1
2 3 2
5 3
1 2 3 4 5
7 0
4 7 1 3 2 4 1
11 4
3 2 1 4 4 3 4 2 1 3 3
5 5
1 2 3 4 5

*/

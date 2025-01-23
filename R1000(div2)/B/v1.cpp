#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(1e5+5);
int n,l,r;
int nums1[MAXN],nums2[MAXN];
void solve()
{
    int ans1(0),ans2(0);
    cin>>n>>l>>r;
    inc(i,1,n)
    {
        cin>>nums1[i];
        nums2[i]=nums1[i];
    }
    sort(nums1+1,nums1+1+r,greater<int>());
    sort(nums2+l,nums2+1+n);
    // inc(i,1,n)cout<<nums1[i]<<" ";cout<<endl;
    // inc(i,1,n)cout<<nums2[i]<<" ";cout<<endl;
    inc(i,l,r)
    {
        ans1+=nums1[i];
        ans2+=nums2[i];
    }
    cout<<min(ans1,ans2)<<endl;
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
6
2 1 1
2 1
3 2 3
1 2 3
3 1 3
3 1 2
4 2 3
1 2 2 2
5 2 5
3 3 2 3 5
6 1 3
3 6 6 4 3 2
*/

/*
100
10 4 7
1 1 4 5 1 4 1 9 1 9
10 4 7
1 2 3 4 5 6 7 3 2 1
*/
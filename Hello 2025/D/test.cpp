#include<bits/stdc++.h>
using namespace std;
#define inc(i,a,b) for(int i(a);i<=b;i++)

signed main()
{
    int nums[10000];
    int _;
    cin>>_;
    while(_--)
    {
        int n,m;
        cin>>n>>m;
        inc(i,1,n)cin>>nums[i];
        cout<<"a:";
        inc(i,1,n)cout<<-(nums[i]+i)<<" ";cout<<endl;
        cout<<"b:";
        inc(i,1,n)cout<<-(i-nums[i])<<" ";cout<<endl;
        while(m--)
        {
            int pos,v;
            cin>>pos>>v;
            nums[pos]=v;
            cout<<"a:";
            inc(i,1,n)cout<<-(nums[i]+i)<<" ";cout<<endl;
            cout<<"b:";
            inc(i,1,n)cout<<-(i-nums[i])<<" ";cout<<endl;
        }
    }
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

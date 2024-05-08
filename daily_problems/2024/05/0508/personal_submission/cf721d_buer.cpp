#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2*N,mod=998244353;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int>;
int n,m,k;
int a[N],b[N];

void solve()
{
    int x;cin>>n>>k>>x;
    for(int i=1;i<=n;i++) cin>>a[i];
    int f=0;
    for(int i=1;i<=n;i++){
        if(a[i]<0) f^=1;
    }
    //如果没负数
    if(!f){
        int idx=1;
        for(int i=1;i<=n;i++)
            if(abs(a[i])<abs(a[idx]))
            idx=i;
        int opt=(abs(a[idx])+x-1)/x;
        //可以把其中一个数变成相反，正负改变
        if(k>=opt)
        {
            if(a[idx]<0) f^=1;
            k-=opt;
            if(a[idx]<0) a[idx]+=opt*x;
            else a[idx]-=opt*x;
            if(a[idx]<0) f^=1;
        }
        //尽量让乘积最小
        else{
            if(a[idx]<0)
            a[idx]+=k*x;
            else a[idx]-=k*x;
            for(int i=1;i<=n;i++)
            cout<<a[i]<<" ";
            return ;
        }
    }
    
    priority_queue<PII,vector<PII>,greater<PII>> q;
    for(int i=1;i<=n;i++)
    q.emplace(abs(a[i]),i);
    for(int i=1;i<=k;i++)
    {
        auto [val,id]=q.top();
        q.pop();
        if(a[id]==0&&!f){
            a[id]=-x;
            f=true;
        }else{
            if(a[id]>=0) a[id]+=x;
            else a[id]-=x;
        }
        q.emplace(abs(a[id]),id);
    }
    for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
   
    //cin>>t;
    while(t--) solve();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2*N,mod=1e9+7;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int>;
int n,m,k;
int x[N],y[N];

void solve()
{
    cin>>m>>n>>k;
   int res=0;
   vector<int> x(m),y(n);
   for(auto&i:x) cin>>i;
   for(auto&i:y) cin>>i;
   map<int,int> xx,yy;
   map<PII,int> comx,comy;
   for(int i=1;i<=k;i++)
   {
       int u,v;cin>>u>>v;
       //0 1 2 6 10000
       //0 4 8 1000000
       auto it=lower_bound(x.begin(),x.end(),u);
       auto it1=lower_bound(y.begin(),y.end(),v);
       if(u==*it&&v==*it1)
       {
           //res-=i;
           continue;
       }
       int lst=res;
       if(v==*it1)//在x轴
       {
            res+=xx[*it]-comx[{*it,v}];
       }
       else
       {
           res+=yy[*it1]-comy[{*it1,u}];
       }
      // cout<<i<<" "<<res-lst<<"\n";
       if(*it!=u)//在y轴
       xx[*it]++,comx[{*it,v}]++;

       if(*it1!=v)
       yy[*it1]++,comy[{*it1,u}]++;
   }
   
   cout<<res<<"\n";
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}

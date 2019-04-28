#include<bits/stdc++.h>
#define ll long long
#define  MOD 1000000007
#define start ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

ll dfsfind(vector<ll>op[],ll arr1[],ll arr2[],ll ss,ll no,ll x,map<ll,ll>&sol)
{
ll ans;
ll count1=0;
vector<ll>::iterator it;
for(it=op[ss].begin();it!=op[ss].end();it++)
{
if(*it!=no)
    {

     ans=__gcd(arr1[*it],x);

     count1++;

     dfsfind(op,arr1,arr2,*it,ss,ans,sol);
    }
}

    if(count1==0)
    {
        x=arr2[ss]-__gcd(x,arr2[ss]);
        sol[ss]=x;

    }




}


int main()
{

start
ll test;
cin>>test;
while(test--)
{ll N;
cin>>N;
ll arr1[N+1];
ll arr2[N+1];
vector<ll>op[N+1];
map<ll,ll>sol;

for(ll k=1;k<=N-1;k++)
{ll var1,var2;
   cin>>var1;
   cin>>var2;
   op[var1].push_back(var2);
   op[var2].push_back(var1);
}
for(ll k=1;k<=N;k++)
    cin>>arr1[k];
 for(ll k=1;k<=N;k++)
    cin>>arr2[k];

ll ss=1;
ll no=-1;
ll mod1=arr1[1];
 dfsfind(op,arr1,arr2,ss,no,mod1,sol);
 map<ll,ll>::iterator st;

 for(st=sol.begin();st!=sol.end();st++)
    cout<<st->second<<" ";


}


}


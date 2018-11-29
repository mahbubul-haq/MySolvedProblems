/*
 ans = derangement(n)/factorial(n)
*/

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<long,long>
#define vi vector<int>
#define vii vector<pii>
#define vll vector<ll>
#define MOD 1000000007
#define EPS 1e-7
#define mem(x,y) memset(x,y,sizeof x)
#define MAX 4e18
#define ff(i,a,b) for(int i=(a);i<=(b);i++)
#define fb(i,a,b) for(int i=(a);i>=(b);i--)

class compare{
public:
    bool operator()(pii x,pii y){
        if(x.second==y.second){
            return x.first<y.first;
        }
        return x.second<y.second;
    }
};
int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

ll fact[13];
ll derangement[13];

ll derange(int n){
    if(derangement[n]!=-1) return derangement[n];
    if(n==0 ) return derangement[n]=1L;
    if(n==1) return derangement[n]=0L;
    if(n==2) return derangement[n]=1L;

    ll val=0;

    val=(n-1)*(derange(n-1)+derange(n-2));
    return derangement[n]=val;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    mem(derangement,-1);

    fact[0]=1;

    ff(i,1,12){
        fact[i]=fact[i-1]*i;
    }

    ff(i,1,t){
        int n; cin>>n;

        cout<<derange(n)<<"/"<<fact[n]<<endl;

    }

    return 0;
}

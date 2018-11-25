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

ll ncr[2001][2001];

ll nCr(int n,int r){
    if(ncr[n][r]!=-1) return ncr[n][r]%MOD;
    if(n==r) return ncr[n][r]=1%MOD;
    if(r==0) return ncr[n][r]=1;
    if(r==1) return ncr[n][r]=n%MOD;
    return ncr[n][r]=(nCr(n-1,r)%MOD+nCr(n-1,r-1)%MOD)%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mem(ncr,-1);

    int k; cin>>k;

    ll cnt=1;
    int xx; cin>>xx;

    int cntvacant=xx+1;

    ff(i,2,k){
        int x; cin>>x;

        cnt=(cnt*nCr(cntvacant+x-2,x-1))%MOD;
        cntvacant+=x;

    }

    cout<<cnt<<endl;

    return 0;
}

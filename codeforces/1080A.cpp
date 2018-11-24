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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,k; cin>>n>>k;

    ll cnt=0;

    if((n*2)%k==0){
        cnt+=(n*2)/k;
    }
    else if((n*2)<k){
        cnt+=1;
    }
    else{
        cnt+=(n*2)/k+1;
    }

    if((n*5)%k==0){
        cnt+=(n*5)/k;
    }
    else if((n*5)<k){
        cnt+=1;
    }
    else{
        cnt+=(n*5)/k+1;
    }

    if((n*8)%k==0){
        cnt+=(n*8)/k;
    }
    else if((n*8)<k){
        cnt+=1;
    }
    else{
        cnt+=(n*8)/k+1;
    }

    cout<<cnt<<endl;

    return 0;
}


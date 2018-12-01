
///answer: CatalanNumber(n)
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
#define INF 1e9
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

ll cat[100];

ll Cat(int n){
    if(cat[n]!=-1) return cat[n];

    ll val=((2*n)*(2*n-1)*Cat(n-1))/(n*(n+1));

    return cat[n]=val;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    mem(cat,-1);
    cat[1]=1;
    cat[2]=2;
    
    int cas=0;

    while(cin>>n){
        cas++;
        if(cas!=1) cout<<endl;
        
        cout<<Cat(n)<<endl;

    }


    return 0;
}

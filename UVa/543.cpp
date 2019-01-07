#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define vi vector<int>
#define vvi vector<vi>02
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define vpll vector<pll>
#define MOD 998244353
#define EPS 1e-7
#define mem(x,y) memset(x,y,sizeof x)
#define INF 1e9
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())

class compare{
public:
    bool operator()(pii x,pii y){
        if(x.second==y.second){
            return x.first<y.first;
        }
        return x.second<y.second;
    }
};

ostream& operator<<(ostream &os,const pll &a){
    os<<a.first<<" "<<a.second;
}

/*pll operator+(const pll &a, const ll &b){ return { a.first+b,a.second+b };}
pll operator*(const pll &a,const ll &b){ return {a.first*b,a.second*b};}
pll operator+(const pll &a,const pll &b){ return {a.first+b.first,a.second+b.second};}
pll operator-(const pll &a,const pll &b){ return { a.first-b.first,a.second-b.second};}
pll operator*(const pll &a,const pll &b){ return {a.first*b.first,a.second*b.second};}
pll operator%(const pll &a,const pll &b){ return {a.first%b.first,a.second%b.second};}*/

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

///=======================================template=======================================///

vi primes;
bool isPrime[10000001];

void sieve(int n){
    int limit=sqrt(n)+1;

    isPrime[1]=true;
    for(int i=4;i<=n;i+=2) isPrime[i]=true;
    primes.pb(2);
    for(int i=3;i<=n;i+=2){
        if(!isPrime[i]){
            primes.pb(i);

            if(i<=limit){
                for(int j=i*i;j<=n;j+=i){
                    isPrime[j]=true;
                }
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    sieve(1000000);

    int n; while(cin>>n&&n!=0){
        bool flag=true;

        for(int i=0;primes[i]<=n/2;i++){
            if(!isPrime[n-primes[i]]){
                cout<<n<<" = "<<primes[i]<<" + "<<n-primes[i]<<endl;
                flag=false;
                break;
            }
        }

        if(flag){
            cout<<"Goldbach's conjecture is wrong."<<endl;
        }
    }

    return 0;
}

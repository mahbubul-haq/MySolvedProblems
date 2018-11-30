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

vi primes;
bool isPrime[1000001];

void sieve(int n){
    int limit=sqrt(n)+1;

    for(int i=4;i<=n;i+=2) isPrime[i]=true;

    for(int i=3;i<=n;i+=2){

        if(!isPrime[i]){
            if(i<=limit){

                for(int j=i*i;j<=n;j+=i) isPrime[j]=true;

            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    sieve(1000000);

    int n;

    while(cin>>n){

        cout<<n<<" is ";
        int tempn=n;

        if(isPrime[n]) cout<<"not prime."<<endl;
        else{

            string temp;
            while(n){
                int x=n%10;
                n/=10;
                temp+=x+48;
            }

            int x; stringstream ss(temp);
            ss>>x;
            if(isPrime[x]||x==tempn) cout<<"prime."<<endl;
            else cout<<"emirp."<<endl;

        }

    }

    return 0;
}

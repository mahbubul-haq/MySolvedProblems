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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,t=1;
    while(cin>>n&&n!=-1){
        cout<<n<<" coconuts, ";

        int limit=sqrt(n)+1;
        int i;
        for( i=limit;i>1;i--){

            int temp=n;
            int j;
            for(j=1;j<=i;j++){
                if(temp%i!=1) {
                    break;
                }
                temp=temp-temp/i-1;
            }

            if(j==i+1&&temp%i==0){
                cout<<i<<" people and 1 monkey"<<endl;
                break;
            }

        }
        if(i==1) cout<<"no solution"<<endl;


    }

    return 0;
}

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

    int a,b,v,A,s;
    while(cin>>a>>b>>v>>A>>s){
        if(a==0&&b==0&&v==0&&A==0&&s==0){
            break;
        }
        double aa=a,ab=b,av=v,aA=A,as=s;

        av=as*av/2;///decelerates at a cons. rate
        double pi=acos(-1.0);
        double H=av*cos(aA/180*pi);
        double V=av*sin(aA/180*pi);

        cout<<((int)(2*H/aa)+1)/2;
        cout<<" "<<((int)(2*V/ab)+1)/2<<endl;


    }

    return 0;
}

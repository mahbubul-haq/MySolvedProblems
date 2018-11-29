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

    int T; cin>>T;

    ff(cas,1,T){
        double d,v,u;
        cin>>d>>v>>u;
        cout<<"Case "<<cas<<": ";
        if(u==0||v==0){
            cout<<"can't determine"<<endl;
        }
        else{
            double ans;

            if(u*u<=v*v){
                cout<<"can't determine"<<endl;
                continue;
            }

            ans=-d/(u)+(d/sqrt(u*u-v*v));
            cout<<fixed<<setprecision(3)<<ans<<endl;
        }
    }

    return 0;
}

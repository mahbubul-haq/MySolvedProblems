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
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define debugx(x) cout<<"WTH! "<<x<<endl
#define debug(x,y) cout<<x<<" "<<y<<endl

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

ll bigmod(int b,int m){
    if(b==0) return 1L%m;

    ll x=bigmod(b/2,m);
    x=(x*x)%m;
    if(b&1) x=(x*2)%m;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string input;
    char ch;
    while(cin>>ch){

        while(true){
            if(ch=='#'){
                input+=ch;
                break;
            }
            else input+=ch;

            cin>>ch;
        }

        int len=input.length();
        //debugx(input);

        int power=len-2;
        ll mod=0;

        for(int i=0;i<len-1;i++){
            if(input[i]=='1'){
                mod=(mod+bigmod(power,131071))%131071;
                power--;
            }
            else power--;
        }

        if(mod==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        input.clear();

    }

    return 0;
}

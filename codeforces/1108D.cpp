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
#define MOD 1000000007
#define EPS 1e-8
#define mem(x,y) memset(x,y,sizeof x)
#define INF 1e9
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define PI acos(-1.0)

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

pll operator+(const pll &a, const ll &b){ return { a.first+b,a.second+b };}
pll operator*(const pll &a,const ll &b){ return {a.first*b,a.second*b};}
pll operator+(const pll &a,const pll &b){ return {a.first+b.first,a.second+b.second};}
pll operator-(const pll &a,const pll &b){ return { a.first-b.first,a.second-b.second};}
pll operator*(const pll &a,const pll &b){ return {a.first*b.first,a.second*b.second};}
pll operator%(const pll &a,const pll &b){ return {a.first%b.first,a.second%b.second};}

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

///=======================================template=======================================///

ll bigmod(ll a,ll b){
    a%=MOD;
    ll res=1;

    while(b>0){
        if(b&1) res=(res*a)%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin>>n;

    string input; cin>>input;
    string ans=input;

    for(int i=0;i<n;i++){
        if(i<n-1){
            if(input[i]==input[i+1]){
                if(i<n-2){
                    if(input[i]==input[i+2]){
                        if(input[i]=='G'){
                            ans[i+1]='B';
                        }
                        if(input[i]=='B'){
                            ans[i+1]='R';
                        }
                        if(input[i]=='R'){
                            ans[i+1]='B';
                        }
                        i++;
                    }
                    else{
                        if(input[i]!='G'&&input[i+2]!='G') ans[i+1]='G';
                        else if(input[i]!='R'&&input[i+2]!='R') ans[i+1]='R';
                        else ans[i+1]='B';
                        i++;
                    }
                }
                else{
                    if(input[i]=='G'){
                        ans[i+1]='B';
                    }
                    if(input[i]=='B'){
                        ans[i+1]='R';
                    }
                    if(input[i]=='R'){
                        ans[i+1]='B';
                    }
                }
            }
        }
    }

    int cnt=0;

    for(int i=0;i<n;i++) if(input[i]!=ans[i]) cnt++;
    cout<<cnt<<endl;
    cout<<ans<<endl;

    return 0;
}

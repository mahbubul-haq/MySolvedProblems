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
#define FIFO true
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)

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

ll a[200005];
//ll dp[200005][2];
int n,k;
string s;

/*ll ret(int id,char last,int cnt){

    if(id==n+1){
        return 0;
    }

    ll val1=0,val2=0;

    if(last==s[id-1]) {
        if(cnt<k) {
            val1 = a[id]+ret(id + 1, s[id - 1], cnt + 1);
            val2=ret(id+1,s[id-1],cnt);
        }
        else{
            val2=ret(id+1,s[id-1],cnt);
        }
    }
    else{
        val1=a[id]+ret(id+1,s[id-1],1);
        val2=ret(id+1,last,cnt);
    }

    dp[id][0]=val2;
    dp[id][1]=val1;

    return max(val1,val2);



}*/

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
//mem(dp,-1);

    cin>>s;

    char ch=s[0];
    int cnt=0;
    ll mini=a[0];
    ll dmg=0;
   //dmg+=a[0];

    for(int i=0;i<n;i++){

        vi vec;

        while(ch==s[i]){
            cnt++;
            vec.pb(a[i]);
            i++;
        }

        cnt=0;
        ch=s[i];
        i--;

        if(vec.size()>k){
            sortv(vec);
            int cc=0;
            for(int ii=vec.size()-1;ii>=0;ii--){
                cc++;
                dmg+=vec[ii];
                if(cc==k) break;
            }
        }
        else{
            for(int ii=0;ii<vec.size();ii++) dmg+=vec[ii];
        }



    }

    cout<<dmg<<endl;


    return 0;
}

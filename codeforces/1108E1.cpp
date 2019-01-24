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
    int m;
    cin>>m;

    int ara[n+1];

    int maxdif=0,cnt=0;
    int maxi=INT_MIN,mini=INT_MAX;
    vi ans;

    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        maxi=max(maxi,ara[i]);
        mini=min(mini,ara[i]);
    }

    maxdif=maxi-mini;

    vii vec;

    for(int i=0;i<m;i++) {
        int l,r; cin>>l>>r;
        vec.pb(pii(l,r));
    }

    if(n==1){
        cout<<0<<endl;
        cout<<0<<endl;
        return 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int tempdif=0;
            int cnt1=0,cnt2=0;
            vi temp;
            for(int k=0;k<m;k++){
                if(vec[k].first<=j&&vec[k].second>=j){
                    if(vec[k].first<=i) cnt1++;
                    cnt2++;
                    temp.pb(k);
                }
            }

            tempdif=ara[i]-ara[j]-cnt1+cnt2;
            if(tempdif>maxdif){
                maxdif=tempdif;
                ans=temp;
            }

             tempdif=0;
             cnt1=0,cnt2=0;
            vi temp1;
            for(int k=0;k<m;k++){
                if(vec[k].first<=i&&vec[k].second>=i){
                    if(vec[k].second>=j) cnt2++;
                    cnt1++;
                    temp1.pb(k);
                }
            }

            tempdif=ara[j]-ara[i]-cnt2+cnt1;
            if(tempdif>maxdif){
                maxdif=tempdif;
                ans=temp1;
            }
        }
    }

    cout<<maxdif<<endl;
    cout<<ans.size()<<endl;

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]+1<<" ";
    }

    return 0;
}

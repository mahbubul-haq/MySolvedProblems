#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define vpll vector<pll>
#define MOD 1000000007
#define EPS 1e-12
#define mem(x,y) memset(x,y,sizeof x)
#define INF 100000000
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define PI acos(-1.0)
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define debug(x) cout<<"WTH: "<<x<<endl
#define fof(i,x,y) for(int i=x;i<=(int)y;i++)
#define fob(i,x,y) for(int i=x;i>=(int)y;i--)

template<class T>
class compare{
public:
    bool operator()(pair<T,T> x,pair<T,T> y){
        if(x.second==y.second){
            return x.first<y.first;
        }
        return x.second<y.second;
    }
};

template<class T>
ostream& operator<<(ostream &os,const pair<T,T> &a){
    os<<a.ff<<" "<<a.ss;
}

template<class T> pair<T,T> operator+(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff+b.ff,a.ss+b.ss}; }
template<class T> pair<T,T> operator-(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff-b.ff,a.ss-b.ss}; }
template<class T> pair<T,T> operator*(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff*b.ff,a.ss*b.ss}; }
template<class T> pair<T,T> operator%(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff%b.ff,a.ss%b.ss}; }
template<class T,class U> pair<T,T> operator+(const pair<T,T> &a,const U &b){ return { a.ff+b,a.ss+b}; }
template<class T,class U> pair<T,T> operator*(const pair<T,T> &a,const U &b){ return { a.ff*b,a.ss*b}; }

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

///=======================================template=======================================///
//map<string,int> myMap;
double probs[17][17];

double ans[17];

void calc(int l,int r){
    int mid=(l+r)>>1;
    if(r<=l) return ;

    calc(l,mid);
    calc(mid+1,r);

    double temp[17];
    for(int i=1;i<=16;i++) temp[i]=ans[i];

    double temp1=0.0;
    for(int i=l;i<=mid;i++){
        temp1=0;
        for(int j=mid+1;j<=r;j++){
            temp1+=ans[j]*probs[i][j];
        }

        ans[i]*=temp1;
    }



    for(int i=mid+1;i<=r;i++){
        double temp1=0;
        for(int j=l;j<=mid;j++){
            temp1+=temp[j]*probs[i][j];
        }
        ans[i]*=temp1;
    }
}

int main()
{
    //FI;FO;
    FASTIO;



    //int cnt=0;
    vector<string> countri;

    for(int i=1;i<=16;i++){
        string country;
        cin>>country;
        countri.pb(country);
        //countri[i-1].resize(11);
        //myMap[country]=i;
    }

    for(int i=1;i<=16;i++){
        for(int j=1;j<=16;j++){
            int x; cin>>x;

            probs[i][j]=(x*1.0)/100;
        }
    }
    for(int i=1;i<=16;i++) ans[i]=1;

    calc(1,16);

    for(int i=1;i<=16;i++) ans[i]*=100;

    for(int i=1;i<=16;i++){
        cout<<left<<setw(10)<<countri[i-1]<<" p="<<fixed<<setprecision(2)<<ans[i]<<"%"<<endl;
    }

    return 0;
}

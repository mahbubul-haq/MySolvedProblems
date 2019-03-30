#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<<"WTH: "<<x<<endl
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS 1e-12
#define FastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define ff first
#define fof(i,x,y) for(int i=x;i<(int)y;i++)
#define fob(i,x,y) for(int i=x;i>=(int)y;i--)
#define INF 100000
#define ld long double
#define ll long long
#define mem(x,y) memset(x,y,sizeof x)
#define mp make_pair
#define msi map<string,int>
#define mii map<int,int>
#define mis map<int,string>
#define MOD 1000000007
#define PI acos(-1.0)
#define PQ priority_queue
#define pb push_back
#define pib pair<int,bool>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sfi(x) scanf("%d",&x)
#define sfii(x,y) scanf("%d%d",&x,&y)
#define sfiii(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define siz(x) (int)x.size()
#define sortv(v) sort(v.begin(),v.end())
#define ss second
#define umsi unordered_map<string,int>
#define umii unordered_map<int,int>
#define umis unordered_map<int,string>
#define vb vector<bool>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define vpll vector<pll>

template<class T>
class compare{
public:
    bool operator()(pair<T,T> &x,pair<T,T> &y){
        if(x.first==y.first){
            return x.ss>y.ss;
        }
        return x.ff>y.ff;
    }
};

template<class T>
ostream& operator<<(ostream &os,const pair<T,T> &a){
    os<<a.ff<<" "<<a.ss;
}
template<class T>
void print(vector<T> &vec){
    fof(i,0,vec.size()) cout<<vec[i].ss<<" "; cout<<endl;
}
template<class T>
void print(set<T> &s){
    for(auto it: s) cout<<it<<" "; cout<<endl;
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

string xx;
ll anss=0;

ll ret(int id,bool flag,ll ans){
    int maxi=0;


    if(id==0 and flag){
        if(xx[id]=='1'){
            anss=max(anss,ans);
        }
        else anss=max(anss,ans*(xx[id]-'1'));
    }
    else if(id==0){
        anss=max((xx[id]-'0')*ans,anss);
    }

    if(id==0) return 0;

    if(flag){
        ret(id-1,false,(xx[id]-'1')*ans);
        ret(id-1,true,9*ans);
    }
    else{
        ret(id-1,false,(xx[id]-'0')*ans);
        ret(id-1,xx[id]!='9',9*ans);
    }
}

int main()
{
    //FI;FO;
    FastIO;

    ll ans=1;

    ll n; cin>>n;

    ll n1=n;

    if(n<10){
        cout<<n<<endl;
    }
    else if(n<100){
        ans=1;
        for(int i=0;i<=10 and n-i>9;i++){
            ll nn=n-i;
            ans=max(ans,(nn%10)*(nn/10));
        }

        cout<<max(ans,9LL)<<endl;
    }
    else{

        while(n){
            int x=n%10;
            xx=xx+(char)(x+48);
            n/=10;
        }

        int si=siz(xx);
        reverse(xx.begin(),xx.end());

        //cout<<xx<<endl;

        ret(si-1,false,1);
        cout<<anss<<endl;

    }

    return 0;
}

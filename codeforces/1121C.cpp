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
#define fof(i,x,y) for(int i=x;i<(int)y;i++)
#define fob(i,x,y) for(int i=x;i>=(int)y;i--)

template<class T>
class compare{
public:
    bool operator()(pair<T,T> x,pair<T,T> y){
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
void print(vector<T> vec){
    fof(i,0,vec.size()) cout<<vec[i]<<" "; cout<<endl;
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

int main()
{
    //FI;FO;
    FASTIO;

    int n,k;
    cin>>n>>k;

    int ara[n];
    fof(i,0,n) cin>>ara[i];


    int test=0;


    vector<pair<bool,pair<bool,pii> > > times(k+1,mp(false,mp(false,mp(0,0))));


    int id=0;
    int finish=0;
    int time=0;
    int cnt=0;
    while(true){
        time++;

        for(int i=1;i<=k;i++) {
            if (times[i].ff == false && id < n) {
                times[i] = mp(true, mp(false, mp(time - 1, time + ara[id] - 1)));
                id++;
            }
        }

        int tempfinish=finish;
        for(int i=1;i<=k;i++){
            if(times[i].ff==true){
                if(times[i].ss.ff==false){

                    test=round(100.0*finish*1.0/n)+EPS;

                    ///cout<<test<<" "<<time<<" "<<times[i].ss.ss.ff<<endl;

                    if(test==time-times[i].ss.ss.ff){
                        cnt++;
                        times[i].ss.ff=true;
                    }


                }
                if(times[i].ss.ss.ss==time){
                    times[i]=mp(false,mp(false,mp(0,0)));
                    tempfinish++;
                }
            }
        }

        finish=tempfinish;

        if(finish>=n)break;
    }

    cout<<cnt<<endl;

    return 0;
}

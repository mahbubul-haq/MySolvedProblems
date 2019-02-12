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
#define EPS 1e-8
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

int n;
vii ara;

double dp[17][(1<<17)];

double ret(int id,int mask){
    if(abs(dp[id][mask]+1)>EPS){
        return dp[id][mask];
    }

    double mini=1e15;

    bool flag=false;

    for(int i=0;i<2*n;i++){
        if(!check(mask,i)){
            flag=true;
            double temp=sqrt(dist2D(ara[id].ff,ara[id].ss,ara[i].ff,ara[i].ss));

            int tempmask=Set(mask,i);
            bool flag1=false;
            for(int j=0;j<2*n;j++){
                if(!check(tempmask,j)){
                    flag1=true;
                    temp+=ret(j,Set(tempmask,j));
                    break;
                }
            }


            mini=min(mini,temp);

        }
    }

    return dp[id][mask]=mini;

}

int main()
{
    //FI;FO;
    FASTIO;

    int cas=1;
    while(cin>>n&&n!=0){
        cout<<"Case "<<cas++<<": ";
        ara.clear();

        for(int i=0;i<2*n;i++){
            mem(dp,-1);

            string thro;
            int x,y;
            cin>>thro>>x>>y;

            ara.pb(mp(x,y));

        }

        cout<<fixed<<setprecision(2)<<ret(0,1)<<endl;
    }

    return 0;
}

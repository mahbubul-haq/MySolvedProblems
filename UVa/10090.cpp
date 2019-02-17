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

///Extended Euclid
ll gcd(ll a,ll b, ll &x, ll &y){
    if(b==0){
        y=0;
        x=1;
        return a;
    }

    ll x1,y1;
    ll d=gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return d;
}

///one solution of ax+by=c

bool find_one_solution(ll a,ll b,ll c,ll &x0,ll &y0,ll &g){
    g=gcd(abs(a),abs(b),x0,y0);

    if(c%g) return false;

    x0*=c/g;
    y0*=c/g;
    if(a<0) x0=-x0;
    if(b<0) y0=-y0;
    return true;
}

void shift_solution(ll &x,ll &y,ll a,ll b,ll cnt){
    x+=cnt*b;
    y-=cnt*a;
}

int main()
{
   // FI;FO;
    FASTIO;

    ll n;

    while(cin>>n&&n!=0){
        ll c1,c2,n1,n2;
        cin>>c1>>n1;
        cin>>c2>>n2;

        ll x,y,g;

        ll x1,y1,x2,y2;

        if(find_one_solution(n1,n2,n,x,y,g)){

            ll k=x/(n2/g);

            x-=k*n2/g;
            y+=k*n1/g;
            if(x<0){
                x+=n2/g;
                y-=n1/g;
            }

            x1=x,y1=y;

            if(x<0||y<0){
                cout<<"failed"<<endl;
            }
            else{
                k=y/(n1/g);
                x+=k*n2/g;
                y-=k*n1/g;
                if(y<0){
                    y+=n1/g;
                    x-=n2/g;
                }

                x2=x,y2=y;

                if(x1*c1+y1*c2<=x2*c1+y2*c2) cout<<x1<<" "<<y1<<endl;
                else cout<<x2<<" "<<y2<<endl;
            }



        }
        else cout<<"failed"<<endl;

    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin>>T;

    for(int i=0;i<T;i++){

            double a,b,c;

            cin>>a>>b>>c;

            double ans=0;
            ans=a+b+c;

            double pi=acos(-1.0);


            double s=(sqrt(a)+sqrt(b)+sqrt(c))/2;

            double g=sqrt(s*(s-sqrt(a))*(s-sqrt(b))*(s-sqrt(c)));

            ans+=g;

            double ang=asin(2*g/(sqrt(b)*sqrt(c)));

            double f=sqrt(b)*sqrt(c)*sin(ang)/2;
            ans+=f;

            ang=asin(2*g/(sqrt(a)*sqrt(c)));

            double d=sqrt(a)*sqrt(c)*sin(pi/2+pi-(ang+pi/2))/2;

            ans+=d;

            ang=asin(2*g/(sqrt(a)*sqrt(b)));

              double e=sqrt(a)*sqrt(b)*sin(pi/2+pi-(ang+pi/2))/2;

            ans+=e;


            cout<<fixed<<setprecision(10)<<ans<<endl;

    }


    return 0;
}

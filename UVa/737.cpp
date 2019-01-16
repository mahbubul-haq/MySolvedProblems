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
#define MOD 998244353
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

/*pll operator+(const pll &a, const ll &b){ return { a.first+b,a.second+b };}
pll operator*(const pll &a,const ll &b){ return {a.first*b,a.second*b};}
pll operator+(const pll &a,const pll &b){ return {a.first+b.first,a.second+b.second};}
pll operator-(const pll &a,const pll &b){ return { a.first-b.first,a.second-b.second};}
pll operator*(const pll &a,const pll &b){ return {a.first*b.first,a.second*b.second};}
pll operator%(const pll &a,const pll &b){ return {a.first%b.first,a.second%b.second};}*/

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

///=======================================template=======================================///


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;

    while(cin>>n&&n!=0){
        vector<vi> points;

        for(int i=0;i<n;i++){
            ll x,y,z,dis; cin>>x>>y>>z>>dis;
            vi temp; temp.pb(x);
            temp.pb(y);
            temp.pb(z);
            temp.pb(x+dis);
            temp.pb(y+dis);
            temp.pb(z+dis);
            points.pb(temp);
        }

        ll volume=0;

        int i=0;

        for(int j=1;j<n;j++){

            if(points[i][0]>=points[j][3]||points[j][0]>=points[i][3] ||points[i][1]>=points[j][4]||points[j][1]>=points[i][4]
               ||points[i][2]>=points[j][5]||points[j][2]>=points[i][5]){
                volume=0; break;
            }
            else{
                vll vecx,vecy,vecz;

                vecx.pb(points[i][0]);
                vecx.pb(points[j][0]);
                vecx.pb(points[i][3]);
                vecx.pb(points[j][3]);

                vecy.pb(points[i][1]);
                vecy.pb(points[j][1]);
                vecy.pb(points[i][4]);
                vecy.pb(points[j][4]);

                vecz.pb(points[i][2]);
                vecz.pb(points[j][2]);
                vecz.pb(points[i][5]);
                vecz.pb(points[j][5]);

                sortv(vecx);
                sortv(vecy);
                sortv(vecz);

                points[i][0]=vecx[1];
                points[i][3]=vecx[2];
                points[i][1]=vecy[1];
                points[i][4]=vecy[2];
                points[i][2]=vecz[1];
                points[i][5]=vecz[2];

                volume=(vecx[2]-vecx[1])*(vecy[2]-vecy[1])*(vecz[2]-vecz[1]);
            }
        }

        cout<<volume<<endl;
    }
    return 0;
}

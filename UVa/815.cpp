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

    int n,m;

    int cas=0;

    while(cin>>n>>m&&!(n==0&&m==0)){

        vll heights;

        fof(i,0,m){

            fof(j,0,n){
                int x; cin>>x;
                heights.pb(x);
            }

        }

        double height;
        cin>>height;

        //height/=100;

        sortv(heights);
        //print(heights);

        double maxheight=height+1;

        double mini=heights[0];
        maxheight=heights[0]+height/(100);
        double climbed=0;
        int idx=-1;
        fof(i,1,heights.size()){
            if((climbed+(heights[i]-mini)*i*100)<=height){

                climbed+=(heights[i]-mini)*i*100;
                mini=heights[i];
                idx=i+1;
            }
            else{
                idx=i;
                maxheight=(height-climbed)/(i*100)+mini;
                climbed=height+2;
                break;
            }

        }

        if(height-climbed>EPS){
            maxheight=(height-climbed)/(m*n*100)+heights[m*n-1];
        }

        cout<<"Region "<<++cas<<endl;
        cout<<"Water level is "<<fixed<<setprecision(2)<<maxheight<<" meters."<<endl;

        if(maxheight>=heights[m*n-1]){
            cout<<100.00;
        }
        else {
            cout<<idx*1.0/(m*n)*100;
        }

        cout<<" percent of the region is under water."<<endl<<endl;
    }
    
    return 0;
}

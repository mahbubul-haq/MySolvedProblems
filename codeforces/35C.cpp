#include <bits/stdc++.h>
using namespace std;

#define dist2D(x1,y1,x2,y2)         ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2)   ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS                         1e-12
#define FastIO                      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("input.txt","r",stdin)
#define FO                          freopen("output.txt","w",stdout)
#define fap(x)                      cout<<"WTH: "<<x<<endl
#define ff                          first
#define fof(i,x,y)                  for(int i=x;i<(int)y;i++)
#define fob(i,x,y)                  for(int i=x;i>=(int)y;i--)
#define INF                         100000
#define ld                          long double
#define ll                          long long
#define mem(x,y)                    memset(x,y,sizeof x)
#define mp                          make_pair
#define msi                         map<string,int>
#define mii                         map<int,int>
#define mis                         map<int,string>
#define MOD                         1000000007
#define PI                          acos(-1.0)
#define PQ                          priority_queue
#define pb                          push_back
#define pib                         pair<int,bool>
#define pii                         pair<int,int>
#define pll                         pair<ll,ll>
#define sfi(x)                      scanf("%d",&x)
#define sfii(x,y)                   scanf("%d%d",&x,&y)
#define sfiii(x,y,z)                scanf("%d%d%d",&x,&y,&z)
#define siz(x)                      (int)x.size()
#define sortv(v)                    sort(v.begin(),v.end())
#define ss                          second
#define ull                         unsigned long long
#define umsi                        unordered_map<string,int>
#define umii                        unordered_map<int,int>
#define umis                        unordered_map<int,string>
#define vb                          vector<bool>
#define vi                          vector<int>
#define vvi                         vector<vi>
#define vii                         vector<pii>
#define vvii                        vector<vii>
#define vll                         vector<ll>
#define vpll                        vector<pll>

template<class T> class compare{
public:
    bool operator()(pair<T,T> &x,pair<T,T> &y){
        if(x.first==y.first){
            return x.ss>y.ss;
        }
        return x.ff>y.ff;
    }
};

template<class T> ostream& operator<<(ostream &os,const pair<T,T> &a) { os<<a.ff<<" "<<a.ss; }
template<class T> void print(vector<T> &vec){
    for(int i=1;i<siz(vec);i++) cout<<vec[i]<<" ";cout<<endl;
}
template<class T> void print(set<T> &s) {
    for(auto it: s) cout<<it<<" "; cout<<endl;
}
template<class T> void print(list<T> &lst) {
    for(auto it: lst) cout<<it<<" "; cout<<endl;
}
template<class T> ll power(T a,int b){
    ll po=1; while(b--) po*=a; return po;
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

///=======================================template=======================================//

int dirx[]={-1,1,0,0};
int diry[]={0,0,1,-1};
vb mapp;
int n,m;

int main()
{
    FI;FO;
    FastIO;

    cin>>n>>m;

    int k; cin>>k;

    vi temp1(1000*1000),temp2;
    mapp.assign(4e6+2,0);

    int cnt=0;
    for(int i=0;i<k;i++){
        int u,v; cin>>u>>v;
        mapp[(u-1)*2000+v-1]=1;
        temp1[cnt++]=(u-1)*2000+v-1;
    }

    int ans=temp1[0];
    temp2.resize(1e6);
    bool flag=true;
    int sz,val,j,i,fff,sss;
    int now;
    while(true){
        //fap(1);
        sz=cnt;
        cnt=0;
        if(flag) {
            for (i = 0; i < sz; i++) {
                now = temp1[i];

                for (j = 0; j < 4; j++) {
                    fff = now/2000+diry[j],sss=now%2000+dirx[j];
                    val=fff*2000+sss;
                    if (fff >= 0 and fff <= n-1 and sss >= 0 and sss <= m-1) {
                        if (mapp[val] == 0) {
                            ans=val;
                            mapp[val] = 1;
                            temp2[cnt++] = val;
                        }
                    }
                }
            }
            flag=false;
        }
        else{
            for (i = 0; i < sz; i++) {
                now = temp2[i];

                for (j = 0; j < 4; j++) {
                    fff = now/2000+diry[j],sss=now%2000+dirx[j];
                    val=fff*2000+sss;
                    if (fff >= 0 and fff <= n-1 and sss >= 0 and sss <= m-1) {
                        if (mapp[val] == 0) {
                            ans=val;
                            mapp[val] = 1;
                            temp1[cnt++] = val;
                        }
                    }
                }
            }
            flag=true;
        }

        if(cnt==0) break;
        ///for(int i=0;i<cnt;i++) temp1[i]=temp2[i];
    }

    //cout<<ans<<endl;
    cout<<ans/2000+1<<" "<<ans%2000+1<<endl;

    return 0;
}

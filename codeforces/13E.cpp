#include <bits/stdc++.h>
using namespace std;

#define dist2D(x1,y1,x2,y2)         ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2)   ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS                         1e-12
#define FastIO                      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt","r",stdin)
#define FO                          freopen("out.txt","w",stdout)
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
    for(int i=0;i<siz(vec);i++) cout<<vec[i]<<" ";cout<<endl;
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

///=======================================template=======================================///

int n,m;
vi Power;

int main()
{
    //FI;FO;
    //FastIO;

    //cin>>n>>m;
    sfii(n,m);
    Power.resize(n+1);

    fof(i,0,n){
        sfi(Power[i]);
       //cin>>Power[i];
    }
    Power[n]=0;

    int K=(int)sqrt(n)+1;
    int next[n+5];
    int count[n+5];
    int id[n+5];

    for(int i=0;i<n+2;i++){
        id[i]=i/K;
    }

    for(int i=0;i<n;i++){

        int kk=id[i];
        int j=i;
        count[i]=0;

        while(id[j]==kk){
            count[i]++;
            j+=Power[j];
            if(j>=n){
                j=n;
                break;
            }
        }
        next[i]=j;
    }

    fof(i,0,m){
        int x; //cin>>x;
        sfi(x);

        if(x){
            int a; sfi(a);//cin>>a;
            a--;
            int cnt=0;
            int last=a;
            while(Power[a]){
                cnt+=count[a];
                last=a;
                a=next[a];
                if(a>=n) break;
            }

            while(last+Power[last]<n){
                last+=Power[last];
            }

            printf("%d %d\n",last+1,cnt);

        }
        else{

            int a,b; sfii(a,b);//cin>>a>>b;
            a--;

            int kk=id[a];

            Power[a]=b;

            count[a]=0;

            int j=a;

            while(id[j]==kk){
                count[a]++;
                j+=Power[j];
                if(j>=n) {
                    j=n;
                    break;
                }
            }
            next[a]=j;

            for(int j=a-1;j>-1 and id[j]==kk;j--){
                int jj=j+Power[j];
                if(jj>=n){
                    next[j]=n;
                    count[j]=1;
                }
                else if(id[jj]==kk){
                    next[j]=next[j+Power[j]];
                    count[j]=count[j+Power[j]]+1;
                }
            }
        }
    }

    return 0;
}

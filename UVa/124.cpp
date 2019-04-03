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
    for(int i=0;i<siz(vec);i++) cout<<vec[i].ff<<" "<<vec[i].ss.ff<<" "<<vec[i].ss.ss<<endl;
}
template<class T> void print(set<T> &s) {
    for(auto it: s) cout<<it<<" "; cout<<endl;
}
template<class T> void print(list<T> &lst) {
    for(auto it: lst) cout<<it<<" "; cout<<endl;
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

map<char,int> mapp;
map<int,char> mapic;

vi mask;
vvi g;
int cnt;
char ans[24];
bool taken[25];

void rec(int l){
    if(l==cnt-1){
        for(int i=1;i<cnt;i++)
            cout<<ans[i];
        cout<<endl;
    }
    else{
        for(int i=1;i<cnt;i++){
            if(mask[i]==0 and !taken[i]){

                ans[l+1]=mapic[i];
                taken[i]=true;
                for(int j=0;j<siz(g[i]);j++){
                    int v=g[i][j];
                    mask[v]=reset(mask[v],i);
                }

                rec(l+1);

                for(int j=0;j<siz(g[i]);j++){
                    int v=g[i][j];
                    mask[v]=Set(mask[v],i);
                }
                taken[i]=false;

            }
        }
    }
}

int main()
{
    //FI;FO;
    FastIO;

    string input;

    int cas=0;
    while(getline(cin,input)){
        if(cas++!=0) cout<<endl;
        stringstream ss(input);
        mapp.clear();
        mapic.clear();

        cnt=1;

        string now;
        while(ss>>input){

            now+=input[0];
            //mapp[input[0]]=cnt++;
        }

        sort(now.begin(),now.end());

        for(int i=0;i<siz(now);i++){
            cnt++;
            mapp[now[i]]=i+1;
            mapic[i+1]=now[i];
        }

        mask.assign(cnt,0);
        g.assign(cnt,vi());

        getline(cin,input);

        stringstream ss1(input);

        while(ss1>>input){
            char ch=input[0];
            //fap(ch);
             ss1>>input;
             char ch1=input[0];
             mask[mapp[ch1]]=Set(mask[mapp[ch1]],mapp[ch]);
             g[mapp[ch]].pb(mapp[ch1]);
        }

        mem(taken,false);
        for(int i=1;i<cnt;i++){
            if(mask[i]==0){

                ans[1]=mapic[i];
                taken[i]=true;
                for(int j=0;j<siz(g[i]);j++){
                    int v=g[i][j];
                    mask[v]=reset(mask[v],i);
                }

                rec(1);

                for(int j=0;j<siz(g[i]);j++){
                    int v=g[i][j];
                    mask[v]=Set(mask[v],i);
                }
                taken[i]=false;

            }
        }

    }

    return 0;
}

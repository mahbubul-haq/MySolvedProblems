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
#define INF                         1000000000
#define ld                          long double
#define ll                          long long
#define mem(x,y)                    memset(x,y,sizeof x)
#define mp                          make_pair
#define msi                         map<string,int>
#define mii                         map<int,int>
#define mis                         map<int,string>
#define MOD                         2147483647
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

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;

//os.order_of_key(v): returns how many elements strictly less than v
//os.find_by_order(k-1): returns kth smallest element's iterator
*/

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

int main()
{
    //FI;FO;
    FastIO;

    bool f=false,s=false;

    map<pii,multiset<string> > mapp;
    map<int,multiset<string> > mappp;

    int n; cin>>n;

    string vow="aeiou";

    int fcnt=0,scnt=0;

    while(n--){
        string str; cin>>str;
        int fff=0,sss=-1;
        for(int i=0;i<siz(str);i++){
            for(int j=0;j<5;j++){
                if(str[i]==vow[j]){
                    fff++;
                    sss=vow[j]-'a';
                    break;
                }
            }
        }

        mapp[mp(fff,sss)].insert(str);
        //mappp[fff].insert(str);
    }

    vector<string> err;
    for(auto &it:mapp){
        if(it.ss.size()&1){
            string temp=*it.ss.begin();
            auto fit=it.ss.find(temp);
            it.ss.erase(fit);
            mappp[it.ff.ff].insert(temp);
        }
    }

    auto it=mappp.begin();
    auto it1=mapp.begin();
    vector<pair<string,string> > ans;
    vector<string> errr;

    while(it!=mappp.end()){
        //fap(1);
        if((*it).ss.size()>1){
            auto it2=(*it).ss.begin();
            while(it2!=(*it).ss.end()){
                string f1=(*it2);
                it2++;
                if(it2==(*it).ss.end()) break;
                string f2=(*it2);
                it2++;
                errr.clear();
                string s1,s2;
                while((*it1).ss.size()<=1){
                    it1++;
                }
                if(it1==mapp.end())
                    break;

                for(auto &v:(*it1).ss){
                    if(errr.size()<2) errr.pb(v);
                    else break;
                }
                ans.pb(mp(f1,errr[0]));
                ans.pb(mp(f2,errr.at(1)));
                auto fit=(*it1).ss.find(errr.at(0));
                (*it1).ss.erase(fit);
                fit=(*it1).ss.find(errr.at(1));
                (*it1).ss.erase(fit);
            }
        }
        if(it1==mapp.end()) break;
        it++;
    }
    string ffir="0",sfir;
    while(it1!=mapp.end()){
       // fap(1);
        errr.clear();

        if(ffir=="0" and (*it1).ss.size()>=2){
            for(auto &v:(*it1).ss){
                if(errr.size()<2)
                    errr.pb(v);
                else break;
            }
            ffir=errr.at(0),sfir=errr.at(1);
            auto fit=(*it1).ss.find(errr.at(0));
            (*it1).ss.erase(fit);
            fit=(*it1).ss.find(errr.at(1));
            (*it1).ss.erase(fit);
            errr.clear();
        }
        else if((*it1).ss.size()>=2){
            //ans.pb(mp(ffir,sfir));
            //ffir="0";
            for(auto &v:(*it1).ss){
                errr.pb(v);
                if(errr.size()>=2) break;
            }

            ans.pb(mp(ffir,errr.at(0)));
            ans.pb(mp(sfir,errr.at(1)));
            auto fit=(*it1).ss.find(errr.at(0));
            (*it1).ss.erase(fit);
            fit=(*it1).ss.find(errr.at(1));
            (*it1).ss.erase(fit);
            ffir="0";
            errr.clear();
        }
        else it1++;
    }

    loop:
    cout<<ans.size()/2<<endl;

    if(ans.size()){

        for(auto &v: ans){
            cout<<v.ff<<" "<<v.ss<<endl;
        }
    }

    return 0;
}


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
class data{
public:
    int zero;
    int neg;
    int pos;
};

#define vd vector<data>
#define LSOne(n) (n&(-n))

class FenwickTree{
    vd ft;
public:
    FenwickTree(vi _ara){
        int siz=_ara.size();
        ft.assign(siz+1,data());
        init();
        for(int i=0;i<siz;i++){
            add(i+1,_ara[i]);
        }
    }

    void init(){
        for(int i=0;i<ft.size();i++){
            ft[i].neg=ft[i].pos=ft[i].zero=0;
        }
    }

    void add(int i,int val){

        int cngpos=0,cngneg=0,cngzero=0;

        int pos=query(i,i);

        if(pos==0){
            if(val>0){
                cngneg=0;
                cngzero=-1;
                cngpos=1;
            }
            else if(val<0){
                cngneg=1;
                cngzero=-1;
                cngpos=0;
            }
        }
        else if(pos<0){
            if(val>0){
                cngneg=-1;
                cngzero=0;
                cngpos=1;
            }
            else if(val==0){
                cngneg=-1;
                cngzero=1;
                cngpos=0;
            }
        }
        else{
            if(val<0){
                cngneg=1;
                cngzero=0;
                cngpos=-1;
            }
            else if(val==0){
                cngneg=0;
                cngzero=1;
                cngpos=-1;
            }
        }

        for(;i<ft.size();i+=LSOne(i)){
           ft[i].pos+=cngpos;
           ft[i].neg+=cngneg;
           ft[i].zero+=cngzero;
        }
    }

    data query(int i){
        data temp;
        temp.neg=0;
        temp.pos=0;
        temp.zero=0;

        for(;i>0;i-=LSOne(i)){
            temp.neg+=ft[i].neg;
            temp.pos+=ft[i].pos;
            temp.zero+=ft[i].zero;
        }
        return temp;
    }

    int query(int i,int j){
        data first,scond;
        (i==1)? first=query(0):first=query(i-1);
        scond=query(j);

        int neg=scond.neg-first.neg;
        int pos=scond.pos-first.pos;
        int zero=scond.zero-first.zero;

        if(zero>0){
            return 0;
        }
        else if(neg&1){
            return -1;
        }
        else return 1;
    }
};

int main()
{
    //FI;FO;
    FASTIO;

    int n,k;

    while(cin>>n>>k){

        vi ara(n);
        fof(i,0,n){
            int x; cin>>x;
            ara[i]=x;
        }

        FenwickTree ft(ara);

        fof(i,0,k){
            char ch;
            cin>>ch;
            if(ch=='C'){
                int ii,val;
                cin>>ii>>val;
                ft.add(ii,val);
            }
            else{
                int i,j;
                cin>>i>>j;
                int val=ft.query(i,j);
                if(val>0){
                    cout<<"+";
                }
                else if(val<0){
                    cout<<"-";
                }
                else cout<<"0";
            }
        }
        cout<<endl;

    }

    return 0;
}


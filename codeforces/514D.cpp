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

#define K 25

class SparseTable{
    vector<vll> st;
    vi log;
public:
    SparseTable(vi ara){
        int n=ara.size();
        log.resize(n+5);
        log[1]=0;
        for(int i=2;i<=n;i++){
            log[i]=log[i/2]+1;
        }

        st.resize(n+5);

        fof(i,0,n){
            st[i].resize(K);
            st[i][0]=ara[i];
        }

        fof(j,1,K+1){
            for(int i=0;i+(1<<j)<=n;i++){
                st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            }
        }
    }

    ll rmq(int L,int R){
        int j=log[R-L+1];
        return min(st[L][j],st[R-(1<<j)+1][j]);
    }

};

ll sum(vi vec){
    ll tem=0;
    fof(i,0,vec.size()){
        tem+=vec[i];
    }
    return tem;
}

int mini(vi vec){
    int minii=1e7;
    fof(i,0,vec.size()) minii=min(minii,vec[i]);

    return minii;
}

int main()
{
    //FI;FO;
    FASTIO;

    int n,m,k;

    cin>>n>>m>>k;

    ll tempsum=0;

    vi ans(m,0);
    int maxlen=-1;
    //vll temp,last;

    deque<pii> dq[m+1];

    int added=0,removed=0;
    int idx=0;

    fof(i,0,n){

        fof(j,0,m){
            int x; cin>>x;

            while(!dq[j].empty() and dq[j].back().ff<x){
                dq[j].pop_back();
            }
            dq[j].pb(mp(x,added));
        }
        added++;

        vi temp;
        fof(j,0,m){
            temp.pb(dq[j].front().ff);
        }
        ll tempsum=sum(temp);

        if(tempsum<=k and (i-idx+1)>maxlen){
            maxlen=i-idx+1;
            ans=temp;
        }
        else if(tempsum>k){
            bool flag=false;
            fof(l,idx,i){

                fof(j,0,m){
                    if(!dq[j].empty()&&dq[j].front().ss==l){
                        dq[j].pop_front();
                    }
                }
                vi temp1;
                fof(j,0,m){
                    temp1.pb(dq[j].front().ff);
                }
                ll tempsum1=sum(temp1);

                if(tempsum1<=k){
                    idx=l+1;
                    if(i-idx+1>maxlen){
                        maxlen=i-idx+1;
                        ans=temp1;
                    }
                    flag=true;
                    break;
                }

            }
            
            if(!flag){
                idx=i;
            }
        }

    }

    print(ans);

    return 0;
}

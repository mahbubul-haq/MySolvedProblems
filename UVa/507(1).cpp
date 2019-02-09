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
#define INF 1e9
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define PI acos(-1.0)
//#define FIFO
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

class data{
public:
    pair<int,pii> ans,pref,suff,sum;
};

class SegmentTree{
    vi ara;
    vector< data > st;
    int n;
    int left(int node){ return (node<<1);}
    int right(int node){ return (node<<1)+1;}

    data make_data(int val,int idx){
        data temp;
        temp.pref=true? mp(val,mp(idx,idx+1)):mp(0,mp(idx+1,idx));
        temp.suff=true?mp(val,mp(idx,idx+1)):mp(0,mp(idx+1,idx));
        temp.sum=mp(val,mp(idx,idx+1));
        temp.ans=true? mp(val,mp(idx,idx+1)):mp(0,mp(idx+1,idx));
        return temp;
    }

    data combine(data lef,data rait){
        data temp;
        temp.sum=mp(lef.sum.ff+rait.sum.ff,mp(lef.sum.ss.ff,rait.sum.ss.ss));
        temp.suff=(rait.suff.ff>rait.sum.ff+lef.suff.ff)? rait.suff: mp(rait.sum.ff+lef.suff.ff,mp(lef.suff.ss.ff,rait.sum.ss.ss));
        temp.pref=(lef.pref.ff>lef.sum.ff+rait.pref.ff)? lef.pref:mp(lef.sum.ff+rait.pref.ff,mp(lef.sum.ss.ff,rait.pref.ss.ss));

        if(lef.ans.ff>rait.ans.ff&&lef.ans.ff>lef.suff.ff+rait.pref.ff){
            temp.ans=lef.ans;
        }
        else if(lef.suff.ff+rait.pref.ff>lef.ans.ff&&lef.suff.ff+rait.pref.ff>rait.ans.ff){
            temp.ans=mp(lef.suff.ff+rait.pref.ff,mp(lef.suff.ss.ff,rait.pref.ss.ss));
        }

        else if(rait.ans.ff>lef.ans.ff&&rait.ans.ff>lef.suff.ff+rait.pref.ff){
            temp.ans=rait.ans;
        }
        else if(lef.ans.ff>=rait.ans.ff&&lef.ans.ff>=lef.suff.ff+rait.pref.ff){
            pair<int,pii> temp1;
            if(lef.suff.ff+rait.pref.ff>=rait.ans.ff){
                if(lef.suff.ff+rait.pref.ff==rait.ans.ff){
                    (rait.pref.ss.ss-lef.suff.ff>=rait.ans.ss.ss-rait.ans.ss.ff)? temp1=mp(lef.suff.ff+rait.pref.ff,mp(lef.suff.ss.ff,rait.pref.ss.ss)): temp1=rait.ans;
                }
                else temp1=rait.ans;
            }
            else temp1=rait.ans;

            if(lef.ans.ff>=temp1.ff){
                if(lef.ans.ff==temp1.ff){
                    (temp1.ss.ss-temp1.ss.ff>lef.ans.ss.ss-lef.ans.ss.ff)? temp.ans=temp1:temp.ans=lef.ans;
                }
                else temp.ans=temp1;
            }
            else temp.ans=temp1;
        }
        else if(lef.suff.ff+rait.pref.ff>=lef.ans.ff&&lef.suff.ff+rait.pref.ff>=rait.ans.ff){

            if(lef.suff.ff+rait.pref.ff==rait.ans.ff){
                (rait.ans.ss.ss-rait.ans.ss.ff<=rait.pref.ss.ss-lef.suff.ss.ff)? temp.ans=mp(lef.suff.ff+rait.pref.ff,mp(lef.suff.ss.ff,rait.pref.ss.ss)):temp.ans=rait.ans;
            }
            else temp.ans=mp(lef.suff.ff+rait.pref.ff,mp(lef.suff.ss.ff,rait.pref.ss.ss));

        }
        else if(rait.ans.ff>=lef.ans.ff&&rait.ans.ff>=lef.suff.ff+rait.pref.ff){
            temp.ans=rait.ans;
        }

        return temp;
    }

    void build(int node,int L,int R){
        if(L==R){
            st[node]=make_data(ara[L],L+1);
        }
        else{
            int mid=(L+R)>>1;
            build(left(node),L,mid);
            build(right(node),mid+1,R);

            st[node]=combine(st[left(node)],st[right(node)]);
        }
    }

    pair<int,pii> query(int node,int L,int R){
        if(true) return st[node].ans;
        else{
            int mid=(L+R)>>1;
            pair<int,pii> val1=query(left(node),L,mid);
            pair<int,pii> val2=query(right(node),mid+1,R);

            if(val1.ff+val2.ff>=val1.ff&&val1.ff+val2.ff>=val2.ff) return mp(val1.ff+val2.ff,mp(val1.ss.ff,val2.ss.ss));
            else if(val1.ff>=val2.ff&&val1.ff>=val2.ff+val1.ff) return val1;
            else return val2;
        }
    };
public:
    SegmentTree(vi _ara){
        ara=_ara;
        n=ara.size();
        st.assign(8*n,data());
        build(1,0,n-1);
    }
    pair<int,pii> query(){
        return query(1,0,n-1);
    };
};

int main()
{
#ifdef FIFO
    FI;
    FO;
#endif
    FASTIO;

    int n; cin>>n;
    int cas=1;

    while(n--){
        int howmany;
        cin>>howmany;
        vi ara;

        for(int i=1;i<howmany;i++){
            int x; cin>>x;
            ara.pb(x);
        }

        SegmentTree st(ara);

        pair<int,pii> ans=st.query();

        if(ans.ff>0){
            //debug(ans.ff);
            cout<<"The nicest part of route "<<cas++<<" is between stops "<<ans.ss.ff<<" and "<<ans.ss.ss<<endl;
        }
        else cout<<"Route "<<cas++<<" has no nice parts"<<endl;
    }

    return 0;
}

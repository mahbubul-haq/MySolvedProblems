
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
    pii left,right,ans;
};

class SegmentTree{
    vector<data> st;
    vi ara;
    int n;
public:
    SegmentTree(vi _ara){
        n=_ara.size();
        ara=_ara;
        st.assign(8*n+1,data());
        build(1,0,n-1);
    }

    int left(int node){ return (node<<1);}
    int right(int node){ return (node<<1)+1;}

    data combine(data l,data r){
        data temp;
        if(l.left.ss==r.left.ss){
            temp.left=mp(l.ans.ff+r.left.ff,l.left.ss);
        }
        else temp.left=l.left;

        if(r.right.ss==l.right.ss){
            temp.right=mp(r.ans.ff+l.right.ff,r.right.ss);
        }
        else temp.right=r.right;

        pii tempp=mp(0,0);
        if(r.left.ss==l.right.ss){
            tempp=mp(r.left.ff+l.right.ff,l.right.ss);
        }

        tempp.ff<max(r.ans.ff,l.ans.ff)? tempp= (r.ans.ff>=l.ans.ff? r.ans: l.ans): tempp=tempp;
        temp.ans=tempp;

        return temp;

    }

    void build(int node,int L,int R){
        if(L==R){
            st[node].left=st[node].right=st[node].ans=mp(1,ara[L]);
            return;
        }

        int mid=(L+R)>>1;
        build(left(node),L,mid);
        build(right(node),mid+1,R);
        st[node]=combine(st[left(node)],st[right(node)]);
    }

    data make_data(){
        data temp;
        temp.ans=mp(0,0);
        temp.left=temp.right=temp.ans;
        return temp;
    }

    data query(int node,int L,int R,int i,int j){
        if(L>j||R<i) return make_data();
        if(R<=j&&L>=i){
            return st[node];
        }
        int mid=(L+R)>>1;
        data temp1=query(left(node),L,mid,i,j);
        data temp2=query(right(node),mid+1,R,i,j);
        temp1=combine(temp1,temp2);
        return temp1;
    }
};

int main()
{
    //FI;FO;
    FASTIO;

    int n,q;

    while(cin>>n>>q){
        vi ara;
        fof(i,0,n){
            int x; cin>>x;
            ara.pb(x);
        }
        SegmentTree st(ara);

        while(q--){
            int i,j;
            cin>>i>>j;
            i--,j--;
            cout<<st.query(1,0,n-1,i,j).ans.ff<<endl;
        }
    }

    return 0;
}

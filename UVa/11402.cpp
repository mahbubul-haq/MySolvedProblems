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
#define MOD 1000000007
#define EPS 1e-8
#define mem(x,y) memset(x,y,sizeof x)
#define INF 1e9
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define PI acos(-1.0)
#define FIFO true
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define debug(x) cout<<"WTH: "<<x<<endl;

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

pll operator+(const pll &a, const ll &b){ return { a.first+b,a.second+b };}
pll operator*(const pll &a,const ll &b){ return {a.first*b,a.second*b};}
pll operator+(const pll &a,const pll &b){ return {a.first+b.first,a.second+b.second};}
pll operator-(const pll &a,const pll &b){ return { a.first-b.first,a.second-b.second};}
pll operator*(const pll &a,const pll &b){ return {a.first*b.first,a.second*b.second};}
pll operator%(const pll &a,const pll &b){ return {a.first%b.first,a.second%b.second};}

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

///=======================================template=======================================///

class SegmentTree{
    vii st;
    string ara;
    int n;
    int left(int node){ return (node<<1);}
    int right(int node){ return (node<<1)+1;}

    void build(int node,int L,int R){
        if(L==R){
            if(ara[L]=='1') st[node].first=1;
            else st[node].first=0;
            st[node].second=0;
        }
        else{
            int mid=(L+R)/2;
            build(left(node),L,mid);
            build(right(node),mid+1,R);

            st[node].first=st[left(node)].first+st[right(node)].first;
            st[node].second=0;
        }
    }

    int doFlip(int now){
        if(now==0) return 3;
        else if(now==2) return 1;
        else if(now==1) return 2;
        else return 0;
    }

    void propagate(int node,int l,int r){

        if(st[node].second==0) return;
        if(st[node].second==1){
            st[node].first=r-l+1;
        }
        else if(st[node].second==2){
            st[node].first=0;
        }
        else if(st[node].second==3){
            st[node].first=r-l+1-st[node].first;
        }
        if(l!=r){
            if(st[node].second==1||st[node].second==2){
                st[left(node)].second=st[right(node)].second=st[node].second;
            }
            else{
                st[left(node)].second=doFlip(st[left(node)].second);
                st[right(node)].second=doFlip(st[right(node)].second);
            }
        }

        st[node].second=0;

    }

    int query(int node,int L,int R,int i,int j){
        propagate(node,L,R);

        if(i>R||j<L) return 0;
        if(L>=i&&R<=j){
            return st[node].first;
        }

        int mid=(L+R)/2;

        int val1=query(left(node),L,mid,i,j);
        int val2=query(right(node),mid+1,R,i,j);

        return val1+val2;
    }

    void updateF(int node,int L,int R,int i,int j){
        propagate(node,L,R);

        if(i>R||j<L) return;
        if(L>=i&&R<=j){
            st[node].first=R-L+1;
            st[left(node)].second=st[right(node)].second=1;
        }
        else{
            int mid=(L+R)/2;

            updateF(left(node),L,mid,i,j);
            updateF(right(node),mid+1,R,i,j);
            st[node].first=st[left(node)].first+st[right(node)].first;
        }
    }

    void updateE(int node,int L,int R,int i,int j){
        propagate(node,L,R);

        if(i>R||j<L) return;
        if(L>=i&&R<=j){
            st[node].first=0;
            st[left(node)].second=st[right(node)].second=2;
        }
        else{
            int mid=(L+R)/2;

            updateE(left(node),L,mid,i,j);
            updateE(right(node),mid+1,R,i,j);
            st[node].first=st[left(node)].first+st[right(node)].first;
        }
    }

    void updateI(int node,int L,int R,int i,int j){
        propagate(node,L,R);

        if(i>R||j<L) return;
        if(L>=i&&R<=j){
            st[node].first=R-L+1-st[node].first;
            st[left(node)].second=doFlip(st[left(node)].second);
            st[right(node)].second=doFlip(st[right(node)].second);
        }
        else{
            int mid=(L+R)/2;

            updateI(left(node),L,mid,i,j);
            updateI(right(node),mid+1,R,i,j);
            st[node].first=st[left(node)].first+st[right(node)].first;
        }
    }

public:
    SegmentTree(string _ara){
        ara=_ara;
        n=ara.size();
        st.assign(8*n+100,pii(0,0));
        build(1,0,n-1);
    }
    int query(int i,int j){
        return query(1,0,n-1,i,j);
    }
    void updateF(int i,int j){
        updateF(1,0,n-1,i,j);
    }
    void updateE(int i,int j){
        updateE(1,0,n-1,i,j);
    }
    void updateI(int i,int j){
        updateI(1,0,n-1,i,j);
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
/*
#ifdef FIFO
    FI;
    FO;
#endif*/

    int t; cin>>t;

    for(int cas=1;cas<=t; cas++){

        int m; cin>>m;

        string ara;

        for(int i=0;i<m;i++){
            int x; cin>>x;
            string temp; cin>>temp;

            for(int j=0;j<x;j++) ara+=temp;

        }
       /// debug(ara);

        SegmentTree st(ara);
        cout<<"Case "<<cas<<":"<<endl;

        int q; cin>>q;
        int cnt=0;
        for(int i=0;i<q;i++){
            char ch;
            int lef,rig;
            cin>>ch>>lef>>rig;

            if(ch=='F') st.updateF(lef,rig);
            if(ch=='E') st.updateE(lef,rig);
            if(ch=='I') st.updateI(lef,rig);
            if(ch=='S'){
                cout<<"Q"<<++cnt<<": ";
                cout<<st.query(lef,rig)<<endl;
            }
        }
    }

    return 0;
}

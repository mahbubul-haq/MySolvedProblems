#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define vi vector<int>
#define vii vector<pii>
#define vll vector<ll>
#define MOD 1000000007
#define EPS 1e-7
#define mem(x,y) memset(x,y,sizeof x)
#define INF 1e9
#define ff(i,a,b) for(int i=(a);i<=(b);i++)
#define fb(i,a,b) for(int i=(a);i>=(b);i--)
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())

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

class SegmentTree{
    vi st,ara;
    int n;
    int left(int node){ return (node<<1);}
    int right(int node){ return (node<<1)+1;}
    void build(int node,int L,int R){
        if(L==R){
            st[node]=ara[L];
            return;
        }
        build(left(node),L,(L+R)/2);
        build(right(node),(L+R)/2+1,R);

        st[node]= st[left(node)]+st[right(node)];
    }
    int rsq(int node,int L,int R,int i,int j){
        if(i>R||j<L){ return 0;}
        if(L>=i&&R<=j){
            return st[node];
        }
        int val1=rsq(left(node),L,(L+R)/2,i,j);
        int val2=rsq(right(node),(L+R)/2+1,R,i,j);

        return val1+val2;
    }

    void update(int node,int L,int R,int i,int value){
        if(i<L||i>R) return;
        if(i==L&&i==R){
            st[node]=st[node]+value;
            return;
        }

        update(left(node),L,(L+R)/2,i,value);
        update(right(node),(R+L)/2+1,R,i,value);
        st[node]=st[left(node)]+st[right(node)];

    }

public:
    SegmentTree(vi _ara){
        ara=_ara;
        n=ara.size();
        st.assign(4*n,0);
        build(1,0,n-1);
    }
    int rsq(int i,int j) { return rsq(1,0,n-1,i,j);}
    void update(int i,int value){ update(1,0,n-1,i,value);}
};

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; scanf("%d",&T);

    for(int cas=0;cas<T;cas++){
        int n,q;
        scanf("%d%d",&n,&q);

        vi ara;
        for(int i=0;i<n;i++) {
            int x; scanf("%d",&x); ara.pb(x);
        }
        SegmentTree st(ara);
        printf("Case %d:\n",cas+1);
        for(int i=0;i<q;i++){

            int wq; scanf("%d",&wq);
            if(wq==1){
                int ii; scanf("%d",&ii);
                int val=st.rsq(ii,ii);
                printf("%d\n",val);
                st.update(ii,-val);
            }
            else if(wq==2){
                int ii,val;
                scanf("%d %d",&ii,&val);
                st.update(ii,val);

            }
            else{
                int ii,val;
                scanf("%d %d",&ii,&val);
                printf("%d\n",st.rsq(ii,val));
            }


        }

    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define MOD 998244353
#define EPS 1e17
#define mem(x,y) memset(x,y,sizeof x)
#define INF 1e18
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

///=======================================template=======================================///

class SegmentTree{
    vector<pair<int,pii > > st;
    vector<char> ara;
    int n;
    int left(int node){ return (node<<1);}
    int right(int node){ return (node<<1)+1;}

    void build(int node,int L,int R){
        if(L==R){
            st[node].first=0;
            if(ara[L]=='('){
                st[node].second=pii(1,0);
            }
            else{
                st[node].second=pii(0,1);
            }
        }
        else{
            int mid=(L+R)/2;
            build(left(node),L,mid);
            build(right(node),mid+1,R);

            int ans=0;

            int mini=min(st[left(node)].second.first,st[right(node)].second.second);

            ans+=mini*2+st[left(node)].first+st[right(node)].first;
            st[node].first=ans;
            st[node].second=pii(st[left(node)].second.first+st[right(node)].second.first-mini,st[left(node)].second.second+st[right(node)].second.second-mini);
        }
    }

    pair<int,pii> query(int node,int L,int R,int i,int j){
        if(i>R||j<L) return pair<int,pii>(0,pii(0,0));
        if(L>=i&&R<=j) return pair<int,pii>(st[node].first,pii(st[node].second.first,st[node].second.second));
        int mid=(L+R)/2;
        pair<int,pii> temp1=query(left(node),L,mid,i,j);
        pair<int,pii> temp2=query(right(node),mid+1,R,i,j);

        int mini=min(temp1.second.first,temp2.second.second);
        return pair<int,pii>(temp1.first+temp2.first+mini*2,pii(temp1.second.first+temp2.second.first-mini,temp1.second.second+temp2.second.second-mini));
    }

public:
    SegmentTree(vector<char> _ara){
        ara=_ara;
        n=ara.size();
        st.assign(4*n+1,pair<int,pii >());
        build(1,0,n-1);
    }
    int query(int i,int j){ return query(1,0,n-1,i,j).first;}
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string input;
    cin>>input;
    vector<char> vec;

    for(int i=0;i<input.size();i++){
        vec.pb(input[i]);
    }
    int q; cin>>q;

    SegmentTree st(vec);

    for(int i=0;i<q;i++){
        int from,to;
        cin>>from>>to;
        from--,to--;
        cout<<st.query(from,to)<<endl;
    }

    return 0;
}

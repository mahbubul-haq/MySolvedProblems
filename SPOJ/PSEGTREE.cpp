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
    for(int i=1;i<siz(vec);i++) cout<<vec[i]<<" ";cout<<endl;
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

///=======================================template=======================================//

class node{
public:
    int val;
    node *left,*right;

    node(node *l,node *r,int v){
        left=l,right=r;
        val=v;
    }
};


vector<node*> version;
vi ara;
int n;

void build(node *n,int L,int R){
    if(L==R) n->val=ara[L];
    else{
        int mid=(L+R)>>1;
        n->left=new node(NULL,NULL,0);
        n->right=new node(NULL,NULL,0);
        build(n->left,L,mid);
        build(n->right,mid+1,R);
        n->val=n->left->val+n->right->val;
    }
}

void upgrade(node *prev,node *curr,int L,int R,int id,int val){
    if(id>R or id<L) return;
    if(L==R){
        curr->val=val+prev->val;
        return;
    }

    int mid=(L+R)>>1;
    if(id<=mid){
        curr->right=prev->right;
        curr->left=new node(NULL,NULL,0);
        upgrade(prev->left,curr->left,L,mid,id,val);
    }
    else{
        curr->left=prev->left;
        curr->right=new node(NULL,NULL,0);
        upgrade(prev->right,curr->right,mid+1,R,id,val);
    }
    curr->val=curr->left->val+curr->right->val;
}

int query(node *n,int L,int R,int l,int r){
    if(l>R or r<L) return 0;
    if(L>=l and R<=r) return n->val;
    int mid=(L+R)>>1;
    int val1=query(n->left,L,mid,l,r);
    int val2=query(n->right,mid+1,R,l,r);
    return val1+val2;
}

int main()
{
    //FI;FO;
    FastIO;

    cin>>n;
    ara.resize(n);

    for(int i=0;i<n;i++) cin>>ara[i];

    node *root=new node(NULL,NULL,0);
    build(root,0,n-1);
    int cnt=0;
    version.emplace_back();
    version[cnt++]=root;

    int q; cin>>q;

    while(q--){
        int t; cin>>t;
        if(t==1){
            int idx,pos,v;
            cin>>idx>>pos>>v;
            version.emplace_back();
            version[cnt++]=new node(NULL,NULL,0);
            upgrade(version[idx],version[cnt-1],0,n-1,pos-1,v);
        }
        else{
            int idx,l,r;
            cin>>idx>>l>>r;
            cout<<query(version[idx],0,n-1,l-1,r-1)<<endl;
        }
    }

    return 0;
}

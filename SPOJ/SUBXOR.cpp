#include <bits/stdc++.h>
using namespace std;

#define dist2D(x1,y1,x2,y2)         ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2)   ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS                         1e-16
#define endl                        "\n"
#define FastIO                      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt","r",stdin)
#define FO                          freopen("out.txt","w",stdout)
#define fap(x)                      cout<<"WTH: "<<x<<endl
#define ff                          first
#define fof(i,x,y)                  for(int i=x;i<(int)y;i++)
#define fob(i,x,y)                  for(int i=x;i>=(int)y;i--)
#define INF              1000000000000000000
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
#define timeTaken                   endd=clock();cout<<(double)(endd-beginn)/CLOCKS_PER_SEC*1000<<endl
#define timeInit                    clock_t beginn=clock(),endd
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
#define vvll                        vector<vll>
#define vpll                        vector<pll>


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;

//os.order_of_key(v): returns how many elements strictly less than v
//os.find_by_order(k-1): returns kth smallest element's iterator


template<class T> class compare{
public:
    bool operator()(pair<T,T> &x,pair<T,T> &y){
        if(x.first==y.first){
            return x.ss>y.ss;
        }
        return x.ff>y.ff;
    }
};

//template<class T> ostream& operator<<(ostream &os,const pair<T,T> &a) { os<<a.ff<<" "<<a.ss; }
ll power(ll a,int b) {
    ll po = 1;
    while (b) {
        if (b & 1)
            po *= a;
        a *= a;
        b >>= 1;
    }
    return po;
}

template<class T> pair<T,T> operator+(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff+b.ff,a.ss+b.ss}; }
template<class T> pair<T,T> operator-(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff-b.ff,a.ss-b.ss}; }
template<class T> pair<T,T> operator*(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff*b.ff,a.ss*b.ss}; }
template<class T> pair<T,T> operator%(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff%b.ff,a.ss%b.ss}; }
template<class T,class U> pair<T,T> operator+(const pair<T,T> &a,const U &b){ return { a.ff+b,a.ss+b}; }
template<class T,class U> pair<T,T> operator*(const pair<T,T> &a,const U &b){ return { a.ff*b,a.ss*b}; }

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(ll N,int pos){  return (bool) (N&(1LL<<pos));}

///=======================================template=======================================///

ll ans;

class node{
public:
    node *left,*right,*parent;
    ll val;
    node(){
        left=right=parent=NULL;
        val=0;
    }
} *root;

void update(node *root, string &s, int level){
    if(s[level]=='0'){
        if(root->left==NULL){
            root->left=new node();
            root->left->parent=root;
        }
        if(level==20)
            root->left->val++;
        else
            update(root->left,s,level+1);
    }
    else{
        if(root->right==NULL){
            root->right=new node();
            root->right->parent=root;
        }
        if(level==20)
            root->right->val++;
        else
            update(root->right,s,level+1);
    }
    root->val=(root->left!=NULL? root->left->val:0)+(root->right!=NULL? root->right->val:0);
}

void add(node *root,string &ks,string &s, int level){
    if(level==21 or root==NULL)
        return ;
    if(ks[level]=='1'){
        if(s[level]=='1'){
            if(root->right!=NULL){
                ans+=root->right->val;
            }
            add(root->left,ks,s,level+1);
        }
        else{
            if(root->left!=NULL)
                ans+=root->left->val;
            add(root->right,ks,s,level+1);
        }
    }
    else{
        if(s[level]=='1'){
            add(root->right,ks,s,level+1);
        }
        else{
            add(root->left,ks,s,level+1);
        }
    }
}

int main()
{
    //FI;//FO;
    FastIO;//timeInit;

    int t;
    cin>>t;

    while(t-- > 0){
        ans=0;
        int n; cin>>n;
        int k; cin>>k;
        int zor=0;
        root=new node();
        string ks;
        bitset<21> bs2(k);
        for(int i=0;i<21;i++){
            if(bs2[i])
                ks+='1';
            else ks+='0';
        }
        reverse(ks.begin(),ks.end());

        bitset<21> bs3(0);
        string s3;
        for(int i=0;i<21;i++){
            if(bs3[i])
                s3+='1';
            else s3+='0';
        }
        reverse(s3.begin(),s3.end());
        update(root,s3,0);

        while(n--){
            int x; cin>>x;
            zor^=x;
            bitset<21> bs(zor);
            string s;
            for(int i=0;i<21;i++){
                if(bs[i])
                    s+='1';
                else s+='0';
            }
            reverse(s.begin(),s.end());
            add(root,ks,s,0);
            update(root,s,0);
        }

        cout<<ans<<endl;

    }

    //timeTaken;
    return 0;
}

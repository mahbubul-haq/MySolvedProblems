#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define PQ priority_queue
#define ld long double
#define ll long long
#define pll pair<ll,ll>
#define vb vector<bool>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define vpll vector<pll>
#define MOD 1000000007
#define EPS 1e-12
#define mem(x,y) memset(x,y,sizeof x)
#define INF 100000000
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define FastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define PI acos(-1.0)
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define debug(x) cout<<"WTH: "<<x<<endl
#define fof(i,x,y) for(int i=x;i<(int)y;i++)
#define fob(i,x,y) for(int i=x;i>=(int)y;i--)

template<class T>
class compare{
public:
    bool operator()(pair<T,T> &x,pair<T,T> &y){
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
void print(vector<T> &vec){
    fof(i,0,vec.size()) cout<<vec[i]<<" "; cout<<endl;
}
template<class T>
void print(set<T> &s){
    for(auto it: s) cout<<it++<<" "; cout<<endl;
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

class node{
public:
    bool endmark;
    node* next[11];///only for lowercase letters

    node(){
        endmark=false;
        fof(i,0,11)next[i]=NULL;
    };
} ;

class Trie {
public:

    Trie(){
        //root=new node();
    }

    bool insert(string str, node* root) {
        int len = str.length();

        node* curr = root;
        fof(i, 0, len) {
            int id = str[i] - '0';
            if(curr->endmark) return true;
            if (curr->next[id] == NULL) curr->next[id] = new node();
            curr = curr->next[id];
        }
        curr->endmark = true;
        return false;
    }

    bool search(string str,node* root) {
        int len = str.length();

        node *curr = root;
        fof(i, 0, len) {
            int id = str[i] - '0';
            if (curr->next[id] == NULL) return false;

            curr = curr->next[id];
        }
        return curr->endmark;
    }

    void del(node* curr) {
        fof(i, 0, 11) {
            if (curr->next[i]!=NULL) del(curr->next[i]);
        }
        delete(curr);
    }
};

int main()
{
    //FI;FO;
    FastIO;

    int t; cin>>t;

    while(t--) {
        vector< pair<int, string> > vec;

        int n; cin>>n;
        int n1=n;

        while(n1--){
            string str; cin>>str;

            vec.pb(mp(str.size(),str));
        }

       // debug("hi");
        sortv(vec);
        node* root=new node();
        Trie tri;

        int i=0;

        while (i<n) {

            //cout<<vec[i].ss<<endl;
            if(tri.insert(vec[i].ss, root)){
                cout<<"NO"<<endl;
                break;
            }
            i++;
        }

        if(i==n){
            cout<<"YES"<<endl;
        }
        tri.del(root);
    }

    return 0;
}


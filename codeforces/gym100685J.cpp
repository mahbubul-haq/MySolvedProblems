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

class Node{
public:
    int key;
    Node *left,*right;
    int height;
};

Node * newNode(int key){
    Node *node=new Node();
    node->key=key;
    node->height=1;
    node->left=node->right=NULL;
    return node;
}

int height(Node *node){
    if(node==NULL) return 0;
    return node->height;
}
vi ans;
void inOrder(Node *node){
    if(node!=NULL){
        inOrder(node->left);
        ans.pb(node->key);
        inOrder(node->right);
    }
}

Node *leftRotate(Node *node){
    Node *temp=node->right;
    Node *t2=temp->left;

    temp->left=node;
    node->right=t2;

    node->height=1+max(height(node->left),height(node->right));
    temp->height=1+max(height(temp->left),height(temp->right));

    return temp;
}

Node *rightRotate(Node *node){
    Node *temp=node->left;
    Node *t2=temp->right;

    temp->right=node;
    node->left=t2;

    node->height=1+max(height(node->left),height(node->right));
    temp->height=1+max(height(temp->left),height(temp->right));

    return temp;
}

int getBalance(Node *node){
    if(node==NULL) return 0;
    return height(node->left)-height(node->right);
}

Node *insert(Node *node, int key){
    if(node==NULL){
        return newNode(key);
        //return node;
    }
    cout<<"1 "<<key<<" "<<node->key<<endl;
    string input;
    cin>>input;
    if(input=="YES"){
        node->left=insert(node->left,key);
    }
    else{
        node->right=insert(node->right,key);
    }

    node->height=1+max(height(node->left),height(node->right));

    int balance=getBalance(node);

    if(balance>1 and getBalance(node->left)>=0){
        return rightRotate(node);
    }
    if(balance>1){
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }

    if(balance<-1 and getBalance(node->right)<=0){
        return leftRotate(node);
    }
    if(balance<-1){
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }

    return node;

}

int main()
{
    //FI;FO;
    FastIO;

    int n; cin>>n;
    Node *root=NULL;

    for(int i=1;i<=n;i++){
        root=insert(root,i);
    }

    inOrder(root);

    for(int i=0;i<siz(ans)-1;i++){
        cout<<"1 "<<ans[i]<<" "<<ans[i+1]<<endl;
        string input;
        cin>>input;
        if(input=="NO"){
            ans.assign(n,0);
            break;
        }
    }

    cout<<"0";
    for(auto v: ans) cout<<" "<<v;
    cout<<endl;

    return 0;
}

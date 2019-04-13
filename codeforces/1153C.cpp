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
    for(int i=0;i<siz(vec);i++) cout<<vec[i]<<" ";cout<<endl;
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

///=======================================template=======================================///

int main()
{

    //FI;FO;
    FastIO;

    int n; cin>>n;

    string input; cin>>input;

    stack<char> stk;
    stack<int > what,stk1;
    bool flag=false;

    if(input[0]!=')'){
        stk1.push(0);
        stk.push('(');
        input[0]='(';
    }
    else flag=true;

    for(int i=1;i<n;i++){
        if(input[i]=='('){
            stk.push('(');
            stk1.push(i);
        }
        else if(i==n-1){
            what.push(i);
            input[i]=')';
        }
        else if(input[i]==')'){
            if(stk.size()==1 and i==n-1){
                stk.pop();
                stk1.pop();
            }
            else if(what.size()==1 and i==n-1){
                int id=what.top();
                what.pop();
                input[id]='(';
            }
            else if(stk.size()<2){


                if(what.size()+stk.size()<2) {
                    flag = true;
                    break;
                }
                else{
                    int pci=what.top();
                    what.pop();
                    input[pci]='(';
                }
            }
            else {
                stk.pop();
                stk1.pop();
            }
        }
        else{
            what.push(i);
        }

    }
    if(flag){
        cout<<":("<<endl;
    }
    else if(stk1.size()>what.size()){
        cout<<":("<<endl;
    }
    else{

        if(stk1.size()==0 and what.size()==0){
            cout<<input<<endl;
        }
        else{
            deque<int> dq;

            while(stk1.size()){
                dq.push_back(stk1.top());
                stk1.pop();
            }

            if(dq.size()) {
                int iii = dq.back();
                int jj = what.top();
                what.pop();
                dq.pop_back();

                if (jj < iii) {
                    cout << ":(" << endl;
                    return 0;
                } else input[jj] = ')';
            }

            while(dq.size()){
                int ii=dq.front();
                dq.pop_front();
                int id=what.top();
                what.pop();
                if(id<ii){
                    cout<<":("<<endl;
                    return 0;
                }
                else input[id]=')';
            }

            if(what.size()&1){
                cout<<":("<<endl;
                return 0;
            }
            else{
                int si=what.size();


                for(int i=1;i<=si/2;i++){
                    int id=what.top();
                    what.pop();
                    input[id]=')';
                }
                for(int i=1;i<=si/2;i++){
                    int id=what.top();
                    what.pop();
                    input[id]='(';
                }
                cout<<input<<endl;
            }
        }
    }



    return 0;
}

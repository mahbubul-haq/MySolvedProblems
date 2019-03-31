/*not sure why getting wrong answer, passes all sample test cases of uDebug.*/

#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<<"WTH: "<<x<<endl
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS 1e-12
#define FastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define ff first
#define fof(i,x,y) for(int i=x;i<(int)y;i++)
#define fob(i,x,y) for(int i=x;i>=(int)y;i--)
#define INF 100000
#define ld long double
#define ll long long
#define mem(x,y) memset(x,y,sizeof x)
#define mp make_pair
#define msi map<string,int>
#define mii map<int,int>
#define mis map<int,string>
#define MOD 1000000007
#define PI acos(-1.0)
#define PQ priority_queue
#define pb push_back
#define pib pair<int,bool>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sfi(x) scanf("%d",&x)
#define sfii(x,y) scanf("%d%d",&x,&y)
#define sfiii(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define siz(x) (int)x.size()
#define sortv(v) sort(v.begin(),v.end())
#define ss second
#define umsi unordered_map<string,int>
#define umii unordered_map<int,int>
#define umis unordered_map<int,string>
#define vb vector<bool>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define vpll vector<pll>
#define vs vector<string>

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
    fof(i,0,vec.size()) {
        if(i!=0) cout<<" ";
        cout<<vec[i];
    }
}
template<class T>
void print(set<T> &s){
    for(auto it: s) cout<<it<<" "; cout<<endl;
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

int n;

vector<pair<int,vs> > g;//adjLst
stack<string> ans;

void dfs(int id){
    g[id].ff--;
    string now=g[id].ss.back();
    g[id].ss.pop_back();

    int idd=now[siz(now)-1]-'a'+1;
    while(g[idd].ff){
        dfs(idd);
    }
    ans.push(now);
}

int main()
{
    //FI;FO;
   // FastIO;

    int t; cin>>t;

    fof(cas,1,t+1){
        g.assign(27,pair<int,vs>());

        cin>>n;

        int firs[27],last[27];
        mem(firs,0);
        mem(last,0);

        int cntf=0,cntl=0;

        int idd;
        fof(i,0,n){
            string input; cin>>input;
            int id=input[0]-'a'+1;
            idd=id;
            int id1=input[siz(input)-1]-'a'+1;
            g[id].ff++;
            g[id].ss.pb(input);
            firs[id]++;
            last[id1]++;
        }

        bool flag=true;

        for(int i=1;i<=26;i++){
            if(abs(firs[i]-last[i])>=2) flag=false;
            else if(firs[i]-last[i]==1){
                cntf++;
                idd=i;
            }
            else if(last[i]-firs[i]==1){
                cntl++;
            }
        }

        if((cntf==0 and cntl==0) or (cntl==1 and cntf==1)){

            while(g[idd].ff)
                dfs(idd);

        }
        else flag=false;

        cout<<"Case "<<cas<<": ";

        vs ans1;

        if(flag){

            int ii=0;
            while(!ans.empty()){
                //if(ii) cout<<" ";
                ans1.pb(ans.top());
                //cout<<ans.top()<<endl;
                ans.pop();
                ii++;
            }
            if(ans1.size()==n) {
                cout<<"Yes"<<endl;

                vs ans2;

                vs ans3;
                ans2.pb(ans1[0]);
                int i=1;
                for(;i<siz(ans1);i++){
                    string now=ans2.back();
                    if(ans1[i][0]!=now[siz(now)-1]) break;
                    ans2.pb(ans1[i]);
                }
                while(i<siz(ans1)){
                    ans3.pb(ans1[i]);
                    i++;
                }
                if(siz(ans3)==0){
                    for(int j=0;j<siz(ans2);j++){
                        if(j!=0) cout<<" ";
                        cout<<ans2[j];
                    }
                    cout<<endl;
                }
                else{

                    char fir=ans3[0][0];
                    char las=ans3[siz(ans3)-1][siz(ans3[siz(ans3)-1])-1];
                    bool flagg=false;
                    if(las==ans2[0][0]){
                        for(int j=0;j<siz(ans3);j++){
                            cout<<ans3[j]<<" ";
                        }
                        flagg=true;
                    }

                    cout<<ans2[0];
                    string now=ans2[0];
                    for(int j=1;j<siz(ans2);j++){
                        if(now[siz(now)-1]==fir and las==ans2[j][0] and !flagg){
                            for(int jj=0;jj<siz(ans3);jj++) cout<<" "<<ans3[jj];
                            flagg=true;
                        }
                        cout<<" "<<ans2[j];
                        now=ans2[j];
                    }

                    cout<<endl;

                }
            }
            else cout<<"No"<<endl;
        }
        else cout<<"No"<<endl;

    }

    return 0;
}

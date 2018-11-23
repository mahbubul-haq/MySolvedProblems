#include<bits/stdc++.h>
using namespace std;


#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<long,long>
#define vi vector<int>
#define vii vector<pii>
#define vll vector<ll>
#define MOD 1000000007
#define EPS 1e-7
#define mem(x,y) memset(x,y,sizeof x)
#define INF 1e9
#define ff(i,a,b) for(int i=(a);i<=(b);i++)
#define fb(i,a,b) for(int i=(a);i>=(b);i--)

class compare{
public:
    bool operator()(pii x,pii y){
        if(x.second==y.second){
            return x.first<y.first;
        }
        return x.second<y.second;
    }
};
int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

///Graph input: V E; next E lines edges with weights u, v, w
/*5 9
  0 1 2
  0 2 1
  0 4 3
  1 3 4
  2 1 1
  2 4 1
  3 0 1
  3 2 3
  3 4 5
 */

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    ll AdjMat[n][n];

    ff(i,0,n-1){
        ff(j,0,n-1){
            int w; cin>>w;
            AdjMat[i][j]=w;
        }
    }

    int x[n];


    ff(i,0,n-1) cin>>x[i];
    bool taken[n];
    mem(taken,false);
    ll ans[n];

    fb(k,n-1,0){
        //taken[k]=true;
        int kk=x[k]-1;
        taken[kk]=true;

        ff(i,0,n-1){
            ff(j,0,n-1){
                if(taken[i]&&taken[j]){
                    AdjMat[kk][i]=min(AdjMat[kk][i],AdjMat[kk][j]+AdjMat[j][i]);
                    AdjMat[i][kk]=min(AdjMat[i][kk],AdjMat[i][j]+AdjMat[j][kk]);
                }
            }
        }

        ff(i,0,n-1){
            ff(j,0,n-1){
                if(taken[i]&&taken[j]){
                    if(AdjMat[i][j]>AdjMat[i][kk]+AdjMat[kk][j]){
                        AdjMat[i][j]=AdjMat[i][kk]+AdjMat[kk][j];
                    }
                }
            }
        }

        ll sum=0;

        ff(i,0,n-1){
            ff(j,0,n-1){
                if(taken[i]&&taken[j]){
                    sum+=AdjMat[i][j];
                }
            }
        }

        ans[k]=sum;
    }

    ff(i,0,n-1) cout<<ans[i]<<" ";

    return 0;
}

#include<iostream>
#include<cstdio>
#include<set>
#include<queue>
#include<cstring>
#include<math.h>
#include<map>
#include<string>
#include<climits>
#include<algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <list>
#include <iterator>
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
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define debugx(x) cout<<"WTH! "<<x<<endl
#define debug(x,y) cout<<x<<" "<<y<<endl

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

long long compute_hash(string const &s){
    const int p=59;///only lowercase alphabets
    const int m=1e9+7;

    long long hash_value=0;
    long long p_pow=1;

    for(char c: s){
        hash_value=((hash_value+(c-'a'+1))*p_pow)%m;
        p_pow=(p_pow*p)%m;
    }
    return hash_value;
}

vector< vi > group_identical_strings(vector<string> const &s){
    int siz=s.size();

    vector<pair<long long,int> > hashes(siz);

    for(int i=0;i<siz;i++) hashes[i]={compute_hash(s[i]),i};

    sortv(hashes);

    vector<vector<int> > groups;

    for(int i=0;i<siz;i++){
        if(i==0||hashes[i].first!=hashes[i-1].first){
            groups.emplace_back();
        }
        groups.back().push_back(hashes[i].second);
    }

    return groups;

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string input;

    while(cin>>input&&input!="0"){
        int siz=input.size();

        int cnt[2005];
        mem(cnt,0);

        bool flag=false;

        for(int i=1;i<siz;i++){
            if(input[i]=='0'){
                if(cnt[i]&1){
                    if(!flag) {
                        cout<<i;
                        flag=true;
                    }
                    else cout<<" "<<i;

                    for(int j=i;j<=siz;j+=i) cnt[j]++;
                }
            }
            else{
                if(cnt[i]%2==0){
                    if(!flag) {
                        cout<<i;
                        flag=true;
                    }
                    else cout<<" "<<i;

                    for(int j=i;j<=siz;j+=i) cnt[j]++;
                }
            }
        }
        cout<<endl;

    }

    return 0;
}

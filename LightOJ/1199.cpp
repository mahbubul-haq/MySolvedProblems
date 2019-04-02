#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define ll long long

int g[10005];

int grandi(int u){

    for(int i=3;i<=u;i++){
        set<int> s;
        for(int j=1;j<=i/2;j++){
            if(i-j!=j){
                s.insert(g[j]^g[i-j]);
            }
        }
        int ii=0;

        for(auto it: s){
            if(it!=ii) break;
            ii++;
        }
        g[i]=ii;
    }

}

int main(){

    int t; cin>>t;

    g[0]=g[1]=g[2]=0;
    grandi(10000);

    for(int i=1;i<=t;i++)
    {
        int sum=0;
        int n; cin>>n;
        while(n--){
            int x; cin>>x; sum^=g[x];
        }

         cout<<"Case "<<i<<": ";

        if(sum) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }


    return 0;
}

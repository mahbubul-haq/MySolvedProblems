#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int main(){

    int t; cin>>t;
    int ara[1005];

    while(t--){
        int n; cin>>n;

        ll sum=0;

        //int ara[n+1];

        for(int i=1;i<=n;i++) cin>>ara[i];

        sort(ara+1,ara+n+1);

        bool flag=(n&1);
        int last=0;
        for(int i=1;i<=n;i++){
            int y=ara[i];
            if(flag and i&1) sum^=(y-last-1);
            if(!flag and !(i&1)) sum^=(y-last-1);
            last=y;
        }
        if(sum) cout<<"Georgia will win"<<endl;
        else cout<<"Bob will win"<<endl;
    }

    return 0;
}

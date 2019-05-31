#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t; cin>>t;

    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<": ";
        int n; cin>>n;
        double prob=1;
        int cnt=1;
        while(prob>0.5){
            prob*=(n-cnt)*1.0/n;
            cnt++;
        }
        cout<<cnt-1<<endl;
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    int L,C,R1,R2;

    while(cin>>L>>C>>R1>>R2&&!(R1==0&&C==0&&R2==0&L==0)){
        double maxr=max(R1,R2);
        double minr=min(R1,R2);
        double mini=min(L,C);
        double maxi=max(L,C);

        if(mini>=2*maxr){
            if(maxi>=2*maxr+2*minr){
                cout<<"S"<<endl;
                continue;
            }
            else{

                double ang1,ang2;

                ang1=asin((mini-R1-R2)/(R1+R2));
                double ground=(R1+R2)*cos(ang1);

                if(maxi>=ground+R1+R2){
                    cout<<"S"<<endl;
                }
                else cout<<"N"<<endl;

            }

        }else cout<<"N"<<endl;
    }

    return 0;
}

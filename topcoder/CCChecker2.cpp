#include <bits/stdc++.h>
using namespace std;

class CCChecker2{
public:
    string check(int n, vector <int> startRow, vector <int> startCol, vector <int> destRow, vector <int> destCol, vector <int> moveStartRow, vector <int> moveStartCol, vector <int> moveDestRow, vector <int> moveDestCol){
        string valid="valid",invalid="invalid";

        map<pair<int,int>,int> current;

        for(int i=0;i<(int)startRow.size();i++){
            int id=startRow[i]*n+startCol[i];
            current[make_pair(startRow[i],startCol[i])]=id;
        }


        for(int i=0;i<(int)moveStartRow.size();i++){

            if(moveStartCol[i]>n or moveStartCol[i]<1 or moveDestCol[i]<1 or moveDestCol[i]>n or
               moveStartRow[i]>n or moveStartRow[i]<1 or moveDestRow[i]<1 or moveDestRow[i]> n){
                return invalid;
            }
            else if(abs(moveStartCol[i]-moveDestCol[i])+abs(moveStartRow[i]-moveDestRow[i])!=1){
                return invalid;
            }
            else{

                int id=current[make_pair(moveStartRow[i],moveStartCol[i])];

                if(id==0) return invalid;

                if(current[make_pair(moveDestRow[i],moveDestCol[i])]!=0){
                    return invalid;
                }
                else{
                    current[make_pair(moveDestRow[i],moveDestCol[i])]=id;
                    current[make_pair(moveStartRow[i],moveStartCol[i])]=0;
                }

            }

        }

        for(int i=0;i<(int)startRow.size();i++){
            int id=startRow[i]*n+startCol[i];
            if(current[make_pair(destRow[i],destCol[i])]!=id){
                return invalid;
            }
        }

        return valid;
    }
};

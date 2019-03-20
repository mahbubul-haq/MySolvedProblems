#include <bits/stdc++.h>
using namespace std;



class KerimJavati{
public:
    int howLong(string text){
        int cnt=0;
        
        for(int i=0;i<(int)text.size();i++){
            int id=text[i]-'a';
            cnt+=id*2+1;
        }
        
        return cnt;
    }
};

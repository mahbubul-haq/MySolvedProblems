#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class node{
public:
    int cnt;
    bool endmark;
    node* next[26];

    node(){
        cnt=0;
        endmark=false;
        for(int i=0;i<26;i++){
            next[i]=NULL;
        }
    }
} *root;

class Trie{
public:
    Trie(){
        root=new node();
    }

    void insert(string str){

        int siz=str.size();

        node* cur=root;

        for(int i=0;i<siz;i++){
            int id=str[i]-'a';
            if(cur->next[id]==NULL) cur->next[id]=new node();
            cur=cur->next[id];
            cur->cnt++;
        }
        cur->endmark=true;
    }

    string search(string str){
        int siz=str.size();
        node* cur=root;

        string temp;

        for(int i=0;i<siz;i++){

            if(i==siz-1){
                return str;
            }

            int id=str[i]-'a';

            if(cur->next[id]) cur=cur->next[id];

            if(cur->cnt==1){
                temp+=str[i];
                return temp;
            }
            else temp+=str[i];

        }
    }
};

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string input;

    vector<pair<int,string> > vec;
    Trie tri;

    vector<string> serial;

    while(cin>>input and !input.empty()){
        serial.push_back(input);
        tri.insert(input);
        vec.push_back(make_pair(input.size(),input));

    }

    sort(vec.begin(),vec.end());

    map<string,string> mapp;

    for(int i=0;i<vec.size();i++){
        mapp[vec[i].second]=tri.search(vec[i].second);
    }

    for(int i=0;i<serial.size();i++){
        cout<<serial[i]<<" "<<mapp[serial[i]]<<endl;
    }

    return 0;
}

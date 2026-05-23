#include <iostream>
#include <map>
#include <set>
using namespace std;
int main(){
    map <string,int> m;
    m.insert["ABC"]=1000;
    m.insert["DEF"]=100;
    m.insert["XYZ"]=2000;
    m.insert["HIJ"]=500;
    m.insert["RTS"]=5000;
    set <int>s;
    s.insert(1000);
    s.insert(100);
    s.insert(2000);
    s.insert(500);
    s.insert(5000);
    set <int> :: iterator it;
    map <string,int> :: iterator ii;
    for(it=s.begin();it!=s.end();it++){
        for(ii=m.begin();ii!=m.end();ii++){
            if(*it==ii->second){
                cout << ii->first << " "<< ii->second << endl;
                break;
            }
        }
    }
}
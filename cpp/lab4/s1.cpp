/*#include <iostream>
#include <set>
using namespace std;
int main(){
    set<int> s{};
    int a,b;
    cin >> a;
    for(int i=0;i<a;i++){
        cin >> b;
        switch (b)
        {
        case 1:
            int x;
            cin >> x;
                s.insert(x);
                cout << "Elements inserted succesfully" << endl;
            break;

        case 2:
            int search;
            cin >> search;
            for(auto it:s){
                if(it = search){
                    cout << "Element found" << endl;
                }
                else{
                    cout << "Element not found" << endl;
                }
            } 
        
        default:
            break;
        }
    }
}*/

/*#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;
int main(){
    int n,a;
    set<int> s;
    cin >> a;
    cout << "To insert enter 1" << endl << "To search enter 2" << endl;
    for(int i=0;i<a;i++){
        cin>>n;
        if(n==1){
            int x;
            cin>>x;
            if(s.find(x)!=s.end()){
                cout<<"number already there in the set"<<endl;
                continue;
            }
            s.insert(x);
        }
        else if(n==2){
            int x;
            cin>>x;
            if(s.find(x)!=s.end()){
                cout<<"Found"<<endl;
            }
            else{
                cout<<"Not Found"<<endl;
            }
        }
        else{
            break;
        }
    }
}*/

/*#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;
int main(){
    int n,a;
    multiset<int> s;
    cin >> a;
    cout << "To insert enter 1" << endl << "To search enter 2" << endl;
    for(int i=0;i<a;i++){
        cin>>n;
        if(n==1){
            int x;
            cin >> x;
            s.insert(x);
            if(s.find(x)!=s.end()){
                cout<<"number already there in the set"<<endl;
                continue;
            }
        }
        else if(n==2){
            int x;
            cin>>x;
            if(s.find(x)!=s.end()){
                cout<<"Found"<<endl;
                if(s.count(x)>1){
                    cout<<"There are "<<s.count(x)<<" elements in the set of "<<x<<endl;
                }
            }
            else{
                cout<<"Not Found"<<endl;
            }
        }
        else{
            break;
        }
    }
}*/


/*#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
struct tr{
    int a;
    int b;
    bool operator<(const tr& t) const
    {
        return (this->a < t.a);
    }
};
int main(){
    set<struct tr> s;
    vector<int> v{1,30,8,7,60,75,41};
    s.insert({1,9});
    s.insert({10,20});
    s.insert({21,40});
    s.insert({41,60});
    s.insert({61,80});
    s.insert({81,100}); 
    for(auto it=s.begin();it!=s.end();it++){
        cout<<it->a<<" "<<it->b<<endl;
    }
    for(auto it=v.begin();it!=v.end();it++){
        for(auto it2=s.begin();it2!=s.end();it2++){
            if(*it<=it2->b){
                cout<<*it<<" is in range "<<it2->a<<" "<<it2->b<<endl;
                break;
            }
        }
    }
}*/

/*#include<iostream>
#include<map>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;

//For finding Days
int finding(string month_name,vector<string> mon){
    std::vector<string>::iterator it;
    int thirty_days = 3;
    int thirtyone_days = 10;
    int twentyone = 11;
    it = find(mon.begin(),mon.end(),month_name);
    if(it != mon.end())
        if((it - mon.begin())<=3){
            return 30;
        }
        if((it - mon.begin())>3&&it - mon.begin()<=10){
            return 31;
        }
        else{
            return 28;
        }
}


int main()
{
    string month;
    multimap<int,string>m;
    m.insert(make_pair(1,"January"));
    m.insert(make_pair(2,"February"));
    m.insert(make_pair(3,"March"));
    m.insert(make_pair(4,"April"));
    m.insert(make_pair(5,"May"));
    m.insert(make_pair(6,"June"));
    m.insert(make_pair(7,"July"));
    m.insert(make_pair(8,"August"));
    m.insert(make_pair(9,"September"));
    m.insert(make_pair(10,"October"));
    m.insert(make_pair(11,"November"));
    m.insert(make_pair(12,"December"));
    vector<string>months = {"April","September","November","June","January","March","July","August","October","May","December","February"};
    
    cin>>month;
    cout << finding(month,months)<< endl;
    int num = 0;
    map<string,int>::iterator it;
    for(auto &p:m){
        if(p.second == month){
            num = p.first;
        } 
    }
    for(auto &p1:m){
        if(num!=12 and num != 1){
            if(p1.first+1==num){
                cout << p1.second<< endl;
                cout << finding(p1.second,months)<< endl;
            }
            if(p1.first-1==num){
                cout << p1.second<< endl;
                cout << finding(p1.second,months)<< endl;
            }
            
        }
    }
    if(num==1){
        cout << "December" << endl;
        cout << finding("December",months)<< endl;
        cout << "February" << endl;
        cout << finding("February",months)<< endl;
    }
    if(num==12){
        cout << "November" << endl;
        cout << finding("November",months)<< endl;
        cout << "January" << endl;
        cout << finding("January",months)<< endl;
    }
}*/

/*#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    map<string,int> mymap;
    mymap.insert(make_pair("harsha",21443));
    mymap.insert(make_pair("vishnu",21437));
    mymap.insert(make_pair("sohan",21454));
    mymap.insert(make_pair("dinesh",21459));
    mymap.insert(make_pair("jushith",21430));
    cout << "ascending order of names :" << endl;
    map<string,int>::iterator it;
    for(it=mymap.begin();it!=mymap.end();it++){
        cout << (*it).first << ":" << (*it).second << endl;
    }
    cout << "descending order of names :" << endl;
    map<string,int>::reverse_iterator rit;
    for(rit=mymap.rbegin();rit!=mymap.rend();rit++){
        cout << (*rit).first << ":" << (*rit).second << endl;
    }
    map<int,string> mymap2;
    for(auto it=mymap2.begin();it!=mymap2.end();it++){
        //mymap2[it->second]=it->first;
  }
}*/

/*#include <iostream>
#include<map>
using namespace std;
int main(){
    string s;
    map<pair<int,string>,int>mymap;
    mymap[{1,"January"}]=31;
    mymap[{2,"February"}]=28;
    mymap[{3,"March"}]=31;
    mymap[{4,"April"}]=30;
    mymap[{5,"May"}]=31;
    mymap[{6,"June"}]=30;
    mymap[{7,"July"}]=31;
    mymap[{8,"August"}]=31;
    mymap[{9,"September"}]=30;
    mymap[{10,"October"}]=31;
    mymap[{11,"November"}]=30;
    mymap[{12,"December"}]=31;
    cin>>s;
    map<pair<int,string>,int>:: iterator it; 
    for(it=mymap.begin();it !=mymap.end();it++){
        if((*it).first.second==s){
            cout<<(*it).second<<endl;
            *it++;
            cout<<(*it).first.second<<endl;
            cout<<(*it).second<<endl;
            *it--;
            *it--;
            cout<<(*it).first.second<<endl;
            cout<<(*it).second<<endl;
            break;
        }
    }
}*/

/*#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    map<string,int> m;
    int i=0;
    while(i<s.length()){
        string word="";
        while(i<s.length() && s[i]!=' '){
            word+=s[i];
            i++;
        }
        m[word]==word.length();
        i++;
    }
    cout<<m.size();
}*/

#include <iostream>
#include <map>
#include <set>
using namespace std;
int main(){
map <string ,int> m;
m.insert(make_pair("Dinesh",21459));
m.insert(make_pair("vishnu",21437));
m.insert(make_pair("harsha",21443));
m.insert(make_pair("vijay",21415));
m.insert(make_pair("shiva",21467));
map<string ,int> ::iterator it;
    cout<<"details in ascending order of name"<<endl;
for(it=m.begin();it!=m.end();it++){
cout<<"key :"<<it->first<<" value :"<<it->second<<endl;
}
cout<<"details in descending order of name"<<endl;
map<string,int>::reverse_iterator i;
for(i=m.rbegin();i!=m.rend();i++){
    cout<<"key :"<<i->first<<" value :"<<i->second<<endl;
}
set <int> s;
s.insert(21459);
s.insert(21443);
s.insert(21437);
s.insert(21415);
s.insert(21467);
set<int> ::iterator io;
cout<<"details in ascending order of rollno"<<endl;
for(io =s.begin();io!=s.end();io++){
        for(it=m.begin();it!=m.end();it++){
            if(*io==it->second){
                cout<<"key :"<<it->first<<" value :"<<it->second<<endl;
                break;
            }
        }

}
cout<<"details in descending order of rollno"<<endl;
set<int> ::reverse_iterator ii;
for(ii=s.rbegin();ii!=s.rend();ii++){
        for(it=m.begin();it!=m.end();it++){
            if(*ii==it->second){
                cout<<"key :"<<it->first<<" value :"<<it->second<<endl;
                break;
            }
        }
    }
}
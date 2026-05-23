//1
/*#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
int main(){
    vector<int> a{1,2,3};
    a.push_back(4);
    a.pop_back();
    //a.push_front(0);
    //a.pop_front();
    vector<int>:: iterator i;
    for ( i = a.begin(); i!= a.end(); i++)
    {
        cout << *i << " " << endl;
    }
    deque<int> b{1,2,3};
    b.push_back(4);
    b.pop_back();
    b.push_front(0);
    b.pop_front();
    for ( i = a.begin(); i!= a.end(); i++)
    {
        cout << *i << " " << endl;
    }
}*/


//2a
/*#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a{20,25,25,50,40,22,25,45,42,44,33,35,44,48};
    vector<int>::iterator i;
    int count=0;
    for(i=a.begin();i!=a.end();i++){
        if (*i%2!=0)
        count++;
    }
    if (count==a.size()){
        cout << "all are odd" << endl;
    }else{
        cout << "all are not odd" << endl;
    }
}*/

//2b
/*#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a{20,25,25,50,40,22,25,45,42,44,33,35,44,48};
    vector<int>::iterator i;
    int count=0;
    for(i=a.begin();i!=a.end();i++){
        if (*i%2==0)
        count++;
    }
    if (count==a.size()){
        cout << "all are even" << endl;
    }else{
        cout << "all are not even" << endl;
    }
}*/

//2c
/*#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a{20,25,25,50,40,22,25,45,42,44,33,35,44,48};
    vector<int>::iterator i;
    int count=0;
    for(i=a.begin();i!=a.end();i++){
        if (*i>20)
        count++;
    }
    if (count==a.size()){
        cout << "all are greater than 20" << endl;
    }else{
        cout << "all are not greater than 20" << endl;
    }
}*/

/// 2d
/*#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a{20,25,25,50,40,22,25,45,42,44,33,35,44,48};
    vector<int>::iterator i;
    int count=0;
    for(i=a.begin();i!=a.end();i++){
        if (*i==50)
        count++;
    }
    if (count>0){
        cout << "someone got 50" << endl;
    }else{
        cout << "no one got  50" << endl;
    }
}*/

//2e
/*#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a{20,-25,25,50,40,22,25,45,42,44,33,35,44,48};
    vector<int>::iterator i;
    int count=0;
    for(i=a.begin();i!=a.end();i++){
        if (*i<0)
        count++;
    }
    if (count>0){
        cout << "some one got negative marks" << endl;
    }else{
        cout << "no one got negative marks" << endl;
    }
}*/

///  2f
/*#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a{20,25,50,40,22,25,45,42,44,33,35,44,48};
    vector<int>::iterator i;
    for(i=a.begin();i!=a.end();i++){
        *i = *i+5;
    }
    for(i=a.begin();i!=a.end();i++){
        cout << *i << " " << endl;
    }
}*/

//2g
/*#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a{20,25,50,40,22,25,45,42,44,33,35,44,48};
    vector<int>::iterator i;
    int count=0;
    for(i=a.begin();i!=a.end();i++){
        count++;
        if (*i==44){
            cout << count << endl;
        }
    }
}*/

//2h
/*#include<iostream>
#include<vector>
#include<numeric> 
using namespace std;
int main(){
    vector<int> a{20,25,50,40,22,25,45,42,44,33,35,44,48};
    vector<int>::iterator i;
    int count=0,sum=0;
    for(i=a.begin();i!=a.end();i++){
        count++;
    }
    int n=accumulate(a.begin(), a.end(), 0);
    cout << n/count << endl;
}*/

//2i
/*#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
int main(){
    vector<int> a{20,25,50,40,22,25,45,42,44,33,35,44,48};
    vector<int>::iterator i;
    sort(a.begin(), a.end());
    for(i=a.begin();i!=a.end();i++){
        cout << *i << " ";
    }
}*/

//2j
/*#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a{20,25,50,40,22,25,45,42,44,33,35,44,48};
    for( int i=0;i!=a.size()-1;i++){
         cout<<abs(a.at(i)-(a.at(i+1)))<<" ";
    }
}*/




//2k
/*#include<iostream>
#include<vector>
#include<algorithm> 
#include<numeric>
using namespace std;
int main(){
    vector<int> a{20,25,50,40,22,25,45,42,44,33,35,44,48};
    vector<int>::iterator i;
    vector<int> b{30,44,35,22,38,49,33,41,44,43,25,39,33,38};
    a.insert(a.end(),b.begin(),b.end());
    for(i=a.begin();i!=a.end();i++){
        cout << *i << " ";
    }
}*/

//3
/*#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>s;
    stack<int>s1;
    s.push(3);
    s.push(5);
    s.push(1);
    s.push(4);
    s.push(2);
    s.push(8);
   while(!s.empty()){
        int myvar = s.top();
        s.pop();
       while(!s1.empty() && s1.top()<myvar){
                s.push(s1.top());
                s1.pop();
        }
        s1.push(myvar);
    }
    while(!s1.empty()){
        cout<<" "<<s1.top();
        s1.pop();
    }
}*/

//5
/*#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
    queue<int>q1;
    queue<int>q2;
    cout<<q1.empty()<<endl;
    cout<<q1.size()<<endl;
    q1.emplace(3);
    q1.emplace(6);  
    q1.emplace(7);
    //q1.swap(q2);
    while(!q1.empty()){
        cout<<" "<<q1.front();
        q1.pop();
    }
    cout<<endl;
    q1.emplace(10);
    q1.emplace(20);
    q2.emplace(30);
    q2.emplace(40);
    q2.emplace(50);
    q1.swap(q2);
    while(!q1.empty()){
        q2.emplace(q1.front());
        q1.pop();
    }
    cout<<q1.size()<<endl;
    cout<<q2.size()<<endl;
}*/

//6
/*#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<vector<int>>pq;
    vector<int> data_1{ 10, 20, 30, 40 };
    vector<int> data_2{ 10, 20, 35, 40 };
    vector<int> data_3{ 30, 25, 10, 50 };
    vector<int> data_4{ 20, 10, 30, 40 };
    vector<int> data_5{ 5, 10, 30, 40 };
    pq.push(data_1);
    pq.emplace(data_2);
    pq.emplace(data_3);
    pq.emplace(data_4);
    pq.emplace(data_5);
    cout << "Max priority Queue ";
    vector<int>  x =  pq.top();
    for(int i: x){
        cout << i << " ";
    }
    cout << endl;
   int y = pq.size()-1;
   for(int j =0;j!=y;j++){
        pq.pop();
    }
    cout << endl;
    cout << "Least priority Queue ";
    vector<int>  x1 =  pq.top();
    for(int i: x1){
        cout << i << " ";
    }sw
}*/

//8
/*#include <iostream>
#include <queue>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
    int n,power;
	cin>>n>>power;
	priority_queue<int>pq;
	while(n--){
        int a;
        cin>>a;
        pq.emplace(a);
    }
	    int i = 0;
	    while(true){
	        int s = pq.top();
	        power = power - s;
	        pq.pop();
	        int a = s/2;
	        if(a>=1){
	            pq.emplace(a);
	        }
	        i++;
	        if(power<=0){
                cout << i <<endl;
	            break;
	        }
            if(pq.empty()){
	            cout << "Evacuate" << endl;
	            break;
	        }
	    }
	}
	return 0;
}*/

/*#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v={1,2,3,4,5,6,7,8,9,10};
    vector<int>::iterator i,j;
    i=v.end();
    j=prev(i,4);
    cout << *j << endl;
}*/

/*#include <bits/stdc++.h>
using namespace std;

int main(){
    multimap<int,int> m;
    int n;
    int c=0;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a;
        cin >> b;
        m.insert({a,b});
    }
    //multimap<int,int>::iterator i;
    for(auto i=m.begin();i!=m.end();i++){
        if(m.count(i->first)>2){
            c++;
            break;
        }
    }
    if(c>0){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
}*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    multimap<string,int> m;
    multiset<int> s;
    m.insert({"a",1000});
    m.insert({"b",100});
    m.insert({"c",2000});
    m.insert({"d",500});
    m.insert({"e",5000});
    s.insert(1000);
    s.insert(100);
    s.insert(2000);
    s.insert(500);
    s.insert(5000);
    for(auto i=s.rbegin();i!=s.rend();i++){
        for(auto it=m.begin();it!=m.end();it++){
            if(*i==it->second){
                cout << it->first << " " << it->second << endl;
            }
        }
    }
}
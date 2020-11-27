#include <iostream>
#include<array>
#include<numeric>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <forward_list>
#include <list>
#include<queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <regex>
#include <functional>
#include<string.h>
#include<exception>
using namespace std;
class Person{
public:
    int age;
//    string name;
    Person(int age){
        this->age=age;
//        this->name=name;
        cout<<"Constructor person\n";
    }
    Person(const Person &rhs){age=rhs.age;cout<<"It is copied damn it\n";}
    bool operator >(const Person& rhs) const{
        return this->age > rhs.age;
    }
};
int main() {
//    vector<int> v={0,1,2,3,4,5,6,7,8,9};
//    array<int,10> a1{};
//    copy(v.begin(),v.end(),a1.begin());
//    //iota(a1.begin(),a1.end(),0);
//    make_heap(a1.begin(),a1.end());
//    sort_heap(v.begin(),v.end(),less<int>());
//    for(auto& ele:v)
//        cout<<ele<<" ";
//    cout<<endl;
//    make_heap(a1.begin(),a1.end());
//    //int i=1;
//    //nth_element(a1.begin(),a1.begin()+i,a1.end(),greater<>());
//    //cout<<a1.at(i);
//    //cout<<endl;
//    auto j = a1.rbegin();
//    cout<<*(a1.rbegin())<<" "<<*(a1.rend())<<" "<<*(a1.cbegin());
//    multiset<int,greater<>> s1={1,2,5,4,3,5,3,4,1,2};
//    for(auto& ele:s1)cout<<ele<<" ";
//    s1.insert(12);
//    cout<<endl;
//    for(auto& ele:s1)cout<<ele<<" ";
//    auto a=s1.find(2);
//    if(a!=s1.end())cout<<"element found\n";
//    set<int> s2(s1.begin(),s1.end());
//    s2.erase(s2.begin(),s2.find(4));
//    //for(auto& ele:s2)cout<<ele<<" ";
//    cout<<*s1.upper_bound(1);
//    cout<<*s1.lower_bound(2);
//    deque<Person> dq;
//    Person saiki(18,"saiki");
//    Person sahith(15,"sahith");
//    Person rama(40,"rama");
//    Person sathyam(47,"sathyam");
//    dq.push_back(saiki);
//    dq.push_back(sahith);
//    dq.push_back(rama);
//    dq.push_front(sathyam);
//    for(auto &ele:dq)cout<<ele.name<<" "<<ele.age<<endl;
//    dq.pop_back();
//    cout<<dq.front().name<<" "<<dq.front().age;
//    map<int,char,greater<>>m={};
//    m.insert(make_pair(1,'d'));
//    m.insert(make_pair(3,'b'));
//    m.insert(make_pair(4,'a'));
//    m.insert(make_pair(2,'c'));
//    for(auto ele:m)cout<<ele.first<<" "<<ele.second<<" ";
//    cout<<m.at(3);
//    multimap<string,int>m1;
//    m1.insert(make_pair("krishna",108));
//    m1.insert(make_pair("krishna",109));
//    m1.insert(make_pair("krishna",110));
//    m1.insert(make_pair("radha",108));
//    m1.insert(make_pair("radha",109));
//    auto  range=m1.equal_range("krishna");
//    for(auto i=range.second;i!=m1.find("krishna");i--)cout<<i->first<<" "<<i->second;
//    cout<<endl;
//    cout<<m1.count("krishna");
//    for(auto ele:m1)cout<<ele.first<<" "<<ele.second<<" ";
    set<Person,greater<Person>> s;
    s.emplace(15);
    s.insert(10);
//    s.emplace(20);
    forward_list<int> l;
    list<int> l1;
    string a="So my password is : Anumalla@2332 boss!";
    //regex r("[A-Z]+(.*)[a-z]*[//@][0-9]+[a-z]*(.*)");
    regex r("(Anu)(.*)[//@][0-9]+");
    if(regex_match(a,r))cout<<"match";else cout<<"not matching";
    smatch smt;
    string result="Result-> ";
    regex_search(a,smt,r);
    for(auto i:smt)
        cout<<i<<" ";
    cout<<endl;
    regex_replace(back_inserter(result),a.begin(),a.end(),r,"replaced");
    cout<<result;
    return 0;


}

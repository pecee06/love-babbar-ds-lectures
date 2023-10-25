#include <iostream>
#include <forward_list>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
    forward_list<int> fl = {8,6,1,24,4,12};
    fl.sort();
    for (auto it=fl.begin(); it!=fl.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    forward_list<int> fl2(4,2);
    fl2.merge(fl);
    forward_list<int> fl3 = fl2;
    fl3.reverse();
    for (auto it=fl3.begin(); it!=fl3.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    list<int> l = {7,3,3,7,6,1,1,1,6,9};
    l.pop_back();
    cout<<l.back()<<endl;
    
    return 0;
}

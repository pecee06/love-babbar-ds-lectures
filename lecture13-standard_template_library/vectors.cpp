#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v(10,1);
    int i=1;
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++){
        *(it)+=(i++);
    }
    v.pop_back();

    v.push_back(56);
    v.push_back(69);
    v.push_back(13);

    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}

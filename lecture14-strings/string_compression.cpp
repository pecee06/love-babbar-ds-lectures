// Problem statement: Compress {'a','b','b','c','c','c','a','a'} into {'a','b','2','c','3','a','2'} and return length of new character array

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print(vector<char>& v){
    for (auto ch:v){
        cout<<ch<<" ";
    }
    cout<<endl;
}

int compress(vector<char>& v){
    vector<string> strArr;
    string temp = "";
    int n = v.size();
    for (int i=0; i<n; i++){
        temp+=v[i];
        if (v[i+1]!=v[i]){
            strArr.push_back(temp);
            temp = "";
        }
    }
    v.clear();
    for (auto elem:strArr){
        v.push_back(elem[0]);
        if (elem.length()>1){
            v.push_back(to_string(elem.length())[0]);
        }
    }
    return v.size();
}

int main(int argc, char const *argv[])
{
    vector<char> v;
    int n;
    cout<<"How many characters you want to enter : ";
    cin>>n;

    char temp;
    for (int i=0; i<n; i++){
        cout<<"Element "<<i+1<<" : ";
        cin>>temp;
        v.push_back(temp);
    }

    int newSize = compress(v);
    cout<<newSize<<endl;
    print(v);
    
    return 0;
}

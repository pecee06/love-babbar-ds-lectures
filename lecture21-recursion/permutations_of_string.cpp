// Problem statement: Given a string, print all its permutations in lexicographically increasing order

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print(vector<string>& v){
    for (auto elem:v){
        cout<<elem<<endl;
    }
}

int lastInd(vector<string>& v){
    int n = v.size();
    string last = v[0];
    int index = 0;
    for (register int i=1; i<n; i++){
        if (last.compare(v[i]) < 0){
            last = v[i];
            index = i;
        }
    }
    return index;
}

void lexSort(vector<string>& v){
    int n = v.size();
    for (register int i=n-1; i>0; i--){
        swap(v[lastInd(v)],v[i]);
    }
}

vector<string> permutation(string str){
    
}

int main()
{
    

    return 0;
}
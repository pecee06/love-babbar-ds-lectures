// Problem statement: Given 2 strings, you have to merge them in such a way that the resulting string should have words in increasing order of their length

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int minIndex(const vector<string>& v, int from){
    int min = v[from].length(), minIndex = from;
    int n = v.size();
    for (register int i=from+1; i<n; i++){
        if (v[i].length()<min){
            min = v[i].length();
            minIndex = i;
        }
    }
    return minIndex;
}

void sortString(vector<string>& v){
    int n = v.size();
    for (register int i=0; i<n; i++){
        swap(v[i],v[minIndex(v,i)]);
    }
}

string merge(string s1, string s2){
    string s = s1+" "+s2;
    vector<string> v;
    string temp;
    int n = s.length();
    for (register int i=0; i<=n; i++){
        if (s[i]==' ' || s[i] == '\0'){
            v.push_back(temp);
            temp = "";
            continue;
        }
        temp += s[i];
    }
    sortString(v);
    s.clear();
    for (auto elem:v){
        s+=elem+" ";
    }
    s.pop_back();
    return s;
}

int main(int argc, char const *argv[])
{
    string str1, str2;
    cout<<"Enter first string\n";
    getline(cin,str1);
    cout<<"Enter second string\n";
    getline(cin,str2);

    string s3 = merge(str1,str2);
    cout<<"Resulting string\n"<<s3<<endl;
    
    return 0;
}

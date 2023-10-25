// Assumption: Given string only has alphabets

#include <iostream>
#include <string>
using namespace std;

bool isUpperCase(char ch){
    int ascii = (int)ch;
    if (ascii>=65 && ascii<=90){
        return true;
    }
    return false;
}

bool isLowerCase(char ch){
    int ascii = (int)ch;
    if (ascii>=97 && ascii<=122){
        return true;
    }
    return false;
}

int maxIndex(int* arr, int n){
    int max = arr[0], maxI = 0;
    for (int i=1; i<n; i++){
        if (arr[i]>max){
            max = arr[i];
            maxI = i;
        }
    }
    return maxI;
}

char mostFreqChar(const string& str){
    int freq[26] = {0};

    for (auto ch:str){
        if (isLowerCase(ch)){
            freq[ch-'a']++;
        }
        if (isUpperCase(ch)){
            freq[ch-'A']++;
        }
    }

    return 'a'+maxIndex(freq,26);
}

int main(int argc, char const *argv[])
{
    string str;
    cout<<"Enter a string\n";
    getline(cin,str);

    cout<<"The most frequent character in the entered string is "<<mostFreqChar(str)<<endl;
    
    return 0;
}

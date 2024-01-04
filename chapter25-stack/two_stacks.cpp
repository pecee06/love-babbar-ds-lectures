// Problem: Implement 2 stacks using a single array

#include <iostream>
using namespace std;

template<typename T> class TwoStacks{
    T* container;
    int leftTop, rightTop, size;

    bool full(){
        return leftTop == rightTop-1;
    }
public:
    TwoStacks(int n=2){
        size = n;
        container = new T[n];
        leftTop = -1;
        rightTop = n;
    }

    void push_1(T key){
        if (!this->full()) container[++leftTop] = key;
        else cout<<"Stack overflow!\n";
    }
    void push_2(T key){
        if (!this->full()) container[--rightTop] = key;
        else cout<<"Stack overflow!\n";
    }
    bool empty_1(){
        return leftTop == -1;
    }
    bool empty_2(){
        return rightTop == size;
    }
    T pop_1(){
        if (!this->empty_1())
            return container[leftTop--];
        return (T)NULL;
    }
    T pop_2(){
        if (!this->empty_2())
            return container[rightTop++];
        return (T)NULL;
    }
};

int main()
{
    TwoStacks<int> s(10);

    int n, temp;
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>temp;
        s.push_1(temp);
    }
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>temp;
        s.push_2(temp);
    }

    cout<<"Reversing 1st stack\n";
    while (!s.empty_1()){
        cout<<s.pop_1()<<" ";
    }
    cout<<endl;
    cout<<"Reversing 2nd stack\n";
    while (!s.empty_2()){
        cout<<s.pop_2()<<" ";
    }
    cout<<endl;

    return 0;
}
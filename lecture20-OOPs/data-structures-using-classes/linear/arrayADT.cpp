#include <iostream>
using namespace std;

class Array{
    int* arr;
    int size;
    int current;

    bool empty(){
        if (current == -1){
            return true;
        }
        return false;
    }
    bool filled(){
        if (current == size-1){
            return true;
        }
        return false;
    }
    int found(int n){
        for (register int i=0; i<=this->current; i++){
            if (arr[i] == n){
                return i;
            }
        }
        return -1;
    }
public:
    Array(int size):current(-1){
        this->size = size;
        arr = new int[size];
    }

    void insert(int data){
        if (! this->filled()){
            arr[++(this->current)] = data;
        }
        else{
            cout<<"Array is full\n";
        }
    }
    void remove(int n){
        if (! this->empty()){
            int index = this->found(n);
            if (index != -1){
                for (register int i=index; i<this->current; i++){
                    arr[i] = arr[i+1];
                }
                (this->current)--;
            }
            else{
                cout<<"Element not present in array\n";
            }
        }
        else{
            cout<<"Array is empty\n";
        }
    }
    void print(){
        for (register int i=0; i<=this->current; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Array a(6);

    a.insert(24);
    a.insert(4);
    a.insert(7);
    a.insert(43);
    a.insert(12);

    a.remove(43);
    a.remove(0);

    a.print();
    
    return 0;
}

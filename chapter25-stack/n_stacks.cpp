// Problem: Design a DS and implement n stacks using a single array of size N

#include <iostream>
using namespace std;

class NStacks{
    int *container, *top, *next;
    int freeSpot;

    void initializeTop(int n){
        for (int i=0; i<n; i++)
            top[i] = -1;
    }
    void initializeNext(int n){
        for (int i=0; i<n-1; i++)
            next[i] = i+1;
        next[n-1] = -1;
    }
public:
    NStacks(int n, int N){
        container = new int[N];
        top = new int[n];
        initializeTop(n);
        next = new int[N];
        initializeNext(N);
        freeSpot = 0;
    }

    bool push(int stack, int key){
        if (freeSpot == -1) return false;
        int index = freeSpot;
        freeSpot = next[index];
        container[index] = key;
        next[index] = top[stack-1];
        top[stack-1] = index;
        return true;
    }
    int pop(int stack){
        if (top[stack-1] == -1) return -1;
        int index = top[stack-1];
        top[stack-1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;
        return container[index];
    }
};

int main()
{
    NStacks s(3,6);
    s.push(1,10);
    s.push(2,5);
    s.pop(1);
    s.push(2,6);
    s.push(3,1);
    s.pop(3);
    s.pop(2);

    return 0;
}
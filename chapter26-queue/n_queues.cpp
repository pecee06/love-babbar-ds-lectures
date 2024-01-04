#include <iostream>
using namespace std;

class NQueues{
    int size, freeSpot;
    int *container, *front, *rear, *next;
public:
    NQueues(int n, int k){
        freeSpot = 0;
        size = n;
        container = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        for (int i=0; i<k; i++){
            front[i] = -1;
            rear[i] = -1;
        }
        for (int i=1; i<n; i++)
            next[i] = i;
        next[n-1] = -1;
    }

    bool full(){
        return freeSpot == -1;
    }
    void enqueue(int queue, int key){
        // queue belongs-to [1,k]
        if (!this->full()){
            int index = freeSpot;
            freeSpot = next[index];
            
            if (front[queue-1] == -1)
                front[queue-1] = index;
            else next[rear[queue-1]] = index;

            next[index] = -1;
            rear[queue-1] = index;
            container[index] = key;
        }
    }
    void dequeue(int queue){
        if (front[queue-1] != -1){
            int index = front[queue-1];
            front[queue-1] = next[index];
            next[index] = freeSpot;
            freeSpot = index;
        }
    }
    int first(int queue){
        if (front[queue-1] == -1) return -1;
        return container[front[queue-1]];
    }
};

int main()
{
    NQueues q(6,3);

    q.enqueue(1,2);
    q.enqueue(1,4);
    q.enqueue(2,5);
    q.enqueue(3,8);
    q.enqueue(3,2);
    q.enqueue(2,1);

    q.dequeue(2);
    q.dequeue(1);

    cout<<q.first(1)<<","<<q.first(2)<<","<<q.first(3)<<endl;

    return 0;
}
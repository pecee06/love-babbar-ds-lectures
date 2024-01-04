// Assumption: The road on which the truck is running is one-way
// Assumption: In 1 unit petrol, truck can go 1 unit distance
// Assumption: At every petrol pump, the truck fills the tank with as much petrol as the station can provide with
// Find the 1st petrol pump, from where the truck may start and complete the circle without exhausting its petrol

#include <iostream>
#include <vector>
using namespace std;

int tour(vector<pair<int,int>> v){
    int n = v.size();
    int front = 0, balance = 0, deficit = 0;
    for (int rear = 0; rear < n; rear++){
        balance += v[rear].first - v[rear].second;
        if (balance < 0){
            deficit += balance;
            front = rear + 1;
            balance = 0;
        }
    }
    if (balance >= 0) return front;
    return -1;
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> data;
    // first-> amount of petrol
    // second-> distance from next petrol pump
    for (int i=0; i<n; i++){
        int petrol, distance;
        cin>>petrol>>distance;
        data.push_back(make_pair(petrol,distance));
    }

    cout<<tour(data)<<endl;

    return 0;
}
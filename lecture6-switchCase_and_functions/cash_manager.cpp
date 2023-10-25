// Problem statement: We'll be provided with an amount that we have to pay. We have to find the number of currency notes of each type that we have to give, so that we give the least number of notes. Provided we only have 100, 50, 20 and 1 rupee notes

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int initialAmount;
    cout<<"Enter the amount to be paid : ";
    cin>>initialAmount;

    int notes[] = {100,50,20,1};
    int correspondingQuantity[4];
    int i = 0;
    int remAmount = initialAmount;
    while (remAmount != 0){
        correspondingQuantity[i] = remAmount/notes[i];
        remAmount -= correspondingQuantity[i]*notes[i];
        i++;
    }

    for (int j=0; j<4; j++){
        cout<<notes[j]<<" rupee notes : "<<correspondingQuantity[j]<<endl;
    }
    
    return 0;
}

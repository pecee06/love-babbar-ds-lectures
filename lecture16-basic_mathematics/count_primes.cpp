// Problem statement: Given an integer n, return the number of primes strictly less than n

#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n){
    if (n<=1){
        return false;
    }
    for (register int i=2; i<=n/2; i++){
        if (n%i==0){
            return false;
        }
    }
    return true;
}

int countPrimes(int n){
    int count = 0;
    if (n>2){
        count++;
    }
    for (register int i=3; i<n; i+=2){
        if (isPrime(i)){
            count++;
        }
    }
    return count;
}

// sieve of eratosthenes approach
int countPrimesOptimized(int n){
    // We'll make a boolean array of size n, it will have its indices from 0 to n-1. Initially, all the values will be initialized as true (except 0th and 1st index, as they aren't primes). While iterating through the array, we'll mark all the multiples of a prime number as false

    int count = 0;
    
    vector<bool> primes(n,true);
    primes[0] = primes[1] = false;
    int multiple;
    for (register int i=2; i<n; i++){
        if (primes[i]){
            count++;
            multiple = i;
            while (multiple<n){
                primes[multiple] = false;
                multiple += i;
            }
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    cout<<"There are "<<countPrimes(n)<<" primes strictly less than "<<endl;
    cout<<"There are "<<countPrimesOptimized(n)<<" primes strictly less than "<<endl;
    
    return 0;
}

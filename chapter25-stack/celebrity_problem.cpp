// Problem: A celebrity is a person, who knows nobody but everybody knows him/her. A given group can have at max 1 celeb, find that

#include <iostream>
#include <stack>
using namespace std;

int celeb(int** matrix, int n){
    stack<int> potentialCeleb;
    for (int i=0; i<n; i++)
        potentialCeleb.push(i);
    
    while (potentialCeleb.size() != 1){
        int personA = potentialCeleb.top();
        potentialCeleb.pop();
        int personB = potentialCeleb.top();
        potentialCeleb.pop();

        // Both know each-other
        if (matrix[personA][personB] && matrix[personB][personA]) continue;

        // A knows B
        if (matrix[personA][personB]) potentialCeleb.push(personB);
        // B knows A
        else if (matrix[personB][personA]) potentialCeleb.push(personA);
    }

    int celeb = potentialCeleb.top();
    bool couldBeCeleb = true;
    for (int i=0; i<n; i++){
        if (matrix[celeb][i]){
            couldBeCeleb = false;
            break;
        }
    }
    if (couldBeCeleb){
        for (int i=0; i<n; i++){
            if (i!=celeb && !matrix[i][celeb]){
                couldBeCeleb = false;
                break;
            }
        }
        if (couldBeCeleb) return celeb;
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int** matrix = new int*[n];
    for (int i=0; i<n; i++){
        matrix[i] = new int[n];
        for (int j=0; j<n; j++){
            cin>>matrix[i][j];
        }
    }

    int c = celeb(matrix,n);
    (c!=-1)?cout<<"Celebrity is guest "<<c<<endl:cout<<"No celebrity\n";

    return 0;
}
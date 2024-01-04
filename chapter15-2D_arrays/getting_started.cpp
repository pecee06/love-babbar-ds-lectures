#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // printing 2D arrays

    /*
    int m1[5][2] = {
        {7,3},{3,7},{6,1},{1,1},{6,9}
    };
    for (register int i=0; i<5; i++){
        for (register int j=0; j<2; j++){
            cout<<m1[i][j];
        }
    }
    */

    // Taking user input into matrix
    int m2[3][3];
    for (register int i=0; i<3; i++){
        for (register int j=0; j<3; j++){
            cin>>m2[i][j];
        }
    }
    for (register int i=0; i<3; i++){
        for (register int j=0; j<3; j++){
            cout<<m2[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}

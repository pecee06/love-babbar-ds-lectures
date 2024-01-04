#include <iostream>
#include <cmath>
using namespace std;

class Matrix{
    int** arr;
    int row;
    int col;
public:
    int x,y;
    Matrix(int row=1, int col=2){
        // By default it's a pair
        this->row = row;
        this->col = col;
        arr = new int*[row];
        for (register int i=0; i<row; i++){
            arr[i] = new int[col];
        }
    }

    void input(){
        int temp;
        for (register int i=0; i<row; i++){
            for (register int j=0; j<col; j++){
                cin>>temp;
                arr[i][j] = temp;
            }
        }
        if (this->row == 1 && this->col == 2){
            x = arr[0][0];
            y = arr[0][1];
        }
    }

    void print(){
        for (register int i=0; i<row; i++){
            for (register int j=0; j<col; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

void distance(int x1, int y1, int x2, int y2){
    int delX = pow(x1-x2,2);
    int delY = pow(y1-y2,2);
    float ans = sqrt(delX+delY);
    cout<<ans<<endl;
}

int main()
{
    Matrix m(2,3);
    m.input();
    m.print();

    // Using as a pair
    Matrix p1, p2;
    p1.input();
    p2.input();

    distance(p1.x,p1.y,p2.x,p2.y);
    
    return 0;
}

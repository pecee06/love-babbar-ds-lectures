#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char opr;
    int n1,n2,ans;

    cout<<"Enter the expression : ";
    cin>>n1>>opr>>n2;

    switch (opr)
    {
    case '+':
        ans = n1+n2;
        break;
    case '-':
        ans = n1-n2;
        break;
    case '*':
        ans = n1*n2;
        break;
    case '/':
        ans = n1/n2;
        break;
    
    default:
        cout<<"Not a valid operation\n";
    }

    cout<<ans<<endl;
    
    return 0;
}

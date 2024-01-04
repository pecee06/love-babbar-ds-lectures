#include <iostream>
using namespace std;

/*
void update(int* p){
    *p *= 2;
}
*/

void increment(int** p){
    ++(**p);
}

int main(int argc, char const *argv[])
{
    // Q1
    /*
    int first = 8;
    int second = 18;
    int* ptr = &second;
    *ptr = 9;
    cout<<first<<" "<<second<<endl;
    */
    // expected output -> 8 9

    // Q2
    /*
    int first = 6;
    int* p = &first;
    int* q = p;
    (*q)++;
    cout<<first<<endl;
    */
    // expected output -> 7

    // Q3
    /*
    int* p = 0;
    int first = 110;
    *p = first; // this will generate error, it should have been like p = &first
    cout<<*p<<endl;
    */
    // expected output -> segmentation fault

    // Q4
    /*
    int first = 8;
    int second = 11;
    int* third = &second;
    *third += 2;
    cout<<first<<" "<<second<<endl;
    */
    // expected output -> 8 13

    // Q5
    /*
    float f = 12.5;
    float p = 21.5;
    float* ptr = &f;
    (*ptr)++;
    *ptr = p;
    cout<<*ptr<<" "<<f<<" "<<p<<endl;
    */
    // expected output -> 21.5 21.5 21.5

    // Q6
    /*
    int arr[5];
    int* ptr;
    cout<<sizeof(arr)<<" "<<sizeof(ptr)<<endl;
    */
    // expected output -> 20 4

    // Q7
    /*
    int arr[] = {11,21,13,14};
    cout<<*arr<<" "<<*(arr+1)<<endl;
    */
    // expected output -> 11 21

    // Q8
    /*
    int arr[6] = {11,12,31};
    cout<<arr<<" "<<&arr<<endl;
    */
    // expected output -> <address of 11> <same address>

    // Q9
    /*
    int arr[6] = {11,12,31};
    cout<<arr+1<<" "<<&arr[1]<<endl;
    */
    // expected output -> <address of 12> <same address>

    // Q10
    /*
    int arr[6] = {11,12,31};
    int* p = arr;
    cout<<p[2]<<endl;
    */
    // expected output -> 31

    // Q11
    /*
    int arr[] = {11,12,13,14,15};
    cout<<*arr<<" "<<*(arr+3)<<endl;
    */
    // expected output -> 11 14

    // Q12
    /*
    int arr[] = {11,21,31,41};
    // int* ptr = arr++; // this line would throw error as you can't increment an array
    // cout<<*ptr<<endl;
    */

    // Q13
    /*
    char ch = 'a';
    char* ptr = &ch;
    ch++;
    cout<<*ptr<<endl;
    */
    // expected output -> b

    // Q14
    /*
    char arr[] = "abcde";
    char* p = &arr[0];
    cout<<p<<endl;
    */
    // expected output -> abcde

    // Q15
    /*
    char arr[] = "abcde";
    char* p = &arr[0];
    p++;
    cout<<p<<endl;
    */
    // expected output -> bcde

    // Q16
    /*
    char str[] = "babbar";
    char* p = str;
    cout<<str[0]<<" "<<p[0]<<endl;
    */
    // expected output -> b b

    // Q17
    /*
    int i = 10;
    update(&i);
    cout<<i<<endl;
    */
    // expected output -> 20

    // Q18
    /*
    int first = 110;
    int* p = &first;
    int** q = &p;
    int second = (**q)++ + 9;
    cout<<first<<" "<<second<<endl;
    */
    // expected output -> 111 119

    // Q19
    /*
    int first = 110;
    int* p = &first;
    int** q = &p;
    int second = ++(**q);
    int* r = *q;
    ++(*r);
    cout<<first<<" "<<second<<endl;
    */
    // expected output -> 112 111

    // Q20
    /*
    int num = 110;
    int* ptr = &num;
    increment(&ptr);
    cout<<num<<endl;
    */
    // expected output -> 111
    
    return 0;
}

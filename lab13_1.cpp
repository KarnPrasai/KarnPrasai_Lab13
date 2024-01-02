#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[], int x,double B[6])
{
    double sum;
    for(int i = 0;i < x;i++)
    {
        sum += A[i];
    }
    B[0] = sum/x;


    double sum2;
    for(int j = 0;j < x;j++)
    {
        sum2 += pow(A[j]-B[0],2);
    }
    B[1] = sqrt(sum2/x);
    
    double sum3 = 1;
    for(int i = 0;i<x;i++)
    {
        sum3 *= A[i];
    }
    
    B[2] = pow(sum3 ,(float)1/x);

    double sum4;
    for(int i = 0;i < x;i++)
    {
        sum4 += 1/A[i];
    }
    B[3] = x/sum4;

    B[4] = A[0];
    for(int k = 0;k<x;k++)
    {
        if(B[4] < A[k])
            B[4] = A[k];
    }

    B[5] = A[0];
    for(int k = 0;k<x;k++)
    {
        if(B[5] > A[k])
            B[5] = A[k];
    }
}
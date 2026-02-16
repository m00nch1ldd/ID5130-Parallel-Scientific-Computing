#include <iostream>
#include <omp.h>
using namespace std;

void randomMatrix (double A[][100], int m, int n){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            A[i][j]=rand() % 101;
        }
    }
    return;
  }

void sumTwoMatrix (double A[][100], double B[][100], double sum[][100], int m, int n) {
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            sum[i][j]=A[i][j]+B[i][j];
        }
    }
    return;
  }

int main()
{
    int N;
    double A[100][100], B[100][100], C[100][100];
    cout<<"Enter size N (<100): ";
    cin>>N;
    randomMatrix(A,N,N);
    #pragma omp parallel for
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            C[i][j]=A[i][j]+B[i][j];
        }
    }
    cout<<"Resultant Matrix: \n";
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
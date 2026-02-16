#include <iostream>
#include <omp.h>
using namespace std;

void randomFloatMatrix (float A[][100], float a, float b, int m, int n){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            A[i][j]=((b - a) * ((float)rand() / RAND_MAX)) + a;
            // cout<<A[i][j];
        }
    }
    return;
  }

int main()
{
    int N;
    float A[100][100],B[100][100],C[100][100],D[100][100];
    cout<<"Enter size N (<100): ";
    cin>>N;
    randomFloatMatrix(A,0.0,100.0,N,N);
    randomFloatMatrix(B,0.0,100.0,N,N);
    float t;
    t=omp_get_wtime();
    #pragma omp parallel for collapse(2)
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            D[i][j]=0;
            for (int k=0;k<N;k++){
                D[i][j]+=A[i][k]*B[k][j];
            }

        }
    }
    t=omp_get_wtime()-t;
    cout<<"N="<<N<<" t="<<t<<"\n";
    
    // cout<<"Resultant Product Matrix: \n";
    // for (int i=0; i<N; i++){
    //     for (int j=0; j<N; j++){
    //         cout<<D[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;

}
#include <iostream>
 #include <cstdlib>
 #include <time.h> //clock_t
 using namespace std;
 void randomMatrix (double A[][600], int m, int n){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            A[i][j]=rand() % 101;
        }
    }
    return;
  }
  void randomVector (double A[][1], int m){
    for (int i=0; i<m; i++){
        A[i][1]=rand() % 101;
    }
    return;
  }
  void multiplyMatrixVector(double A[][600], double B[][1], double C[][1], int m, int n) {
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            C[i][1]=0;
            for (int k=0;k<m;k++){
                C[i][1]+=A[i][k]*B[k][1];
            }

        }
    }
    return;
  }
  void multiplyMatrix(double A[][100], double B[][100], double C[][100], int m, int n) {
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            C[i][j]=0;
            for (int k=0;k<m;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }

        }
    }
    return;
  }

  int main() {
    double A[600][600],B[600][1],C[600][1];
    int Narr[4]={64,128,256,512};
    int time[4];
    for (int i=0;i<4;i++) {
        int N=Narr[i];
        randomMatrix(A,N,N);
        randomVector(B,N);
        clock_t t;
        t=clock();
        multiplyMatrixVector(A,B,C,N,N);
        t=clock()-t;
        time[i]=((float)t)/CLOCKS_PER_SEC;
        cout<<"N="<<N<<" t="<<((float)t)/CLOCKS_PER_SEC<<"\n";

    }

}
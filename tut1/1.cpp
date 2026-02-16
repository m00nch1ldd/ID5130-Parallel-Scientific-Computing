//Tutorial 1
  #include <iostream>
  #include <cstdlib>
  #include <time.h> //clock_t
  using namespace std;

  void randomMatrix (double A[][100], int m, int n){
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
  void transposeMatrix (double A[][100], double AT[][100], int m, int n){
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++){
            AT[j][i]=A[i][j];
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
  bool checkEqualityMatrix (double A[][100], double B[][100], int m, int n) {
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (A[i][j] != B[i][j]) {
                return false;
            }
        }
    }
    return true;
  }

  int main(){
    //Q1
    int N;
    double A[100][100], AT[100][100], sum1[100][100], sum2[100][100];
    cout<<"Enter size N (<100): ";
    cin>>N;
    randomMatrix(A,N,N);
    transposeMatrix(A,AT,N,N);
    sumTwoMatrix(A,AT,sum1,N,N);
    transposeMatrix(sum1,sum2,N,N);
    cout<<checkEqualityMatrix(sum1, sum2, N, N);
    if (checkEqualityMatrix(sum1, sum2, N, N)) {
        cout<<"Hence showed (A+AT) is symmetric";
    }
    else {
        cout<<"Try again";
    }
    cout<<sum1[1][1];
  }
 

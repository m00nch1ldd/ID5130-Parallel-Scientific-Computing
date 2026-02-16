/*basic hello io - first program

#include <iostream>
using namespace std;

int main(){
    char name[50];
    cout<<"Enter your name: ";
    cin>>name;
    cout<<"Hello "<<name<<"! Welcome to ID5130";
}
*/

/* Array - 1D operations

#include <iostream>
using namespace std;

int main(){
    //Create elements of array. Retrieve the elements.
    int arr[5];
    for (int i=0; i<=4; i++){
        arr[i]=i*2;
        cout<<arr[i]<<" ";
    }
    //Compute sum of arrays
    int n=5;
    double arr1[n]={2,3,4,5,6};
    double arr2[n]={4,5,6,7,8};
    for (int i=0; i<n; i++){
        cout<<arr1[i]+arr2[i]<<" ";
    }
    //Compute dot product of arrays
    for (int i=0; i<n; i++){
        cout<<arr1[i]*arr2[i]<<" ";
    }
}
*/ 

/* Intro to new libraries and functions
//Dynamic array - get size of array from user
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int m;
    cout<<"Enter size of array: ";
    cin>>m;
    double* arr = new double[m];
    for (int i=0; i<m; i++) {
    arr[i] = pow(i,m);
    cout << arr[i] << "\t";
  }
  delete arr;
  cout<<arr;
}
  */
 
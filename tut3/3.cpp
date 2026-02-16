#include <iostream>
#include <cmath>
#include <vector>
#include <omp.h>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<int> primes;
    cout<<"Enter n: ";
    cin>>n;
    for (int i = 2; i <= n; ++i) {
        primes.push_back(i);
    }
    int k=2;
    int index=2;
    while (pow(k,2)<=n) 
    {
        // cout<<"hello"<<endl;
        int i=pow(k,2);
        while (i<=n)
        {
            // cout<<i<<" "<<k<<endl;
            if (i%k==0) {
                primes.erase(std::remove(primes.begin(), primes.end(), i), primes.end());
                i++;
            }
            else{
            i++;
            }
        }
        for (int i=0; i<primes.size();i++) 
        {
            cout<<primes[i]<<" ";
        }
        cout<<endl;
        k++;
    }
    
    return 0;
}
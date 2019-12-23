#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
 
int main() {
    int n,k;
    cin >> n >> k;
    int t = 1;
    for (int i = t; i < k; i++) {
        if (n % i == 0)
            t = i;
    }
    int m = n/t;
    cout << m * k + t;
 
    return 0;
}
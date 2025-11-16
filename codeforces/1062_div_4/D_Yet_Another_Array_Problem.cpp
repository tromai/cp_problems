#include <bits/stdc++.h>
#include <vector>
#include <cmath>

using namespace std;

const long long primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

// Observation:
//      If x is the answer, x must be a prime number, and there exists at least one element in the array
//      not a product of x.
// 
// "x must be a prime number": we can prove this. Let say x is the answer, and x is a composite number. If gcd(ai, x) == 1. Then gcd(ai, p) == 1 with p being a prime that makes up x -> contradiction.
// "there exists at least one element in the array not a product of x": Obvious, because if all element is a product
// of x then we cannot find ai with gcd(ai, x) == 1
//
// Solution: we can find prime number starting from 2 and check against all element in the array until we find an element that is not a product of that prime.
//
// However, we don't need to loop through all primes!
// We are checking each prime from 2 up, which mean 2 -> 3 -> 5 ... (because the problem ask for minimal x).
//
// If 2 is not the answer (all elements are divisible by 2) then we check 3, then 5, ...
// If we are checking 5, this means that all element are divisible by 2 and 3 -> they must be at least 6.
// If we are checking 7, this means that all element are divisible by 2, 3, 5 -> they must be at least 30.
// If we are checking 11, this means that all element are divisible by 2, 3, 5, 7 -> they must be at least 210.
// If we are checking 53 -> all elements must be at least P with P being the product of all primes from 2 -> 53. This is 6.148897825884914e+17
// If we are checking 59 -> all elements must be at least P with P being the product of all primes from 2 -> 59. This 1.922760350154213e+21 which is larger than the limit for an element in the array (10^18).
// Therefore x can only be atmost 53.
// Remember each element in the array has max value of 10^18 which is long long.

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;

        vector<long long> v(len);
        for (int k = 0; k < len; k++) {
            cin >> v[k];
        }

        long long answer = -1;

        for (long long prime : primes) {
            bool found = false;
            for (long long ele : v) {
                if (ele % prime != 0) {
                    found = true;
                    break;
                }
            }

            if (found) {
                answer = prime;
                break;
            }
        }

        cout << answer << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
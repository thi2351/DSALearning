#include <iostream>
#include <bitset>
#include <vector>
#include <math.h>
using namespace std;

//Create a Eratosthenes sieve for storing primes
vector<int> createEratosthenes(int n) {
	vector<int> primes;
	vector<bool> isPrime(n + 1, true);
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i = 2; i < n; i++) {
		if (isPrime[i]) {
			primes.push_back(i);
			for (int j = i*i; j < n; j += i) {
				isPrime[j] = 0;
			}
		}
	}
	return primes;
}

vector<pair<int,int>> primeFactorization(int N) {
	vector<int> primes = createEratosthenes(sqrt(N)+1);
	vector<pair<int,int>> result;
	int index = 0, f = primes[0];
	while (N != 1 && N >= f*f) {
		if (N%f == 0) {
			result.push_back({f,1});
			N = N/f;
		}
		while (N%f == 0) {
			result.back().second++;
			N = N/f;
		}
		f = primes[++index];
	}
	if (N != 1) {
		result.push_back({N,1});
	}
	return result;
}

void printFactorization(vector<pair<int,int>> a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i].first;
		if (a[i].second > 1) {cout << "^" << a[i].second;}
		if (i < a.size() - 1) {cout << "*";}
	}
}
int main() {
	int a;
	cin >> a;
	printFactorization(primeFactorization(a));
}

//Even use this heuristic strategy, you may fail to boost the efficent of the algorithm.
//This Brute-force algorithm has better performance with a small scale.
vector<pair<int, int>> primeFactorizationBruteForce(int N) {
    vector<pair<int, int>> result;

    for (int i = 2; i <= N; i++) {
        if (N % i == 0) {
            int count = 0;
            while (N % i == 0) {
                N /= i;
                count++;
            }
            result.emplace_back(i, count);
        }
        if (N == 1) break;
    }

    return result;
}
//You can use chrono to check this:

// With input: 234235123 = 37 * 6330679
// Time taken by Brute-force prime factorization: 23754 microseconds
// Time taken by Efficient prime factorization: 1793 microseconds

// With input: 14142 = 2 * 3 * 2357
// Time taken by Brute-force prime factorization: 21 microseconds
// Time taken by Efficient prime factorization: 26 microseconds

// With input: 1945 = 5 * 389
// Time taken by Brute-force prime factorization: 9 microseconds
// Time taken by Efficient prime factorization: 13 microseconds
  


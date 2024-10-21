#include <iostream>

/*Given an integer n, return the number of prime numbers that are strictly less than n.*/

void sieve(bool* notPrimes, int size, int curr) {
    for (int i = curr * 2; i < size; i += curr) {
        notPrimes[i] = true;
    }
}

int countPrimes(int n) {
    if (n < 2)
        return 0;
    bool* notPrimes = new bool[n] {0};
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (!notPrimes[i]) {
            count++;
            sieve(notPrimes, n, i);
        }
    }
    delete[] notPrimes;
    return count;
}

int main()
{
    std::cout << countPrimes(100);

}

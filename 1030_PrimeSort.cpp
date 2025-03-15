// 注意：此题需要使用厄拉托塞师筛法提前计算出素数表，否则会超时

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef struct Prime
{
    int begin;
    int end;
    int count;
} Prime;

const int MAXN = 10001;
bool isPrime[MAXN];
vector<int> primeCount(MAXN, 0);

void sieve()
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < MAXN; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < MAXN; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i < MAXN; i++)
    {
        primeCount[i] = primeCount[i - 1] + isPrime[i];
    }
}

int FindPrime(int begin, int end)
{
    if (begin > end)
        return 0;
    return primeCount[end] - primeCount[begin - 1];
}

int main()
{
    sieve();

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        vector<Prime> primes(n);

        for (int j = 0; j < n; j++)
        {
            cin >> primes[j].begin >> primes[j].end;
            primes[j].count = FindPrime(primes[j].begin, primes[j].end);
        }

        sort(primes.begin(), primes.end(), [](const Prime &a, const Prime &b)
            {
            if (a.count != b.count) return a.count < b.count;
            if (a.begin != b.begin) return a.begin < b.begin;
            return a.end < b.end; });

        cout << "case #" << i << ":" << endl;
        for (int j = 0; j < n; j++)
        {
            cout << primes[j].begin << " " << primes[j].end << endl;
        }
    }
    return 0;
}
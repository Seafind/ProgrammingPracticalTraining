#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        int numbers[N];
        for (int j = 0; j < N; j++)
        {
            cin >> numbers[j];
        }

        for (int j = 0; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                if (numbers[j] > numbers[k])
                {
                    int temp = numbers[j];
                    numbers[j] = numbers[k];
                    numbers[k] = temp;
                }
            }
        }

        int unique[N];
        int count = 0;
        for (int j = 0; j < N - 1; j++)
        {
            if (numbers[j] != numbers[j + 1])
            {
                unique[count++] = numbers[j];
            }
        }
        unique[count++] = numbers[N - 1];

        cout << "case #" << i << ":" << endl;
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < count; k++)
            {
                if (unique[k] % 10 == j)
                {
                    cout << unique[k] << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}
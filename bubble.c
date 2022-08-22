// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main()
{
    // int ar[7]= {8,1,4,6,9,3,2};
    int ar[7] = {1, 20, 10, 4, 33, 2, 3};

    int temp;
    // cout << ar[6];

    for (int i = 0; i <= 6; i++)
    {
        for (int j = 6; j >= i; j--)
        {
            if (ar[j] < ar[j - 1])
            {
                 temp = ar[j];
                 ar[j]=ar[j-1];
                 ar[j-1] =temp;
                // ar[j] = ar[j] + ar[j - 1];
                // ar[j - 1] = ar[j] - ar[j - 1];
                // ar[j] = ar[j] - ar[j - 1];
            }
        }
    }
    for (int i = 0; i <= 6; i++)
    {
        cout << ar[i] << endl;
    }
    return 0;
}
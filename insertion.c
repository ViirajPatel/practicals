// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main()
{
    // int ar[7]= {8,1,4,6,9,3,2};
    int a[7] = {1, 20, 10, 4, 33, 3, 2};
    int key, j;
    for (int i = 1; i <= 7; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
    for (int i = 0; i <= 6; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}
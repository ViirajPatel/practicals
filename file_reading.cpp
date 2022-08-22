#include <bits/stdc++.h>
using namespace std;
// converting string to integer array
void convert_array(string str)
{
    int str_length = str.length();
    int arr[str_length] = {0};
    int j = 0, i, sum = 0;
    // traversing the string
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ', ')
        {
            j++;
        }
        else
        {
            arr[j] = arr[j] * 10 + (str[i] - 48);
        }
    }
    cout << "arr[] = ";
    for (i = 0; i <= j; i++)
    {
        cout << arr[i] << " ";
        sum += arr[i];
    }
    cout << "\nSum of array is = " << sum << endl;
}
int main()
{
    string str = "2, 6, 3, 14";
    convert_array(str);
    return 0;
}
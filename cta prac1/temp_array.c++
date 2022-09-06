#include <stdio.h>
#include <vector>
#include <iostream>
#include <time.h>
using namespace std;
void printArray(int v[],int size)
{
    for (auto i = 0; i <5; i++)
    {
        cout << v[i] << " ";
    }
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void selection(int v[], int len)
{
    int min;
    clock_t t;
    t = clock();
    for (int i = 0; i < len; i++)
    {
        min = v[i];
        for (int j = i; j < len; j++)
        {
            if (v[j] < min)
            {
                min = v[j];
                swap(v[i], v[j]);
            }
        }
    }
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("it took %f seconds to execute selection \n", time_taken);
}

void insertion(int v[], int len)
{
    int key, j;
    clock_t t;
    t = clock();
    for (int i = 1; i < len; i++)
    {
        key = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("it took %f seconds to execute insertion \n", time_taken);
}

void bubble(int v[], int len)
{
    int temp;
    clock_t t;
    t = clock();
    for (int i = 0; i < len; i++)
    {
        for (int j = len - 1; j > i; j--)
        {
            if (v[j] < v[j - 1])
            {
                swap(v[j], v[j - 1]);
            }
        }
    }
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("it took %f seconds to execute bubble \n", time_taken);
}

// // int partition(vector<int> arr, int low, int high)
// int partition(int arr[], int low, int high)

// {
//     int pi = arr[low];
//     int i = low;
//     int j = high + 1;
//     int a = 1;
//     while (a == 1)
//     {
//         do
//         {
//             i = i + 1;

//         } while (arr[i] < pi && i != high);
//         do
//         {
//             j = j - 1;

//         } while (arr[j] > pi && j != low);

//         if (i < j)
//         {

//             swap(&arr[i], &arr[j]);
//         }
//         else
//         {
//             swap(&arr[j], &arr[low]);
//             return j;
//         }
//     }
// }
// // vector<int> quick(vector<int> arr, int low, int high)
// void quick(int arr[], int low, int high)

// {
//     int pi;
//     if (low < high)
//     {
//         pi = partition(arr, low, high);
//         quick(arr, pi + 1, high);
//         quick(arr, low, pi - 1);
//     }
   
// }
vector<int> fileRead(const char* fname,int size){
    vector<int> v;
    FILE *pFile;
    int temp;
    int arr[100001], count = 0;
    pFile = fopen(fname, "r");

    while (temp != -1)
    {
        fscanf(pFile, "%d", &temp);
        v.push_back(temp);
        // arr[count] = temp;
        // count++;
    }

    fclose(pFile);

    v.pop_back();
    return v;
}
int main()
{

    vector<int> v;
    // int arr[100001],arr2[100001];
    // arr = fileRead("./100k_dsc.txt",100001);
    cout << "...10k Random..." << endl;
    v = fileRead("./10k_random.txt", 10001);
  
    int arr[v.size()];
    std::copy(v.begin(), v.end(), arr);

    
    insertion(arr, v.size());
    std::copy(v.begin(), v.end(), arr);
    selection(arr, v.size());
    std::copy(v.begin(), v.end(), arr);
    bubble(arr, v.size());
    std::copy(v.begin(), v.end(), arr);

    cout << "...10k asc..." << endl;
    v = fileRead("./10k_asc.txt", 10001);

    
    std::copy(v.begin(), v.end(), arr);

    insertion(arr, v.size());
    std::copy(v.begin(), v.end(), arr);
    selection(arr, v.size());
    std::copy(v.begin(), v.end(), arr);
    bubble(arr, v.size());
    std::copy(v.begin(), v.end(), arr);

    cout << "...10k dsc..." << endl;
    v = fileRead("./10k_dsc.txt", 10001);

    
    std::copy(v.begin(), v.end(), arr);

    insertion(arr, v.size());
    std::copy(v.begin(), v.end(), arr);
    selection(arr, v.size());
    std::copy(v.begin(), v.end(), arr);
    bubble(arr, v.size());
    std::copy(v.begin(), v.end(), arr);

    cout << "...50k random..." << endl;
    v = fileRead("./50k_random.txt", 50001);

    int arr50[v.size()];
    std::copy(v.begin(), v.end(), arr50);

    insertion(arr50, v.size());
    std::copy(v.begin(), v.end(), arr50);
    selection(arr50, v.size());
    std::copy(v.begin(), v.end(), arr50);
    bubble(arr50, v.size());
    std::copy(v.begin(), v.end(), arr50);
    cout << "...50k asc..." << endl;
    v = fileRead("./50k_asc.txt", 50001);

    // int arr[v.size()];
    std::copy(v.begin(), v.end(), arr50);

    insertion(arr50, v.size());
    std::copy(v.begin(), v.end(), arr50);
    selection(arr50, v.size());
    std::copy(v.begin(), v.end(), arr50);
    bubble(arr50, v.size());
    std::copy(v.begin(), v.end(), arr50);
    cout << "...50k dsc..." << endl;
    v = fileRead("./50k_dsc.txt", 50001);

    // int arr[v.size()];
    std::copy(v.begin(), v.end(), arr50);

    insertion(arr50, v.size());
    std::copy(v.begin(), v.end(), arr50);
    selection(arr50, v.size());
    std::copy(v.begin(), v.end(), arr50);
    bubble(arr50, v.size());
    std::copy(v.begin(), v.end(), arr50);
    cout << "...100k random..." << endl;
    v = fileRead("./100k_random.txt", 100001);

    int arr100[v.size()];
    std::copy(v.begin(), v.end(), arr100);

    insertion(arr100, v.size());
    std::copy(v.begin(), v.end(), arr100);
    selection(arr100, v.size());
    std::copy(v.begin(), v.end(), arr100);
    bubble(arr100, v.size());
    std::copy(v.begin(), v.end(), arr100);
    cout << "...100k asc..." << endl;
    v = fileRead("./100k_asc.txt", 100001);

    // int arr[v.size()];
    std::copy(v.begin(), v.end(), arr100);

    insertion(arr100, v.size());
    std::copy(v.begin(), v.end(), arr100);
    selection(arr100, v.size());
    std::copy(v.begin(), v.end(), arr100);
    bubble(arr100, v.size());
    std::copy(v.begin(), v.end(), arr100);
    cout << "...100k dsc..." << endl;
    v = fileRead("./100k_dsc.txt", 100001);

    // int arr[v.size()];
    std::copy(v.begin(), v.end(), arr100);

    insertion(arr100, v.size());
    std::copy(v.begin(), v.end(), arr100);
    selection(arr100, v.size());
    std::copy(v.begin(), v.end(), arr100);
    bubble(arr100, v.size());
    std::copy(v.begin(), v.end(), arr100);

      return 0;
}
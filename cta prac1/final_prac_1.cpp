#include <stdio.h>
#include <vector>
#include <iostream>
#include <time.h>
using namespace std;

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

int partition(int arr[], int low, int high)
{
    int pi = arr[low];
    int i = low;
    int j = high + 1;
    int a = 1;
    while (a == 1)
    {
        do
        {
            i = i + 1;

        } while (arr[i] < pi && i != high);
        do
        {
            j = j - 1;

        } while (arr[j] > pi && j != low);

        if (i < j)
        {

            swap(&arr[i], &arr[j]);
        }
        else
        {
            swap(&arr[j], &arr[low]);
            return j;
        }
    }
}

void quick(int arr[], int low, int high)
{
    int pi;
    if (low < high)
    {
        pi = partition(arr, low, high);
        quick(arr, pi + 1, high);
        quick(arr, low, pi - 1);
    }
}

vector<int> fileRead(const char *fname, int size)
{
    vector<int> v;
    FILE *pFile;
    int temp;

    pFile = fopen(fname, "r");

    while (temp != -1)
    {
        fscanf(pFile, "%d", &temp);
        v.push_back(temp);
    }

    fclose(pFile);

    v.pop_back();
    return v;
}
int main()
{

    vector<int> v;
    const char *files[3][3] = {{"./10k_random.txt", "./10k_asc.txt", "./10k_dsc.txt"}, {"./50k_random.txt", "./50k_asc.txt", "./50k_dsc.txt"}, {"./100k_random.txt", "./100k_asc.txt", "./100k_dsc.txt"}};
    int count = 10001;
    clock_t t;

    int *arr = new int[count];
    for (int i = 0; i < 3; i++)
    {
        arr = (int *)realloc(arr, count * sizeof(int));
        for (int j = 0; j < 3; j++)
        {

            cout << "..." << files[i][j] << "..." << endl;
            v = fileRead(files[i][j], sizeof(arr) / sizeof(int));

            std::copy(v.begin(), v.end(), arr);
            t = clock();
            insertion(arr, v.size());
            t = clock() - t;
            double time_taken = ((double)t) / CLOCKS_PER_SEC;
            printf("it took %f seconds to execute insertion \n", time_taken);

            std::copy(v.begin(), v.end(), arr);
            selection(arr, v.size());

            std::copy(v.begin(), v.end(), arr);
            bubble(arr, v.size());

            std::copy(v.begin(), v.end(), arr);
            t = clock();
            quick(arr, 0, v.size());
            t = clock() - t;
            time_taken = ((double)t) / CLOCKS_PER_SEC;
            printf("it took %f seconds to execute quick \n", time_taken);
        }
        count += 50000;
    }

    return 0;
}
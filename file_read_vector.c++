#include <stdio.h>
#include<vector>
#include <iostream>
using namespace std;
int main()
{

    int f,count=0;
    vector<int> v;
    FILE *pFile;
  

    pFile = fopen("./program.txt", "r");
  
    while (f != -1)
    {
        fscanf(pFile, "%d", &f);
        v.push_back(f);
     
        count++;
    }
    v[3] = 1;
    cout << v[3];
    fclose(pFile);
    
    // v.pop_back();
    // for (auto i = v.cbegin(); i != v.cend(); ++i)
    //     cout << *i << " ";
    // cout << endl
    //      << "______________________________________________";.

   
    return 0;
}
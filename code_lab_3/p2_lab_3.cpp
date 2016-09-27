#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;
    cout << endl;
    
    int vector[n];
    unsigned int i = 0;
    for (i = 0; i < n; i++ ){
        vector[i] = i;
    }
    
    random_shuffle(&vector[0], &vector[n]);
    
    cout << "The resulting outcome is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << vector[i] << endl;
    }
    
    return 0;
}
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

typedef vector<int> IntVector;
typedef IntVector::iterator IntVectorIt;

void stl_sorting(IntVector& a)
{
    IntVectorIt startv,endv;
    startv =a.begin();
    endv = a.end();
    clock_t start=clock();
    sort(startv,endv);
    clock_t stop=clock();
    cout << "The elapsed time for stl_sorting: ";
    cout << 1000*(stop-start) /CLOCKS_PER_SEC << endl;
    
}

bool is_sorted(IntVector& a,int s,int r)
{
    for(int i=s;i<r;i++)
        if(a[i]>a[i+1])
            return false;
    
    return true;
}

void stl_merge(IntVector& a,IntVector& b,int s,int m,int r)
{
    //Function stl_merge merges segments a[s..m] and a[m+1..r],
    //stores the result in b[s..r] and then copies the result
    //back to a[s..r]
    IntVectorIt ita=a.begin();
    IntVectorIt itb=b.begin();
    merge(ita+s,ita+m+1,ita+m+1,ita+r+1,itb+s);
    for(int i=s;i<=r;i++)
        a[i]=b[i];
    
}

void mergesort(IntVector& a,IntVector& b,int s,int r)
{
    //Function mergesort is a recursive version of Merge-Sort
    //algorithm. We need vector b to store the results of merging
    //Both vectors a and b are passed by reference. The algorithm
    //needs memory which is twice the size of the array to be sorted
    if(r<=s) return;
    int m=(r+s)/2;
    mergesort(a,b,s,m);
    mergesort(a,b,m+1,r);
    stl_merge(a,b,s,m,r);
}

void timed_mergesort(IntVector& a, IntVector& b, int n)
{
    
    clock_t start=clock();
    mergesort(a,b,0,n-1);
    clock_t stop=clock();
    cout << "The elapsed time for mergesort: ";
    cout << 1000*(stop-start) /CLOCKS_PER_SEC << endl;
    
}
void swap(int v[], int i, int j)
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void quicksort(int v[], int n)
{
    int i, last;
    if(n <=1)
        return;
    swap(v, 0, rand() % n);
    last = 0;
    for (i = 1; i < n; i++)
        if (v[i] < v[0])
            swap(v, ++last, i);
    swap(v, 0, last);
    quicksort(v, last);
    quicksort(v+last+1, n-last-1);
    
}

void timed_quicksort(int a[], int n)
{
    clock_t start=clock();
    quicksort(a, n);
    clock_t stop=clock();
    cout << "The elapsed time for quicksort: ";
    cout << 1000*(stop-start) /CLOCKS_PER_SEC << endl;
}






int main()
{
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;
    cout << endl;
    
    IntVector vector1(n);
    IntVector vector2(n);
    IntVector vector2b(n);
    int vector3[n];
    unsigned int i = 0;
    for (i = 0; i < n; i++ ){
        vector1[i] = i;
    }
    
    random_shuffle(&vector1[0], &vector1[n]);
    vector2 = vector1;
    for(i=0; i<vector1.size(); i++)
    {
        vector3[i] = vector1[i];
    }
    
    stl_sorting(vector1);
    timed_mergesort(vector2, vector2b, n);
    timed_quicksort(vector3, n);
    
    
    return 0;
}
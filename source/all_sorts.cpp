#include <vector>

using namespace std;

//- - - - - - next sorts are added below - - - - - -
// - Bubble sort (пузырьком)
// - Insertion sort (вставками)
// - Merge sort(recursive) (слиянием)
// - Quick sort(recursive) (быстрая)
// - Heap sort (хип сорт)

void bubble_sort(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < v.size() - i - 1; j++)
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
}


void insertion_sort(vector<int> &v)
{
    for(int i = 1; i < v.size(); i++)
    {
       int t = v[i];
       int j = i;
       while(j > 0 && v[j - 1] > t)
       {
          v[j] = v[j-1];
          j--;
       }
       v[j] = t;
    }
}


vector<int> merge(vector<int> &v, int l, int m, int r)
{
    int i, j, k, nl, nr;
    //size of left and right sub-arrays
    nl = m - l + 1; nr = r - m;
    int larr[nl], rarr[nr];
    //fill left and right sub-arrays
    for(i = 0; i < nl; i++)
       larr[i] = v[l + i];
    for(j = 0; j < nr; j++)
       rarr[j] = v[m + 1 + j];
    i = 0; j = 0; k = l;
   //marge temp arrays to real array
    while(i < nl && j<nr)
    {
       if(larr[i] <= rarr[j])
       {
          v[k] = larr[i];
          i++;
       }
       else
       {
          v[k] = rarr[j];
          j++;
       }
       k++;
    }
    while(i < nl)
    {       //extra element in left array
       v[k] = larr[i];
       i++; k++;
       
    }
    while(j<nr)
    {     //extra element in right array
       v[k] = rarr[j];
       j++; k++;
    }
    return v;
}
void merge_sort(vector<int> &v, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      merge_sort(v, l, m);
      merge_sort(v, m+1, r);
      merge(v, l, m, r);
   }
}


int partition(vector<int> &v, int low, int high)
{
    int pivot = v[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (v[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return (i + 1);
}
void quick_sort(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(v, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quick_sort(v, low, pi - 1);
        quick_sort(v, pi + 1, high);
    }
}


void heapify(vector<int> &v, int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
  
    // If left child is larger than root
    if (l < n && v[l] > v[largest])
        largest = l;
  
    // If right child is larger than largest so far
    if (r < n && v[r] > v[largest])
        largest = r;
  
    // If largest is not root
    if (largest != i)
    {
        swap(v[i], v[largest]);
  
        // Recursively heapify the affected sub-tree
        heapify(v, n, largest);
    }
}
void heap_sort(vector<int> &v, int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);
  
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--)
    {
        // Move current root to end
        swap(v[0], v[i]);
  
        // call max heapify on the reduced heap
        heapify(v, i, 0);
    }
}

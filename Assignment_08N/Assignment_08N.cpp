/*******************************************************************
Problem: Assignment 08N 
Question: Benchmark each of the sorting methods listed: Insertion Sort,
        Bubble Sort, Selection Sort, Heap Sort, Quick Sort, Merge Sort.
        Benchmark each of the above sorting methods for data sizes of 
        10000, 20000, 30000, 40000 and 50000. Display the results in a
        table as shown below. The table should have rows and columns.
        However, the rows and columns need not be separated by lines.
        Add two more columns for Selection and Insertion Sorts.

Name: Mykhaylo Ignatyev
ID: 1718264
Date: 03/31/2019

Status: 100% Complete
*******************************************************************/
#include <ctime>
#include <string>
#include <random>
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;

const int MAX_CELL_LENGTH = 16;
const int NUM_CELLS = 6;
const int VECTOR_SIZE = 500000;
const int MAX_NUMBER = 1000000;
const int VECTOR_CHANGE_IN_SIZE = 100000;
const string TOP = "============+" + string(MAX_CELL_LENGTH * NUM_CELLS, '=');

template<typename Type>
void siftDown(vector<Type> &toSort, const int &start, const int &end)
{
  int root = start;

  while (((2 * root) + 1) <= end)
  {
    int child = (2 * root) + 1;
    int swp = root;

    if (toSort.at(swp) < toSort.at(child))
      swp = child;

    if ((child + 1) <= end && toSort.at(swp) < toSort.at(child + 1))
      swp = child + 1;

    if (swp == root)
      return;
    else
    {
      swap(toSort.at(child), toSort.at(root));
      root = swp;
    }
  }
}

template<typename Type
void heapify(vector<Type> &toSort, const int &count)
{
  int start = (count - 2) / 2;

  while (start >= 0)
  {
    siftDown(toSort, start--, count - 1);
  }
}

template<typename Type>
void heapSort(vector<Type> &toSort, const int &count)
{
  heapify(toSort, count);

  int end = count - 1;

  while (end > 0)
  {
    swap(toSort.at(end--), toSort.at(0));
    siftDown(toSort, 0, end);
  }
}

// merge()                             
// Merge the two sections of the array 
//  using Insertion Sort treating one  
//  section as the sorted section and  
//  the other as the unsorted section. 
template<typename Type>
void merge(vector<Type> &toSort, const int &start1, const int &end1, 
          const int &start2, const int &end2)
{
  int j = 0;
  Type temp;
  bool notDone = false;
  Type key;

  for (int i = start2; i <= end2; i++)
  {
    key = toSort.at(i);
    j = i;
    notDone = (toSort.at(j - 1) > key);
    temp = toSort.at(j);

    while (notDone)
    {
      // Slide all others to the right
      toSort.at(j) = toSort.at(j - 1);
      j--;

      notDone = (j > start1) && (toSort.at(j - 1) > key);
    }

    // Put removed record into correct slot
    toSort.at(j) = temp;
  }
}

template<typename Type>
void mergeSort(vector<Type> &toSort, const int &start, const int &end)
{
  int i = 0;
  int j = 0;

  if (start < end)  // If there is more than one item to sort 
  {
    i = start;
    j = start + ((end - start) / 2);
    mergeSort(toSort, i, j);

    i = j + 1;
    j = end;
    mergeSort(toSort, i, j);
    merge(toSort, start, (i - 1), i, j);
  }
}

template<typename Type>
int partition(vector<Type> &toSort, const int &start, const int &end)
{
  int l = start;
  int h = end;
  int midpoint = start + (end - start) / 2;     /** Pick middle element as pivot */
  Type pivot = toSort.at(midpoint);
  bool done = false;

  while (!done)
  {
    /** Increment l while numbers[l] < pivot */
    while (toSort.at(l) < pivot)
    {
      l++;
    }

    /** Decrement h while pivot < numbers[h] */
    while (pivot < toSort.at(h))
    {
      h--;
    }

    /** If there are zero or one elements remaining,
     all numbers are partitioned. Return h */
    if (l >= h)
    {
      done = true;
    }
    else
    {
      /** Swap numbers[l] and numbers[h],
       update l and h */
      swap(toSort.at(l), toSort.at(h));
      l++;
      h--;
    }
  }

  return h;
}

template<typename Type>
void quickSort(vector<Type> &toSort, const int &start, const int &end)
{
  int j = 0;

  if (start < end)
  {
    /** Partition the data within the array. Value j returned
    from partitioning is location of last element in low partition. */
    j = partition(toSort, start, end);

    /** Recursively sort low partition (i to j) and
     high partition (j + 1 to k) */
    quickSort(toSort, start, j);
    quickSort(toSort, (j + 1), end);
  }
}

template<typename Type>
void bubbleSort(vector<Type> &toSort)
{
  bool isSwap = false;

  do
  {
    isSwap = false;

    for (int count = 0; count < (toSort.size() - 1); count++)
    {
      if (toSort.at(count) > toSort.at(count + 1))
      {
        swap(toSort.at(count), toSort.at(count + 1));
        isSwap = true;
      }
    }
  } while (isSwap);
}

template<typename Type>
void selectionSort(vector<Type> &toSort)
{
  int startScan = 0;
  int minIndex = 0;
  Type minValue;

  for (startScan = 0; startScan < (toSort.size() - 1); startScan++)
  {
    minIndex = startScan;
    minValue = toSort.at(startScan);

    for (int i = startScan + 1; i < toSort.size(); i++)
    {
      if (toSort.at(i) < minValue)
      {
        minValue = toSort.at(i);
        minIndex = i;
      }
    }

    toSort.at(minIndex) = toSort.at(startScan);
    toSort.at(startScan) = minValue;
  }
}

template<typename Type>
void insertionSort(vector<Type> &toSort)
{
  int j = 0;
  Type temp;
  bool notDone = false;
  Type key;

  for (int i = 1; i < toSort.size(); i++)
  {
    key = toSort.at(i);
    j = i;

    notDone = (toSort.at(j - 1) > key);

    temp = toSort.at(j);

    while (notDone)
    {
      toSort.at(j) = toSort.at(j - 1);
      j--;

      notDone = (j > 0) && (toSort.at(j - 1) > key);
    }

    toSort.at(j) = temp;
  }
}
 
template<typename Type>
double sortingTime(const vector<Type> &vect, const int &size,
                   const int &sortOption)
{
  vector<Type> temp(vect.begin(), (vect.begin() + size));
  clock_t start, finish;
  double duration = 0;

  start = clock();

  switch(sortOption)
  {
  case 1: 
    heapSort(temp, temp.size());
    break;
  case 2:
    mergeSort(temp, 0, (temp.size() - 1));
    break;
  case 3:
    quickSort(temp, 0, (temp.size() - 1));
    break;
  case 4:
    bubbleSort(temp);
    break;
  case 5:
    selectionSort(temp);
    break;
  case 6:
    insertionSort(temp);
    break;
  default:
    break;
  }

  finish = clock();
  duration = static_cast<double>(finish - start) / CLOCKS_PER_SEC;

  return duration;
}

void initVector(vector<int> &vect)
{
  random_device rd;
  default_random_engine generator(rd());
  uniform_int_distribution<int> distribution(1, MAX_NUMBER);

  for (int i = 0; i < vect.size(); i++)
  {
    vect.at(i) = distribution(generator);
  }
}

int main()
{
  vector<int> vect(VECTOR_SIZE);

  initVector(vect);

  cout << endl;
  
  cout
    << setw(78) << "Execution Time of Each of Sorting Methods in Seconds"
    << endl << TOP << endl
    << setw(14) << left << "  Data Size |"
    << setw(15) << "  Merge Sort  |"
    << setw(14) << "  Heap Sort  |"
    << setw(15) << "  Quick Sort  |"
    << setw(16) << "  Bubble Sort  |"
    << setw(19) << "  Selection Sort  |"
    << setw(15) << "  Insertion Sort"
    << endl << TOP << endl;

  for (int i = VECTOR_CHANGE_IN_SIZE; i <= VECTOR_SIZE; i += VECTOR_CHANGE_IN_SIZE)
  {
    cout
      << setw(11) << right << i << " |"
      << setprecision(3) << fixed;
    cout
      << setw(11) << sortingTime(vect, i, 1) << " s  |";
    cout
      << setw(9) << sortingTime(vect, i, 2) << " s  |";
    cout
      << setw(10) << sortingTime(vect, i, 3) << " s  |";
    cout
      << setw(11) << sortingTime(vect, i, 4) << " s  |";
    cout
      << setw(14) << sortingTime(vect, i, 5) << " s  |";
    cout
      << setw(14) << sortingTime(vect, i, 6) << " s"
      << endl;
  }
  
  cout << TOP << endl;

  return 0;
}
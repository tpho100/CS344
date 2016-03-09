#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

template <typename T>
void mySwap(T &a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
}


template <typename T>
void printVector(vector<T> &A)
{
	cout << endl;
	for(int i = 0; i < A.size(); i++)
	{
		cout << A[i] << endl;
	}
}

template <typename T>
//p and r are indices (0 and length-1)
int partition(vector<T> &A, int p, int r)
{
	T pivot = A[r]; //pivot is the last elm
	int i = p-1; //will end up being 1 before pivot
	for(int j = p; j < r; j++)
	{
		if(A[j] <= pivot)
		{
			i++;
			mySwap(A[i],A[j]);
		}
	}	
	mySwap(A[i+1],A[r]);
	//printVector(A);
	return i+1;
}

template <typename T>
int randomPartition(vector<T>&A, int p, int r)
{
	srand(time(NULL));
	T pivot = (rand() % (r-p+1))+p; //Pick random number between 0 and r
	cout << "pivot " << pivot << endl;
	mySwap(A[r],A[pivot]);
	return partition(A,p,r);
}

template <typename T>
void quicksort(vector<T> &A, int p, int r)
{
	if(p < r)
	{
		int q = partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}

template <typename T>
void randomQuicksort(vector<T> &A, int p, int r)
{
	if(p < r)
	{
		int q = randomPartition(A,p,r);
		randomQuicksort(A,p,q-1);
		randomQuicksort(A,q+1,r);
	}
}

int main()
{
	vector<int> B = {23, 1, 7, 4, 0, 3, 4,5,6,2};
	printVector(B);
	cout << "\n\n" << endl;
	randomQuicksort(B,0,B.size()-1);
	printVector(B);
	return 0;
}

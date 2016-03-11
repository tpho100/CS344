#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Integer.h"
#include <algorithm>

using namespace std;

int get_total_comparisons(vector<Integer> &A)
{
	int comparisons = 0;
	
	for(int i = 0; i < A.size(); i++)
	{
		//cout << A[i].get_count() << " , ";
		comparisons = comparisons + A[i].get_count();
	}
	return comparisons;
}

template <typename T>
void my_swap(T &a, T&b)
{//Swaps two objects
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void print_vector(vector<T> &A)
{//Print content of vector
	cout << "===Printing contents of vector===" << endl;
	for(int i = 0; i < A.size(); i++)
	{
		cout << A[i] << " , ";
	}
	cout << endl;
}

void print_vector_integer(vector<Integer> &A)
{
	cout << "===Printing vector of Integer objects===" << endl;
	
	for(int i = 0; i < A.size(); i++)
	{
		cout << A[i].get_value() << " , "; 
	}
	cout << endl;
}

template <typename T>
void insertion_sort(vector<T> &A)
{
	for(int i = 1; i < A.size(); i++)
	{
		T value = A[i];
		int index = i - 1;
		while( index >= 0 && value < A[index]   )
		{
			A[index+1] = A[index];
			index--;
		}
		A[index+1] = value;
	}
}


template <typename T>
int partition(vector<T> &A, int p, int r)
{//Partition using last elm
	T pivot = A[r];
	int i = p-1;
	for(int j = p; j < r; j++)
	{
		if(A[j] <= pivot)
		{
			i++;
			my_swap(A[i],A[j]);
		}
	}	
	my_swap(A[i+1],A[r]);
	return i+1;
}

int get_random_number(int p, int r)
{
	return ( rand() % (r-p+1) ) + p;
}


template <typename T>
int random_partition(vector<T>&A, int p, int r)
{ //Partition using random pivot
	int pivot = get_random_number(p,r);
	my_swap(A[r],A[pivot]);
	return partition(A,p,r);
}

template <typename T>
void quicksort(vector<T> &A, int p, int r)
{//Quicksort using last elm as pivot
	if(p < r)
	{
		int q = partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}

template <typename T>
void random_quicksort(vector<T> &A, int p, int r)
{ //Quicksort using random pivot
	if(p < r)
	{
		int q = random_partition(A,p,r);
		random_quicksort(A,p,q-1);
		random_quicksort(A,q+1,r);
	}
}



int main()
{
	int vectorSizeN = 5000;
	int randomNumberCap = vectorSizeN;//Maximum number when generating random numbers
	int randomCount = 1000; //Number of times to use random vector for each case (generates new one each time)
	cout << "Using size N vector: " << vectorSizeN << endl;	
	
	vector<Integer> sortedVector;
	for(int i = 0; i < vectorSizeN; i++)
	{
		Integer tempInt = Integer(i);
		sortedVector.push_back(tempInt);
	}
	vector<Integer> sortedVectorInsertion = sortedVector;
	vector<Integer> sortedVectorQuick = sortedVector;
	vector<Integer> sortedVectorRandomQuick = sortedVector;		
	
	//===SORTED VECTOR RESULTS===
	//(1A)
	insertion_sort(sortedVectorInsertion);
	cout << "Insertion Sort - Sorted Vector Count: " << get_total_comparisons(sortedVectorInsertion) << endl;
	
	//(1B)
	quicksort(sortedVectorQuick,0,sortedVectorQuick.size()-1);
	cout << "Quick Sort - Sorted Vector Count: " << get_total_comparisons(sortedVectorQuick) << endl;

	//(1C)
	random_quicksort(sortedVectorRandomQuick,0,sortedVectorRandomQuick.size()-1);
	cout << "Random Quick Sort - Sorted Vector Count: " << get_total_comparisons(sortedVectorRandomQuick) << endl;


	vector<Integer> reversedVector;
	for(int i = 0; i < vectorSizeN; i++)
	{
		Integer tempInt = Integer(vectorSizeN-i-1);
		reversedVector.push_back(tempInt);
	}
	vector<Integer> reversedVectorInsertion = reversedVector;
	vector<Integer> reversedVectorQuick = reversedVector;
	vector<Integer> reversedVectorRandomQuick = reversedVector;	

	//===REVERSED VECTOR RESULTS===
	//(2A)
	insertion_sort(reversedVectorInsertion);
	cout << "Insertion Sort - Reversed Vector Count: " << get_total_comparisons(reversedVectorInsertion) << endl;

	//(2B)
	quicksort(reversedVectorQuick,0,reversedVectorQuick.size()-1);
	cout << "Quick Sort - Reversed Vector Count: " << get_total_comparisons(reversedVectorQuick) << endl;

	//(2B)
	random_quicksort(reversedVectorRandomQuick,0,reversedVectorRandomQuick.size()-1);
	cout << "Random Quick Sort - Reversed Vector Count: " << get_total_comparisons(reversedVectorRandomQuick) << endl;

	srand(time(NULL));
	//===RANDOM VECTOR RESULTS===
	cout << "BEGINNING RANDOM VECTOR PROCESS - MAKE TAKE A WHILE..." << endl;
	double randomCountInsertion = 0;
	double randomCountQuick = 0;
	double randomCountRandomQuick = 0;
	for(int i = 0; i < randomCount; i++)	
	{
		vector<Integer> randomVector;
		for(int i = 0; i < vectorSizeN; i++)
		{
			Integer tempInt = Integer(get_random_number(0,randomNumberCap));
			randomVector.push_back(tempInt);
		}
		
		vector<Integer> randomVectorInsertion = randomVector;
		insertion_sort(randomVectorInsertion);
		randomCountInsertion = randomCountInsertion + get_total_comparisons(randomVectorInsertion);

		vector<Integer> randomVectorQuick = randomVector;
		quicksort(randomVectorQuick,0,randomVectorQuick.size()-1);
		randomCountQuick = randomCountQuick + get_total_comparisons(randomVectorQuick);		

		vector<Integer> randomVectorRandomQuick = randomVector;
		random_quicksort(randomVectorRandomQuick,0,randomVectorRandomQuick.size()-1);
		randomCountRandomQuick = randomCountRandomQuick + get_total_comparisons(randomVectorRandomQuick);			

	}
	cout << "Average Insertion: " <<  (randomCountInsertion/randomCount)  << endl;
	cout << "Average Quick: " <<  (randomCountQuick/randomCount)  << endl;
	cout << "Average Random Quick: " <<  (randomCountRandomQuick/randomCount)  << endl;

	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void insertion_sort(vector<T> &A)
{
	for(int i = 1; i < A.size(); i++)
	{
		T value = A[i];
		T index = i - 1;
		while( index >= 0 && value < A[index]   )
		{
			A[index+1] = A[index];
			index--;
		}
		A[index+1] = value;
	}
}


int main()
{
	vector<float> B;
	
	B.push_back(6.6);
	B.push_back(6.3);
	B.push_back(6.7);
	B.push_back(4.5);
	B.push_back(1.2);
	B.push_back(3.3);
	B.push_back(10.3);
	B.push_back(0.5);	

	for(int i = 0; i < B.size(); i++)
	{
		cout << B.at(i) << endl;
	}
	cout << '\n' << endl;

	insertion_sort(B);
	
	for(int i = 0; i < B.size(); i++)
	{
		cout << B.at(i) << endl;
	}
	return 0;
}

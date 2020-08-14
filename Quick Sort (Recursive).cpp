//Quick Sort (Recursive)
//
//Sample Output:
//Before Sorting: 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
//After Sorting: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define ARRAY_SIZE 20

void assignSerialNumbersIntoArray(int myArray[])
{
	for( int i = 0; i < ARRAY_SIZE; i++ )
	{
		myArray[i] = i;
	}
}

void assignSerialNumbersReverselyIntoArray(int myArray[])
{
	for( int i = 0; i < ARRAY_SIZE; i++ )
	{
		myArray[i] = (ARRAY_SIZE - i - 1);
	}
}

void assignRandomNumbersIntoArray(int myArray[])
{
	srand(time(0));
	for( int i = 0; i < ARRAY_SIZE; i++ )
	{
		myArray[i] = rand();
	}
}

void printArrayContents(int myArray[])
{
	for( int i = 0; i < ARRAY_SIZE; i++ )
	{
		cout << myArray[i] << " ";
	}
}

void quickSort(int myArray[], int firstIndex, int lastIndex)
{
	if( firstIndex >= lastIndex )
	{
		return;
	}
	
	int index1 = (firstIndex + 1);
	int index2 = lastIndex;
	
	while( index1 < lastIndex && myArray[firstIndex] >= myArray[index1] )
	{
		index1++;
	}
	while( firstIndex < index2 && myArray[firstIndex] <= myArray[index2] )
	{
		index2--;
	}
	while( index1 < index2 )
	{
		swap(myArray[index1], myArray[index2]);
		index1++;
		index2--;
		
		while( index1 < lastIndex && myArray[firstIndex] >= myArray[index1] )
		{
			index1++;
		}
		while( firstIndex < index2 && myArray[firstIndex] <= myArray[index2] )
		{
			index2--;
		}
	}
	
	// index2 is partition index now
	swap(myArray[firstIndex], myArray[index2]);
	
	quickSort(myArray, firstIndex, (index2 - 1));
	quickSort(myArray, (index2 + 1), lastIndex);
}

int main()
{
	int myArray[ARRAY_SIZE];
	
	assignSerialNumbersReverselyIntoArray(myArray);
	
	cout << "Before Sorting: ";
	printArrayContents(myArray);
	cout << endl;
	
	quickSort(myArray, 0, (ARRAY_SIZE - 1));
	
	cout << "After Sorting: ";
	printArrayContents(myArray);
	cout << endl;
	
	return 0;
}
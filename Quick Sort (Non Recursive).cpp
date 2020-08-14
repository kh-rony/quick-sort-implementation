//Quick Sort (Non Recursive)
//
//Sample Output:
//Before Sorting: 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
//After Sorting: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define ARRAY_SIZE 20

struct list
{
	int data;
	struct list *next;
};
typedef struct list node;

node *listOfArrayIndexes = NULL;
node *pointerToLastItemInList = NULL;

void printArrayContents(int myArray[])
{
	for( int i = 0; i < ARRAY_SIZE; i++ )
	{
		cout << myArray[i] << " ";
	}
}

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

void enqueue(int item)
{
	if( listOfArrayIndexes == NULL )
	{
		listOfArrayIndexes = new node;
		listOfArrayIndexes->next = NULL;
		listOfArrayIndexes->data = item;
		pointerToLastItemInList = listOfArrayIndexes;
		return;
	}
	
	node *newNode = new node;
	newNode->next = NULL;
	newNode->data = item;
	
	pointerToLastItemInList->next = newNode;
	pointerToLastItemInList = newNode;
}

int dequeue()
{
	int item = listOfArrayIndexes->data;
	
	listOfArrayIndexes = listOfArrayIndexes->next;
	
	if( listOfArrayIndexes == NULL )
	{
		pointerToLastItemInList = listOfArrayIndexes;
	}
	return item;
}

int quickSort(int myArray[], int firstIndex, int lastIndex)
{
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
	return index2;
}

int main()
{
	int myArray[ARRAY_SIZE];
	
	assignSerialNumbersReverselyIntoArray(myArray);
	
	cout << "Before Sorting: ";
	printArrayContents(myArray);
	cout << endl;
	
	int firstIndex = 0;
	int lastIndex = (ARRAY_SIZE - 1);
	int partitionIndex;
	
	enqueue(firstIndex);
	enqueue(lastIndex);
	
	while( listOfArrayIndexes != NULL )
	{
		firstIndex = dequeue();
		lastIndex = dequeue();
		
		partitionIndex = quickSort(myArray, firstIndex, lastIndex);
		
		if( firstIndex < (partitionIndex - 1) )
		{
			enqueue(firstIndex);
			enqueue(partitionIndex - 1);
		}
		if( (partitionIndex + 1) < lastIndex )
		{
			enqueue(partitionIndex + 1);
			enqueue(lastIndex);
		}
	}
	
	cout << "After Sorting: ";
	printArrayContents(myArray);
	cout << endl;
	
	return 0;
}
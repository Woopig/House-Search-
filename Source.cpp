#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "House.h"

using namespace std;

void openFile(vector<House*>& houses, const string fileName);
void saveFile(vector<House*> &houses, const string fileName);
void displayHouses(vector<House*> houses);
int Partition(vector<House*> & houses, int i, int j);
void QuickSort(vector<House*> & houses, int i, int j);
void InsertionSort(vector<House*>& houses);
void SelectionSort(vector<House*> & houses);
void Merge(vector<House*> & houses, int i, int j, int k);
void MergeSort(vector<House*> & houses, int i, int k);
void BubbleSort(vector<House*> & houses);
int BinarySearch(vector<House*> & houses, int value);


int main()
{
	const string fileName = "houses.txt";
	vector<House*> houses;
	houses.push_back(new House{ { 123, "first", "Little_rock", "AR", 72201}, 3, 1, 1600, 50000 });
	houses.push_back(new House{ { 789, "second", "Bryant", "AR", 72201 }, 1, 4, 3500, 100000 });
	houses.push_back(new House{ { 456, "third", "Benton", "AR", 72201 }, 2, 3, 2000, 75000 });
	houses.push_back(new House{ { 222, "fifth", "Jonesboro", "AR", 72201 }, 4, 3, 3300, 75000 });
	
		/*std::cout << "Enter House Number for House " << i + 1 << ": ";
		cin >> houses[i]->address.houseNumber;
		std::cout << "Enter Street for House " << i + 1 << ": ";
		cin >> houses[i]->address.street;
		std::cout << "Enter City for House " << i + 1 << ": ";
		cin >> houses[i]->address.city; 
		std::cout << "Enter State for House " << i + 1 << ": ";
		cin >> houses[i]->address.state;
		std::cout << "Enter Zip for House " << i + 1 << ": ";
		cin >> houses[i]->address.zipcode;
		std::cout << "Enter Number of Baths for House " << i + 1 << ": ";
		cin >> houses[i]->numBaths;
		std::cout << "Enter Number of Beds for House " << i + 1 << ": ";
		cin >> houses[i]->numBeds;
		std::cout << "Enter Sqft for House " << i + 1 << ": ";
		cin >> houses[i]->sqft;
		std::cout << "Enter price for House " << i + 1 << ": ";
		cin >> houses[i]->price;*/

	char choice = ' ';
	
	while (choice != 'Q')
	{
		displayHouses(houses);
		cout << endl;
		cout << "Enter from Following: " << endl;
		cout << "Choose A: Address" << endl;
		cout << "Choose B: Bedrooms" << endl;
		cout << "Choose C: Baths" << endl;
		cout << "Choose D: Sqft" << endl;
		cout << "Choose E: Price" << endl;
		cout << "Choose F to Change Price " << endl;
		cout << "Choose G to Save File" << endl;
		cout << "Choose H to Open File" << endl;
		cout << "Choose Q: Quit" << endl;
		cout << "Enter Q to quit, otherwise keep sorting." << endl;
		cin >> choice;
		switch (choice)
		{
		case 'A':
			InsertionSort(houses);
			break;

		case 'B':
			SelectionSort(houses);
			break;

		case 'C':
			MergeSort(houses, 0, houses.size() - 1);
			break;

		case 'D':
			QuickSort(houses, 0, houses.size() - 1);
			break;

		case 'E':
			BubbleSort(houses);
			break;

		case 'F':
			InsertionSort(houses);
			cout << "Enter House Number" << endl;
			int value;
			cin >> value;
			int key;
			key = BinarySearch(houses, value);
			cout << "Key is: " << key << endl;
			if (key == -1)
			{
				cout << "House Number Not Found" << endl;
			}
			else
			{
				cout << "Enter New Price: " << endl;
				int newPrice;
				cin >> newPrice;
				houses[key]->price = newPrice;
			}
			break;

			case 'G':
			saveFile(houses, fileName);
			break;

			case 'H':
			openFile(houses, fileName);
			break;
		}
	}
	std::system("PAUSE");
	return 0;	
}
void displayHouses(vector<House*> houses)
{
	for (int i = 0; i < houses.size(); ++i)
	{
		cout << "ADDRESS" << setw(20) << "\t" <<
			"NUM BEDS" << "\t" << "NUM BATH" << "\t" << "SQFT" << "\t" << "PRICE" << endl;
		cout << houses[i]->address.houseNumber << " " << houses[i]->address.street << " " << houses[i]->address.city << ", " << houses[i]->address.state << " " << houses[i]->address.zipcode;
		cout << "\t" << houses[i]->numBeds << "\t\t" << houses[i]->numBaths << "\t\t" << houses[i]->sqft << "\t" << houses[i]->price << endl;
	}
}
void openFile(vector<House*>& houses, const string fileName)
{
	ifstream fin(fileName);

	if (fin.is_open())
	{
		cout << "File open" << endl;
	}
	int i = 0;
	while (!fin.eof() && i < houses.size())
	{
		fin >> houses[i]->address.houseNumber >> houses[i]->address.street >> houses[i]->address.city >> houses[i]->address.state >> houses[i]->address.zipcode;
		fin >> houses[i]->numBeds >> houses[i]->numBeds >> houses[i]->price >> houses[i]->sqft;
		++i;
	}
	fin.close();
}
void saveFile(vector<House*> &houses, const string fileName)
{
	ofstream fout(fileName);

	for (int i = 0; i < houses.size(); ++i)
	{
		fout << houses[i]->address.houseNumber << " " << houses[i]->address.street << " " << houses[i]->address.city << " ";
		fout << houses[i]->address.state << " " << houses[i]->address.zipcode << " " << houses[i]->numBeds << " " << houses[i]->numBaths << " " << houses[i]->sqft << " " << houses[i]->price << endl;
	}
	fout.close();
}

void QuickSort(vector<House*> & houses, int i, int j)
{
	int z = 0;
	// base case: if 1 is 0 or more elements, partion already sorted.
	if (i >= j)
	{
		return;
	}
	// Partion the array
	// value j is the location in the last element of the low partition
	z = Partition(houses, i, j);

	// recursively sort high and low
	QuickSort(houses, i, z);
	QuickSort(houses, z + 1, j);

	return;
}
int Partition(vector<House*> & houses, int i, int j)
{
	
	House* pivot = houses[(i+j)/2];
	bool done = false;
	int h = 0;
	int l = 0;
	House* temp = nullptr;

	//pivot = houses[j];

	l = i;
	h = j;

	while (!done)
	{
		// Increment l while a[l] < pivot
		while (houses[l]->sqft < pivot->sqft)
		{
			++l;
		}
		while (pivot->sqft < houses[h]->sqft)
		{
			--h;
		}
		if (l >= h)
		{
			done = true;
		}
		else
		{
			// swap numbers[l] and a[h], update h and l
			temp = houses[l];
			houses[l]= houses[h];
			houses[h] = temp;
			++l;
			--h;
		}
	}
	return h;
}
void InsertionSort(vector<House*> & houses)
{
	int i = 0;
	int j = 0;
	int temp = 0;  // Temporary variable for swap

	for (i = 1; i < houses.size(); ++i) 
	{
		j = i;
		//            i
		// 123  456  222  789
		// [0]  [1]  [2]  [3]
		//            j
		// temp = 
		// Insert numbers[i] into sorted part
		// stopping once numbers[i] in correct position
		while (j > 0 && houses[j]->address.houseNumber < houses[j-1]->address.houseNumber) 
		{
			// Swap numbers[j] and numbers[j - 1]
			temp = houses[j]->address.houseNumber;
			houses[j]->address.houseNumber = houses[j - 1]->address.houseNumber;
			houses[j - 1]->address.houseNumber = temp;
			--j;
		}
	}
}
void SelectionSort(vector<House*> & houses) 
{
	int i = 0;
	int j = 0;
	int indexSmallest = 0;
	int temp = 0;  // Temporary variable for swap

	for (i = 0; i < houses.size(); ++i) 
	{
		// Find index of smallest remaining element
		indexSmallest = i;
		for (j = i + 1; j < houses.size(); ++j) 
		{
			if (houses[j]->numBeds < houses[indexSmallest]->numBeds) 
			{		
				indexSmallest = j;
			}
		}
		// Swap numbers[i] and numbers[indexSmallest]
		temp = houses[i]->numBeds;
		houses[i]->numBeds = houses[indexSmallest]->numBeds;
		houses[indexSmallest]->numBeds = temp;
	}
}
void Merge(vector<House*> & houses, int i, int j, int k)
{
	int mergedSize = k - i + 1;            // Size of merged partition
	int mergePos = 0;                      // Position to insert merged number
	int leftPos = 0;                       // Position of elements in left partition
	int rightPos = 0;					   // Position of elements in right partition
	vector<House> mergedNumbers;
	mergedNumbers.resize(houses.size());    // Dynamically allocates temporary array		
	
	leftPos = i;                           // Initialize left partition position
	rightPos = j + 1;                      // Initialize right partition position

										   // Add smallest element from left or right partition to merged numbers
	while (leftPos <= j && rightPos <= k)
	{
		if (houses[leftPos]->numBaths <= houses[rightPos]->numBaths)
		{	
			mergedNumbers[mergePos].numBaths = houses[leftPos]->numBaths;
			++leftPos;	
		}
		else
		{
			mergedNumbers[mergePos].numBaths = houses[rightPos]->numBaths;
			++rightPos;
		}
		++mergePos;
	}

	// If left partition is not empty, add remaining elements to merged numbers
	while (leftPos <= j)
	{
		//mergedNumbers.push_back(new House);
		mergedNumbers[mergePos].numBaths = houses[leftPos]->numBaths;
		++leftPos;
		++mergePos;
	}

	// If right partition is not empty, add remaining elements to merged numbers
	while (rightPos <= k)
	{
		mergedNumbers[mergePos].numBaths = houses[rightPos]->numBaths;
		++rightPos;
		++mergePos;
	}

	// Copy merge number back to numbers
	for (mergePos = 0; mergePos < mergedSize; ++mergePos)
	{
		houses[i + mergePos]->numBaths = mergedNumbers[mergePos].numBaths;
	}
}

void MergeSort(vector<House*>& houses, int i, int k)
{
	int j = 0;

	if (i < k)
	{
		j = (i + k) / 2;  // Find the midpoint in the partition

						  // Recursively sort left and right partitions
		MergeSort(houses, i, j);
		MergeSort(houses, j + 1, k);

		// Merge left and right partition in sorted order
		Merge(houses, i, j, k);
	}
}
void BubbleSort(vector<House*> & houses)
{
	bool swapped;
	int j = 0;
	int i = 0;
	int temp = 0;
	for (i = 0; i < houses.size() - 1; ++i)
	{
		swapped = false;
		for (j = 0; j < houses.size() - i - 1; ++j)
		{
			if (houses[j]->price > houses[j + 1]->price)
			{
				temp = houses[j]->price;
				houses[j]->price = houses[j+1]->price;
				houses[j+1]->price = temp;
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}
int BinarySearch(vector<House*> & houses, int number)
{

	int low = 0;
	int high = houses.size() - 1;
		
	while (low <= high)
	{
		// 123 789 456 222
		// [0] [1] [2] [3]
		// Number is 222.
		// first loop mid = 1, which is 789. 789 is not less than 222, so the third branh executes. High is now 0.
		// second loop mid = 0, which 123. 123 is less than 222. so the second branch executes. low is now 1. but high is 0, so branch stops execution.
		int mid = (low + high) / 2;

		if (houses[mid]->address.houseNumber == number)
		{
			return mid;
		}
		if (houses[mid]->address.houseNumber < number)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
		
	}

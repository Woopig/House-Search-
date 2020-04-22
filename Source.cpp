#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "House.h"

using namespace std;

enum FIELD{ ADDRESS, BEDS, BATHS, SQFT, PRICE, QUIT };

vector<House*> loadHouses(const string fileName);
void displayHouses(const vector<House*> & houses);
FIELD displayChoices();
void changePrice(const FIELD field, const string key, vector<House*> & houses);
FIELD prompt(const string & key, const vector<House*> & houses);

void insertionSort(vector<House*> & houses);
void selectionSort(vector<House*> & houses);
void mergeSort(vector<House*> & houses);
void quickSort(vector<House*> & houses);
//Add one more sorting algorithm!!!!!

void binarySearch(const FIELD field, const string key, const vector<House*> & houses);


void saveHouses(const string fileName, const vector<House*> & houses);

House * remove_(House * house);
House * insert_(House * house);

int main()
{

	
}

//removes underscores from street name and city name
House * remove_(House * house)
{
	for (int i = 0; i < house->address.street.size(); i++)
	{
		if (house->address.street[i] == '_') house->address.street[i] = ' ';
	}
	for (int i = 0; i < house->address.city.size(); i++)
	{
		if (house->address.city[i] == '_') house->address.city[i] = ' ';
	}
	return house;
}

//replace spaces with underscores.
House * insert_(House * house)
{
	for (int i = 0; i < house->address.street.size(); i++)
	{
		if (house->address.street[i] == ' ') house->address.street[i] = '_';
	}
	for (int i = 0; i < house->address.city.size(); i++)
	{
		if (house->address.city[i] == ' ') house->address.city[i] = '_';
	}

	return house;
}

vector<House*> loadHouses(const string fileName)
{
	
}

int longestName(const vector<House*>& houses)
{
	int longest = 0;
	for (auto house : houses)
	{
		if (int currSize = house->address.street.size(); currSize > longest)
		{
			longest = currSize;
		}

	}
	return longest;
}
void displayHouses(const vector<House*>& houses)
{
	int longest = longestName(houses);
	cout << "ADDRESS" << setw(longest - 12) << "\t" << "PRICE"  << "\t" <<
		"NUM BEDS" << "\t" << "NUM BATH"<< "\t" << "SQFT" << endl;
	
}

FIELD displayChoices()
{
	
}

FIELD prompt(const string & key, const vector<House*> & houses)
{
	
}

void insertionSort(vector<House*>& houses)
{
}

void selectionSort(vector<House*>& houses)
{
}

void mergeSort(vector<House*>& houses)
{
}

void quickSort(vector<House*>& houses)
{
}

void jumpSort(vector<House*>& houses)
{
}

void binarySearch(const FIELD field, const string key, const vector<House*>& houses)
{
}

void changePrice(const FIELD field, const string key, vector<House*>& houses)
{
}

void saveHouses(const string fileName, const vector<House*>& houses)
{
}

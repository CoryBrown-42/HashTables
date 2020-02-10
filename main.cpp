#include <iostream>
#include <vector>
#include <algorithm>//sort, random_shuffle
#include <string>

#include "Timer.h"
#include "DirectAddressTable.h"
#include "HashTable.h"

using namespace std;

class Movie
{
public:
	int id;//Key to our Direct Address Table.
	string movieData;
	string name;
	int playCount;
	string genre;

	bool operator<(Movie &rhs) const//const here means this func can't change 'id' or 'name', etc. of the movie
	{
		return playCount < rhs.playCount;
	}

private:
};

//bool operator<(Movie &leftSide, Movie &rightSide)
//{
//	return leftSide.id < rightSide.id;
//}

/*Searching
	Binary Search O(log(n))
	Linear Search, Brute Force Search O(n)
	Can we search in O(1) complexity?
  Sorting
	Bubble Sort O(n^2)
	Selection Sort O(n^2)
	Insertion Sort O(n^2) - Best Case Big-Omega(n)
	Quick Sort O(n^2) - Average case O(nlog(n))
	Merge Sort O(nlog(n))
	Can we sort in O(n)?
*/

//Downside = only works on positive, unique integers
//And requires an array as big as the largest value + 1 - so you might waste alot of space
//Comparative Sorting = Sort by comparing values to each other
//Counting Sort is NOT a comparative sort (it doesn't compare numbers to determine locations)
//In-place sort = just shuffles things around the original vector (doesn't make new vectors)
//Counting Sort is NOT an in place sort
void CountingSort(vector<int> &vec)//O(n)
{
	vector<int> sortedVec(vec.size());//new vector same size as original
	
	for (int i = 0; i < vec.size(); ++i)
		sortedVec[vec[i]] = vec[i];

	vec = sortedVec;//copy sorted vector back to original
}

int main()
{
	int n = 10;

	vector<int> numbers;
	for(int i = 0; i < n; ++i)
		numbers.push_back(i);
		
	random_shuffle(numbers.begin(), numbers.end());

	for (int i = 0; i < n; ++i)
		cout << numbers[i] << endl;

	cout << endl;
	CountingSort(numbers);

	for (int i = 0; i < n; ++i)
		cout << numbers[i] << endl;

	Movie lordOfTheRings;
	lordOfTheRings.id = 742;
	lordOfTheRings.name = "Lord of the Rings";
	Movie jurassicParty;
	jurassicParty.id = 369;
	jurassicParty.name = "Jurassic Party";
	Movie dannydevito; 
	dannydevito.id = 204;
	dannydevito.name = "Danny Devito";
	Movie civilWar;
	civilWar.id = 839;
	civilWar.name = "Captain America: Civil War";

	DirectAddressTable<Movie> datMovie(850);
	datMovie.Add(lordOfTheRings.id, lordOfTheRings);
	datMovie.Add(jurassicParty.id, jurassicParty);
	datMovie.Add(dannydevito.id, dannydevito);
	datMovie.Add(civilWar.id, civilWar);

	Movie lotRCopy = datMovie.Search(lordOfTheRings.id);//O(1) search
	cout << lotRCopy.name << endl;

	HashTable<Movie, int> mHT;//movieHashTable
	mHT.Add(lordOfTheRings.id, lordOfTheRings);
	mHT.Add(jurassicParty.id, jurassicParty);
	mHT.Add(dannydevito.id, dannydevito);
	mHT.Add(civilWar.id, civilWar);
	//mHT[civilWar.id] = civilWar;//next time...

	Movie tempMovie = mHT[civilWar.id];
	cout << tempMovie.name << endl;

	HashTable<double, int> importantMathConstants;
	importantMathConstants.Add(3, 3.14159);
	importantMathConstants.Add(1, 6.022e23);
	cout << importantMathConstants[3] << endl;

	int num = 5;
	int num2 = 6;
	//jurassicParty = civilWar;//Memberwise assignment 
	//cout << jurassicParty + civilWar << endl;

	return 0;
}
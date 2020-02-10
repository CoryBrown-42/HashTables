#pragma once

#include <vector>

using namespace std;

//Stores values at the index that matches that value
//So that they can be retrieved in constant time. O(1) Search
template <class T>
class DirectAddressTable
{
public:
	DirectAddressTable(int size = 100)
	{
		table.resize(size);
	}
	T Search(int key)
	{
		return table[key];
	}
	void Add(int key, T val)
	{
		table[key] = val;
	}

private:
	vector<T> table;
};
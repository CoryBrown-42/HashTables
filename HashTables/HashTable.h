#pragma once

#include <vector>

using namespace std;

/*
Hash value = Fixed Length string/number generated deterministically from a variable length input
	Deterministic = For a given input, you always get the same output
					No randomization. If input = 5, output = 7, then every 5 will output 7

Web/Security Example
password1234 (plaintext)
Hash(password1234) =  980234jsfkjg093jkjfd0894
Hash(password123)  =  HB794LJZSD0823LJ098234JJ

Hash Table Example
Hash(742) = 2
Hash(369) = 9
Hash(204) = 4
Hash(839) = 9//Hash Collision - 2 different inputs hash to the same output
					
*/

template<class T, class K>
class HashTable
{
	struct ValuePair
	{
		T data;
		K key;
	};

public:
	HashTable(int initialSize = 10)
	{
		table.resize(10);
	}
	int Hash(K key) const//Calculate an array index from whatever 'key' is
	{//Rule is hash values have to be within 0 - (arraySize - 1)

		return key % table.size();
	}
	void Add(K key, T data)
	{
		ValuePair storedData;
		storedData.key = key;
		storedData.data = data;
		table[Hash(key)].push_back(storedData);
	}
	T Search(K key) const
	{
		int hash = Hash(key);
		//Collisions should be rare, so it still behaves like a O(1) function
		for (int i = 0; i < table[hash].size(); ++i)//O(bucketSize)
		{
			if (table[hash][i].key == key)
				return table[hash][i].data;
		}
		//bucket 0:
		//bucket 1:
		//bucket 3:
		//...
		//bucket 9: Jurassic Party, Civil War 
	}
	T operator[](K key) const
	{ 
		return Search(key);
	}
	//Pointer vs. Reference
	//A reference can't be null, and can't be reassigned

private:
	vector<vector<ValuePair>> table;
};
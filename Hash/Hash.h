#pragma once
#ifndef HASH_H
#define HASH_H
#include <iostream>

using namespace std;
const int SIZE=10 ;

template <typename HashType1, typename HashType2> class hash
{
	HashType tab[SIZE][2];
public:
	void remove();
	void add();
	void search();
	void output();
};
#endif // !HASH_H

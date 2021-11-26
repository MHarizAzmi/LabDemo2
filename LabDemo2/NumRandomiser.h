#pragma once
#include <random>

using namespace std;

class NumRandomiser
{
private:
	default_random_engine re;
	uniform_int_distribution<>	dist;

public:
	//constructor
	NumRandomiser(int low, int high) :
		dist{ low, high } {}

	//functor
	//This is a functor, returning a random number
	int operator() () { return dist(re); }

};





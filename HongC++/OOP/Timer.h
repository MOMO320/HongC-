#pragma once
#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include <vector>

using namespace std;

class Timer
{
	using clock_t = chrono::high_resolution_clock;
	using second_t = chrono::duration<double, std::ratio<1>>;

	chrono::time_point<clock_t> start_time = clock_t::now();

public:
	void elapsed()
	{
		chrono::time_point<clock_t> end_time = clock_t::now();
		cout << chrono::duration_cast<second_t>(end_time - start_time).count() << endl;
	}
};
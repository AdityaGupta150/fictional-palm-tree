#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

#include <ranges>

#include "util/converters.hpp"

using namespace std;

int main(){
	vector<int> a(20);
	a.resize(20);


	cout << util::converter::inToPost("(A+B)*9-(C-62)*F+41") << endl;

	iota(a.begin(), a.end(), 1);
	shuffle(a.begin(), a.end(), std::random_device{});

	for (auto &&i : a)
	{
		cout << i << ' ';
	}
	cout << endl;

	cout << __cplusplus << endl;

	// std::vector<int> ints{0,1,2,3,4,5};
	// auto even = [](int i){ return 0 == i % 2; };
	// auto square = [](int i) { return i * i; };
	
	// for (int i : ints | std::view::filter(even) | std::view::transform(square)) {
	// 	std::cout << i << ' ';
	// }
}
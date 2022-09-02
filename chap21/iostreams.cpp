#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <set>

int main() {
	std::ifstream is {"input.txt"};
	std::ofstream os {"output.txt"};

	std::istream_iterator<std::string> ii {is};
	std::istream_iterator<std::string> eos;
	std::ostream_iterator<std::string> oo {os, "\n"};

	// std::vector<std::string> v {ii, eos};
	// // std::vector<std::string> v {10000}; // terrible soln, to guess size and write
	// // std::copy(ii, eos, v.begin());

	// std::sort(v.begin(), v.end());
	// std::unique_copy(v.begin(), v.end(), oo);

	// set soln.
	std::set<std::string> st {ii, eos};
	std::copy(st.begin(), st.end(), oo);
}
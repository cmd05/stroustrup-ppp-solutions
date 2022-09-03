#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>
#include <numeric>
#include <algorithm>

void read_vals(std::vector<double>& vd, std::string file) {
	std::ifstream is {file};
	std::istream_iterator<double> ii {is};
	
	vd.assign(ii, std::istream_iterator<double>{});
}

int main() {
	std::vector<double> vd;
	read_vals(vd, "drill3_input.txt");
	for(double x : vd)
		std::cout << x << "\n";

	std::vector<int> vi {vd.begin(), vd.end()};

	std::cout << "\n";
	for(int i = 0; i < vd.size(); i++)
		std::cout << vd[i] << "\t" << vi[i] << "\n";

	std::cout << "\n";
	std::cout << "vdsum=" << std::accumulate(vd.begin(), vd.end(), 0.0) << "\n";
	std::cout << "vdsum - visum=" << std::accumulate(vd.begin(), vd.end(), 0.0) - std::accumulate(vi.begin(), vi.end(), 0) << "\n";

	std::cout << "\n";
	std::reverse(vd.begin(), vd.end());
	for(double x : vd)
		std::cout << x << "\n";
	
	std::cout << "\n";
	double vd_mean = std::accumulate(vd.begin(), vd.end(), 0.0) / vd.size();
	std::cout << "vdmean=" << vd_mean  << "\n";
	
	std::cout << "\n";
	std::vector<double> vd2;
	std::copy_if(vd.begin(), vd.end(), std::back_inserter(vd2), [vd_mean](double d) { return d < vd_mean; });
	for(double x : vd2)
		std::cout << x << "\n";
	
	std::cout << "\n";
	std::sort(vd.begin(), vd.end());
	for(double x : vd)
		std::cout << x << "\n";
}
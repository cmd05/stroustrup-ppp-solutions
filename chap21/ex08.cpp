#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>

int main() {
	std::map<std::string ,int> words;
	std::ifstream is {"words.txt"};

	for (std::string s; is >> s;)
		++words[s];

	// for(auto p : words)
	// 	std::cout << p.second << ": " << p.first << '\n';

	using pair_type = std::pair<std::string, int>;
	
	std::vector<pair_type> v_words {words.size()};
	
	int i = 0;
	for(auto& word : words) {
		v_words[i] = std::move(word);
		i++;
	}

	std::sort(v_words.begin(), v_words.end(), [](pair_type a, pair_type b){ return a.second > b.second; });

	for(pair_type& p : v_words)
		std::cout << p.second << ": " << p.first << '\n';
}
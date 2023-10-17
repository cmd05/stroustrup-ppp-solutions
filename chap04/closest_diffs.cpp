/* You are given an array and a value n. You need to find the
pair of elements of the array whose sum is closest to n.
Example: Input: array = {31,40,34,11,5,25}, n = 46
Output: 5 and 40
 */

#include <iostream>
#include <vector>
#include <limits>

std::vector<std::vector<int>> closest_diffs(std::vector<int> v, int req) {
    int diff_last = std::numeric_limits<int>::max(); // Guarantees that first difference will always be true
    std::vector<std::vector<int>> nums;

    for(int i = 0; i < v.size(); i++) {
        for(int j = i+1; j < v.size(); j++) {
            int s = v[i] + v[j];
            int new_diff = abs(req - s);
            
            // Check if pair is unique (assuming option to erase duplicates in given vector is not available)
            bool is_uniq = true;
            for(std::vector<int> pair : nums) {

                if((pair[0] == v[i] || pair[1] == v[i]) && 
                    (pair[0] == v[j] || pair[1] == v[j])) {
                    is_uniq = false;
                    break;
                }
            }

            if(new_diff <= diff_last && is_uniq) {
                if(new_diff < diff_last) 
                    nums = {};
                
                diff_last = new_diff;
                nums.push_back({v[i], v[j]});
            }
        }
    }

    return nums;
}

int main() {
    std::vector<std::vector<int>> v = closest_diffs({31,40,34,11,5,25,34}, 46);
    for(std::vector<int> vv : v) {
        for(int x : vv)
            std::cout << x << " ";
        std::cout << "\n";
    }
}
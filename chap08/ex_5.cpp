/*  Write two functions that reverse the order of elements in a
vector<int>. For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1. The
first reverse function should produce a new vector with the reversed
sequence, leaving its original vector unchanged. The other reverse
function should reverse the elements of its vector without using any
other vectors (hint: swap). */

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// void ascend_ref(vector<int>& v) {
//     int count = 0;
    
//     for(int i = 0; i < v.size(); i++) {
//         if((i+1 != v.size()) && v[i] > v[i+1]) {
//             swap(v[i], v[i+1]);
//             count++;
//         }  
//     }
    
//     if(count > 0) ascend_ref(v);
// }

void descend_ref(vector<int>& v) {
    int count = 0;
    
    for(int i = 0; i < v.size(); i++) {
        if((i+1 != v.size()) && v[i] < v[i+1]) {
            swap(v[i], v[i+1]);
            count++;
        }  
    }
    
    if(count > 0) descend_ref(v);
}

void descend_str(vector<string>& v) {
    int count = 0;
    
    for(int i = 0; i < v.size(); i++) {
        if((i+1 != v.size()) && v[i].size() < v[i+1].size()) {
            swap(v[i], v[i+1]);
            count++;
        }
    }
    
    if(count > 0) descend_str(v);
}

vector<int> descend_val(vector<int> v) {
    int count = 0;
    
    for(int i = 0; i < v.size(); i++) {
        if((i+1 != v.size()) && v[i] < v[i+1]) {
            swap(v[i], v[i+1]);
            count++;
        }  
    }
    
    if(count > 0) descend_val(v);
    return v;
}

void rev(vector<int>& v) {
    int n = v.size();

    for(int i = 0; i < (n / 2); i++)
        swap(v[i], v[n-1-i]);
}

int main() {
    vector<int> v = {3, 1, 2, 9, 7, 10, -1, 32, -321};
    rev(v);
    for(int x : v) cout << x << " ";
}
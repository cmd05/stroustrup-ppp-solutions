#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


template<typename In, typename T>
std::pair<In, bool> binary_search(In begin, In end, T val) {
    if(begin >= end)
        return {end, false}; // exit empty sequence
    
    In middle = begin + (end - begin) / 2;

    if(*middle == val)
        return {middle, true}; // found
    
    if(begin == middle) // test this first to avoid infinite recursion
        return {end, false}; // not found
    
    if(*middle < val)
        return binary_search(middle, end, val); // search in right half
    
    return binary_search(begin, middle, val); // search in left half
}

struct Test {
          string label;
          int val;
          std::vector<int> seq;
          bool res;
};

struct Test_IO_Err { std::string msg; };

// pretty messy
istream& operator>>(istream& input_stream, Test& t) {
    string ss;
    
    if(!std::getline(input_stream, ss)) { // no more input, exit with badbit
        input_stream.clear(std::ios_base::badbit);
        return input_stream;
    }

    // store line in istringstream
    istringstream is{ss};

    // start of test    
    char c1;
    is >> c1;

    if(c1 != '{')
        throw Test_IO_Err{"missing opening '{' for test"};

    // read label and value
    is >> t.label;
    is >> t.val;

    // skip through whitespace
    is >> std::ws;
    
    // start of sequence
    char c2;
    is >> c2;

    if(c2 != '{') throw Test_IO_Err{"missing opening '{' for sequence"};

    // read integers
    for(int x; is >> x;)
        t.seq.push_back(x);
    
    // undo failed int read when encountered '}'
    is.clear(std::ios_base::goodbit);
    
    // skip whitespace
    is >> std::ws;
    
    // end of sequence
    char c3;
    is >> c3;

    if(c3 != '}') throw Test_IO_Err{"error parsing sequence or missing closing '}' for sequence"};

    // input bool
    is >> t.res;

    // skip whitespace
    is >> std::ws;

    // end of test
    char c4;
    is >> c4;

    if(c4 != '}') throw Test_IO_Err{"missing closing '}' for test"};

    return input_stream;
}

int test_all(istream& is) 
{
    int error_count = 0;

    while(true) {
        Test t;
    
        if(!(is >> t))
            break;
        
        bool r = binary_search(t.seq.begin(), t.seq.end(), t.val).second;

        if (r != t.res) {
            cout << "failure: test " << t.label
                 << " binary_search: "
                 << t.seq.size() << " elements, val==" << t.val
                 << " -> " << t.res << '\n';
            
            ++error_count;
        }
    }

    return error_count;
}

int main()
{
    try {
        ifstream is {"drill_tests.txt"}; // 27 and 29 tests are incorrect tests on purpose
        if(!is) throw Test_IO_Err{"file not found"};

        int errors = test_all(is);
        cout << "number of errors: " << errors << "\n";
    } catch(Test_IO_Err& e) {
        std::cerr << e.msg;
    }
}
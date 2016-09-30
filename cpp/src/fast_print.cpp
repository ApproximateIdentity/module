#include <fast_print.hpp>
#include <iostream>


using namespace std;

void fast_print_strings(vector<string> strings) {
    for (const auto& s : strings) {
        cout << s << endl;
    }
}

#include <fast_print.hpp>

#include <iostream>
#include <chrono>
#include <thread>


using namespace std;

void fast_print_strings(vector<string> strings) {
    this_thread::sleep_for(chrono::milliseconds(500));
    for (const auto& s : strings) {
        cout << s << "\t";
    }
    cout << endl;
}

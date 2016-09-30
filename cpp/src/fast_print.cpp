#include <fast_print.hpp>

#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>


using namespace std;

mutex gil;

void fast_print_strings(vector<string> strings) {
    this_thread::sleep_for(chrono::milliseconds(500));
    gil.lock();
    for (const auto& s : strings) {
        cout << s << "\t";
    }
    cout << endl;
    gil.unlock();
}

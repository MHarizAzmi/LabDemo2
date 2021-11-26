#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include "NumRandomiser.h"
#include <mutex>
#include <queue>

using namespace std;
using namespace std::chrono;

struct reading
{
    string type;    //temperature or light type
    double value;   // value of result
    std::time_t timestamp;      //timestamp
};
vector<reading> sensor_data;

mutex _mu; //mutex for unique lock
condition_variable cond_v;


//producer
void temperature() {
    unique_lock<mutex>lock(_mu);

        cond_v.notify_all();
    
    
}

//producer
//void light_level() {
//    NumRandomiser rand(1, 100);
//
//    vector<int> data;
//    for (auto i = 0; i < 300; ++i)data.push_back(rand());
//}

//consumer
    void smart_home_application() {

}

    template<typename T>
    void print_v(const vector<T>& v) {
        if (v.empty()) return;
        for (auto& item : v) cout << item << ",";
    }

int main(const string& type, const double& value, const time_t& timestamp)
{
    thread t_temp(temperature);
    // number generator
    NumRandomiser(1, 100);

    vector<int> data;
    vector<int>::iterator it; // vector for extracting unique integers
    for (auto i = 0; i < 100; ++i) {
        int n = rand();
        data.push_back(n);
        it = unique(data.begin(), data.end()); // applying default comparison technique using the "Unique" function
        data.resize(it - data.begin());
        for (it = data.begin(); it != data.end(); ++it);
       
   // thread t_lights(light_level);

    t_temp.join();
    //t_lights.join();

    return 0;
}

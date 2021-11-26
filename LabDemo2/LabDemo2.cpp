#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include "NumRandomiser.h"

using namespace std;
using namespace std::chrono;

struct reading
{
    string type;    //temperature or light type
    double value;   // value of result
    std::time_t timestamp;      //timestamp
};
vector<reading> sensor_data;

void temperature() {

}

void light_level() {

}

int main()
{
    thread t_temp(temperature);
    thread t_lights(light_level);

    t_temp.join();
    t_lights.join();

    return 0;
}

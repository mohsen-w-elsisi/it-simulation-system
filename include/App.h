#pragma once
#include "DynamicArray.h"
#include "Technician.h"
#include <string>
#include "ConfigLoader.h"
using namespace std;

class App
{
    DynamicArray<string> locations;
    DynamicArray<Technician> technicians;

    int time = 0;

public:
    App(AppConfig config);

    void run();
};

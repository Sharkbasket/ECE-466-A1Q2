#include "systemc.h"
#include "monitor.h"
#include <iostream>


void monitor::report_values()
{
    while (true)
    {
        std::cout << "Timestamp: " << sc_time_stamp() << endl;
        std::cout << "X = " << X->read() << endl;
        std::cout << "Y = " << Y->read() << endl << endl;
        wait();
    }
}

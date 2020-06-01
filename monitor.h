#include "systemc.h"
#include <iostream>


SC_MODULE(monitor)
{
    // Ports
    sc_in<float> X, Y;
    sc_in_clk clock;
    
    // Processes
    void report_values()
    {
        while (true)
        {
            std::cout << "Timestamp: " << sc_time_stamp() << endl;
            std::cout << "X = " << X->read() << endl;
            std::cout << "Y = " << Y->read() << endl << endl;
            wait();
        }
    }
    
    // Constructor
    SC_CTOR(monitor)
    {
        SC_CTHREAD(report_values, clock.pos());
        dont_initialize();
    }
};

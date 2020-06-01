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
            std::cout << "timestamp: " << sc_time_stamp() << endl;
            std::cout << "x = " << x->read() << endl;
            std::cout << "y = " << y->read() << endl << endl;
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

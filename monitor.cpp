#include "systemc.h"
#include "monitor.h"


// Constructor
SC_HAS_PROCESS(monitor);
monitor::monitor(sc_module_name n) : sc_module(n)
{
    SC_CTHREAD(report_values, clock.pos());
}


// Print current values of X and Y to console on clock edges.
void monitor::report_values()
{
    while (true)
    {
        std::cout << std::setw(15) << sc_time_stamp()
                  << std::setw(15) << X->read()
                  << std::setw(15) << Y->read() << endl;
        wait();
    }
}

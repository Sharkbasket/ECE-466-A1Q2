#include "systemc.h"


// Clocked register with reset. Transfers input to output on clock edges.
SC_MODULE(clk_register)
{
    // Ports
    sc_in<float> in;
    sc_in<bool> reset;
    sc_in_clk clock;
    sc_out<float> out;
    
    // Constructor
    clk_register(sc_module_name n);
    
    // Processes
    void clock_thread();
};

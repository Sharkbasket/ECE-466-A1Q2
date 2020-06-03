#include "systemc.h"


// Simple adder with two inputs and one output.
SC_MODULE(adder)
{
    // Ports
    sc_in<float> in_1, in_2;
    sc_out<float> out;
    
    // Constructor
    adder(sc_module_name n);
    
    // Processes
    void add();
};

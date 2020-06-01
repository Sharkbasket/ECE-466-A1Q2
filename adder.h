#include "systemc.h"


// Simple adder with two inputs and one output.
SC_MODULE(adder)
{
    // Ports
    sc_in<float> in_1, in_2;
    sc_out<float> out;
    
    // Processes
    void add();
    
    SC_CTOR(adder)
    {
        SC_METHOD(add);
        sensitive << in_1 << in_2;
    }
};

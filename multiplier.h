#include "systemc.h"


// Simple multiplier scales input with a constant coefficient.
SC_MODULE(multiplier)
{
    // Ports
    sc_in<float> in;
    sc_out<float> out;
    
    // Multiplier constant
    float coeff;
    
    // Processes
    void multiply();
    
    /* Need to call SC_HAS_PROCESS and use normal constructor so we can pass a
       value to coeff during instantiation */
    SC_HAS_PROCESS(multiplier);
    multiplier(sc_module_name n, float c = 1.0) : sc_module(n), coeff(c)
    {
        SC_METHOD(multiply);
        sensitive << in;
    }
};

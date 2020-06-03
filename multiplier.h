#include "systemc.h"


// Simple multiplier scales input with a constant coefficient.
SC_MODULE(multiplier)
{
    // Ports
    sc_in<float> in;
    sc_out<float> out;
    
    // Multiplier constant
    const float coeff;
    
    // Constructor
    multiplier(sc_module_name n, const float c);
    
    // Processes
    void multiply();
};

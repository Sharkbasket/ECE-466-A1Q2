#include "systemc.h"


SC_MODULE(multiplier)
{
    // Ports
    sc_in<float> in;
    sc_out<float> out;
    
    // Multiplier constant
    const float coeff;
    
    // Processes
    void multiply()
    {
        out->write(coeff * in->read());
    }
    
    SC_HAS_PROCESS(multiplier);
    
    multiplier(sc_module_name n, float c = 1.0) : sc_module(n), coeff(c)
    {
        SC_METHOD(multiply);
        sensitive << in;
    }
};

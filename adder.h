#include "systemc.h"


SC_MODULE(adder)
{
    // Ports
    sc_in<float> in_1, in_2;
    sc_out<float> out;
    
    // Processes
    void add()
    {
        out->write(in_1->read() + in_2->read());
    }
    
    SC_CTOR(adder)
    {
        SC_METHOD(add);
        sensitive << a << b;
    }
};

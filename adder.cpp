#include "systemc.h"
#include "adder.h"


// Constructor
SC_HAS_PROCESS(adder);
adder::adder(sc_module_name n) : sc_module(n)
{
    SC_METHOD(add);
    sensitive << in_1 << in_2;
}


// Add two inputs and write to output.
void adder::add()
{
    out->write(in_1->read() + in_2->read());
}

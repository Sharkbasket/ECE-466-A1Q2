#include "systemc.h"
#include "multiplier.h"


// Constructor
SC_HAS_PROCESS(multiplier);
multiplier::multiplier(sc_module_name n, const float c = 1.0)
: sc_module(n), coeff(c)
{
    SC_METHOD(multiply);
    sensitive << in;
}


// Scale input by value stored in coeff and write result to output.
void multiplier::multiply()
{
    out->write(coeff * in->read());
}

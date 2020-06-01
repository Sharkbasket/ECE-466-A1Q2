#include "systemc.h"
#include "multiplier.h"


    void multiplier::multiply()
    {
        out->write(coeff * in->read());
    }

#include "systemc.h"
#include "adder.h"


void adder::add()
{
    out->write(in_1->read() + in_2->read());
}

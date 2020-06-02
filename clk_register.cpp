#include "systemc.h"
#include "clk_register.h"


void clk_register::clock_thread()
{
    if (reset)
    {
        out->write(0.0);
        wait();
    }
    
    while (true)
    {
        out->write(in->read());
        wait();
    }
}

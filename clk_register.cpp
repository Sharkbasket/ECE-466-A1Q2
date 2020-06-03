#include "systemc.h"
#include "clk_register.h"


// Constructor
SC_HAS_PROCESS(clk_register);
clk_register::clk_register(sc_module_name n) : sc_module(n)
{
    SC_CTHREAD(clock_thread, clock.pos());
    reset_signal_is(reset, true);
}


// Transfer input to output on clock edge. Zero if reset asserted.
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

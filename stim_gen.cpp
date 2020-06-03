#include "systemc.h"
#include "stim_gen.h"


// Constructor
SC_HAS_PROCESS(stim_gen);
stim_gen::stim_gen(sc_module_name n) : sc_module(n)
{
    SC_CTHREAD(clock_thread, clock.pos());
}


// Generate testbench stimulus.
void stim_gen::clock_thread()
{
    // Clear X and assert reset
    X->write(0.0);
    reset->write(true);
    wait();

    // De-assert reset and send a unit pulse to X
    reset->write(false);
    X->write(1.0);
    wait();
    X->write(0.0);

    while (true)
    {
        wait();
    }
}

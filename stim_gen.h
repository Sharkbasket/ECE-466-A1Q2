#include "systemc.h"


SC_MODULE(stim_gen)
{
    // Ports
    sc_in_clk clock;
    sc_out<float> X;
    sc_out<bool> reset;
    
    // Processes
    void clock_thread();
    
    // Constructor
    SC_CTOR(stim_gen)
    {
        SC_CTHREAD(clock_thread, clock.pos());
        dont_initialize();
    }
};

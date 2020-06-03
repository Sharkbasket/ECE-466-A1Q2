#include "systemc.h"


// Stimulus generator. Provides reset and input pulse signals to filter.
SC_MODULE(stim_gen)
{
    // Ports
    sc_in_clk clock;
    sc_out<float> X;
    sc_out<bool> reset;
    
    // Constructor
    stim_gen(sc_module_name n);
    
    // Processes
    void clock_thread();
};

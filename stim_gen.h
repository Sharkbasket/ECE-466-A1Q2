#include "systemc.h"


SC_MODULE(stim_gen)
{
    // Ports
    sc_in_clk clock;
    sc_out<float> X;
    sc_out<bool> reset;
    
    // Processes
    void clock_thread()
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
    
    // Constructor
    SC_CTOR(stim_gen)
    {
        SC_CTHREAD(clock_thread, clock.pos());
        dont_initialize();
    }
};

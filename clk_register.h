#include "systemc.h"


SC_MODULE(clk_register)
{
    // Ports
    sc_in<float> in;
    sc_in<bool> reset;
    sc_in_clk clock;
    sc_out<float> out;
    
    // Processes
    void clock_thread()
    {
        if (reset)
        {
            out->write(0.0);
            wait();
        }
        
        while (true)
        {
            out->write(in.read());
            wait();
        }
    }
    
    SC_CTOR(clk_register)
    {
        SC_CTHREAD(clock_thread, clock.pos());
        reset_signal_is(reset);
        dont_initialize();
    }
};

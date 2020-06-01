#include "systemc.h"
#include "adder.h"
#include "multiplier.h"
#include "clk_register.h"


SC_MODULE(filter)
{
    // Ports
    sc_in<float> X;
    sc_in<bool> reset;
    sc_in_clk clock;
    sc_out<float> Y;
    
    // Internal signals
    sc_signal<float> A, B, C, D, E, F, G, H, I, J, K, L;
    
    // Declare constructor (implemented in filter.cpp)
    SC_HAS_PROCESS(filter);
};
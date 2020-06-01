#include "systemc.h"
#include "adder.h"
#include "multiplier.h"
#include "clk_register.h"


// Digital filter described by filter_diagram.png
SC_MODULE(filter)
{
    // Ports
    sc_in<float> X;
    sc_in<bool> reset;
    sc_in_clk clock;
    sc_out<float> Y;
    
    // Internal signals
    sc_signal<float> A, B, C, D, E, F, G, H, I, J, K, L, M;
    
    // Submodule declarations
    clk_register reg_1, reg_2, reg_3;
    multiplier mult_1, mult_2, mult_3, mult_4, mult_5, mult_6;
    adder add_1, add_2, add_3, add_4, add_5;
    
    // Declare constructor (implemented in filter.cpp)
    filter(sc_module_name n);
};
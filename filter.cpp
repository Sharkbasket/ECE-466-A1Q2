#include "systemc.h"
#include "filter.h"


SC_HAS_PROCESS(filter);
filter::filter(sc_module_name n)
: sc_module(n),
  reg_1("reg_1"), reg_2("reg_2"), reg_3("reg_3"),
  mult_1("mult_1", 0.4), mult_2("mult_2", 0.24), mult_3("mult_3", -0.8),
  mult_4("mult_4", 0.2), mult_5("mult_5", -0.5), mult_6("mult_6", 0.25),
  add_1("add_1"), add_2("add_2"), add_3("add_3"),
  add_4("add_4"), add_5("add_5")
{
    // Describe submodule connectivity
    reg_1.in(A);
    reg_1.reset(reset);
    reg_1.clock(clock);
    reg_1.out(B);
    
    reg_2.in(E);
    reg_2.reset(reset);
    reg_2.clock(clock);
    reg_2.out(F);
    
    reg_3.in(F);
    reg_3.reset(reset);
    reg_3.clock(clock);
    reg_3.out(G);
    
    mult_1.in(B);
    mult_1.out(C);
    
    mult_2.in(B);
    mult_2.out(D);
    
    mult_3.in(F);
    mult_3.out(H);
    
    mult_4.in(F);
    mult_4.out(I);
    
    mult_5.in(G);
    mult_5.out(J);
    
    mult_6.in(G);
    mult_6.out(K);
    
    add_1.in_1(X);
    add_1.in_2(C);
    add_1.out(A);
    
    add_2.in_1(X);
    add_2.in_2(L);
    add_2.out(E);
    
    add_3.in_1(H);
    add_3.in_2(J);
    add_3.out(L);
    
    add_4.in_1(I);
    add_4.in_2(K);
    add_4.out(M);
    
    add_5.in_1(D);
    add_5.in_2(M);
    add_5.out(Y);
}
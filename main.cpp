#include "systemc.h"
#include "filter.h"
#include "stim_gen.h"
#include "monitor.h"


int sc_main(int argc, char* argv[])
{
    // Channels
    sc_signal<float> X, Y;
    sc_signal<bool> reset;
    sc_clock clock("clock", 10.0, SC_NS);
    
    // Instantiate & initialize modules
    filter filter_i("filter_i");
    filter_i.X(X);
    filter_i.Y(Y);
    filter_i.reset(reset);
    filter_i.clock(clock);
    
    stim_gen stim_gen_i("stim_gen_i");
    stim_gen_i.X(X);
    stim_gen_i.reset(reset);
    stim_gen_i.clock(clock);
    
    monitor monitor_i("monitor_i");
    monitor_i.X(X);
    monitor_i.Y(Y);
    monitor_i.clock(clock);
    
    // Set up waveform tracing
    sc_trace_file* tf = sc_create_vcd_trace_file("filter_traces");
    tf->set_time_unit(1, SC_NS);
    sc_trace(tf, X, "X");
    sc_trace(tf, Y, "Y");
    sc_trace(tf, reset, "reset");
    sc_trace(tf, clock, "clock");
    
    // Run simulation for 130 ns
    sc_start(130, SC_NS);
    sc_close_vcd_trace_file(tf);
    
    return 0;
}

#include "systemc.h"
#include "stim_gen.h"


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

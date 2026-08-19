#include "Vspram.h"
#include "verilated.h"
#include <verilated_vcd_c.h>
#include <stdio.h>

// Keep track of simulation time
vluint64_t sim_time = 0;

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vspram* dut = new Vspram();
    
    if (!dut) {
        fprintf(stderr, "Error: Failed to create DUT instance\n");
        return 1;
    }

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99); // 99 levels of hierarchy
    tfp->open("waveform.vcd");

    printf("You ran an executable\n");

    // Initialize inputs
    dut->clk = 0;
    dut->rst = 1;

    while (sim_time < 20 && !Verilated::gotFinish()) {
        // Toggle clock: low to high, then high to low
        dut->clk ^= 1; 
        
        // Apply reset for first few cycles
        if (sim_time > 4) {
            dut->rst = 0;
        }

        // Evaluate the model
        dut->eval();
        tfp->dump(sim_time);
        sim_time++;
    }

    tfp->close();
    dut->final();
    delete dut;
    return 0;
}
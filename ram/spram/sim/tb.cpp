#include "Vspram.h"
#include "verilated.h"
#include <stdio.h>

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vspram* dut = new Vspram;

    printf("You ran an executable\n");

    delete dut;
    return 0;
}
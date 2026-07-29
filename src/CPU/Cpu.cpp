#include "Cpu.h"

Cpu::Cpu(Bus& busRef) : bus(busRef) {
	for (int i = 0; i < 16; i++) {
		registers[i] = 0;
	}
	registers[15] = 0x08000000;
	cpsr = 0;
}


void Cpu::Step() {
	uint32_t instruction = bus.Read32(registers[15]);

	uint32_t opcodeBits = (instruction >> 25) & 0x7;

	if (opcodeBits == 0b101) {
		int32_t offset = instruction & 0xFFFFFF;

		if (offset & 0x800000) {
			offset |= 0xFF000000;
		}

		offset = offset << 2;

		registers[15] = registers[15] + 8 + offset;
		
	}
	else {
		registers[15] = registers[15] + 4;
	}
}
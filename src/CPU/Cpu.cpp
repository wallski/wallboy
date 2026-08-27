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
	uint32_t dataProcBits = (instruction >> 26) & 0x3;	

	if (opcodeBits == 0b101) {
		int32_t offset = instruction & 0xFFFFFF;

		if (offset & 0x800000) {
			offset |= 0xFF000000;
		}

		offset = offset << 2;

		registers[15] = registers[15] + 8 + offset;
		
	}
    else if (dataProcBits == 0b00) {
        uint32_t opcode = (instruction >> 21) & 0xF;
        uint32_t rd = (instruction >> 12) & 0xF;
        uint32_t immediate = instruction & 0xFFF;
        uint32_t rn = (instruction >> 16) & 0xF;
        uint32_t sBit = (instruction >> 20) & 0x1;
        uint32_t rm = instruction & 0xF;

        if (opcode == 0b1101) {
            registers[rd] = immediate;
        }
        else if (opcode == 0b0100) {
            registers[rd] = registers[rn] + immediate;
        }
        else if (opcode == 0b1001 && sBit == 0) {
            // MSR: rn here is actually the field mask, not a real register
            uint32_t fieldMask = rn;

            uint32_t mask = 0;
            if (fieldMask & 0b0001) mask |= 0x000000FF; // c
            if (fieldMask & 0b0010) mask |= 0x0000FF00; // x
            if (fieldMask & 0b0100) mask |= 0x00FF0000; // s
            if (fieldMask & 0b1000) mask |= 0xFF000000; // f

            cpsr = (cpsr & ~mask) | (registers[rm] & mask);
        }
        else if (opcode == 0b0010) {
            registers[rd] = registers[rn] - immediate;
        }

        registers[15] = registers[15] + 4;
    }
	else {
		registers[15] = registers[15] + 4;
	}
}
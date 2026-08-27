#include "BUS/Bus.h"
#include "CPU/Cpu.h"
#include <iostream>
#include <string>

int main() {
	Bus bus;
	Cpu cpu(bus);

	std::string path;
	std::cout << "Enter ROM path: ";
	//std::getline(std::cin, path);
	std::cout << "Rom path auto set for testing";
	path = "C:\\Users\\elias\\Downloads\\POKEMONLEAFGREEN\\PokemonLeafGreen.gba";

	bus.LoadROM(path);

	uint8_t firstByte = bus.Read8(0x08000003);
	std::cout << "\n\nFirst byte: 0x" << std::hex << (int)firstByte << std::endl;

	uint32_t entry = bus.Read32(0x08000000);
	std::cout << "\n\nEntry instruction: 0x" << std::hex << entry << std::endl;


	std::cout << "\n\nPC before: 0x" << std::hex << cpu.registers[15] << std::endl;
	cpu.Step();
	std::cout << "PC after: 0x" << std::hex << cpu.registers[15] << std::endl;
	

	uint32_t nextInstruction = bus.Read32(cpu.registers[15]);
	std::cout << "Instruction at new PC: 0x:" << std::hex << nextInstruction << std::endl;
	
	cpu.Step();
	std::cout << "r0 after MOV: " << std::dec << cpu.registers[0] << std::endl;

	uint32_t thirdInstruction = bus.Read32(cpu.registers[15]);
	std::cout << "Instruction at PC: 0x" << std::hex << thirdInstruction << std::endl;

	cpu.Step();
	std::cout << "cpsr after MSR: 0x" << std::hex << cpu.cpsr << std::endl;

	uint32_t fourthInstruction = bus.Read32(cpu.registers[15]);
	std::cout << "Instruction at PC: 0x" << std::hex << fourthInstruction << std::endl;

	return 0;
}

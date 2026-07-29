#include "BUS/Bus.h"
#include "CPU/Cpu.h"
#include <iostream>
#include <string>

int main() {
	Bus bus;
	Cpu cpu(bus);

	std::string path;
	std::cout << "Enter ROM path: ";
	std::getline(std::cin, path);

	bus.LoadROM(path);

	uint8_t firstByte = bus.Read8(0x08000003);
	std::cout << "\n\nFirst byte: 0x" << std::hex << (int)firstByte << std::endl;

	uint32_t entry = bus.Read32(0x08000000);
	std::cout << "\n\nEntry instruction: 0x" << std::hex << entry << std::endl;


	std::cout << "\n\nPC before: 0x" << std::hex << cpu.registers[15] << std::endl;
	cpu.Step();
	std::cout << "PC after: 0x" << std::hex << cpu.registers[15] << std::endl;
	
	


	return 0;
}

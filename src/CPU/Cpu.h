#pragma once
#include <cstdint>
#include "../BUS/Bus.h"

class Cpu {
public:
	Cpu(Bus& bus);

	uint32_t registers[16];
	uint32_t cpsr;

	void Step();

private:
	Bus& bus;
};
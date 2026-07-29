#pragma once
#include <cstdint>
#include <vector>
#include <string>

class Bus {
public:
	Bus();

	void LoadROM(const std::string& path);

	uint8_t Read8(uint32_t address);
	uint16_t Read16(uint32_t address);
	uint32_t Read32(uint32_t address);

	void Write8(uint32_t address, uint8_t value);
	void Write16(uint32_t address, uint16_t value);
	void Write32(uint32_t address, uint32_t value);

private:
	std::vector<uint8_t> bios;
	std::vector<uint8_t> ewram;
	std::vector<uint8_t> iwram;
	std::vector<uint8_t> paletteRam;
	std::vector<uint8_t> vram;
	std::vector<uint8_t> oam;
	std::vector<uint8_t> romData;
};
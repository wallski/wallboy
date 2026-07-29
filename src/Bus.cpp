#include "Bus.h"
#include <fstream>

Bus::Bus() {
	bios.resize(0x4000);
	ewram.resize(0x40000);
	iwram.resize(0x8000);
	paletteRam.resize(0x400);
	vram.resize(0x18000);
	oam.resize(0x400);
}

void Bus::LoadROM(const std::string& path) {
	std::ifstream file(path, std::ios::binary | std::ios::ate);

	size_t size = file.tellg();

	romData.resize(size);

	file.seekg(0);
	file.read(reinterpret_cast<char*>(romData.data()), size);
}

// read
uint8_t Bus::Read8(uint32_t address) {
	if (address >= 0x00000000 && address <= 0x00003FFF) {
		return bios[address - 0x00000000];
	}
	else if (address >= 0x02000000 && address <= 0x0203FFFF) {
		return ewram[address - 0x02000000];
	}
	else if (address >= 0x03000000 && address <= 0x03007FFF) {
		return iwram[address - 0x03000000];
	}
	else if (address >= 0x05000000 && address <= 0x050003FF) {
		return paletteRam[address - 0x05000000];
	}
	else if (address >= 0x06000000 && address <= 0x06017FFF) {
		return vram[address - 0x06000000];
	}
	else if (address >= 0x07000000 && address <= 0x070003FF) {
		return oam[address - 0x07000000];
	}
	else if (address >= 0x08000000 && address <= 0x09FFFFFF) {
		return romData[address - 0x08000000];
	}
		
	return 0;
}

uint16_t Bus::Read16(uint32_t address) {
	if (address >= 0x00000000 && address <= 0x00003FFF) {
		// bios
		uint8_t low = bios[address - 0x00000000];
		uint8_t high = bios[address - 0x00000000 + 1];
		return(high << 8) | low;
	}
	else if (address >= 0x02000000 && address <= 0x0203FFFF) {
		// ewram
		uint8_t low = ewram[address - 0x02000000];
		uint8_t high = ewram[address - 0x02000000 + 1];
		return(high << 8) | low;
	}
	else if (address >= 0x03000000 && address <= 0x03007FFF) {
		// iwram
		uint8_t low = iwram[address - 0x03000000];
		uint8_t high = iwram[address - 0x03000000 + 1];
		return(high << 8) | low;
	}
	else if (address >= 0x05000000 && address <= 0x050003FF) {
		// paletteRam
		uint8_t low = paletteRam[address - 0x05000000];
		uint8_t high = paletteRam[address - 0x05000000 + 1];
		return(high << 8) | low;
	}
	else if (address >= 0x06000000 && address <= 0x06017FFF) {
		// vram
		uint8_t low = vram[address - 0x06000000];
		uint8_t high = vram[address - 0x06000000 + 1];
		return(high << 8) | low;
	}
	else if (address >= 0x07000000 && address <= 0x070003FF) {
		// oam
		uint8_t low = oam[address - 0x07000000];
		uint8_t high = oam[address - 0x07000000 + 1];
		return(high << 8) | low;
	}
	else if (address >= 0x08000000 && address <= 0x09FFFFFF) {
		// romData
		uint8_t low = romData[address - 0x08000000];
		uint8_t high = romData[address - 0x08000000 + 1];
		return(high << 8) | low;
	}

	return 0;
}

uint32_t Bus::Read32(uint32_t address) {
	if (address >= 0x00000000 && address <= 0x00003FFF) {
		// bios
		uint8_t b0 = bios[address - 0x00000000];
		uint8_t b1 = bios[address - 0x00000000 + 1];
		uint8_t b2 = bios[address - 0x00000000 + 2];
		uint8_t b3 = bios[address - 0x00000000 + 3];
		return (b3 << 24) | (b2 << 16) | (b1 << 8) | b0;
	}
	else if (address >= 0x02000000 && address <= 0x0203FFFF) {
		// ewram
		uint8_t b0 = ewram[address - 0x02000000];
		uint8_t b1 = ewram[address - 0x02000000 + 1];
		uint8_t b2 = ewram[address - 0x02000000 + 2];
		uint8_t b3 = ewram[address - 0x02000000 + 3];
		return (b3 << 24) | (b2 << 16) | (b1 << 8) | b0;
	}
	else if (address >= 0x03000000 && address <= 0x03007FFF) {
		// iwram
		uint8_t b0 = iwram[address - 0x03000000];
		uint8_t b1 = iwram[address - 0x03000000 + 1];
		uint8_t b2 = iwram[address - 0x03000000 + 2];
		uint8_t b3 = iwram[address - 0x03000000 + 3];
		return (b3 << 24) | (b2 << 16) | (b1 << 8) | b0;
	}
	else if (address >= 0x05000000 && address <= 0x050003FF) {
		// paletteRam
		uint8_t b0 = paletteRam[address - 0x05000000];
		uint8_t b1 = paletteRam[address - 0x05000000 + 1];
		uint8_t b2 = paletteRam[address - 0x05000000 + 2];
		uint8_t b3 = paletteRam[address - 0x05000000 + 3];
		return (b3 << 24) | (b2 << 16) | (b1 << 8) | b0;
	}
	else if (address >= 0x06000000 && address <= 0x06017FFF) {
		// vram
		uint8_t b0 = vram[address - 0x06000000];
		uint8_t b1 = vram[address - 0x06000000 + 1];
		uint8_t b2 = vram[address - 0x06000000 + 2];
		uint8_t b3 = vram[address - 0x06000000 + 3];
		return (b3 << 24) | (b2 << 16) | (b1 << 8) | b0;
	}
	else if (address >= 0x07000000 && address <= 0x070003FF) {
		// oam
		uint8_t b0 = oam[address - 0x07000000];
		uint8_t b1 = oam[address - 0x07000000 + 1];
		uint8_t b2 = oam[address - 0x07000000 + 2];
		uint8_t b3 = oam[address - 0x07000000 + 3];
		return (b3 << 24) | (b2 << 16) | (b1 << 8) | b0;
	}
	else if (address >= 0x08000000 && address <= 0x09FFFFFF) {
		// romData
		uint8_t b0 = romData[address - 0x08000000];
		uint8_t b1 = romData[address - 0x08000000 + 1];
		uint8_t b2 = romData[address - 0x08000000 + 2];
		uint8_t b3 = romData[address - 0x08000000 + 3];
		return (b3 << 24) | (b2 << 16) | (b1 << 8) | b0;
	}

	return 0;
}

// write
void Bus::Write8(uint32_t address, uint8_t value) {
	if (address >= 0x00000000 && address <= 0x00003FFF) {
		bios[address - 0x00000000] = value;
	}
	else if (address >= 0x02000000 && address <= 0x0203FFFF) {
		ewram[address - 0x02000000] = value;
	}
	else if (address >= 0x03000000 && address <= 0x03007FFF) {
		iwram[address - 0x03000000] = value;
	}
	else if (address >= 0x05000000 && address <= 0x050003FF) {
		paletteRam[address - 0x05000000] = value;
	}
	else if (address >= 0x06000000 && address <= 0x06017FFF) {
		vram[address - 0x06000000] = value;
	}
	else if (address >= 0x07000000 && address <= 0x070003FF) {
		oam[address - 0x07000000] = value;
	}
	else if (address >= 0x08000000 && address <= 0x09FFFFFF) {
		romData[address - 0x08000000] = value;
	}
}

void Bus::Write16(uint32_t address, uint16_t value) {
	uint8_t low = value & 0xFF;
	uint8_t high = (value >> 8) & 0xFF;

	if (address >= 0x00000000 && address <= 0x00003FFF) {
		bios[address - 0x00000000] = low;
		bios[address - 0x00000000 + 1] = high;
	}
	else if (address >= 0x02000000 && address <= 0x0203FFFF) {
		ewram[address - 0x02000000] = low;
		ewram[address - 0x02000000 + 1] = high;
	}
	else if (address >= 0x03000000 && address <= 0x03007FFF) {
		iwram[address - 0x03000000] = low;
		iwram[address - 0x03000000 + 1] = high;
	}
	else if (address >= 0x05000000 && address <= 0x050003FF) {
		paletteRam[address - 0x05000000] = low;
		paletteRam[address - 0x05000000 + 1] = high;
	}
	else if (address >= 0x06000000 && address <= 0x06017FFF) {
		vram[address - 0x06000000] = low;
		vram[address - 0x06000000 + 1] = high;
	}
	else if (address >= 0x07000000 && address <= 0x070003FF) {
		oam[address - 0x07000000] = low;
		oam[address - 0x07000000 + 1] = high;
	}
	else if (address >= 0x08000000 && address <= 0x09FFFFFF) {
		romData[address - 0x08000000] = low;
		romData[address - 0x08000000 + 1] = high;
	}
}

void Bus::Write32(uint32_t address, uint32_t value) {
	uint8_t b0 = value & 0xFF;
	uint8_t b1 = (value >> 8) & 0xFF;
	uint8_t b2 = (value >> 16) & 0xFF;
	uint8_t b3 = (value >> 24) & 0xFF;

	if (address >= 0x00000000 && address <= 0x00003FFF) {
		bios[address - 0x00000000] = b0;
		bios[address - 0x00000000 + 1] = b1;
		bios[address - 0x00000000 + 2] = b2;
		bios[address - 0x00000000 + 3] = b3;
	}
	else if (address >= 0x02000000 && address <= 0x0203FFFF) {
		ewram[address - 0x02000000] = b0;
		ewram[address - 0x02000000 + 1] = b1;
		ewram[address - 0x02000000 + 2] = b2;
		ewram[address - 0x02000000 + 3] = b3;
	}
	else if (address >= 0x03000000 && address <= 0x03007FFF) {
		iwram[address - 0x03000000] = b0;
		iwram[address - 0x03000000 + 1] = b1;
		iwram[address - 0x03000000 + 2] = b2;
		iwram[address - 0x03000000 + 3] = b3;
	}
	else if (address >= 0x05000000 && address <= 0x050003FF) {
		paletteRam[address - 0x05000000] = b0;
		paletteRam[address - 0x05000000 + 1] = b1;
		paletteRam[address - 0x05000000 + 2] = b2;
		paletteRam[address - 0x05000000 + 3] = b3;
	}
	else if (address >= 0x06000000 && address <= 0x06017FFF) {
		vram[address - 0x06000000] = b0;
		vram[address - 0x06000000 + 1] = b1;
		vram[address - 0x06000000 + 2] = b2;
		vram[address - 0x06000000 + 3] = b3;
	}
	else if (address >= 0x07000000 && address <= 0x070003FF) {
		oam[address - 0x07000000] = b0;
		oam[address - 0x07000000 + 1] = b1;
		oam[address - 0x07000000 + 2] = b2;
		oam[address - 0x07000000 + 3] = b3;
	}
	else if (address >= 0x08000000 && address <= 0x09FFFFFF) {
		romData[address - 0x08000000] = b0;
		romData[address - 0x08000000 + 1] = b1;
		romData[address - 0x08000000 + 2] = b2;
		romData[address - 0x08000000 + 3] = b3;
	}
}
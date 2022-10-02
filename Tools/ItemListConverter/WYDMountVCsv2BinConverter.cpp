#include "WYDMountVCsv2BinConverter.h"
#include <fstream>
#include <iostream>

void WYDMountVCsv2BinConverter::Read()
{
	std::ifstream stream{ "MountDataV.csv " };
	if (!stream.is_open())
		throw std::exception("Can't open MountDataV.csv");

	std::string line;
	while (std::getline(stream, line))
	{
		STRUCT_MOUNTDATAV item{};
		int itemId = 0;

		std::string fixedString;
		for (auto& character : line)
		{
			if (character == ',' || character == '.')
				fixedString += ' ';
			else
				fixedString += character;
		}
 
		int ret = sscanf(fixedString.c_str(), "%d %d %d %d %d %d %d %d %d %d %d %d %d %d",
            &itemId,
			&item.BoneAniIndex,
			& item.Mesh[0].m1, & item.Mesh[0].m2, & item.Mesh[0].m3,
			& item.Mesh[1].m1, & item.Mesh[1].m2, & item.Mesh[1].m3,
			& item.Mesh[2].m1, & item.Mesh[2].m2, & item.Mesh[2].m3,
			& item.Scale,
			& item.Unk[0],
			& item.Unk[1]
		);
  
		if (ret != 14 || itemId <= 0 || itemId >= 400)
			throw std::exception("Can't ret MountDataV.csv");

		_mountdatav[itemId] = item;
	}

	stream.close();
}

void WYDMountVCsv2BinConverter::Convert()
{
	std::fstream stream{ "MountDataV_new.bin", std::ios::out | std::ios::binary };
	if (!stream.is_open())
		throw std::exception("Can't open MountDataV_new.bin");

	auto itemList = _mountdatav;

	for (auto itemIt = std::begin(itemList); itemIt != std::end(itemList); ++itemIt)
	{
		STRUCT_MOUNTDATAV itemToWrite = *itemIt;

		for (size_t i = 0; i < sizeof STRUCT_MOUNTDATAV; ++i)
			*reinterpret_cast<uint8_t*>((uint32_t)&itemToWrite + i) ^= 0x5Au;

		int itemId = std::distance(std::begin(itemList), itemIt);
		int position = sizeof STRUCT_MOUNTDATAV * itemId;

		stream.seekg(position, std::ios::beg);
		stream.write(reinterpret_cast<char*>(&itemToWrite), sizeof STRUCT_MOUNTDATAV);
	}

	stream.close();
}

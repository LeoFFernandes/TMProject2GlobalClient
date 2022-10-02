#include "WYDMountVBin2CsvConverter.h"
#include <fstream>


void WYDMountVBin2CsvConverter::Read()
{
	std::fstream stream{ "MountDataV.bin", std::ios::in | std::ios::binary };
	if (!stream.is_open())
		throw std::exception("Can't open MountDataV.bin");

	for (auto& item : _mountdatav)
	{
		stream.read(reinterpret_cast<char*>(&item), sizeof STRUCT_MOUNTDATAV);

		for (size_t i = 0; i < sizeof STRUCT_MOUNTDATAV; ++i)
			*reinterpret_cast<uint8_t*>((uint32_t)&item + i) ^= 0x5Au;
	}

	stream.close();
}


void WYDMountVBin2CsvConverter::Convert()
{

	std::fstream stream{ "MountDataV.csv", std::ios::out | std::ios::trunc };
	if (!stream.is_open())
		throw std::exception("Can't open MountDataV.csv to write");

	int Count = -1;
	for (auto itemIt = std::begin(_mountdatav); itemIt != std::end(_mountdatav); ++itemIt)
	{
		const auto& item = *itemIt;
		Count++;

		if (item.BoneAniIndex <= 0 || item.BoneAniIndex >= 100)
			continue;

		stream << Count << "," << item.BoneAniIndex << ",";
		for (int i = 0; i < 3; i++)
			stream << item.Mesh[i].m1 << "," << item.Mesh[i].m2 << "," << item.Mesh[i].m3 << ",";

		stream <<  item.Scale << "," << item.Unk[0] << "," << item.Unk[1];
		stream << std::endl;
	}

	stream.close();
}
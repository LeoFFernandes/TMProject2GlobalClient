#pragma once
#include "WYDConverter.h"


class WYDMountVBin2CsvConverter : public WYDConverter
{
private:
	virtual void Read();

public:
	WYDMountVBin2CsvConverter()
	{
		Read();
	}
	virtual void Convert();
};
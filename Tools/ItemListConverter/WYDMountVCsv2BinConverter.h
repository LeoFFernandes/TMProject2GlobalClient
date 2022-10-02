#pragma once
#include "WYDConverter.h"

class WYDMountVCsv2BinConverter : public WYDConverter
{
protected:
	virtual void Read();

public:
	WYDMountVCsv2BinConverter()
	{
		WYDMountVCsv2BinConverter::Read();
	}
	virtual void Convert();
};

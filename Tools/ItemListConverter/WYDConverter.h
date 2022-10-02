#pragma once

#include <map>
#include <array>
#include <string>
#include <exception>
#include "Structs.h"
 
class WYDConverter
{
private:
	void ReadItemEffect();
	void ReadItemName();
protected:
	WYDConverter()
	{
		ReadItemEffect();
		ReadItemName();
	}
	
	std::map<std::string, int> _effects;
	std::array<std::string, 6500> _itemName;
	std::array<STRUCT_ITEMLIST, 6500> _itemList;
	std::array<int, 6500> _itemicon;
	std::array<STRUCT_ITEMLIST, 6500> _extraitem;
	std::array<STRUCT_MOUNTDATA, 400> _mountdata;
	std::array<STRUCT_MOUNTDATAV, 400> _mountdatav;
	virtual void Read() = 0;
 
public:
	
	virtual void Convert() = 0;
};


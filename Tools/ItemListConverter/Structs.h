#pragma once


struct STRUCT_STATICEFFECT
{
	short sEffect;
	short sValue;
};

struct STRUCT_ITEMLIST
{
	char Name[64];
	short nIndexMesh;
	short nIndexTexture;
	short nIndexVisualEffect;
	short nReqLvl;
	short nReqStr;
	short nReqInt;
	short nReqDex;
	short nReqCon;
	STRUCT_STATICEFFECT stEffect[12];
	int nPrice;
	short nUnique;
	short UNK_1;
	int nPos;
	short nExtra;
	short nGrade;
	int UNK_2;
	short mType;
	short mData;
	short UNK_3;
	short UNK_4;

	unsigned short UNKValues[4];
};

#pragma pack(push, 1)
struct STRUCT_MOUNTDATA
{
	int Index;
	int CotumeIndex;
	int MountIndex;
	int BabyItem;
	int BabyIndex;
	int MaxVita;
	int MountItem;
	struct
	{
		int MaxHp;
		int Damage;
		int Magic;
		int Parry;
		int Resist;
		int Speed;
		int Abs;
	}Status;
	short CostumeList[6];

};
#pragma pack(pop)


#pragma pack(push, 1)
struct STRUCT_MOUNTDATAV
{
	short BoneAniIndex;
	struct
	{
		short m1;
		short m2;
		short m3;
	}Mesh[3];
	float Scale;
	short Unk[2];
};
#pragma pack(pop)

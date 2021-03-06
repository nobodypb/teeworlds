/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef ENGINE_MESSAGE_H
#define ENGINE_MESSAGE_H

#include <engine/shared/packer.h>

class CMsgPacker : public CPacker
{
public:
	CMsgPacker(int Type, bool ExtMsg = false)
	{
		Reset();
		if (!ExtMsg || Type < 31)
			AddInt(Type);
		else
		{
			AddInt(31);
			AddString("ExtMsg", 6);
			AddInt(Type - 31);
		}
	}
};

#endif

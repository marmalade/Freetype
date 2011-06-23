#pragma once

#include <IwGeom.h>
#include <IwTexture.h>
#include <IwImage.h>
#include <freetypehelper.h>

namespace TinyOpenEngine
{
	struct CfthAtlas
	{
		bool isUploaded;
		CIwTexture* texture;
		CIwImage* image;
		CIwTexture* GetTexture() { if (!isUploaded) { texture->Upload(); isUploaded = true; } return texture;}
		uint32 mask[(FREETYPEHELPER_GLYPHATLASSIZE/FREETYPEHELPER_GLYPHSTEP)/32*(FREETYPEHELPER_GLYPHATLASSIZE/FREETYPEHELPER_GLYPHSTEP)];
		bool GetMask(int16 x,int16 y) { int16 index = x+y*(FREETYPEHELPER_GLYPHATLASSIZE/FREETYPEHELPER_GLYPHSTEP); return 0!=(mask[index/32]&(1<<(index&31)));}
		void SetMask(int16 x,int16 y) { int16 index = x+y*(FREETYPEHELPER_GLYPHATLASSIZE/FREETYPEHELPER_GLYPHSTEP); mask[index/32] |= (1<<(index&31));}
		bool TryToAllocateRect(int16 x,int16 y,int16 w,int16 h);
	};
}
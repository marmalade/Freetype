#pragma once

#include <IwGeom.h>
#include <freetypehelper.h>

namespace TinyOpenEngine
{
	class CfthAtlas;

	struct CfthGlyph
	{
		bool isLoaded;
		CIwSVec2 advance;
		CIwSVec2 offset;
		int16 width;
		int16 height;
		int16 x;
		int16 y;
		CfthAtlas* texture;
		CfthGlyph():isLoaded(false),width(0),height(0),x(0),y(0),texture(0){}
	};
}
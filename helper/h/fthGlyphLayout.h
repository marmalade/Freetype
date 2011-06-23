#pragma once

#include <freetypehelper.h>
#include <fthGlyph.h>

namespace TinyOpenEngine
{
	struct CfthGlyphLayout
	{
		int32 charCode;
		CfthGlyph*glyph;
		CIwSVec2 uv;
		CIwSVec2 uvSize;
		CIwSVec2 pos;
		CIwSVec2 size;

		CfthGlyphLayout():pos(0,0),size(0,0),uv(0,0),uvSize(IW_GEOM_ONE,IW_GEOM_ONE){}
	};
}
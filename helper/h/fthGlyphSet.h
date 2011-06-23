#pragma once

#include <freetypehelper.h>
#include <fthGlyph.h>
#include <IwArray.h>

namespace TinyOpenEngine
{
	struct CfthGlyphSet
	{
		int32 pixelSize;
		CIwArray<CfthGlyph> glyphs;

		CfthGlyphSet():pixelSize(0){}
	};
}
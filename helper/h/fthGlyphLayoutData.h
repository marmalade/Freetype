#pragma once

#include <freetypehelper.h>
#include <fthGlyphLayout.h>
#include <IwArray.h>
#include <IwColour.h>

namespace TinyOpenEngine
{
	struct CfthGlyphLayoutData
	{
		//Current Origin (left/top) Of Text (input)
		CIwSVec2 origin;
		//Current size (width is input, heihgt is output)
		CIwSVec2 size;
		//Actual size of area taken by glyphs (output)
		CIwSVec2 actualSize;
		//Actual origin (left/top) of area taken by glyphs (output)
		CIwSVec2 actualOrigin;

		bool isRightToLeft;

		//0 .. IW_GEOM_ONE
		iwfixed textAlignment;

		CIwArray<CfthGlyphLayout> glyphs;
		CIwArray<CIwSVec2> renderBufferPos;
		CIwArray<CIwSVec2> renderBufferUV;
		CIwArray<CIwColour> renderBufferColors;

		void RenderAt(const CIwSVec2 & pos,const CIwSVec2 & viewport);
		void RenderAt(const CIwSVec2 & pos, const CIwSVec2 & viewport,const CIwMat & t);
		void RenderAt(const CIwSVec2 & pos, const CIwSVec2 & viewport,const CIwMat & t, const CIwColour& col);
	};
}
#pragma once

#include <freetypehelper.h>
#include <fthGlyphLayout.h>
#include <IwArray.h>
#include <IwColour.h>

namespace FreeTypeHelper
{
	struct CfthGlyphLayoutData
	{
		//Current Origin (left/top) Of Text (input)
		CIwSVec2 origin;
		//Required size (width is viewport width, heihgt is font size)
		CIwSVec2 size;
		//Actual size of area taken by glyphs (output)
		CIwSVec2 actualSize;
		//Actual origin (left/top) of area taken by glyphs (output)
		CIwSVec2 actualOrigin;
		//Text shadow offset. (0, 0) - no shadow
		CIwSVec2 shadowOffset;
		//Text shadow color. shadowColour.a = 0 - no shadow
		CIwColour shadowColour;

		bool isRightToLeft;

		//0 .. IW_GEOM_ONE
		iwfixed textAlignment;

		CIwArray<CfthGlyphLayout> glyphs;
		CIwArray<CIwSVec2> renderBufferPos;
		CIwArray<CIwSVec2> renderBufferUV;
		CIwArray<CIwColour> renderBufferColors;

		void RenderAt(const CIwSVec2 & pos,const CIwSVec2 & viewport);
		void RenderAt(const CIwSVec2 & pos, const CIwSVec2 & viewport,const CIwMat2D & t);
		void RenderAt(const CIwSVec2 & pos, const CIwSVec2 & viewport,const CIwMat2D & t, const CIwColour& col);

		inline bool HasShadow() const {return shadowColour.a != 0 && ((shadowOffset.x != 0) || (shadowOffset.y != 0)); }

		CfthGlyphLayoutData():
			origin(0,0),
			size(100,12),
			actualSize(0,0),
			actualOrigin(0,0),
			shadowOffset(0,0),
			isRightToLeft(false),
			textAlignment(0)
		{
			shadowColour.Set(0,0,0,128);
		}
	};
}
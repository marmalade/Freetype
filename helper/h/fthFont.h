#pragma once

#include <IwResManager.h>
#include <IwManagedList.h>
#include <freetypehelper.h>
#include <fthGlyphSet.h>
#include <fthAtlas.h>
#include <fthGlyphLayoutData.h>

namespace FreeTypeHelper
{
	class CfthFont : public CIwResource
	{
	protected:
		CIwStringL pathname;
		FT_Face face;
		bool isFaceLoaded;
		CIwArray<CfthGlyphSet> glyphSets;
		CIwArray<CfthAtlas> atlases;
	public:
		//Declare managed class
		IW_MANAGED_DECLARE(CfthFont);
		//Constructor
		CfthFont();
		//Constructor
		CfthFont(const CIwStringL& pathname);
		//Desctructor
		virtual ~CfthFont();

		//Reads/writes a binary file using @a IwSerialise interface.
		virtual void Serialise ();

		//Render text
		void Render(const char* utf8);

		void LoadFace();

		CfthGlyph* GetGlyph(int32 charCode, int32 sizeInPixels);
		CfthAtlas* FindSpaceOnTextureAtlas(int16 w, int16 h, int16*x,int16*y);
		void LayoutGlyphs(const char* utf8z, CfthGlyphLayoutData& layoutDaya);
		void AlignRow(CfthGlyphLayoutData& layoutData, int16& currentY, uint32 startRow);
		void ReorderGlyphs(CfthGlyphLayoutData& layoutData, uint32 startRow);
		void SplitRowInLines(CfthGlyphLayoutData& layoutData,int16& currentY, uint32 startRow);
		void PositionLine(CfthGlyphLayoutData& layoutData,int16& currentY, uint32 startRow, uint32 end);

		static bool IsRightToLeft(int32 charCode);
		static bool IsRightToLeft();
		static int32 ExtractUtfCode(const char* & c);
		static bool IsSeparator(int32 code);
		static bool IsWhiteSpace(int32 code);
	};

#ifdef IW_BUILD_RESOURCES
	class CfthFontResHandler : public CIwResHandler
	{
	public:
		//Declare managed class
		IW_MANAGED_DECLARE(CfthFontResHandler);

		//Constructor
		CfthFontResHandler(const char * ext, const char* name);
		//Desctructor
		virtual ~CfthFontResHandler();

		//Buid resource method
		virtual CIwResource*	Build(const CIwStringL& pathname);
	};
#endif
}
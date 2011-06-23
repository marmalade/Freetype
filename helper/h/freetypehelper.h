#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H

#define FREETYPEHELPER_GLYPHSTEP (4)
#define FREETYPEHELPER_GLYPHATLASSIZE (256)

namespace FreeTypeHelper
{
	void fthInit();
	void fthTerminate();
}

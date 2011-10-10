#include <IwDebug.h>
#include <freetypehelper.h>
#include <fthFont.h>

namespace FreeTypeHelper
{
	int initCounter = 0;
	FT_Library  library=0;

	FT_Library fthGetFreeTypeLibrary() {return library;}
}

using namespace FreeTypeHelper;

void FreeTypeHelper::fthInit()
{
	++initCounter;
	if (initCounter != 1)
		return;


	#ifdef IW_BUILD_RESOURCES
	IwGetResManager()->AddHandler(new CfthFontResHandler("ttf","fthFreeTypeTTF"));
	IwGetResManager()->AddHandler(new CfthFontResHandler("otf","fthFreeTypeOTF"));
	#endif

	IW_CLASS_REGISTER(CfthFont);

	FT_Error error = FT_Init_FreeType( &library );
	IwAssertMsg(FT, !error, ("Could not initialize FreeType library") );
}

void FreeTypeHelper::fthTerminate()
{
	--initCounter;
	if (initCounter < 0)
		IwAssertMsg(FREETYPE,false,("FreeTypeTerminate doesn't match FreeTypeInit"));
	if (initCounter != 0)
		return;

	FT_Done_FreeType( library );

}
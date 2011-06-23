#include <IwDebug.h>
#include <freetypehelper.h>

namespace FreeTypeHelper
{
	int initCounter = 0;
}

using namespace FreeTypeHelper;

void FreeTypeHelper::fthInit()
{
	++initCounter;
	if (initCounter != 1)
		return;
}

void FreeTypeHelper::fthTerminate()
{
	--initCounter;
	if (initCounter < 0)
		IwAssertMsg(FREETYPE,false,("FreeTypeTerminate doesn't match FreeTypeInit"));
	if (initCounter != 0)
		return;
}
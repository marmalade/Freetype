#include <s3e.h>
#include <IwGx.h>
#include <IwGraphics.h>
#include <freetypehelper.h>

using namespace FreeTypeHelper;

//-----------------------------------------------------------------------------
// Main global function
//-----------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	IwGxInit();
	IwResManagerInit();
	IwGraphicsInit();
	fthInit();

	IwGxSetColClear(0x7f, 0x7f, 0x7f, 0x7f);

	for (;;)
	{
		s3eDeviceYield(0);
		s3eKeyboardUpdate();

		bool result = true;
		if	(
			(result == false) ||
			(s3eKeyboardGetState(s3eKeyEsc) & S3E_KEY_STATE_DOWN) ||
			(s3eKeyboardGetState(s3eKeyAbsBSK) & S3E_KEY_STATE_DOWN) ||
			(s3eDeviceCheckQuitRequest())
			)
			break;

		//IwGxClear(IW_GX_DEPTH_BUFFER_F);
		IwGxClear(IW_GX_COLOUR_BUFFER_F | IW_GX_DEPTH_BUFFER_F);

		IwGxFlush();
		IwGxSwapBuffers();
	}

	fthTerminate();
	IwGraphicsTerminate();
	IwResManagerTerminate();
	IwGxTerminate();
}
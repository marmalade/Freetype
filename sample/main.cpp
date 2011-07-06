#include <s3e.h>
#include <IwGx.h>
#include <IwGraphics.h>
#include <freetypehelper.h>
#include <fthFont.h>

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

	IwGxSetColClear(0x1f, 0x1f, 0xc0, 0x7f);

	CIwResGroup* sampleGroup =  IwGetResManager()->LoadGroup("sample.group");
	CfthFont* font = (CfthFont*)sampleGroup->GetResNamed("font", "CfthFont");

	const char* sampleText = "Hebrew (עִבְרִית, Ivrit,  Hebrew pronunciation (help·info)) is a Semitic language of the Afro-Asiatic language family.";
	const char* sampleText2 = "אנגלית (במקור: English), אחת השפות המדוברות ביותר בעולם, היא שפה גרמאנית שמקורה באנגליה. השפה רכשה לה מעמד דומיננטי והיא השפה המרכזית והרשמית בארצות רבות. אנגלית נלמדת ומובנת יותר מכל שפות העולם, משמשת שפה שנייה ושפה רשמית במדינות רבות, ולעתים מוגדרת לינגואה פרנקה בזכות השפעתה העצומה בתחומים רבים.";

	{
		CfthGlyphLayoutData layoutData;
		layoutData.size.x = IwGxGetScreenWidth();
		layoutData.size.y = 12;
		font->LayoutGlyphs(sampleText, layoutData);

		CfthGlyphLayoutData layoutData2;
		layoutData2.size.x = IwGxGetScreenWidth();
		layoutData2.size.y = 12;
		layoutData2.isRightToLeft = true;
		layoutData2.shadowOffset = CIwSVec2(-1,-1);
		font->LayoutGlyphs(sampleText2, layoutData2);

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

			layoutData.RenderAt(CIwSVec2(0,0),CIwSVec2(IwGxGetScreenWidth(),IwGxGetScreenHeight()));
			layoutData2.RenderAt(CIwSVec2(0,layoutData2.actualSize.y+10),CIwSVec2(IwGxGetScreenWidth(),IwGxGetScreenHeight()));

			IwGxFlush();
			IwGxSwapBuffers();
		}
	}
	IwGetResManager()->DestroyGroup(sampleGroup);

	fthTerminate();
	IwGraphicsTerminate();
	IwResManagerTerminate();
	IwGxTerminate();
}
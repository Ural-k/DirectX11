#include "FrameWork.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	FrameWork frameWork;
	if (!frameWork.Initialize()) return -1;

	frameWork.Run();

	frameWork.Finalize();

	return 0;
}
#ifndef LOW_LEVEL_WINDOW_X11_H
#define LOW_LEVEL_WINDOW_X11_H

/* A nice, simple OpenGL window direct to X11 through Xlib. */
#include "LowLevelWindow.h"

#include <X11/Xlib.h>	// XVisualInfo

class LowLevelWindow_X11 : public LowLevelWindow
{
private:
	bool windowIsOpen;
	RageDisplay::VideoModeParams CurrentParams;

public:
	LowLevelWindow_X11();
	~LowLevelWindow_X11();

	void *GetProcAddress(CString s);
	CString TryVideoMode(RageDisplay::VideoModeParams p, bool &bNewDeviceOut);
	void SwapBuffers();

	RageDisplay::VideoModeParams GetVideoModeParams() const { return CurrentParams; }
};
// XXX: Shouldn't we try multiple LowLevelWindows and use whichever works?
#undef ARCH_LOW_LEVEL_WINDOW
#define ARCH_LOW_LEVEL_WINDOW LowLevelWindow_X11


#endif

/*
 * (c) 2005 Ben Anderson
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, and/or sell copies of the Software, and to permit persons to
 * whom the Software is furnished to do so, provided that the above
 * copyright notice(s) and this permission notice appear in all copies of
 * the Software and that both the above copyright notice(s) and this
 * permission notice appear in supporting documentation.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF
 * THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR HOLDERS
 * INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL INDIRECT
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#include <iostream>
#include <Windows.h>


int main()
{
	HDC hdc = GetDC(NULL);
	POINT p;
	COLORREF color;

	while (1)
	{
		if (GetCursorPos(&p))
		{
			color = GetPixel(hdc, p.x, p.y);
			std::cout << std::hex << color << std::endl;
		}
		if (color == 0)
		{
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		}
	}
}
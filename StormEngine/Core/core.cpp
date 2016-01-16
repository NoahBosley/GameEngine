#include "data\graphics\window.h"

int main()
{
	TheStormEngine::graphics::Window m_Window("StormEditor", 800, 700);

	while (!m_Window.closed())
	{
		m_Window.update();
	}

	return 0;
}
#include "App.hpp"
#include "Log.hpp"
#include "Window.hpp"

namespace Graphics
{
	App::App()
	{
		LOG_INFO("Starting Application");
	}

	App::~App()
	{
		LOG_INFO("Closing Application");
	}

	int App::start(unsigned int width, unsigned int height, const char* title)
	{
		_pWindow = std::make_unique<Window>(title, width, height);

		while (true)
		{
			_pWindow->onUpdate();
			onUpdate();
		}
	}

	void App::onUpdate()
	{
		return;
	}
}
#ifndef APP_HPP
#define APP_HPP

#include <memory>

namespace Graphics {

	class App
	{
	public:
		App();
		virtual ~App();

		App(const App&)					= delete;
		App(App&&)						= delete;
		App& operator = (const App&)	= delete;
		App& operator = (App&&)			= delete;

		virtual int				start(unsigned int width, unsigned int height, const char *title);

		virtual void			onUpdate();

	private:
		std::unique_ptr<class Window>			_pWindow;
	};

}

#endif // APP_HPP
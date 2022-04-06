#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

namespace Graphics {

	class Window
	{
	public:
		Window(std::string title, unsigned int width, unsigned int height);
		~Window();

		Window(const Window&)				=	delete;
		Window(Window&&)					=	delete;
		Window& operator = (const Window&)	=	delete;
		Window& operator = (Window&&)		=	delete;

		void			onUpdate();
		unsigned int	getWidth()	const noexcept;
		unsigned int	getHeight()	const noexcept;

	private:
		struct GLFWwindow*		_pWindow;
		unsigned int			_width;
		unsigned int			_height;
		std::string				_title;

		int				init();
		void			shutDown();
	};

}

#endif // !WINDOW_HPP
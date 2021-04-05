#include <SFML/Graphics.hpp>
#include <iostream>
 
using namespace sf;//включаем пространство имен sf, чтобы постоянно не писать sf::
int main()
{
	RenderWindow window(VideoMode(1920, 1080), "Game" /*,Style::Fullscreen*/); //увеличили для удобства размер окна


	Image pimage; //создаем объект Image (изображение)
	pimage.loadFromFile("images/Phon.jpg");//загружаем в него файл
 
	Texture ptxt;//создаем объект Texture (текстура)
	ptxt.loadFromImage(pimage);//передаем в него объект Image (изображения)
 
	Sprite psp;//создаем объект Sprite(спрайт)
	psp.setTexture(ptxt);//передаём в него объект Texture (текстуры)
	psp.setTextureRect(IntRect(0, 0, 1920, 1080));
	psp.setPosition(0, 0);//задаем начальные координаты появления спрайта
 

	while (window.isOpen())	
	{

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
			{
				if (event.key.code == Mouse::Left)//а именно левая
				{
					if (IntRect(47, 39, 380, 124).contains(Mouse::getPosition(window))) { psp.setColor(Color::Blue); }//и при этом координата курсора попадает в спрайт


					std::cout << "isClicked!\n";//выводим в консоль сообщение об этом						
				}

				if (event.key.code == Mouse::Right)//правая
				{
					if (IntRect(47, 39, 380, 124).contains(Mouse::getPosition(window))) { psp.setColor(Color::White); }//и при этом координата курсора попадает в спрайт

					std::cout << "isClicked!\n";//выводим в консоль сообщение об этом	
				}
			}
	



			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(psp);//выводим спрайт на экран
		window.display();
	}
 
	return 0;
}
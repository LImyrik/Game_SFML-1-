#include <SFML/Graphics.hpp>
#include <iostream>
 
using namespace sf;//�������� ������������ ���� sf, ����� ��������� �� ������ sf::
int main()
{
	RenderWindow window(VideoMode(1920, 1080), "Game" /*,Style::Fullscreen*/); //��������� ��� �������� ������ ����


	Image pimage; //������� ������ Image (�����������)
	pimage.loadFromFile("images/Phon.jpg");//��������� � ���� ����
 
	Texture ptxt;//������� ������ Texture (��������)
	ptxt.loadFromImage(pimage);//�������� � ���� ������ Image (�����������)
 
	Sprite psp;//������� ������ Sprite(������)
	psp.setTexture(ptxt);//������� � ���� ������ Texture (��������)
	psp.setTextureRect(IntRect(0, 0, 1920, 1080));
	psp.setPosition(0, 0);//������ ��������� ���������� ��������� �������
 

	while (window.isOpen())	
	{

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)//���� ������ ������� ����
			{
				if (event.key.code == Mouse::Left)//� ������ �����
				{
					if (IntRect(47, 39, 380, 124).contains(Mouse::getPosition(window))) { psp.setColor(Color::Blue); }//� ��� ���� ���������� ������� �������� � ������


					std::cout << "isClicked!\n";//������� � ������� ��������� �� ����						
				}

				if (event.key.code == Mouse::Right)//������
				{
					if (IntRect(47, 39, 380, 124).contains(Mouse::getPosition(window))) { psp.setColor(Color::White); }//� ��� ���� ���������� ������� �������� � ������

					std::cout << "isClicked!\n";//������� � ������� ��������� �� ����	
				}
			}
	



			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(psp);//������� ������ �� �����
		window.display();
	}
 
	return 0;
}
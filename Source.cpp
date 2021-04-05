#include<iostream>
using namespace std;

class Point
{
private: 
	int x;
	int y;

public:
	int GetX()
	{
		return x;
	};

	void SetX(int valueX) 
	{
		x = valueX;
	};

	int GetY()
	{
		return y;
	}

	void SetY(int valueY)
	{
		y = valueY;
	};

	void Print()
	{
		cout << "X = " << x << "\t Y = " << y << endl << endl;
	}
};

class CG
{
private:

	bool CheckVolt()
	{
		return true;
	}

public:
	void start()
	{
		bool VoltOk = CheckVolt();

		if (VoltOk)
		{
			cout << "zbc" << endl;
		}
		else
		{
			cout << "beep" << endl;
		}
	}




};

int main()
{
	CG a;
	a.start();
	
	return 0;
}
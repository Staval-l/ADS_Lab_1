#include <iostream>
#include <math.h>
#include <conio.h>
#include "Polyline.h"

int GetKey()
{
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}

int Menu()
{
	system("cls");
	std::cout << "Good morning\n\n1 - Add a vertex to the beginning of the polyline\n2 - Add a vertex to the end of the polyline\n3 - Calculate the length of the polyline\n4 - View the line\n5 - Overwrite vertex value\n6 - View the value of the vertex\n7 - The sum of two polylines\n8 - Check polylines for equality\n\nExit - Esc" << std::endl;
	while (true)
	{
		int key = GetKey();
		if ((key == 27) || (key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55) || (key == 56)) return key;
	}
}

int Menu_1()
{
	system("cls");
	std::cout << "Choose your line:\n\n1 - First line\n2 - Second line\n\nEsc - Return back" << std::endl;
	while (true)
	{
		int key = GetKey();
		if ((key == 27) || (key == 49) || (key == 50)) return key;
	}
}

int main()
{
	Polyline<IntPoint2> line_1, line_2;
	while (true)
	{
		system("cls");
		int m = Menu();
		if (m == 27)
		{
			break;
		}
		if (m == 49)
		{
			while (true)
			{
				system("cls");
				int m1 = Menu_1();
				if (m1 == 27) break;
				if (m1 == 49)
				{
					system("cls");
					IntPoint2 p;
					std::cout << "Enter the coordinates of the point" << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p._y;
					try
					{
						line_1.AddToHead(p);
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cin.get();
				}
				if (m1 == 50)
				{
					system("cls");
					IntPoint2 p;
					std::cout << "Enter the coordinates of the point" << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p._y;
					try
					{
						line_2.AddToHead(p);
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cin.get();
				}
			}
		}
		if (m == 50)
		{
			while (true)
			{
				system("cls");
				int m1 = Menu_1();
				if (m1 == 27) break;
				if (m1 == 49)
				{
					system("cls");
					IntPoint2 p;
					std::cout << "Enter the coordinates of the point" << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p._y;
					try
					{
						line_1.AddToEnd(p);
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cin.get();
				}
				if (m1 == 50)
				{
					system("cls");
					IntPoint2 p;
					std::cout << "Enter the coordinates of the point" << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p._x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p._y;
					try
					{
						line_2.AddToEnd(p);
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cin.get();
				}
			}
		}
		if (m == 51)
		{
			while (true)
			{
				system("cls");
				int m1 = Menu_1();
				if (m1 == 27) break;
				if (m1 == 49)
				{
					system("cls");
					try
					{
						std::cout << line_1 << std::endl;
						std::cout << "Line_1 lenght : " << line_1.GetLenght() << std::endl;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cin.get();
				}
				if (m1 == 50)
				{
					system("cls");
					try
					{
						std::cout << line_2 << std::endl;
						std::cout << "Line_2 lenght : " << line_2.GetLenght() << std::endl;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
					}
					std::cin.get();
				}
			}
		}
		if (m == 52)
		{
			while (true)
			{
				system("cls");
				int m1 = Menu_1();
				if (m1 == 27) break;
				if (m1 == 49)
				{
					system("cls");
					std::cout << line_1 << std::endl;
					std::cin.get();
				}
				if (m1 == 50)
				{
					system("cls");
					std::cout << line_2 << std::endl;
					std::cin.get();
				}
			}
		}
		if (m == 53)
		{
			while (true)
			{
				system("cls");
				int m1 = Menu_1();
				if (m1 == 27) break;
				if (m1 == 49)
				{
					system("cls");
					std::cout << "Enter index of element: " << std::endl;
					int index;
					std::cin >> index;
					try
					{
						std::cout << "Your element: " << "[" << line_1[index]._x << ";" << line_1[index]._y << "]" << std::endl;
						std::cout << "Enter new value: " << std::endl;
						std::cin >> line_1[index]._x;
						std::cin >> line_1[index]._y;
						std::cin.get();

					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						std::cin.get();
						std::cin.get();
					}
				}
				if (m1 == 50)
				{
					system("cls");
					std::cout << "Enter index of element: " << std::endl;
					int index;
					std::cin >> index;
					try
					{
						std::cout << "Your element: " << "[" << line_2[index]._x << ";" << line_2[index]._y << "]" << std::endl;
						std::cout << "Enter new value: " << std::endl;
						std::cin >> line_2[index]._x;
						std::cin >> line_2[index]._y;
						std::cin.get();

					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						std::cin.get();
						std::cin.get();
					}
				}
			}
		}
		if (m == 54)
		{
			while (true)
			{
				system("cls");
				int m1 = Menu_1();
				if (m1 == 27) break;
				if (m1 == 49)
				{
					system("cls");
					std::cout << "Enter index of element: " << std::endl;
					int index;
					std::cin >> index;
					try
					{
						std::cout << "Your element: " << "[" << line_1[index]._x << ";" << line_1[index]._y << "]" << std::endl;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						std::cin.get();
						std::cin.get();
					}
				}
				if (m1 == 50)
				{
					system("cls");
					std::cout << "Enter index of element: " << std::endl;
					int index;
					std::cin >> index;
					try
					{
						std::cout << "Your element: " << "[" << line_2[index]._x << ";" << line_2[index]._y << "]" << std::endl;
						std::cin.get();
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						std::cin.get();
						std::cin.get();
					}
				}
			}
		}
		if (m == 55)
		{
			while (true)
			{
				system("cls");
				int m1 = Menu_1();
				if (m1 == 27) break;
				if (m1 == 49)
				{
					system("cls");
					line_1 = line_1 + line_2;
					std::cout << "Successfully" << std::endl;
					std::cin.get();
				}
				if (m1 == 50)
				{
					system("cls");
					line_2 = line_2 + line_1;
					std::cout << "Successfully" << std::endl;
					std::cin.get();
				}
			}
		}
		if (m == 56)
		{
			system("cls");
			if (line_1 == line_2) std::cout << "Polylines are equal" << std::endl;
			else std::cout << "Polylines aren't equal" << std::endl;
			std::cin.get();
		}
	}
	return 0;
}
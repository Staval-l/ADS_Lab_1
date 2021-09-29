#include <iostream>
#include <math.h>
#include <conio.h>

struct Point
{
	double x;
	double y;
};

class Polyline {
	Point* arr;
	size_t vertex;
public:
	Polyline() : arr(nullptr), vertex(0) {}
	Polyline(int count) : arr(new Point[count]), vertex(count) {}
	Polyline(const Polyline& p)
	{
		arr = new Point[p.vertex];
		vertex = p.vertex;
		for (size_t i = 0; i < vertex; i++)
		{
			arr[i] = p.arr[i];
		}
	}
	~Polyline() 
	{
		delete[] arr;
		vertex = 0;
	}
	double GetLenght() const 
	{
		if (arr == nullptr) throw "Line is empty";
		double len = 0;
		for (size_t i = 0; i < vertex - 1; i++)
		{
			len += sqrt((pow(arr[i + 1].x - arr[i].x, 2) + (pow(arr[i + 1].y - arr[i].y, 2))));
		}
		return len;
	}
	void AddToHead(const Point& point) 
	{
		vertex += 1;
		Point* tmp = new Point[vertex];
		tmp[0] = point;
		for (size_t i = 1; i < vertex; i++)
		{
			tmp[i] = arr[i - 1];
		}
		if (arr != NULL) delete[] arr;
		arr = tmp;
	}
	void AddToEnd(const Point& point) 
	{
		vertex += 1;
		Point* tmp = new Point[vertex];
		for (size_t i = 0; i < vertex - 1; i++)
		{
			tmp[i] = arr[i];
		}
		tmp[vertex - 1] = point;
		if (arr != NULL) delete[] arr;
		arr = tmp;
	}
	Point& operator [] (const size_t index)
	{
		if ((index >= vertex) || (index < 0)) throw "Invalid index";
		return arr[index];
	}
	Point operator [] (const size_t index) const
	{
		if ((index >= vertex) || (index < 0)) throw "Invalid index";
		return arr[index];
	}
	Polyline operator + (const Polyline& polyline)
	{
		if (!vertex) return polyline;
		if (!polyline.vertex) return *this;
		Polyline res(vertex + polyline.vertex);
		//res.arr = new Point[vertex + polyline.vertex];
		for (size_t i = 0; i < vertex; i++)
		{
			res.arr[i] = arr[i];
		}
		for (size_t i = 0; i < polyline.vertex; i++)
		{
			res.arr[vertex + i] = polyline.arr[i];
		}
		return res;
	}
	bool operator == (const Polyline& polyline)
	{
		if (vertex != polyline.vertex) return false;
		for (size_t i = 0; i < vertex; i++)
		{
			if ((arr[i].x != polyline.arr[i].x) || (arr[i].y != polyline.arr[i].y)) return false;
		}
		return true;
	}
	bool operator != (const Polyline& polyline)
	{
		if (vertex != polyline.vertex) return true;
		for (size_t i = 0; i < vertex; i++)
		{
			if ((arr[i].x != polyline.arr[i].x) || (arr[i].y != polyline.arr[i].y)) return true;
		}
		return false;
	}
	Polyline& operator = (const Polyline& polyline)
	{
		if (this == (&polyline)) return *this;
		if (arr) delete[] arr;
		if (polyline.arr)
		{
			arr = new Point[polyline.vertex];
			vertex = polyline.vertex; 
			for (size_t i = 0; i < polyline.vertex; i++)
			{
				arr[i] = polyline.arr[i];
			}
		}
		else
		{
			arr = NULL;
			vertex = 0;
		}
		return *this;
	}
	friend std::ostream& operator<< (std::ostream& out, const Polyline& polyline);
};

std::ostream& operator<< (std::ostream& out, const Polyline& polyline)
{
	out << "Polyline <";
	for (size_t i = 0; i < polyline.vertex; i++)
	{
		out << "vertex[" << i << "]: " << "(" << polyline.arr[i].x << "," << polyline.arr[i].y;
		if (i != polyline.vertex - 1) out << "); ";
		else out << ")";
	}
	out << ">";
	return out;
}

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
	Polyline line_1, line_2;
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
					Point p;
					std::cout << "Enter the coordinates of the point" << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p.x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p.y;
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
					Point p;
					std::cout << "Enter the coordinates of the point" << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p.x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p.y;
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
					Point p;
					std::cout << "Enter the coordinates of the point" << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p.x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p.y;
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
					Point p;
					std::cout << "Enter the coordinates of the point" << std::endl;
					std::cout << "Enter x: " << std::endl;
					std::cin >> p.x;
					std::cout << "Enter y: " << std::endl;
					std::cin >> p.y;
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
						std::cout << "Your element: " << "[" << line_1[index].x << ";" << line_1[index].y << "]" << std::endl;
						std::cout << "Enter new value: " << std::endl;
						std::cin >> line_1[index].x;
						std::cin >> line_1[index].y;
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
					std::cout << "Enter index of element: " << std::endl;
					int index;
					std::cin >> index;
					try
					{
						std::cout << "Your element: " << "[" << line_2[index].x << ";" << line_2[index].y << "]" << std::endl;
						std::cout << "Enter new value: " << std::endl;
						std::cin >> line_2[index].x;
						std::cin >> line_2[index].y;
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
						std::cout << "Your element: " << "[" << line_1[index].x << ";" << line_1[index].y << "]" << std::endl;
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
					std::cout << "Enter index of element: " << std::endl;
					int index;
					std::cin >> index;
					try
					{
						std::cout << "Your element: " << "[" << line_2[index].x << ";" << line_2[index].y << "]" << std::endl;
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
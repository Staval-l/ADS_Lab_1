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
	int vertex;
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
		double len = 0;
		for (size_t i = 0; i < vertex - 1; i++)
		{
			len += sqrt((pow(arr[i + 1].x, 2) - pow(arr[i].x, 2)) + (pow(arr[i + 1].y, 2) - pow(arr[i].y, 2)));
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
		if (index >= vertex) throw "Invalid index";
		return arr[index];
	}
	Point operator [] (const size_t index) const
	{
		if (index >= vertex) throw "Invalid index";
		return arr[index];
	}
	Polyline operator + (const Polyline& polyline)
	{
		if (!vertex) return polyline;
		if (!polyline.vertex) return *this;
		Polyline res;
		res.arr = new Point[vertex + polyline.vertex];
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
	out << "Polyline[";
	for (size_t i = 0; i < polyline.vertex; i++)
	{
		out << "vertex[" << i << "]: " << "(" << polyline.arr[i].x << "," << polyline.arr[i].y;
		if (i != polyline.vertex - 1) out << "); ";
		else out << ")";
	}
	out << "]";
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
	std::cout << "Good morning\n\n1 - Add a vertex to the beginning of the polyline\n2 - Add a vertex to the end of the polyline\n3 - Calculate the length of the polyline\n4 - The sum of two broken lines\n5 - Overwrite vertex value\n6 - View the value of the vertex\n\nExit - Esc" << std::endl;
	while (true)
	{
		int key = GetKey();
		if ((key == 27) || (key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54)) return key;
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

		}
		if (m == 50)
		{

		}
		if (m == 51)
		{

		}
		if (m == 52)
		{

		}
		if (m == 53)
		{

		}
		if (m == 54)
		{

		}
	}
	return 0;
}
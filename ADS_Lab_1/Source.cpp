#include <iostream>
#include <math.h>

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
			vertex = polyline.vertex; // Уточнить
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
	friend std::istream& operator>> (std::istream& in, Point& point);
	// Операторы вывода +-
	// Оператор обращения по индексу +
	// Расчет длины ломаной
	// Добавление в начало/конец
	// Оператор сложения 2 ломаных +
	// Перегрузка операторов сравнения
};

//std::ostream& operator<< (std::ostream& out, const Polyline& point)
//{
//	out << "Point(" << point. << ", " << point. << ", " << point. << ")";
//	return out;
//}

std::istream& operator>> (std::istream& in, Point& point)
{
	in >> point.x;
	in >> point.y;
	return in;
}
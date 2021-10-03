#include <iostream>
#include "Polyline.h"

Polyline::Polyline(const Polyline& p)
{
	arr = new Point[p.vertex];
	vertex = p.vertex;
	for (size_t i = 0; i < vertex; i++)
	{
		arr[i] = p.arr[i];
	}
}
Polyline::~Polyline()
{
	delete[] arr;
	vertex = 0;
}
double Polyline::GetLenght() const
{
	if (arr == nullptr) throw "Line is empty";
	double len = 0;
	for (size_t i = 0; i < vertex - 1; i++)
	{
		len += sqrt((pow(arr[i + 1].x - arr[i].x, 2) + (pow(arr[i + 1].y - arr[i].y, 2))));
	}
	return len;
}
void Polyline::AddToHead(const Point& point)
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
void Polyline::AddToEnd(const Point& point)
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
Point& Polyline::operator [] (const size_t index)
{
	if (arr == nullptr) throw "Line is empty";
	if ((index >= vertex) || (index < 0)) throw "Invalid index";
	return arr[index];
}
Point Polyline::operator [] (const size_t index) const
{
	if (arr == nullptr) throw "Line is empty";
	if ((index >= vertex) || (index < 0)) throw "Invalid index";
	return arr[index];
}
Polyline Polyline::operator + (const Polyline& polyline)
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
bool Polyline::operator == (const Polyline& polyline)
{
	if (vertex != polyline.vertex) return false;
	for (size_t i = 0; i < vertex; i++)
	{
		if ((arr[i].x != polyline.arr[i].x) || (arr[i].y != polyline.arr[i].y)) return false;
	}
	return true;
}
bool Polyline::operator != (const Polyline& polyline)
{
	if (vertex != polyline.vertex) return true;
	for (size_t i = 0; i < vertex; i++)
	{
		if ((arr[i].x != polyline.arr[i].x) || (arr[i].y != polyline.arr[i].y)) return true;
	}
	return false;
}
Polyline& Polyline::operator = (const Polyline& polyline)
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
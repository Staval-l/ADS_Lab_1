#pragma once
#include <complex>
#include <iostream>

struct IntPoint2 {
	int _x;
	int _y;

	bool operator==(const IntPoint2& p)
	{
		if ((_x == p._x) && (_y == p._y)) return true;
		else return false;
	}

	float Distance(const IntPoint2& p) const
	{
		return static_cast<float>(sqrt(pow(_x - p._x, 2) + pow(_y - p._y, 2)));
	}
};

struct DoublePoint3 {
	double _x;
	double _y;
	double _z;

	bool operator==(const DoublePoint3& p)
	{
		if ((_x == p._x) && (_y == p._y) && (_z == p._z)) return true;
		else return false;
	}

	double Distance(const DoublePoint3& p)
	{
		return sqrt(pow(_x - p._x, 2) + pow(_y - p._y, 2) + pow(_z - p._z, 2));
	}
};

//struct std::complex<double> {
//
//};

template <class T>
class Polyline {
	T* arr;
	size_t vertex;
public:
	Polyline();
	Polyline(int count);
	Polyline(const Polyline& p);
	~Polyline();
	auto GetLenght() const;
	void AddToHead(const T& point);
	void AddToEnd(const T& point);
	T& operator [] (const size_t index);
	T operator [] (const size_t index) const;
	Polyline operator + (const Polyline& polyline);
	bool operator == (const Polyline& polyline);
	bool operator != (const Polyline& polyline);
	Polyline& operator = (const Polyline& polyline);
	//friend std::ostream& operator<< (std::ostream& out, const Polyline& polyline);
};

//template <class T>
//std::ostream& operator<< (std::ostream& out, const Polyline<T>& polyline);

template <class T>
Polyline<T>::Polyline() : arr(nullptr), vertex(0) {}

template <class T>
Polyline<T>::Polyline(int count)
{
	if (count < 0) throw "Invalid index";
	arr = new T[count];
	vertex = count;
}

template <class T>
Polyline<T>::Polyline(const Polyline<T>& p)
{
	arr = new T[p.vertex];
	vertex = p.vertex;
	for (size_t i = 0; i < vertex; i++)
	{
		arr[i] = p.arr[i];
	}
}

template <class T>
Polyline<T>::~Polyline()
{
	delete[] arr;
	vertex = 0;
}

template <class T>
auto Polyline<T>::GetLenght() const
{
	if (arr == nullptr) throw "Line is empty";
	auto len = arr[0].Distance(arr[1]);
	for (size_t i = 1; i < vertex - 1; i++)
	{
		len += arr[i].Distance(arr[i + 1]);
	}
	return len;
}

template <class T>
void Polyline<T>::AddToHead(const T& point)
{
	vertex += 1;
	T* tmp = new T[vertex];
	tmp[0] = point;
	for (size_t i = 1; i < vertex; i++)
	{
		tmp[i] = arr[i - 1];
	}
	if (arr != NULL) delete[] arr;
	arr = tmp;
}

template <class T>
void Polyline<T>::AddToEnd(const T& point)
{
	vertex += 1;
	T* tmp = new T[vertex];
	for (size_t i = 0; i < vertex - 1; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[vertex - 1] = point;
	if (arr != NULL) delete[] arr;
	arr = tmp;
}

template <class T>
T& Polyline<T>::operator [] (const size_t index)
{
	if (arr == nullptr) throw "Line is empty";
	if ((index >= vertex) || (index < 0)) throw "Invalid index";
	return arr[index];
}

template <class T>
T Polyline<T>::operator [] (const size_t index) const
{
	if (arr == nullptr) throw "Line is empty";
	if ((index >= vertex) || (index < 0)) throw "Invalid index";
	return arr[index];
}

template <class T>
Polyline<T> Polyline<T>::operator + (const Polyline<T>& polyline)
{
	if (!vertex) return polyline;
	if (!polyline.vertex) return *this;
	Polyline res(vertex + polyline.vertex);
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

template <class T>
bool Polyline<T>::operator == (const Polyline<T>& polyline)
{
	if (vertex != polyline.vertex) return false;
	for (size_t i = 0; i < vertex; i++)
	{
		if (!(arr[i] == polyline.arr[i])) return false;
	}
	return true;
}

template <class T>
bool Polyline<T>::operator != (const Polyline<T>& polyline)
{
	if (vertex != polyline.vertex) return true;
	for (size_t i = 0; i < vertex; i++)
	{
		if (!(arr[i] == polyline.arr[i])) return true;
	}
	return false;
}

template <class T>
Polyline<T>& Polyline<T>::operator = (const Polyline<T>& polyline)
{
	if (this == (&polyline)) return *this;
	if (arr) delete[] arr;
	if (polyline.arr)
	{
		arr = new T[polyline.vertex];
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

//template <class T>
//std::ostream& operator<< (std::ostream& out, const Polyline<T>& polyline)
//{
//	out << "Polyline <";
//	for (size_t i = 0; i < polyline.vertex; i++)
//	{
//		out << "vertex[" << i << "]: " << "(" << polyline.arr[i].x << "," << polyline.arr[i].y;
//		if (i != polyline.vertex - 1) out << "); ";
//		else out << ")";
//	}
//	out << ">";
//	return out;
//}
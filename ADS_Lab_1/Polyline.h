#pragma once
#include <iostream>
#include <complex>

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

struct std::complex<double> {
	
};

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
	friend std::ostream& operator<< (std::ostream& out, const Polyline& polyline);
};

template <class T>
std::ostream& operator<< (std::ostream& out, const Polyline<T>& polyline);
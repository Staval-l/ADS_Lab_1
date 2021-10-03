#pragma once
#include <iostream>

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
	Polyline(const Polyline& p);
	~Polyline();
	double GetLenght() const;
	void AddToHead(const Point& point);
	void AddToEnd(const Point& point);
	Point& operator [] (const size_t index);
	Point operator [] (const size_t index) const;
	Polyline operator + (const Polyline& polyline);
	bool operator == (const Polyline& polyline);
	bool operator != (const Polyline& polyline);
	Polyline& operator = (const Polyline& polyline);
	friend std::ostream& operator<< (std::ostream& out, const Polyline& polyline);
};

std::ostream& operator<< (std::ostream& out, const Polyline& polyline);
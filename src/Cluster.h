#pragma once
#include "Point.h"

#include <vector>
#include <memory>


class Cluster
{
private:
	std::vector<Point> points;
	Point central_point;
	
public:
	Cluster(Point& p);

	void set_central_point(Point& p);
	void add_point(Point& point);
	void remove_point(Point& point);
	Point get_central_point() const;
	size_t get_total_points() const;
	const std::vector<Point>& get_points() const;

	Cluster& operator=(const Cluster&);

	friend std::ostream& operator << (std::ostream& out, const Cluster& cluster);
};



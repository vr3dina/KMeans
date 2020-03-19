#include "Cluster.h"
#include "vector_os.h"

using namespace std;

Cluster& Cluster::operator=(const Cluster& other)
{
	if (this != &other)
	{
		points = other.points;
		central_point = other.central_point;
	}
	return *this;
}



Cluster::Cluster(Point& p) : central_point(p), points({ p })
{
}


void Cluster::set_central_point(Point& p)
{
	central_point = p;
}

void Cluster::add_point(Point& point)
{
	points.push_back(point);
}

void Cluster::remove_point(Point& point)
{
	auto it = std::find(points.begin(), points.end(), point);
	points.erase(it);
	point.cluster = nullptr;
}

Point Cluster::get_central_point() const
{
	return central_point;
}

size_t Cluster::get_total_points() const
{
	return points.size();
}

const std::vector<Point>& Cluster::get_points() const
{
	return points;
}


ostream& operator << (ostream& out, const Cluster& cluster)
{
	out << "Central point: " << cluster.get_central_point() << "\nPoints: " << cluster.get_points();
	return out;
}




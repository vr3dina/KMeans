#include "Point.h"
#include "vector_os.h"
#include <iomanip>

Point::Point() 
{
}

Point::Point(const std::string& name, const std::vector<double> v) : name(name), values(v), cluster(nullptr)
{
}

Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
		values = other.values;
		name = other.name;
		cluster = other.cluster;
	}
	return *this;
}


bool Point::operator==(const Point& other)
{
	return values == other.values && name == other.name && cluster == other.cluster;
}

std::ostream& operator << (std::ostream& out, const Point& p)
{
	out << std::endl << std::setw(10) << std::left << p.name << " " << p.values;
	//out << std::endl << p.values << (p.name != "" ? " - " + p.name : "");
	return out;
}

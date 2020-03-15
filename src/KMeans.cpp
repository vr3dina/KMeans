#include "KMeans.h"
#include <iostream>
#include "vector_os.h"

using namespace std;


#ifdef _DEBUG
#define LOG cout << "================= iteration # " << iter << " =================\n";\
	for (size_t i = 0; i < clusters.size(); i++) \
		cout << "Cluster # " <<  i << "\n============\n" \
				<< *clusters[i] << endl << endl;
#else
#define LOG {}
#endif



inline double sqr(double x)
{
	return x * x;
}

inline double squared_dist(const Point& a, const Point& b)
{
	double dist = 0.0;
	for (size_t i = 0; i < a.values.size(); i++)
		dist += sqr(a.values[i] - b.values[i]);
	return dist;
}


Cluster* KMeans::get_nearest_cluster(const Point& point)
{
	Cluster* cluster_center = clusters[0];
	int total_values = point.values.size();

	double min_dist = UINT64_MAX;
	for (const auto& cluster : clusters)
	{
		double dist = squared_dist(cluster->get_central_point(), point);
		if (dist < min_dist)
		{
			min_dist = dist;
			cluster_center = cluster;
		}
	}
	return cluster_center;
}


KMeans::KMeans(int K, unsigned int iters) : cluster_count(K), max_iterations(iters)
{
	clusters.resize(K);
}

std::vector<Cluster*> KMeans::run(std::vector<Point>& points)
{
	bool done = false;
	int iter = 0;

	for (size_t i = 0; i < cluster_count; i++)
		clusters[i] = new Cluster(points[i]);

	while (!done && iter < max_iterations)
	{
		done = true;

		// associates each point to the nearest center
		for (Point& point : points)
		{
			auto old_cluster = point.cluster;
			auto nearest_center = get_nearest_cluster(point);

			if (old_cluster != nearest_center)
			{
				if (old_cluster != nullptr)
					old_cluster->remove_point(point);

				nearest_center->add_point(point);
				done = false;
			}
		}

		LOG

			// recalculating the center of each cluster
			for (auto cluster : clusters)
			{
				Point central_point = Point("", cluster->get_central_point().values);
				for (size_t i = 0; i < central_point.values.size(); i++)
				{
					double sum = 0.0;
					int total_points_cluster = cluster->get_total_points();
					if (total_points_cluster > 0)
					{
						for (const auto& point : cluster->get_points())
							sum += point.values[i];
						central_point.values[i] = sum / total_points_cluster;
					}
				}
				cluster->set_central_point(central_point);
			}

		iter++;
	}


	//for (size_t i = 0; i < 3; i++)
	//{
	//	cout << "# " << i << " " << clusters[i]->get_central_point().values << endl;
	//	for (auto p : points)
	//	{
	//		cout << p.name << " " << squared_dist(p, clusters[i]->get_central_point()) << endl;
	//	}
	//}

	return clusters;
}

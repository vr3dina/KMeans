#include "KMeans.h"
#include "vector_os.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<Point> read_data(const string& file_path)
{
	vector<Point> points;
	ifstream fin(file_path);
	while (!fin.eof())
	{
		string name;
		double v1, v2;
		fin >> name >> v1 >> v2;
		points.push_back({ name, {v1, v2} });
	}
	return points;
}
int main()
{
	KMeans k_means(3);

	string file_path = "res/data.txt";
	//string file_path = "res/Text.txt";
	vector<Point> points = read_data(file_path);
	auto res = k_means.run(points);
	cout << res << endl;

	return 0;
}

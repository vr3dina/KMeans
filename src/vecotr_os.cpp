#include "vector_os.h"

template<>
std::ostream& operator << (std::ostream& out, const std::vector<Cluster>& v)
{
	for (size_t i = 0; i < v.size(); i++)
		out << "============ Cluster # " << i << " ============\n"
				<< v[i] << std::endl << std::endl;

	return out;
}

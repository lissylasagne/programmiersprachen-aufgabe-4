#include <vector>
#include <algorithm>
#include "list.cpp"

int main()
{
	List<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);

	std::vector<int> vec(list.size());
	std::copy(list.begin(), list.end(), std::begin(vec));

	for (std::vector<int>::iterator it = vec.begin(); it!=vec.end(); ++it)
	{
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;

}
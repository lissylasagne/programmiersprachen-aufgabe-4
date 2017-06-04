#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "list.cpp"

TEST_CASE("test lists", "[list]")
{
	SECTION ("test default constructor, empty and size")
	{
		List<char> list;
		REQUIRE(list.size() == 0);
		REQUIRE(list.empty() == true);
	}

	SECTION ("push, pop, front and back")
	{
		List<int>list;
		list.push_front(42);
		REQUIRE(list.front() == 42);

		list.pop_back();
		REQUIRE(list.empty() == true);
		list.push_front(1);
		list.push_front(2);
		REQUIRE(list.front() == 2);
		REQUIRE(list.back() == 1);
		list.pop_front();
		list.push_back(3);
		REQUIRE(list.front() == 1);
		REQUIRE(list.back() == 3);
	}

	SECTION("should be empty after clearing")
	{
	List<int> list ;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	list.clear();
	REQUIRE(list.empty());
	}

	SECTION("should be an empty range after default construction")
	{
		List<int> list;
		auto b = list.begin();
		auto e = list.end();
		REQUIRE(b == e);
	}
	
	SECTION("provide acces to the first element with begin")
	{
		List<int > list ;
		list.push_front(42);
		REQUIRE(42 == *list.begin());
		list.push_front(38);
		REQUIRE(38 == *list.begin());
		list.pop_front();
		REQUIRE(42 == *list.begin());

	}

	SECTION("copy constructor")
	{
		List<int> list ;
		list.push_front(1);
		list.push_front(2);
		list.push_front(3);
		list.push_front(4);
		List<int> list2 {list};
		REQUIRE(list == list2);
	}

	SECTION("insert")
	{
		List<int> list ;
		list.push_front(1);
		list.push_front(1);
		list.push_front(1);
		list.push_front(1);
		list.insert(list.begin(), 2);
		list.insert(++list.begin(), 3);
		REQUIRE(*(list.begin()) == 2);
		list.pop_front();
		REQUIRE(*(list.begin()) == 3);	
	}
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
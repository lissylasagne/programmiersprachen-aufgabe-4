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

		List<char>list2;
		list2.push_back('a');
		list2.push_front('b');
		REQUIRE(list2.front() == 'b');
		REQUIRE(list2.back() == 'a');
		list2.pop_front();
		REQUIRE(list2.front() == 'a');
		list2.push_front('c');
		list2.pop_back();
		REQUIRE(list2.back() == 'c');
	}

	SECTION("should be empty after clearing")
	{
		List<int> list;
		list.push_front(1);
		list.push_front(2);
		list.push_front(3);
		list.push_front(4);
		list.clear();
		REQUIRE(list.empty());

		List<int> list2;
		list2.push_front(42);
		list2.push_front(25);
		list2.push_front(0);
		list2.push_front(134);
		list2.clear();
		REQUIRE(list2.empty());

		List<char> list3;
		REQUIRE(list3.empty());
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
		List<int> list;
		list.push_front(42);
		REQUIRE(42 == *list.begin());
		list.push_front(38);
		REQUIRE(38 == *list.begin());
		list.pop_front();
		REQUIRE(42 == *list.begin());

		List<char> list2;
		list2.push_front('a');
		REQUIRE(*list3.begin() == 'a');
		list2.push_front('b');
		REQUIRE(*list3.begin() == 'b');
		list2.push_front('c');
		REQUIRE(*list3.begin() == 'c');

	}

	SECTION("copy constructor")
	{
		List<int> list;
		list.push_front(1);
		list.push_front(2);
		list.push_front(3);
		list.push_front(4);
		List<int> list2 {list};
		REQUIRE(list == list2);

		
		List<int> list3 ;
		list3.push_front(4);
		list3.push_front(25);
		list3.push_front(33);
		list3.push_front(4245);
		List<int> list4 {list3};
		REQUIRE(list3 == list4);
	}

	SECTION("insert")
	{
		List<int> list;
		list.push_front(1);
		list.push_front(1);
		list.push_front(1);
		list.push_front(1);
		list.insert(list.begin(), 2);
		ListIterator<int> sec = list.begin();
		++sec;
		list.insert(sec, 3);
		ListIterator<int> it = list.begin();
		REQUIRE(*it == 2);
		++it;
		REQUIRE(*it == 3);


		List<int> list2;
		list2.push_front(1423);
		list2.push_front(0);
		list2.push_front(15);
		list2.push_front(153);
		list2.insert(list2.begin(), 65);
		list2.insert(++list2.begin(), 355);
		REQUIRE(list2.front() == 65);
		list2.pop_front();
		REQUIRE(list2.front() == 355);	
	}

	SECTION("reverse")
	{
		List<int> list;
		list.push_front(1);
		list.push_front(2);
		list.push_front(3);
		list.push_front(4);
		List<int> list2 = reverse(list);
		list.reverse();
		REQUIRE(list == list2);
		REQUIRE(list.front() == 4);

		List<int> list3;
		list3.push_front(523);
		list3.push_front(51);
		list3.push_front(4765);
		list3.push_front(415);
		List<int> list4 = reverse(list3);
		list3.reverse();
		REQUIRE(list3 == list4);
		REQUIRE(list3.front() == 415);
	}
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
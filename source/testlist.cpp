#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "list.cpp"

TEST_CASE("test lists", "[list]")
{
	SECTION ("test default constructor, empty and size")
	{
		List listA();
		REQUIRE (listA.size() == 0);
		REQUIRE (listA.empty() == true);
	}
}
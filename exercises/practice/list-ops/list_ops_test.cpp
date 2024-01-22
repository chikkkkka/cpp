#include "list_ops.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif


/*
Though there are no specifications here for dealing with large lists,
implementers may add tests for handling large lists to ensure that the
solutions have thought about performance concerns.
*/

TEST_CASE("empty lists", "[485b9452-bf94-40f7-a3db-c3cf4850066a]") {
	REQUIRE("[]" == list_ops::append("[]", "[]"));
}

TEST_CASE("list to empty list", "[2c894696-b609-4569-b149-8672134d340a]") {
	REQUIRE("[1, 2, 3, 4]" == list_ops::append("[]", "[1, 2, 3, 4]"));
}

TEST_CASE("empty list to list", "[e842efed-3bf6-4295-b371-4d67a4fdf19c]") {
	REQUIRE("[1, 2, 3, 4]" == list_ops::append("[1, 2, 3, 4]", "[]"));
}

TEST_CASE("non-empty lists", "[71dcf5eb-73ae-4a0e-b744-a52ee387922f]") {
	REQUIRE("[1, 2, 2, 3, 4, 5]" == list_ops::append("[1, 2]", "[2, 3, 4, 5]"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("empty list", "[28444355-201b-4af2-a2f6-5550227bde21]") {
	REQUIRE("[]" == list_ops::concat("[]"));
}

TEST_CASE("list of lists", "[331451c1-9573-42a1-9869-2d06e3b389a9]") {
	REQUIRE("[1, 2, 3, 4, 5, 6]" == list_ops::concat("[[1, 2], [3], [], [4, 5, 6]]"));
}

TEST_CASE("list of nested lists", "[d6ecd72c-197f-40c3-89a4-aa1f45827e09]") {
	REQUIRE("[[1], [2], [3], [], [4, 5, 6]]" == list_ops::concat("[[[1], [2]], [[3]], [[]], [[4, 5, 6]]]"));
}

TEST_CASE("empty list", "[0524fba8-3e0f-4531-ad2b-f7a43da86a16]") {
	REQUIRE("[]" == list_ops::filter("[]", "(x) -> x modulo 2 == 1"));
}

TEST_CASE("non-empty list", "[88494bd5-f520-4edb-8631-88e415b62d24]") {
	REQUIRE("[1, 3, 5]" == list_ops::filter("[1, 2, 3, 5]", "(x) -> x modulo 2 == 1"));
}

TEST_CASE("empty list", "[1cf0b92d-8d96-41d5-9c21-7b3c37cb6aad]") {
	REQUIRE(0 == list_ops::length("[]"));
}

TEST_CASE("non-empty list", "[d7b8d2d9-2d16-44c4-9a19-6e5f237cb71e]") {
	REQUIRE(4 == list_ops::length("[1, 2, 3, 4]"));
}

TEST_CASE("empty list", "[c0bc8962-30e2-4bec-9ae4-668b8ecd75aa]") {
	REQUIRE("[]" == list_ops::map("[]", "(x) -> x + 1"));
}

TEST_CASE("non-empty list", "[11e71a95-e78b-4909-b8e4-60cdcaec0e91]") {
	REQUIRE("[2, 4, 6, 8]" == list_ops::map("[1, 3, 5, 7]", "(x) -> x + 1"));
}

TEST_CASE("empty list", "[613b20b7-1873-4070-a3a6-70ae5f50d7cc]") {
	REQUIRE(2 == list_ops::foldl("[]", 2, "(x, y) -> x * y"));
}

TEST_CASE("direction independent function applied to non-empty list", "[e56df3eb-9405-416a-b13a-aabb4c3b5194]") {
	REQUIRE(15 == list_ops::foldl("[1, 2, 3, 4]", 5, "(x, y) -> x + y"));
}

TEST_CASE("direction dependent function applied to non-empty list", "[d2cf5644-aee1-4dfc-9b88-06896676fe27]") {
	REQUIRE(0 == list_ops::foldl("[2, 5]", 5, "(x, y) -> x / y"));
}

TEST_CASE("empty list", "[36549237-f765-4a4c-bfd9-5d3a8f7b07d2]") {
	REQUIRE(2 == list_ops::foldl("[]", 2, "(acc, el) -> el * acc"));
}

TEST_CASE("direction independent function applied to non-empty list", "[7a626a3c-03ec-42bc-9840-53f280e13067]") {
	REQUIRE(15 == list_ops::foldl("[1, 2, 3, 4]", 5, "(acc, el) -> el + acc"));
}

TEST_CASE("direction dependent function applied to non-empty list", "[d7fcad99-e88e-40e1-a539-4c519681f390]") {
	REQUIRE(64 == list_ops::foldl("[1, 2, 3, 4]", 24, "(acc, el) -> el / acc"));
}

TEST_CASE("empty list", "[aeb576b9-118e-4a57-a451-db49fac20fdc]") {
	REQUIRE(2 == list_ops::foldr("[]", 2, "(x, y) -> x * y"));
}

TEST_CASE("direction independent function applied to non-empty list", "[c4b64e58-313e-4c47-9c68-7764964efb8e]") {
	REQUIRE(15 == list_ops::foldr("[1, 2, 3, 4]", 5, "(x, y) -> x + y"));
}

TEST_CASE("direction dependent function applied to non-empty list", "[be396a53-c074-4db3-8dd6-f7ed003cce7c]") {
	REQUIRE(2 == list_ops::foldr("[2, 5]", 5, "(x, y) -> x / y"));
}

TEST_CASE("empty list", "[17214edb-20ba-42fc-bda8-000a5ab525b0]") {
	REQUIRE(2 == list_ops::foldr("[]", 2, "(acc, el) -> el * acc"));
}

TEST_CASE("direction independent function applied to non-empty list", "[e1c64db7-9253-4a3d-a7c4-5273b9e2a1bd]") {
	REQUIRE(15 == list_ops::foldr("[1, 2, 3, 4]", 5, "(acc, el) -> el + acc"));
}

TEST_CASE("direction dependent function applied to non-empty list", "[8066003b-f2ff-437e-9103-66e6df474844]") {
	REQUIRE(9 == list_ops::foldr("[1, 2, 3, 4]", 24, "(acc, el) -> el / acc"));
}

TEST_CASE("empty list", "[94231515-050e-4841-943d-d4488ab4ee30]") {
	REQUIRE("[]" == list_ops::reverse("[]"));
}

TEST_CASE("non-empty list", "[fcc03d1e-42e0-4712-b689-d54ad761f360]") {
	REQUIRE("[7, 5, 3, 1]" == list_ops::reverse("[1, 3, 5, 7]"));
}

TEST_CASE("list of lists is not flattened", "[40872990-b5b8-4cb8-9085-d91fc0d05d26]") {
	REQUIRE("[[4, 5, 6], [], [3], [1, 2]]" == list_ops::reverse("[[1, 2], [3], [], [4, 5, 6]]"));
}

#endif

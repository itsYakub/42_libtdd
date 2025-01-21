#include "gtest/gtest.h"

/*	If we want to use C libraries in our testing,
 *	we need to tell the compiler explicitly that we're using a C library here.
 *	(Yes, there are more differences between C and C++ than the syntax. They're 2 different languages!)
 * */
extern "C" {
	#include "../libtdd.h"
}

/*	SECTION:
 *		_sqrt() tests
 * */
TEST (SqrtTest, ValidOutput0) {
	EXPECT_EQ(_sqrt(16), 4);	
}
TEST (SqrtTest, ValidOutput1) {
	EXPECT_EQ(_sqrt(-4), 0);	
}
TEST (SqrtTest, ValidOutput2) {
	EXPECT_EQ(_sqrt(25), 5);	
}

/*	SECTION:
 *		_strjoin() tests
 * */
TEST (StrjoinTest, ValidOutput0) {
	char	str0[] = "Hello, ";
	char	str1[] = "World!";
	char	*str = _strjoin(str0, str1);

	EXPECT_STREQ(str, "Hello, World!");
	free(str);
}

TEST (StrjoinTest, ValidOutput1) {
	char	str0[] = "";
	char	str1[] = "";
	char	*str = _strjoin(str0, str1);

	EXPECT_STREQ(str, "");
	free(str);
}

TEST (StrjoinTest, ValidOutput2) {
	char	str0[] = "Lorem ipsum dolor sit amet, ";
	char	str1[] = "consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
	char	*str = _strjoin(str0, str1);

	EXPECT_STREQ(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");
	free(str);
}

/*	SECTION:
 *		_memmove() tests
 * */
TEST (MemmoveTest, ValidOutput0) {
	char	dst[32] = "";
	char	src[32] = "Hello, world!";

	_memmove(dst, src, 13);
	EXPECT_STREQ(dst, "Hello, world!");
}

TEST (MemmoveTest, ValidOutput1) {
	char	str[32] = "Hello, world!";

	_memmove(str, str + 1, 5);
	EXPECT_STREQ(str, "ello,, world!");
}

TEST (MemmoveTest, ValidOutput2) {
	char	str[32] = "Hello, world!";

	_memmove(str + 1, str, 5);
	EXPECT_STREQ(str,"HHello world!");
}

/*	SECTION:
 *		_split() tests
 * */
TEST (SplitTest, ValidOutput0) {
	const char	*str = "Lorem ipsum dolor sit amet";
	char		**split = _split((char *) str, 32);

	EXPECT_STREQ(split[5], NULL);

	for (size_t i = 0; split[i]; i++)
		free(split[i]);
	free(split);
}

TEST (SplitTest, ValidOutput1) {
	const char	*str = "Lorem ipsum dolor sit amet";
	char		**split = _split((char *) str, 32);
	
	size_t c;
	for (c = 0; split[c]; c++);

	EXPECT_EQ(c, 5);
	
	for (size_t i = 0; split[i]; i++)
		free(split[i]);
	free(split);
}

TEST (SplitTest, ValidOutput2) {
	const char	*str = "The longest word!";
	char		**split = _split((char *) str, 32);
	
	EXPECT_EQ(strlen(split[1]), 7);
	
	for (size_t i = 0; split[i]; i++)
		free(split[i]);
	free(split);
}


#include <iostream>
#include <uf.h>
#include <assert.h>


#ifdef GTEST
	#include <gtest/gtest.h>
#endif

void basic_test()
{
	UF test(5);
        test.unite(0,1);
        test.unite(2,3);
        test.unite(3,4);
	assert(!test.connected(0,4));
	assert(test.connected(2,4));
}

#ifdef GTEST
TEST(UnionFindTest, General) {
	unsigned int full_size = 200;
	UF test(full_size);
	EXPECT_FALSE(test.connected(0, full_size/2-1));
	EXPECT_FALSE(test.connected(0, full_size-1));
	for (unsigned int i=0; i<full_size/2; ++i)
	{
		test.unite(i,i+1);
	}
	EXPECT_TRUE(test.connected(0, full_size/2-1));
	EXPECT_FALSE(test.connected(0, full_size-1));
	for (unsigned int i=0; i<full_size-1; ++i)
        {
                test.unite(i,i+1);
        }
	EXPECT_TRUE(test.connected(0, full_size/2-1));
        EXPECT_TRUE(test.connected(0, full_size-1));
}

void gtest_test()
{
	int res = RUN_ALL_TESTS();
	if (res != 0)
	{
		exit(EXIT_FAILURE);
	}
}
#endif

int main(int argc, char **argv)
{
	
	basic_test();
	#ifdef GTEST
	::testing::InitGoogleTest(&argc, argv);
	gtest_test();
	#endif
	return 0;
}

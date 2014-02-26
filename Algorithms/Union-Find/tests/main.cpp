
#include <iostream>
#include <uf.h>

int main()
{
	UF test(5);
	test.unite(0,1);
	test.unite(2,3);
	test.unite(3,4);
	std::cout << test.connected(0,4) << std::endl;
	std::cout << test.connected(2,4) << std::endl;
	return 0;
}

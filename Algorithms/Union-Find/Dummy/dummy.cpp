
#include "dummy.h"

UFImpl::UFImpl(unsigned int N) {}

UFImpl::~UFImpl() {}

void UFImpl::unite(unsigned int p, unsigned int q) {}

bool UFImpl::connected(unsigned int p, unsigned int q)
{
	// true to avoid infinite loop in perf (tests)
	return true;
}


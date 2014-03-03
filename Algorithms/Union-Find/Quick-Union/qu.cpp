
#ifdef DEBUG
	#include <iostream>
#endif
#include "qu.h"

UFImpl::UFImpl(unsigned int N): _id(new unsigned int[N]), _size(N)
{
	for (unsigned int i = 0; i<N; ++i)
	{
		_id[i] = i;
	}
}

UFImpl::~UFImpl()
{
	delete[] _id;
}

void UFImpl::unite(unsigned int p, unsigned int q)
{
	#ifdef DEBUG
        std::cout << "unite " << p << " to " << q << std::endl;
	#endif
	unsigned int root_q = _root(q);
	unsigned int root_p = _root(p);
	_id[root_p] = root_q;
	while (p != _id[p])
	{
		unsigned old_p = p;
		p = _id[p];
		_id[old_p] = root_q;
	}
	#ifdef DEBUG
	for (unsigned int i=0; i<_size; ++i)
	{
		std::cout << _id[i] << " ";
	}
	std::cout << std::endl;
	#endif
}

bool UFImpl::connected(unsigned int p, unsigned int q)
{
	return _root(p) == _root(q);
}

unsigned int UFImpl::_root(unsigned int node)
{
        while (node != _id[node])
        {
                node = _id[node];
        }
        return node;
}


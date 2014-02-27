
#include <uf.h>
#ifdef DEBUG
	#include <iostream>
#endif

__attribute__ ((visibility ("hidden"))) unsigned int root(unsigned int node, unsigned int *array)
{
        while (node != array[node])
        {
                node = array[node];
        }
        return node;
}

UF::UF(unsigned int N): _id(new unsigned int[N]), _size(N)
{
	for (unsigned int i = 0; i<N; ++i)
	{
		_id[i] = i;
	}
}

UF::~UF()
{
	delete[] _id;
}

void UF::unite(unsigned int p, unsigned int q)
{
	#ifdef DEBUG
        std::cout << "unite " << p << " to " << q << std::endl;
	#endif
	unsigned int root_q = root(q, _id);
	unsigned int root_p = root(p, _id);
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

bool UF::connected(unsigned int p, unsigned int q)
{
	return root(p, _id) == root(q, _id);
}


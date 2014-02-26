
#include <uf.h>

__attribute__ ((visibility ("hidden"))) unsigned int root(unsigned int node, unsigned int *array)
{
        while (node != array[node])
        {
                node = array[node];
        }
        return node;
}

UF::UF(unsigned int N)
{
	id = new unsigned int[N];
	for (unsigned int i = 0; i<N; ++i)
	{
		id[i] = i;
	}
}

UF::~UF()
{
	delete[] id;
}

void UF::unite(unsigned int p, unsigned int q)
{
	unsigned local_root = root(q, id);
	id[p] = q;
	while (p != id[p])
	{
		unsigned old_p = p;
		p = id[p];
		id[old_p] = local_root;
	}
}

bool UF::connected(unsigned int p, unsigned int q)
{
	return root(p, id) == root(q, id);
}


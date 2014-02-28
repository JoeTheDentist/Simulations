
#include "../uf.h"
/* Defined in makefile */
#include LIB_HEADER

UF::UF(unsigned int N): _impl(new UFImpl(N)) {}

UF::~UF() { delete _impl; }

void UF::unite(unsigned int p, unsigned int q) { _impl->unite(p,q); }

bool UF::connected(unsigned int p, unsigned int q) { return _impl->connected(p,q); }


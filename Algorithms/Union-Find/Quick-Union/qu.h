
class UFImpl
{
public:
        UFImpl(unsigned int N);
        ~UFImpl();
        void unite(unsigned int p, unsigned int q);
        bool connected(unsigned int p, unsigned int q);

private:
	unsigned int _root(unsigned int root);
        unsigned int *_id;
        unsigned int _size;
};


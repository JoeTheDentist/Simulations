
class UFImpl;

/**
 * Union Find Algorithm
 */
class __attribute__ ((visibility ("default"))) UF
{
public:
	/**
	 * Constructor.
	 * Initialize an Union-Find that support N elements.
	 */
	UF(unsigned int N);

	/**
	 * Destructor.
	 * Clean up.
	 */
	~UF();

	/**
	 * Create the union between p and q.
	 */
	void unite(unsigned int p, unsigned int q);
	
	/**
	 * Check the connectivity of p and q.
	 */
	bool connected(unsigned int p, unsigned int q);

private:
	/* pimpl idiom */
	UFImpl *_impl;
};


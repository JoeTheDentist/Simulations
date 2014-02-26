
class UF
{
public:
	/**
	 * Constructor.
	 * Initialize an Union-Find that support N elements.
	 */
	UF(unsigned int N);

	/**
	 * Create the union between p and q.
	 */
	void unite(unsigned int p, unsigned int q);
	
	/**
	 * Check the connectivity of p and q.
	 */
	bool connected(unsigned int p, unsigned int q);

private:
	unsigned int *id;
};
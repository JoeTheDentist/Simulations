
#include <iostream>
#include <uf.h>

#include <time.h>
#include <stdlib.h>

// Visual mode
#ifdef PAINT
	#include <unistd.h> // sleep
	#include <curses.h> // ncurses commands
	static WINDOW *g_win;
	static int g_H;
	static int g_W;
#endif

// Benchmarking mode
#ifdef PERF
	#include <valgrind/callgrind.h>
	// Requires callgrind --collect-atstart=no option
	#define CHECK_PERF( x ) \
		do { \
			CALLGRIND_TOGGLE_COLLECT; \
			x; \
			CALLGRIND_TOGGLE_COLLECT; \
		} while (0)
#else
	#define CHECK_PERF( x ) x
#endif

class Grid
{
public:
	enum cell_t { BLACK=0, WHITE };

	/**
	 * Constructor.
	 * H,W: size of the grid.
	 */
	Grid(int H, int W): free_cells(0), _H(H), _W(W), _matrix(new cell_t[H*W]), _uf(H*W+2)
	{
		for (int i=0; i<H*W; ++i)
		{
			_matrix[i] = BLACK;
			#ifdef PAINT
			mvaddch(i/_W, i%_W, '#');
			#endif
		}
		#ifdef PAINT
		refresh();
		#endif
	}

	/**
	 * Destructor.
	 */	
	~Grid() { delete[] _matrix; }

	/**
	 * Get the color at the requested position.
	 */
	cell_t at(int x, int y) { return _matrix[x+y*_W]; }

	/**
	 * Set the given point free (white).
	 */
	void set_free(int x, int y)
	{
		// No need to set free if it is already.
		if (!at(x,y))
		{
			_matrix[x+y*_W] = WHITE;
			++free_cells;

			// Check left
			if (x != 0    && at(x-1,y)) CHECK_PERF(_uf.unite(x+y*_W-1, x+y*_W));
			// Check right
			if (x != _W-1 && at(x+1,y)) CHECK_PERF(_uf.unite(x+y*_W+1, x+y*_W));
			// Check top
			if (y != 0    && at(x,y-1)) CHECK_PERF(_uf.unite(x+(y-1)*_W, x+y*_W));
			// Check bottom
			if (y != _H-1 && at(x,y+1)) CHECK_PERF(_uf.unite(x+(y+1)*_W, x+y*_W));
			// Check top connection
			if (y == 0)    CHECK_PERF(_uf.unite(x+y*_W, _W*_H+1));
			// Check bottom connection
			if (y == _H-1) CHECK_PERF(_uf.unite(x+y*_W, _W*_H));

			#ifdef PAINT
        	        mvaddch(y, x, ' ');
	                refresh();
			// SLEEP defined in Makefile
			usleep(SLEEP);
                	#endif
		}
	}

	/**
	 * Check whether the top is connected to the bottom.
	 */
	bool is_connected()
	{
		// Check the connectivity from the top to the bottom.
		// Bottom: _H*_W
		// Top: _H*_W+1
		bool res;
		CHECK_PERF(res = _uf.connected(_W*_H, _W*_H+1));
		return res;
	}

	int free_cells;

private:
	int _H;
	int _W;
	cell_t *_matrix;
	UF _uf;
};

void init()
{
	#ifdef PAINT
	if ( (g_win = initscr()) == NULL ) {
                fprintf(stderr, "Error initialising ncurses.\n");
                exit(EXIT_FAILURE);
        }
	getmaxyx(g_win, g_H, g_W);
	#endif
	srand(time(NULL));
}

void fini()
{
	#ifdef PAINT
	delwin(g_win);
        endwin();
        refresh();
	#endif
}

int main()
{
	init();

	double av = 0;
	// SAMPLE and BOX defined in Makefile
	int sample = SAMPLE;
	int box = BOX;
	for (int i=0; i<sample; ++i)
	{
		Grid g(box,box);
		while (!g.is_connected())
		{
			g.set_free(rand() % box, rand() % box);
		}
		av += (double)g.free_cells/(double)(box*box*sample);
	}

	fini();	

	std::cout << av << std::endl;
	return EXIT_SUCCESS;
}

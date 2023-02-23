//
//  main.cpp
//  SJTU CP2022-23
//
//  Created by Yoshi Kamiya on 2023/02/16.
//

#include <iostream>
#include <vector>

class Site {
public:
	static int dim; /* dimension */
	static int N_SL; /* number of sublattices */
	static std::vector<int> L; /* system size */
	
	static void set_lattice_info(int N_SL_spec, const std::vector<int>& L_spec) {
		/* set dim, L, N_SL */
		dim = static_cast<int>(L_spec.size());
		L = L_spec;
		N_SL = N_SL_spec;
	};
	
	static int eval_site_index(int sl_index, const std::vector<int>& n) {
		/*
		 s_idx = (n[d-1], n[d-2], ..., n[0], sl_index)
		 */
		int s_idx = n[dim - 1];
		for ( int a = dim - 2; a >= 0; a-- ) {
			assert(n[a] < L[a] && n[a] >= 0);
			s_idx *= L[a];
			s_idx += n[a];
		}
		assert(sl_index < N_SL && sl_index >= 0);
		s_idx *= N_SL;
		s_idx += sl_index;
		
		return s_idx;
	};
	
private:
	int site_index;
	int sublattice_index;
	std::vector<int> coordinate;
	
public:
	Site() {
		/* constructor */
	};
	
	virtual ~Site() {
		/* destructor */
	};
};

int Site::dim;
int Site::N_SL;
std::vector<int> Site::L;

int main(int argc, const char * argv[]) {

	/* square lattice */
	const int N_SL = 1;
	const int dim = 2;
	std::vector<int> L(dim);
	L[0] = 10;
	L[1] = 10;
	Site::set_lattice_info(N_SL, L);
	
	Site test;
	
	return 0;
}

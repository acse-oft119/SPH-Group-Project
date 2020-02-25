
#pragma once
#define _USE_MATH_DEFINES
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class SPH_main;

class SPH_particle
{
public:
	double x[2], v[2];				//position and velocity
	double rho, P;					//density and pressure
	double a[2];					//acceleration
	double D;						//rate of change of density
	double rho2;

	double numerator;
	double denominator;

	static SPH_main* main_data;		//link to SPH_main class so that it can be used in calc_index

	int list_num[2];				//index in neighbour finding array

	void calc_index(void);
};


class SPH_main
{
public:
	SPH_main();
	double cubic_spline(double r[2]);
	double cubic_spline_first_derivative(double r[2]);
	void update_gradients(double r[2], SPH_particle* part, SPH_particle* other_part);
	void density_field_smoothing(SPH_particle* part);

	void set_values(void);
	void initialise_grid(void);

	void place_points(double* min, double* max);

	void allocate_to_grid(void);			//allocates all the points to the search grid (assumes that index has been appropriately updated)

	void neighbour_iterate(SPH_particle* part);
	void update_particle(SPH_particle* part);
	void reset_grid_count();
	void update_rho(SPH_particle* part);

	double h;								//smoothing length
	double h_fac;
	double dx;								//particle initial spacing
	double c0;								//speed of sound

	double dt;								//time step

	double g[2];							//gravity constant
	double mu;								//viscosity
	double rho0;							//initial density
	double B;
	double gamma;

	double numerator2 = 0;
	double denominator2 = 0;

	double min_x[2], max_x[2];				//dimensions of simulation region

	vector<vector<int>> grid_count;

	int max_list[2];

	vector<SPH_particle> particle_list;						//list of all the particles

	vector<vector<vector<SPH_particle*> > > search_grid;		//Outer 2 are the grid, inner vector is the list of pointers in each cell
};
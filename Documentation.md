
# Table of Contents

1.  [Code structure, Class variables and functions](#org7a68bf3)
    1.  [*SPH\_particle*](#org3b3be2b)
        1.  [Class variables:](#org0450d32)
        2.  [Class functions:](#org9907b17)
    2.  [*SPH\_main*](#org6297bd0)
        1.  [Class variables:](#orgefdb094)
        2.  [Class functions:](#org63ed5f4)
2.  [Running the Simulation, Post-processing and Output scripts](#org3350b24)
    1.  [file\_writer.cpp](#orga8ab8d1)
    2.  [post.py](#org3218b37)
3.  [Testing](#org4c3e822)
    1.  [C++ Testing](#org208fbb0)
    2.  [Python Testing](#org91c1fd2)
    3.  [Testing pipeline](#orgbe3671e)

This tool has been implemented in C++ with Python as a means to analyze data and
test the output of the code. Bellow is the documentation of the functions used
in the tool and an analysis of the testing pipline.


<a id="org7a68bf3"></a>

# Code structure, Class variables and functions

The tool is composed of two classes *SPH\_particle* and *SPH\_main*.
*SPH\_particle* is an object that represents each individual particle in our
simulation and holds parameters and values that are specific to every particle
(eg. position, velocity, etc). *SPH\_main* represents the domain the simulation
is using and holds all the functions, globals and data strucutres needed to run
the simulation.


<a id="org3b3be2b"></a>

## *SPH\_particle*

1.  TODO Include complete descriptions of class variables


<a id="org0450d32"></a>

### Class variables:

-   **x[] (double):** Particle position variables. This array has two entries, one
    for the x-direction and one for the y-direction.
-   **v[] (double):** Particle velocity variable. This array has two entries, one
    for the x-direction and one for the y-direction.
-   **rho (double):** Particle density variable.
-   **P (double):** Particle pressure variable.
-   **a[] (double):** Particle acceleration variable. This array has two entries,
    one for the x-direction and one for the y-direction.
-   **D (double):** Particle rate of change of density variable.
-   **rho2 (dobule):** 

-   **vij\_half[] (double):** 

-   **x\_half[] (double):** Particle half-step position variable. This is an array
    that stores the position of the particle after a half step in the second order
    time-stepping method. This array has two entries, one for the x-direction and
    one for the y-direction.
-   **v\_half[] (double):** Particle half-step velocity variable. This is an array
    that stores the velocity of the particle after a half step in the second order
    time-stepping method. This array has two entries, one for the x-direction and
    one for the y-direction.
-   **rho\_half (double):** Particle half-step density variable. This is a variable
    that stores the density of the particle after a half step in the second order
    time-stepping method.
-   **a\_half[] (double):** Particle half-step acceleration variable. This is an
    array that stores the acceleration of the particle after a half step in the
    second order time-stepping method. This array has two entries, one for the
    x-direction and one for the y-direction.
-   **D\_half (double):** Particle half-step rate of change of density variable. This
    variable stores the rate of change of density after a half step in the second
    order time-stepping method.
-   **numerator (double):** 

-   **denominator (double):** 

-   **main\_data (staic SPH\_main \*):** Link to SPH\_main class so that it can be used
    to calc\_index
-   **list\_num[] (int):** Index in neighbour finding array.
-   **is\_boundary (bool):** Set true if the particle is part of the boundary


<a id="org9907b17"></a>

### Class functions:

-   **calc\_index(*void*) (void):** This function is responsible for populating the
    *list\_index[]* array.


<a id="org6297bd0"></a>

## *SPH\_main*

1.  TODO Include complete descriptions of class variables and functions


<a id="orgefdb094"></a>

### Class variables:

-   **h (double):** Smoothing length
-   **h\_fac (double):** 

-   **dx (double):** Particles initial spacing. This is a variable that is
    responsible for the space between neighbouring particles when the initial
    configuration is set.
-   **c0 (double):** Speed of sound. As this is a simple simulation, a different
    speed of sound has been implemented.
-   **dt (double):** Timestep. This is a variable that defines the size of the
    timestep in the time-stepping solution.
-   **g[] (double):** Gravity constant array. This array stores the initial
    accelaration values that describe our sytem. In this case it is only gravity
    and it points in the negative y-direction.
-   **mu (double):** Viscocity variable. This variable holds the viscocity value of
    our system.
-   **rho0 (double):** Initial density variable. This variable stores the initial
    density value for all the particles.
-   **B (double):** 

-   **gamma (double):** 

-   **mass (double):** Mass variable. This variable stores the mass of each particle
    in the simulation.

For dynamic time stepping

-   **v\_max (double):** 

-   **a\_max (double):** 

-   **rho\_max (double):** 

-   **dt\_cfl (double):** 

-   **dt\_f (double):** 

-   **dt\_a (double):** 

-   **cfl (double):** 


-   **min\_x[], max\_x[] (double):** Dimensions of simulation region
-   **grid\_count (vector<vector<int>>):** 

-   **max\_list[] (int):** 

-   **particle\_list (vector<SPH\_particle>):** List of all the particles
-   **search\_grid (<vector<vector<vector<SPH\_particle\*>>>):** Outer two vectors are
    the grid, inner vector is the list.


<a id="org63ed5f4"></a>

### Class functions:

-   **SPH\_main():** Main constructor.
-   **cubic\_spline(*double r[]*) (double):** Cubic Spline calculation function.
    -   *r[]* contains the distance between two points.

Calculates the cubic spline according to three cases:

![equation](https://latex.codecogs.com/gif.latex?W%28r%2C%20h%29%20%3D%20%5Cfrac%7B10%7D%7B7%5Cpi%20h%5E%7B2%7D%7D%20%5Cbegin%7Bcases%7D%201%20-%20%5Cfrac%7B3%7D%7B2%7D%20q%5E2%20&plus;%20%5Cfrac%7B3%7D%7B4%7D%20q%5E3%20%26%20%5Ctext%7B%20if%20%7D%200%20%5Cleq%20q%20%5Cleq%201%5C%5C%20%5Cfrac%7B1%7D%7B4%7D%20%282%20-%20q%29%5E3%20%26%20%5Ctext%7B%20if%20%7D%201%20%5Cleq%20q%20%5Cleq%202%5C%5C%200%20%26%20%5Ctext%7B%20if%20%7D%20q%20%3E%202%20%5Cend%7Bcases%7D%20%5C%5C%20%5Ctext%7BWhere%20%7D%20q%20%3D%20%5Cfrac%7Br%7D%7Bh%7D)

-   **cubic\_spline\_first\_derivative(*double r[]*) (double):** Cubic Spline First
    Derivative calculation function.
    
    -   *r[]* contains the distance between two points.
        
        Calculates the cubic spline according to three cases:
    
![euqation](https://latex.codecogs.com/gif.latex?%5Cnabla%20W%28r%2C%20h%29%20%3D%20%5Cfrac%7B10%7D%7B7%5Cpi%20h%5E%7B3%7D%7D%20%5Cbegin%7Bcases%7D%20-3%20q%20&plus;%20%5Cfrac%7B9%7D%7B4%7D%20q%5E2%20%26%20%5Ctext%7B%20if%20%7D%200%20%5Cleq%20q%20%5Cleq%201%5C%5C%20-10%20%5Cfrac%7B3%7D%7B4%7D%20%282%20-%20q%29%5E2%20%26%20%5Ctext%7B%20if%20%7D%201%20%5Cleq%20q%20%5Cleq%202%5C%5C%200%20%26%20%5Ctext%7B%20if%20%7D%20q%20%3E%202%20%5Cend%7Bcases%7D%20%5C%5C%20%5Ctext%7BWhere%20%7D%20q%20%3D%20%5Cfrac%7Br%7D%7Bh%7D)

-   **update\_gradients(*double r[]*, *SPH\_particle\* part*, *SPH\_particle\* other\_part*) (void):** Updating the values of rate of change of speed (acceleration) and density.
    
    -   *part* is a pointer to the particle that we calculate the change
        for.
    -   *other\_part* is a pointer to the neighbouring particle used in the calculation.
        The calculations are done according to the following functions:
    
![equation](https://latex.codecogs.com/gif.latex?%5Calpha_i%20%3D%20-%20%5Csum_%7Bj%3D1%7D%5E%7BN%7D%20m_j%20%5CBig%28%5Cfrac%7BP_i%7D%7B%5Crho_i%5E2%7D%20&plus;%20%5Cfrac%7BP_j%7D%7B%5Crho_j%5E2%7D%20%5CBig%29%20%5Cfrac%7BdW%7D%7Bdr%7D%28r_%7Bij%7D%2Ch%29e_%7Bij%7D%20&plus;%20%5Csum_%7Bj%3D1%7D%5E%7BN%7D%20m_j%20%5CBig%28%20%5Cfrac%7B1%7D%7B%5Crho_i%5E2%7D%20&plus;%20%5Cfrac%7B1%7D%7B%5Crho_j%5E2%7D%20%5CBig%29%20%5Cfrac%7BdW%7D%7Bdr%7D%28r_%7Bij%7D%2C%20h%29%20%5Cfrac%7Bv_%7Bij%7D%7D%20%7Br_%7Bij%7D%7D)
    
![equation](https://latex.codecogs.com/gif.latex?D_i%20%3D%20%5Csum_%7Bj%3D1%7D%5E%7BN%7D%20m_j%20%5Cfrac%7BdW%7D%7Bdr%7D%28r_%7Bij%7D%2C%20h%29%20v_%7Bij%7D%20%5Ccdot%20e_%7Bij%7D)

-   **density\_field\_smoothing(*SPH\_particle\* part*) (void):** Smoothing out the
    Density/Pressure field. This is done because the integration of the continuity
    equation will result in variations in density and pressure based on the
    macroscopic velocity gradients, but also on local variations in particle
    spacing and velocity; resulting in a &ldquo;rough&rdquo; density and pressure
    distributions. To get around this problem, we implemented a density smoother.
    
    -   *part* is a pointer to the particle whose density is to be smoothed.
    
    ![equation](https://latex.codecogs.com/gif.latex?%5Crho_i%20%3D%20%5Cfrac%7B%5Csum_%7Bj%20%3D%201%7D%5E%7Bn%7D%20W%28r_%7Bij%7D%2Ch%29%7D%7B%20%5Csum_%7Bj%20%3D%201%7D%5E%7Bn%7D%20%5Cfrac%7BW%28r_%7Bij%7D%29%7D%7B%5Crho_j%7D%7D)
    
-   **set\_values(*double delta\_x*) (void):** Setting simulation parameters.
    -   *delta\_x* the distance between particles in the initial configuration.
-   **initialize\_grid(*void*) (void):** This function initializes the search grid
    used to find neighbours. This is done by dividing the points into cell grids
    of size double the initial distance between particles and allocating them to
    the corresponding cell.
-   **place\_points(*double min0*, *double min1*, *double max0*, *double max1*, *bool type*) (void):** This function is responsible for initializing the points to the domain, by
    setting all the variables (as defined in the *SPH\_particle* variables).
    -   *min0* minimum position value for the x-direction.
    -   *min1* minimum position value for the y-direction.
    -   *max0* maximum position value for the x-direction.
    -   *max1* maximum position value for the y-direction.
    -   *type* boolean that defines weather or not the particle is on the boundary.
-   **allocate\_to\_grid(*void*) (void):** Allocates all the points to the search grid
    (assumes that index has been appropriately updated). This function is called
    in every iteration step, as the movement of the particles might change their
    corresponding search grid cell.
-   **neighbour\_iterate(*SPH\_particle\* part*) (void):** The main function that
    searches the search grid to find the corresponding neighbours for the given
    particle.
    
    -   *part* the particle for which the neighbours are searched.
    
    !!!NEED TO ADD DESCRIPTION!!!!
-   **update\_particle(*SPH\_particle\* part*) (void):** Function that updates the
    position, velocity, density and pressure, according to the results of the
    *update\_gradients* functions.
    -   *part* the particle for which the variables are updated.
-   **reset\_grid\_count() (void):** This function resets the grid count of the domain
    after every iteration.
-   **update\_rho(*SPH\_particle\* part*) (void):** This function updates the density
    of the particle after each half and whole timestep.
    -   *part* the particle for which the density is updated.
-   **store\_initial(*SPH\_particle\* part*) (void):** eheheheh

-   **time\_dynamic() (void):** 

-   **full\_update(*SPH\_particle\* part*) (void):** 

-   **get\_new\_max(*SPH\_particle\* part*) (void):** 


<a id="org3350b24"></a>

# Running the Simulation, Post-processing and Output scripts

A sample C++ file (*SPH\_Snippet.cpp*) has been provided in the package that runs
the simulation for the parameters required for the class excericse. That file is
responsible for the entirety of the simulation and serves as a template for any
future simulations anyone would want to run using this tool. Moreover, a
number of post processing scripts have been implemented in C++ and Python for
the purpose of outputing the simulation states in a suitable format for both
visualization and data manipulation.


<a id="orga8ab8d1"></a>

## file\_writer.cpp

A simple C++ file that outputs simulation steps as *.vtp* files; to be used with
ParaView or other software that is build upon the *VTK* library.


<a id="org3218b37"></a>

## post.py

A simple Python script that takes the *.vtp* files created by *file\_writer.cpp*,
creates a Pandas DataFrame for every iteration step and outputs them in a HDF5
file (for easy data transport and data manipulation). A similar version of the
script is used in the testing pipeline in the step where the testing moves from
C++ to Python.


<a id="org4c3e822"></a>

# Testing

Testing on this tool is done by both C++ and Python. For C++ the BOOST library
is used and for Python a custom test file has been written.


<a id="org208fbb0"></a>

## C++ Testing

The C++ side of the testing handles all the mathematical functions defined in
the *SPH\_main* class. Namely *cubic\_spline*, *cubic\_spline\_first\_derivative* and
*update\_gradients*. A set of BOOST test cases has been set that depends on the
possible outputs of the spline functions. Note, that the same principle is
applied for *update\_gradients* as the cubic spline functions play an important
role in the calculation of acceleration and rate of change of pressure.
Moreover, the tests are conducted independently of the model parameters (as they
are defined in the *set\_vales* functions), by setting the desired parameters
before the function call.


<a id="org91c1fd2"></a>

## Python Testing

The Python part of the testing deals with validating the behaviour of the
simulator; checking that the particles stay within the boundaries and that the
particles are present at their proper positions after *N* iterations steps. This
part of the testing can be used for validating that the input parameters by the
user fall within the power of the simulator (ie that the simulator does not
become unstable).


<a id="orgbe3671e"></a>

## Testing pipeline

The teting pipeline goes as follows:

1.  The objects and C++ classes get compiled.
2.  The Python script *run\_tests.py* is being run, which is responsible for
    running both the C++ and Python tests.
3.  The C++ test file *test\_SPH\_2D.cpp* is run, followed by
    *test\_file\_writer.cpp* which outputs a set of *.vtp* files, containing the
    iteration steps of the test simulator.
4.  *test\_post.py* is called (a specialised version of *post.py*) which processes
    the *.vtp* files and creates the *output\_test.h5* file, containing all the
    Pandas DataFrames to be used by the Python part of the tests.
5.  *python\_tests.py* is run with *output\_test.h5* as input; completing a number
    of tests on the behaviour of the simulator.

**Note: The following commands are to be entered from the base repository of the package.**
The complete testing pipeline can be run by using:

    make runtests

To run only the C++ tests you can use:

    ./tests/bin/test_SPH_2D

The *&#x2013;log\_level=unit\_scope* flag can be used to give a detailed report of the
testing suite and *&#x2013;list\_content* provides the user for a description of each
testing case for easier debugging.

To produce the *.vtp* files you can use:

    ./tests/bin/test_file_writer

To produce the *.h5* test files you can use:

    python ./tests/test_post.py

(It goes without saying that the *.vtp* files need to already exist for the
*.h5* files to be produced.)


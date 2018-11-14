#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <fstream>
#include <mpi.h>
using namespace std;


int N;
double mu;
double sigma;
double generarGaussiana(double mu, double sigma);

int main(int argc, char** argv) {
	int world_size;
	int world_rank;
	char processor_name[MPI_MAX_PROCESSOR_NAME];
	int name_len;

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	MPI_Get_processor_name(processor_name, &name_len);



	N=atof(argv[1])/world_size;
	mu=atof(argv[2]);
	sigma=atof(argv[3]);
    	std::cout<<"Procesador:"<<world_rank<<"\n";

	double *dist=new double[N];
	for(int i=0;i<N;i++)
	{
		dist[i]=generarGaussiana(mu,sigma);
	}	

	ofstream myfile;

	char buffer [50];
	sprintf (buffer, "sample_%d.dat",world_rank);
	
	myfile.open (buffer);
	
	for(int i=0;i<N;i++)
	{
		myfile << dist[i]<<"\n";
		N=N-1;
	}

	myfile.close();

	MPI_Finalize();
}


double generarGaussiana(double mu, double sigma)
{

	static const double epsilon = std::numeric_limits<double>::min();
	static const double two_pi = 2.0*3.14159265358979323846;

	double z1;
	bool generate;
	generate = !generate;

	if (!generate)
	   return z1 * sigma + mu;

	double u1, u2;
	do
	 {
	   u1 = rand() * (1.0 / RAND_MAX);
	   u2 = rand() * (1.0 / RAND_MAX);
	 }
	while ( u1 <= epsilon );

	double z0;
	z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2);
	z1 = sqrt(-2.0 * log(u1)) * sin(two_pi * u2);
	return z0 * sigma + mu;
}



#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define INTERVAL 1000000

int main() {
	MPI_Init(NULL,NULL);
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD,&world_rank);
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD,&world_size);

	if (world_size != 2) {
		fprintf(stderr,"World size must be two");
		MPI_Abort(MPI_COMM_WORLD,1);
	}

	srand(time(NULL));
	if (world_rank != 0) {
		int circlePoints = 0;
		int squarePoints = 0;
		double randX,randY, originDist;
		for (int i = 0; i < INTERVAL; i++) {
			randX = (double) rand() / RAND_MAX;
			randY = (double) rand() / RAND_MAX;
			originDist = randX*randX + randY*randY;
			if (originDist <= 1) { circlePoints++; }
			squarePoints++;
		}
		MPI_Send(&circlePoints,1,MPI_INT,0,1,MPI_COMM_WORLD);
		MPI_Send(&squarePoints,1,MPI_INT,0,1,MPI_COMM_WORLD);
		
	} else if (world_rank == 0) {
		int m;
		int n;
		double pi;
		MPI_Recv(&m,1, MPI_INT,MPI_ANY_SOURCE,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		MPI_Recv(&n,1, MPI_INT,MPI_ANY_SOURCE,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		pi = 4.0*(double)m/n;
		printf("PI value is: %lf\n",pi);
	}
	MPI_Finalize();
	return 0;
}

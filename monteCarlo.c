#include <stdio.h>
#include <stdlib.h>
#define INTERVAL 1000000

int main() {
	double randX,randY, originDist, pi;
	float circlePoints, totalPoints;
	time_t t;

	//initialize
	srand((unsigned)time(&t));
	circlePoints = 0;
	totalPoints = 0;

	for (int i = 0; i < INTERVAL; i++) {
		randX = (double) rand() / RAND_MAX;
		randY = (double) rand() / RAND_MAX;
		originDist = randX*randX + randY*randY;
		if (originDist <= 1) { circlePoints++; }
	}
	pi = 4.0 * (double)(circlePoints / INTERVAL);
	printf("PI value is: %lf \n",pi);
	return 0;
}

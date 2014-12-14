#include <stdio.h>
#include <math.h>

#define ROWS 80
#define COLS 81

#define RMAX 20.0
#define RMIN 10.0

#define VPTOUR 1.2
#define PAS 0.05

int fy(double i) {
	double rayvar = (RMIN + (RMAX - RMIN) / 2.0 + (RMAX + RMIN) / 2.0 * sin(i * VPTOUR));
	return floor(ROWS / 2 + rayvar * sin(i));
}

int fx(double i) {
	double rayvar = (RMIN + (RMAX - RMIN) / 2.0 + (RMAX + RMIN) / 2.0 * sin(i * VPTOUR));
	return floor(COLS / 2 + rayvar * cos(i));
}

static char tab[ROWS][COLS] = {[0 ... ROWS - 1] = {[0 ... COLS - 2] = ' ', '\n'}};

int main(void) {
	int i, j;
	double f;
	
	// Remplissage du tableau par des # selon deux fonctions fx et fy
	for (f = 0.0; f < 1000.0; f += PAS) {
		int x = fx(f);
		int y = fy(f);
		/* printf("%d, %d\n", x, y); */
		tab[x][y] = '#';
	}
	
	// Affichage du tableau
	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLS; j++)
			printf("%c", tab[i][j]);

	return 0;
}

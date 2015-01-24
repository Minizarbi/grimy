#include <stdio.h>
#include <math.h>
#include <stropts.h>
#include <termio.h>

#define ROWS 80
#define COLS 81

#define RMAX 18.0
#define RMIN 9.0

#define VPTOUR 1.1
#define PAS 0.05

extern int usleep (__useconds_t __useconds);

static int fx(double i) {
	double rayvar = (RMIN + (RMAX - RMIN) / 2.0 + (RMAX + RMIN) / 2.0 * sin(i * VPTOUR));
	return floor(ROWS / 2 + rayvar * sin(i)) - RMIN;
}

static int fy(double i) {
	double rayvar = (RMIN + (RMAX - RMIN) / 2.0 + (RMAX + RMIN) / 2.0 * sin(i * VPTOUR));
	return floor(COLS / 2 + rayvar * cos(i));
}

int main(void) {
	double f;
	struct termios oldT, newT;
	char c;

	ioctl(0,TCGETS,&oldT); /*get current mode*/

	newT=oldT;

	newT.c_lflag &= ~ECHO; /* echo off */
	newT.c_lflag &= ~ICANON; /*one char @ a time*/
	
	ioctl(0,TCSETS,&newT); /* set new terminal mode */
	
	// Remplissage du tableau par des # selon deux fonctions fx et fy
	for (f = 0.0; f < 1000.0; f += PAS) {
		int x = fx(f);
		int y = fy(f);

		fflush(stdout);
		printf("[%d;%dH%c", x, y, getchar());
	}

	ioctl(0,TCSETS,&oldT); /* restore previous terminal mode */
	
	return 0;
}

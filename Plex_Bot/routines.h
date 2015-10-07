/*
**
**Holds all of the walking stepper motions
**
*/


#ifndef routines_h
#define routines_h

#define SERVOS 10
#define LWALKSTEPS 30
#define RWALKSTEPS 30

//Only concerened with the 5 leg servoes for left and right. 
int lWalk[LWALKSTEPS*SERVOS] = {
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ,
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ,
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ,
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9
};

int rWalk[RWALKSTEPS*SERVOS] = {
	 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ,
	 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ,
	 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ,
	 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 
};

#endif
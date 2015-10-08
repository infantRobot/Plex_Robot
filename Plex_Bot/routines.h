/*
**
**Holds all of the walking stepper motions
**
*/


#ifndef routines_h
#define routines_h

#define SERVOS 10
#define LWALKSTEPS 16
#define RWALKSTEPS 16

//Only concerened with the 5 leg servoes for left and right. 
int rWalk[RWALKSTEPS*SERVOS] = {
//r_ankle r_shin r_knee	r_thigh	r_hip	 l_ankl	 l_shin	 l_knee	 l_thigh  l_hip
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
	10	,	0	,	0	,	0	,	-10	,	-10	,	0	,	0	,	0	,	10	,
	10	,	0	,	0	,	0	,	-10	,	-10	,	0	,	-20	,	20	,	10	,
	10	,	10	,	0	,	0	,	-10	,	-10	,	0	,	-40	,	20	,	10	,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	-40	,	20	,	0	,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0

};

int lWalk[LWALKSTEPS*SERVOS] = {
	 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ,
	 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ,
	 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ,
	 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 
};

#endif
/* Copyright (c) 1991 Regents of the University of California */

#ifndef lint
static char SCCSid[] = "$SunId$ LBL";
#endif

/*
 * Return system page size for non-BSD machine.
 */

#ifndef BSD

#if defined(_AUX_SOURCE)	/* Apple's A/UX */

#include <sys/var.h>
int
getpagesize()			/* use var structure to get page size */
{
	struct var  v;
	uvar(&v);
	return(1 << v.v_pageshift);
}

#elif defined(hpux)		/* Hewlett Packard's HPUX */

#include <machine/param.h>
int
getpagesize()
{
return(NBPG_PA83);	/* This is supposed to be ok for PA-RISC 1.0, but
				I don't know about 1.1 (i.e. Snakes) */
}

#else				/* Unknown version of UNIX */

#ifndef PAGESIZE
#define PAGESIZE	8192		/* Guess on the high side */
#endif
int
getpagesize()
{
	return(PAGESIZE);
}

#endif

#endif /* !BSD */

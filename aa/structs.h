/*
 * Structures and variables for common use
 */

#include "extern.h"

/*
	DTAB :  Table to hold variable names.
		The structure is :
*/

struct	dtab	{
	int	addr;
		struct	dout	{
			char	var_name[MAXVAR];
			int	var_len;
		} d_out ;
	struct	dtab	*next;
	};

/*
	ETAB :	Table to hold the entry points from import export
		and procedures
*/
	

struct	etab	{
	int	ecnt;
		struct	eout	{
			char	type;
			char	ep_name[MAXVAR];
			int	addr;
		} e_out ;
	struct	etab	*next;
	};

/*
	RTAB :	Table to hold the relocation references of
		instrunction in ITAB
*/


struct	rtab	{
		struct	rout	{
			char	rel_ref;
			int	i_addr;
		} r_out ;
	struct	rtab	*next;
	};

/*
	ITAB : table to hold the instructions ( Instruction bank )
*/

int	itab[MAXITAB];


/*
	LTAB : table to hold the label addresses
*/

struct	ltab	{
		int	addr;
		char	lab_name[MAXVAR];
		struct	ltab	*next;
	};

/*
	ULTAB : table to hold undefined label addresses
		while they are not defined
*/

struct	ultab	{
		int	i_addr;
		char	lab_name[MAXVAR];
		struct	ultab	*next;
	};

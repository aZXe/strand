/*--------- definition of data structures and function prototypes ----------*/

#define BYTE unsigned char

// file codes (signatures) recognized by STATISTICA 5 (and this demo):
#define  CSS_CODE       (-9876L)
#define  CSSW_CODE      (-9877L)
#define  CSS_CODE_EX    (-9869L)
#define  CSSW5_CODE     (-9858L)

// maximum number of variables in STATISTICA file:
#define  MAX_CSS_VARS       4092

struct HeadTag {
	char 	Title[4];		/* title identifier - "CSS " */
	long	Code;				/* see above */
	long	NC;				/* number of cases */
	long	NV;				/* number of variables */
	long	Prec;				/* precision 4B or 8B (always 8B for ver5 files) */
	long	NArr;				/* number of description arrays (from 5 to 8)*/
	int	NCLen;			/* length of addit. information - currently 20 */
	int	HLen;				/* length of header - currently 80 */
	int	VLen;				/* total length of variable names - 8 * NV */
	int	FLen;				/* total length of variable formats - 2 * NV */
	int	MDLen;			/* total length of variable MD codes - Prec * NV */
	int	SL1Len;			/* total length of first alpha descr. table - present
									only if NArr >= 6 */
	int	SL2Len;			/* total length of second alpha descr. table - present
									only if NArr >= 7 */
	int	SL3Len;			/* total length of third alpha descr. table - present
									only if NArr >= 8 */
};

#define SizeFH  (sizeof(struct HeadTag))

struct InfoTag {
	long	MemVar;			/* total length of variable long names (labels/formulas) */
	long	MemSvl;			/* total length of short alpha information */
	long	MemLvl;			/* total length of long alpha information */
	long	LCName;			/* length of case name (up to 20) */
	long	ExtraInfo;		/* reserved (must by 0) for CSS3, or length of 
                           extra info for STAT/W */
};

#define	SizeFI 	(sizeof(struct InfoTag))

struct FmTag {
	char 	Nz,		/* length of field */
			Nd;		/* number of decimal places */
};

union ValueTag {
	double	d;		
	float		f;
};

struct LabTag {
	float	V;		/* value of variable */
	char	T[8];	/* alphanumeric for that value */
	int	Offs;	/* offset for long label for that value */
};

#define SizeLT	sizeof(struct LabTag)

/*--------------------------- function prototypes --------------------------*/

int	main(int  argc,char  * *argv);
void	InitInputFile(void);
void	PrintInputInfo(void);
void	CreateOutputHeader(void);
void	ProcessData(void);
void fcopy( FILE * out, FILE * in, unsigned int size );
void Ceil512( long * pL );

/*--------------------------------------------------------------------------*/

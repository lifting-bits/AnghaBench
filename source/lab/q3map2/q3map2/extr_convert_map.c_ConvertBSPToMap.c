#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  vec3_t ;
typedef  int /*<<< orphan*/  entity_t ;
typedef  int /*<<< orphan*/  bspModel_t ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  ConvertEPairs (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ConvertModel (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Error (char*,char*) ; 
 int /*<<< orphan*/  ExtractFileBase (char*,char*) ; 
 int /*<<< orphan*/  GetVectorForKey (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  StripExtension (char*) ; 
 int /*<<< orphan*/  Sys_Printf (char*,...) ; 
 char* ValueForKey (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  VectorClear (int /*<<< orphan*/ ) ; 
 int atoi (char const*) ; 
 int /*<<< orphan*/ * bspModels ; 
 int /*<<< orphan*/ * entities ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char*,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ *,char*,...) ; 
 int numEntities ; 
 int /*<<< orphan*/  strcat (char*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 

int ConvertBSPToMap( char *bspName ){
	int i, modelNum;
	FILE            *f;
	bspModel_t      *model;
	entity_t        *e;
	vec3_t origin;
	const char      *value;
	char name[ 1024 ], base[ 1024 ];


	/* note it */
	Sys_Printf( "--- Convert BSP to MAP ---\n" );

	/* create the bsp filename from the bsp name */
	strcpy( name, bspName );
	StripExtension( name );
	strcat( name, "_converted.map" );
	Sys_Printf( "writing %s\n", name );

	ExtractFileBase( bspName, base );
	strcat( base, ".bsp" );

	/* open it */
	f = fopen( name, "wb" );
	if ( f == NULL ) {
		Error( "Open failed on %s\n", name );
	}

	/* print header */
	fprintf( f, "// Generated by Q3Map2 (ydnar) -convert -format map\n" );

	/* walk entity list */
	for ( i = 0; i < numEntities; i++ )
	{
		/* get entity */
		e = &entities[ i ];

		/* start entity */
		fprintf( f, "// entity %d\n", i );
		fprintf( f, "{\n" );

		/* export keys */
		ConvertEPairs( f, e );
		fprintf( f, "\n" );

		/* get model num */
		if ( i == 0 ) {
			modelNum = 0;
		}
		else
		{
			value = ValueForKey( e, "model" );
			if ( value[ 0 ] == '*' ) {
				modelNum = atoi( value + 1 );
			}
			else{
				modelNum = -1;
			}
		}

		/* only handle bsp models */
		if ( modelNum >= 0 ) {
			/* get model */
			model = &bspModels[ modelNum ];

			/* get entity origin */
			value = ValueForKey( e, "origin" );
			if ( value[ 0 ] == '\0' ) {
				VectorClear( origin );
			}
			else{
				GetVectorForKey( e, "origin", origin );
			}

			/* convert model */
			ConvertModel( f, model, modelNum, origin );
		}

		/* end entity */
		fprintf( f, "}\n\n" );
	}

	/* close the file and return */
	fclose( f );

	/* return to sender */
	return 0;
}
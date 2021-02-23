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
typedef  int /*<<< orphan*/  uint8 ;
typedef  int /*<<< orphan*/  float64 ;

/* Variables and functions */
 int /*<<< orphan*/  fputc (char,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fputs (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stdout ; 
 char* testName ; 
 char* trueName ; 
 int /*<<< orphan*/  writeHex_float64 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writeHex_float_flags (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
 writeOutputs_z_float64(
     float64 trueZ, uint8 trueFlags, float64 testZ, uint8 testFlags )
{

    fputs( trueName, stdout );
    fputs( ": ", stdout );
    writeHex_float64( trueZ, stdout );
    fputc( ' ', stdout );
    writeHex_float_flags( trueFlags, stdout );
    fputs( "  ", stdout );
    fputs( testName, stdout );
    fputs( ": ", stdout );
    writeHex_float64( testZ, stdout );
    fputc( ' ', stdout );
    writeHex_float_flags( testFlags, stdout );
    fputc( '\n', stdout );

}
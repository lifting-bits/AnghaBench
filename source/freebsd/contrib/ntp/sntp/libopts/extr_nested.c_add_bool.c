#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {unsigned int boolVal; } ;
struct TYPE_7__ {char* pzName; int /*<<< orphan*/  valType; TYPE_1__ v; } ;
typedef  TYPE_2__ tOptionValue ;

/* Variables and functions */
 TYPE_2__* AGALOC (size_t,char*) ; 
 scalar_t__ IS_DEC_DIGIT_CHAR (char const) ; 
 int /*<<< orphan*/  IS_FALSE_TYPE_CHAR (char const) ; 
 scalar_t__ IS_WHITESPACE_CHAR (char const) ; 
 char NUL ; 
 int /*<<< orphan*/  OPARG_TYPE_BOOLEAN ; 
 int /*<<< orphan*/  addArgListEntry (void**,TYPE_2__*) ; 
 scalar_t__ atoi (char const*) ; 
 int /*<<< orphan*/  memcpy (char*,char const*,size_t) ; 

__attribute__((used)) static tOptionValue *
add_bool(void ** pp, char const * name, size_t nm_len,
         char const * val, size_t d_len)
{
    size_t sz = nm_len + sizeof(tOptionValue) + 1;
    tOptionValue * new_val = AGALOC(sz, "bool val");

    /*
     * Scan over whitespace is constrained by "d_len"
     */
    while (IS_WHITESPACE_CHAR(*val) && (d_len > 0)) {
        d_len--; val++;
    }

    if (d_len == 0)
        new_val->v.boolVal = 0;

    else if (IS_DEC_DIGIT_CHAR(*val))
        new_val->v.boolVal = (unsigned)atoi(val);

    else new_val->v.boolVal = ! IS_FALSE_TYPE_CHAR(*val);

    new_val->valType = OPARG_TYPE_BOOLEAN;
    new_val->pzName = (char *)(new_val + 1);
    memcpy(new_val->pzName, name, nm_len);
    new_val->pzName[ nm_len ] = NUL;
    addArgListEntry(pp, new_val);
    return new_val;
}
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
typedef  int utf8proc_int32_t ;
typedef  int /*<<< orphan*/  utf8proc_bool ;

/* Variables and functions */
 int UTF8PROC_BOUNDCLASS_EXTEND ; 
 int UTF8PROC_BOUNDCLASS_EXTENDED_PICTOGRAPHIC ; 
 int UTF8PROC_BOUNDCLASS_E_ZWG ; 
 int UTF8PROC_BOUNDCLASS_OTHER ; 
 int UTF8PROC_BOUNDCLASS_REGIONAL_INDICATOR ; 
 int UTF8PROC_BOUNDCLASS_START ; 
 int UTF8PROC_BOUNDCLASS_ZWJ ; 
 int /*<<< orphan*/  grapheme_break_simple (int,int) ; 

__attribute__((used)) static utf8proc_bool grapheme_break_extended(int lbc, int tbc, utf8proc_int32_t *state)
{
  int lbc_override = ((state && *state != UTF8PROC_BOUNDCLASS_START)
                      ? *state : lbc);
  utf8proc_bool break_permitted = grapheme_break_simple(lbc_override, tbc);
  if (state) {
    // Special support for GB 12/13 made possible by GB999. After two RI
    // class codepoints we want to force a break. Do this by resetting the
    // second RI's bound class to UTF8PROC_BOUNDCLASS_OTHER, to force a break
    // after that character according to GB999 (unless of course such a break is
    // forbidden by a different rule such as GB9).
    if (*state == tbc && tbc == UTF8PROC_BOUNDCLASS_REGIONAL_INDICATOR)
      *state = UTF8PROC_BOUNDCLASS_OTHER;
    // Special support for GB11 (emoji extend* zwj / emoji)
    else if (*state == UTF8PROC_BOUNDCLASS_EXTENDED_PICTOGRAPHIC) {
      if (tbc == UTF8PROC_BOUNDCLASS_EXTEND) // fold EXTEND codepoints into emoji
        *state = UTF8PROC_BOUNDCLASS_EXTENDED_PICTOGRAPHIC;
      else if (tbc == UTF8PROC_BOUNDCLASS_ZWJ)
        *state = UTF8PROC_BOUNDCLASS_E_ZWG; // state to record emoji+zwg combo
      else
        *state = tbc;
    }
    else
      *state = tbc;
  }
  return break_permitted;
}
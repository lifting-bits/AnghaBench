#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
typedef  char gchar ;
struct TYPE_3__ {int* cbp; int /*<<< orphan*/  bpListStore; } ;
typedef  TYPE_1__ YuiM68k ;
typedef  int /*<<< orphan*/  GtkTreeIter ;
typedef  int /*<<< orphan*/  GtkCellRendererText ;

/* Variables and functions */
 int /*<<< orphan*/  GTK_LIST_STORE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GTK_TREE_MODEL (int /*<<< orphan*/ ) ; 
 scalar_t__ M68KAddCodeBreakpoint (int) ; 
 int /*<<< orphan*/  M68KDelCodeBreakpoint (int) ; 
 int atoi (char*) ; 
 int /*<<< orphan*/  gtk_list_store_set (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  gtk_tree_model_get_iter_from_string (int /*<<< orphan*/ ,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 int strlen (char*) ; 
 int strtoul (char*,char**,int) ; 

__attribute__((used)) static void yui_m68k_editedBp( GtkCellRendererText *cellrenderertext,
			     gchar *arg1,
			     gchar *arg2,
			     YuiM68k *m68k) {
  /* breakpoint <arg1> has been set to address <arg2> */

  GtkTreeIter iter;
  char bptext[10];
  char *endptr;
  int i = atoi(arg1);
  u32 addr;
  gtk_tree_model_get_iter_from_string( GTK_TREE_MODEL( m68k->bpListStore ), &iter, arg1 );
  addr = strtoul(arg2, &endptr, 16 );
  if ((endptr - arg2 < strlen(arg2)) || (!addr)) addr = 0xFFFFFFFF;
  if ( m68k->cbp[i] != 0xFFFFFFFF) M68KDelCodeBreakpoint(m68k->cbp[i]);
  m68k->cbp[i] = 0xFFFFFFFF;

  if ((addr!=0xFFFFFFFF)&&(M68KAddCodeBreakpoint(addr) == 0)) {
   
    sprintf(bptext, "%08X", (int)addr);
    m68k->cbp[i] = addr;
  } else strcpy(bptext,"<empty>");
  gtk_list_store_set( GTK_LIST_STORE( m68k->bpListStore ), &iter, 0, bptext, -1 );
}
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
typedef  char mpc_val_t ;

/* Variables and functions */
 char* calloc (int,int) ; 
 char* realloc (char*,scalar_t__) ; 
 int /*<<< orphan*/  strcat (char*,char*) ; 
 scalar_t__ strlen (char*) ; 

__attribute__((used)) static mpc_val_t *mpcf_unescape_new(mpc_val_t *x, const char *input, const char **output) {
  
  int i;
  int found = 0;
  char buff[2];
  char *s = x;
  char *y = calloc(1, 1);
  
  while (*s) {
    
    i = 0;
    found = 0;
    
    while (output[i]) {
      if ((*(s+0)) == output[i][0] &&
          (*(s+1)) == output[i][1]) {
        y = realloc(y, strlen(y) + 1 + 1);
        buff[0] = input[i]; buff[1] = '\0';
        strcat(y, buff);
        found = 1;
        s++;
        break;
      }
      i++;
    }
    
    if (!found) {
      y = realloc(y, strlen(y) + 1 + 1);
      buff[0] = *s; buff[1] = '\0';
      strcat(y, buff);
    }
    
    if (*s == '\0') { break; }
    else { s++; }
  }
  
  return y;
  
}
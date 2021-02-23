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
struct TYPE_3__ {long comments; char** user_comments; } ;
typedef  TYPE_1__ vorbis_comment ;

/* Variables and functions */
 char* alloca (int) ; 
 int /*<<< orphan*/  strcat (char*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,char const*) ; 
 int strlen (char const*) ; 
 int /*<<< orphan*/  tagcompare (char*,char*,int) ; 

char *vorbis_comment_query(vorbis_comment *vc, const char *tag, int count){
  long i;
  int found = 0;
  int taglen = strlen(tag)+1; /* +1 for the = we append */
  char *fulltag = alloca(taglen+ 1);

  strcpy(fulltag, tag);
  strcat(fulltag, "=");

  for(i=0;i<vc->comments;i++){
    if(!tagcompare(vc->user_comments[i], fulltag, taglen)){
      if(count == found)
        /* We return a pointer to the data, not a copy */
              return vc->user_comments[i] + taglen;
      else
        found++;
    }
  }
  return NULL; /* didn't find anything */
}
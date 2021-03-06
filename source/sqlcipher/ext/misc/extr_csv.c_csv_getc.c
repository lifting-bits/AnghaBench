#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {scalar_t__ iIn; scalar_t__ nIn; scalar_t__ in; scalar_t__ zIn; } ;
typedef  TYPE_1__ CsvReader ;

/* Variables and functions */
 int EOF ; 
 int csv_getc_refill (TYPE_1__*) ; 

__attribute__((used)) static int csv_getc(CsvReader *p){
  if( p->iIn >= p->nIn ){
    if( p->in!=0 ) return csv_getc_refill(p);
    return EOF;
  }
  return ((unsigned char*)p->zIn)[p->iIn++];
}
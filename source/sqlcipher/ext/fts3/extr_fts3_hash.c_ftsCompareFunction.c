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

/* Variables and functions */
 int FTS3_HASH_BINARY ; 
 int FTS3_HASH_STRING ; 
 int /*<<< orphan*/  assert (int) ; 
 int fts3BinCompare (void const*,int,void const*,int) ; 
 int fts3StrCompare (void const*,int,void const*,int) ; 

__attribute__((used)) static int (*ftsCompareFunction(int keyClass))(const void*,int,const void*,int){
  if( keyClass==FTS3_HASH_STRING ){
    return &fts3StrCompare;
  }else{
    assert( keyClass==FTS3_HASH_BINARY );
    return &fts3BinCompare;
  }
}
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
typedef  int /*<<< orphan*/  uint8_t ;
struct params_s {scalar_t__ lavc; int /*<<< orphan*/  codec; } ;

/* Variables and functions */
 int /*<<< orphan*/  EXPECT (int) ; 
 int OK ; 
 scalar_t__ xiph_IsLavcFormat (int /*<<< orphan*/  const*,size_t,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int test_xiph_IsLavcFormat(const char *run,
                 const uint8_t *p_extra, size_t i_extra,
                 const struct params_s *source)
{
    EXPECT(xiph_IsLavcFormat(p_extra, i_extra, source->codec) == source->lavc);
    return OK;
}
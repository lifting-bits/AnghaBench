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
typedef  int /*<<< orphan*/  system_ids_t ;

/* Variables and functions */
 size_t CopyDescriptors (int /*<<< orphan*/  const*,size_t,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static size_t GetCADSize( const system_ids_t *p_ids,
                          const uint8_t *p_drdata, size_t i_drdata )
{
    return CopyDescriptors( p_drdata, i_drdata, p_ids, NULL );
}
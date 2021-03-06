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
typedef  int /*<<< orphan*/  FT_String ;
typedef  int /*<<< orphan*/  FT_Module_Interface ;
typedef  int /*<<< orphan*/  FT_Module ;

/* Variables and functions */
 int /*<<< orphan*/  FT_UNUSED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ft_service_list_lookup (int /*<<< orphan*/ ,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  winfnt_services ; 

__attribute__((used)) static FT_Module_Interface
  winfnt_get_service( FT_Module         module,
                      const FT_String*  service_id )
  {
    FT_UNUSED( module );

    return ft_service_list_lookup( winfnt_services, service_id );
  }
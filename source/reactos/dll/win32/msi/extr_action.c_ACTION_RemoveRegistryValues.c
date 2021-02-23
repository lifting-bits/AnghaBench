#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  char WCHAR ;
typedef  scalar_t__ UINT ;
struct TYPE_8__ {int /*<<< orphan*/  db; } ;
struct TYPE_7__ {int /*<<< orphan*/  hdr; } ;
typedef  TYPE_1__ MSIQUERY ;
typedef  TYPE_2__ MSIPACKAGE ;

/* Variables and functions */
 scalar_t__ ERROR_SUCCESS ; 
 int /*<<< orphan*/  ITERATE_RemoveRegistryValuesOnInstall ; 
 int /*<<< orphan*/  ITERATE_RemoveRegistryValuesOnUninstall ; 
 scalar_t__ MSI_DatabaseOpenViewW (int /*<<< orphan*/ ,char const*,TYPE_1__**) ; 
 scalar_t__ MSI_IterateRecords (TYPE_1__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  msiobj_release (int /*<<< orphan*/ *) ; 

__attribute__((used)) static UINT ACTION_RemoveRegistryValues( MSIPACKAGE *package )
{
    static const WCHAR registry_query[] = {
        'S','E','L','E','C','T',' ','*',' ','F','R','O','M',' ',
        '`','R','e','g','i','s','t','r','y','`',0};
    static const WCHAR remove_registry_query[] = {
        'S','E','L','E','C','T',' ','*',' ','F','R','O','M',' ',
        '`','R','e','m','o','v','e','R','e','g','i','s','t','r','y','`',0};
    MSIQUERY *view;
    UINT rc;

    rc = MSI_DatabaseOpenViewW( package->db, registry_query, &view );
    if (rc == ERROR_SUCCESS)
    {
        rc = MSI_IterateRecords( view, NULL, ITERATE_RemoveRegistryValuesOnUninstall, package );
        msiobj_release( &view->hdr );
        if (rc != ERROR_SUCCESS)
            return rc;
    }
    rc = MSI_DatabaseOpenViewW( package->db, remove_registry_query, &view );
    if (rc == ERROR_SUCCESS)
    {
        rc = MSI_IterateRecords( view, NULL, ITERATE_RemoveRegistryValuesOnInstall, package );
        msiobj_release( &view->hdr );
        if (rc != ERROR_SUCCESS)
            return rc;
    }
    return ERROR_SUCCESS;
}
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
typedef  int /*<<< orphan*/  apr_pool_t ;
typedef  int /*<<< orphan*/  apr_dbd_t ;
typedef  int /*<<< orphan*/  apr_dbd_row_t ;
typedef  int /*<<< orphan*/  apr_dbd_results_t ;
typedef  int /*<<< orphan*/  apr_dbd_driver_t ;

/* Variables and functions */
 char* apr_dbd_error (int /*<<< orphan*/  const*,int /*<<< orphan*/ *,int) ; 
 char* apr_dbd_get_entry (int /*<<< orphan*/  const*,int /*<<< orphan*/ *,int) ; 
 int apr_dbd_get_row (int /*<<< orphan*/  const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ **,int) ; 
 int apr_dbd_num_cols (int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 int apr_dbd_select (int /*<<< orphan*/  const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ **,char const*,int) ; 
 int /*<<< orphan*/  fputs (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  stdout ; 

__attribute__((used)) static int select_random(apr_pool_t* pool, apr_dbd_t* handle,
                         const apr_dbd_driver_t* driver)
{
    int rv = 0;
    int n;
    const char* entry;
    const char* statement = "SELECT * FROM apr_dbd_test ORDER BY col1, col2";
    apr_dbd_results_t *res = NULL;
    apr_dbd_row_t *row = NULL;
    rv = apr_dbd_select(driver,pool,handle,&res,statement,1);
    if (rv) {
        printf("Select failed: %s", apr_dbd_error(driver, handle, rv));
        return rv;
    }
    rv = apr_dbd_get_row(driver, pool, res, &row, 5) ;
    if (rv) {
        printf("get_row failed: %s", apr_dbd_error(driver, handle, rv));
        return rv;
    }
    printf("ROW 5:	");
    for (n = 0; n < apr_dbd_num_cols(driver, res); ++n) {
        entry = apr_dbd_get_entry(driver, row, n);
        if (entry == NULL) {
            printf("(null)	") ;
        }
        else {
            printf("%s	", entry);
        }
    }
    fputs("\n", stdout);
    rv = apr_dbd_get_row(driver, pool, res, &row, 1) ;
    if (rv) {
        printf("get_row failed: %s", apr_dbd_error(driver, handle, rv));
        return rv;
    }
    printf("ROW 1:	");
    for (n = 0; n < apr_dbd_num_cols(driver, res); ++n) {
        entry = apr_dbd_get_entry(driver, row, n);
        if (entry == NULL) {
            printf("(null)	") ;
        }
        else {
            printf("%s	", entry);
        }
    }
    fputs("\n", stdout);
    rv = apr_dbd_get_row(driver, pool, res, &row, 11) ;
    if (rv != -1) {
        printf("Oops!  get_row out of range but thinks it succeeded!\n%s\n",
                apr_dbd_error(driver, handle, rv));
        return -1;
    }
    rv = 0;

    return rv;
}
#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zval ;
typedef  double zend_long ;
typedef  TYPE_2__* xmlNodePtr ;
typedef  int /*<<< orphan*/  encodeTypePtr ;
struct TYPE_6__ {TYPE_1__* children; } ;
struct TYPE_5__ {scalar_t__ type; scalar_t__ content; int /*<<< orphan*/ * next; } ;

/* Variables and functions */
 int /*<<< orphan*/  E_ERROR ; 
 int /*<<< orphan*/  FIND_XML_NULL (TYPE_2__*,int /*<<< orphan*/ *) ; 
#define  IS_DOUBLE 129 
#define  IS_LONG 128 
 scalar_t__ XML_TEXT_NODE ; 
 int /*<<< orphan*/  ZVAL_DOUBLE (int /*<<< orphan*/ *,double) ; 
 int /*<<< orphan*/  ZVAL_NULL (int /*<<< orphan*/ *) ; 
 int is_numeric_string (char*,int /*<<< orphan*/ ,double*,double*,int /*<<< orphan*/ ) ; 
 double php_get_inf () ; 
 double php_get_nan () ; 
 int /*<<< orphan*/  soap_error0 (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  strlen (char*) ; 
 int /*<<< orphan*/  strncasecmp (char*,char*,int) ; 
 int /*<<< orphan*/  whiteSpace_collapse (scalar_t__) ; 

__attribute__((used)) static zval *to_zval_double(zval *ret, encodeTypePtr type, xmlNodePtr data)
{
	ZVAL_NULL(ret);
	FIND_XML_NULL(data, ret);

	if (data && data->children) {
		if (data->children->type == XML_TEXT_NODE && data->children->next == NULL) {
			zend_long lval;
			double dval;

			whiteSpace_collapse(data->children->content);
			switch (is_numeric_string((char*)data->children->content, strlen((char*)data->children->content), &lval, &dval, 0)) {
				case IS_LONG:
					ZVAL_DOUBLE(ret, lval);
					break;
				case IS_DOUBLE:
					ZVAL_DOUBLE(ret, dval);
					break;
				default:
					if (strncasecmp((char*)data->children->content, "NaN", sizeof("NaN")-1) == 0) {
						ZVAL_DOUBLE(ret, php_get_nan());
					} else if (strncasecmp((char*)data->children->content, "INF", sizeof("INF")-1) == 0) {
						ZVAL_DOUBLE(ret, php_get_inf());
					} else if (strncasecmp((char*)data->children->content, "-INF", sizeof("-INF")-1) == 0) {
						ZVAL_DOUBLE(ret, -php_get_inf());
					} else {
						soap_error0(E_ERROR, "Encoding: Violation of encoding rules");
					}
			}
		} else {
			soap_error0(E_ERROR, "Encoding: Violation of encoding rules");
		}
	} else {
		ZVAL_NULL(ret);
	}
	return ret;
}
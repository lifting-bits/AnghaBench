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
struct TYPE_3__ {int /*<<< orphan*/ * reject; } ;
typedef  TYPE_1__ X509_CERT_AUX ;
typedef  int /*<<< orphan*/  X509 ;
typedef  int /*<<< orphan*/  ASN1_OBJECT ;

/* Variables and functions */
 int /*<<< orphan*/  ASN1_OBJECT_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * OBJ_dup (int /*<<< orphan*/  const*) ; 
 TYPE_1__* aux_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * sk_ASN1_OBJECT_new_null () ; 
 int sk_ASN1_OBJECT_push (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

int X509_add1_reject_object(X509 *x, const ASN1_OBJECT *obj)
{
    X509_CERT_AUX *aux;
    ASN1_OBJECT *objtmp;
    if ((objtmp = OBJ_dup(obj)) == NULL)
        return 0;
    if ((aux = aux_get(x)) == NULL)
        goto err;
    if (aux->reject == NULL
        && (aux->reject = sk_ASN1_OBJECT_new_null()) == NULL)
        goto err;
    return sk_ASN1_OBJECT_push(aux->reject, objtmp);
 err:
    ASN1_OBJECT_free(objtmp);
    return 0;
}
#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {char* state; int /*<<< orphan*/  name; struct TYPE_7__* parent; } ;
typedef  TYPE_2__ widget ;
typedef  int /*<<< orphan*/  ThemeWidget ;
struct TYPE_6__ {double f; scalar_t__ i; } ;
struct TYPE_8__ {scalar_t__ type; TYPE_1__ value; } ;
typedef  TYPE_3__ Property ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  P_DOUBLE ; 
 scalar_t__ P_INHERIT ; 
 int /*<<< orphan*/  P_INTEGER ; 
 int /*<<< orphan*/  g_debug (char*,int /*<<< orphan*/ ,char*,char const*) ; 
 TYPE_3__* rofi_theme_find_property (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * rofi_theme_find_widget (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 

double rofi_theme_get_double ( const widget *widget, const char *property, double def )
{
    ThemeWidget *wid = rofi_theme_find_widget ( widget->name, widget->state, FALSE );
    Property    *p   = rofi_theme_find_property ( wid, P_DOUBLE, property, FALSE );
    if ( p ) {
        if ( p->type == P_INHERIT ) {
            if ( widget->parent ) {
                return rofi_theme_get_double ( widget->parent, property, def );
            }
            return def;
        }
        return p->value.f;
    }
    // Fallback to integer if double is not found.
    p = rofi_theme_find_property ( wid, P_INTEGER, property, FALSE );
    if ( p ) {
        if ( p->type == P_INHERIT ) {
            if ( widget->parent ) {
                return rofi_theme_get_double ( widget->parent, property, def );
            }
            return def;
        }
        return (double) p->value.i;
    }
    g_debug ( "Theme entry: #%s %s property %s unset.", widget->name, widget->state ? widget->state : "", property );
    return def;
}
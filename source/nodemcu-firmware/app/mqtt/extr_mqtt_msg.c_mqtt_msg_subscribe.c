#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint16_t ;
struct TYPE_6__ {scalar_t__ length; } ;
typedef  TYPE_1__ mqtt_message_t ;
typedef  int /*<<< orphan*/  mqtt_connection_t ;

/* Variables and functions */
 TYPE_1__* mqtt_msg_subscribe_fini (int /*<<< orphan*/ *) ; 
 TYPE_1__* mqtt_msg_subscribe_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 TYPE_1__* mqtt_msg_subscribe_topic (int /*<<< orphan*/ *,char const*,int) ; 

mqtt_message_t* mqtt_msg_subscribe(mqtt_connection_t* connection, const char* topic, int qos, uint16_t* message_id)
{
  mqtt_message_t* result;

  result = mqtt_msg_subscribe_init(connection, message_id);
  if (result->length != 0) {
    result = mqtt_msg_subscribe_topic(connection, topic, qos);
  }
  if (result->length != 0) {
    result = mqtt_msg_subscribe_fini(connection);
  }

  return result;
}
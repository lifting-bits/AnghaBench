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
typedef  char uint16_t ;
struct mg_connection {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MG_MQTT_CMD_UNSUBSCRIBE ; 
 int /*<<< orphan*/  MG_MQTT_QOS (int) ; 
 char htons (char) ; 
 int /*<<< orphan*/  mg_send (struct mg_connection*,char*,char) ; 
 int /*<<< orphan*/  mg_send_mqtt_header (struct mg_connection*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t) ; 
 char strlen (char*) ; 

void mg_mqtt_unsubscribe(struct mg_connection *nc, char **topics,
                         size_t topics_len, uint16_t message_id) {
  uint16_t netbytes;
  size_t i;
  uint16_t topic_len;
  size_t total_len = 2;

  for (i = 0; i < topics_len; i++) {
    total_len += 2 + strlen(topics[i]);
  }

  mg_send_mqtt_header(nc, MG_MQTT_CMD_UNSUBSCRIBE, MG_MQTT_QOS(1), total_len);

  netbytes = htons(message_id);
  mg_send(nc, (char *) &netbytes, 2);

  for (i = 0; i < topics_len; i++) {
    topic_len = strlen(topics[i]);
    netbytes = htons(topic_len);
    mg_send(nc, &netbytes, 2);
    mg_send(nc, topics[i], topic_len);
  }
}
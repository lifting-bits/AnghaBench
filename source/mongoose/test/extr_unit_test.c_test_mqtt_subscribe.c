#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct mg_mqtt_topic_expression {char* member_0; int const member_1; } ;
struct mg_mqtt_proto_data {int /*<<< orphan*/  last_control_time; } ;
struct TYPE_2__ {char* buf; char const len; } ;
struct mg_connection {scalar_t__ proto_data; TYPE_1__ send_mbuf; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT_EQ (char const,int const) ; 
 int /*<<< orphan*/  ASSERT_GT (int /*<<< orphan*/ ,double const) ; 
 int /*<<< orphan*/  ASSERT_STREQ_NZ (char const*,char*) ; 
 int MG_MQTT_CMD_SUBSCRIBE ; 
 struct mg_connection* create_test_connection () ; 
 int /*<<< orphan*/  destroy_test_connection (struct mg_connection*) ; 
 int /*<<< orphan*/  mg_mqtt_subscribe (struct mg_connection*,struct mg_mqtt_topic_expression*,int,int) ; 
 int /*<<< orphan*/  mg_set_protocol_mqtt (struct mg_connection*) ; 
 double mg_time () ; 
 int /*<<< orphan*/  msleep (int) ; 

__attribute__((used)) static const char *test_mqtt_subscribe(void) {
  struct mg_connection *nc = create_test_connection();
  const double before = mg_time();
  const int qos = 1;
  const char *got;
  struct mg_mqtt_topic_expression topic_expressions[] = {{"/stuff", qos}};
  mg_set_protocol_mqtt(nc);
  msleep(2);

  mg_mqtt_subscribe(nc, topic_expressions, 1, 42);
  got = nc->send_mbuf.buf;
  ASSERT_EQ(nc->send_mbuf.len, 13);
  ASSERT_EQ((got[0] & 0xf0), (MG_MQTT_CMD_SUBSCRIBE << 4));
  ASSERT_EQ((size_t) got[1], (nc->send_mbuf.len - 2));
  ASSERT_EQ(got[2], 0);
  ASSERT_EQ(got[3], 42);

  ASSERT_EQ(got[4], 0);
  ASSERT_EQ(got[5], 6);
  ASSERT_STREQ_NZ(&got[6], "/stuff");
  ASSERT_EQ(got[12], qos);

  ASSERT_GT(((struct mg_mqtt_proto_data *) nc->proto_data)->last_control_time,
            before);

  destroy_test_connection(nc);
  return NULL;
}
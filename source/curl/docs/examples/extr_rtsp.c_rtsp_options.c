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
typedef  int /*<<< orphan*/  CURLcode ;
typedef  int /*<<< orphan*/  CURL ;

/* Variables and functions */
 int /*<<< orphan*/  CURLE_OK ; 
 int /*<<< orphan*/  CURLOPT_RTSP_REQUEST ; 
 int /*<<< orphan*/  CURLOPT_RTSP_STREAM_URI ; 
 scalar_t__ CURL_RTSPREQ_OPTIONS ; 
 int /*<<< orphan*/  my_curl_easy_perform (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  my_curl_easy_setopt (int /*<<< orphan*/ *,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  printf (char*,char const*) ; 

__attribute__((used)) static void rtsp_options(CURL *curl, const char *uri)
{
  CURLcode res = CURLE_OK;
  printf("\nRTSP: OPTIONS %s\n", uri);
  my_curl_easy_setopt(curl, CURLOPT_RTSP_STREAM_URI, uri);
  my_curl_easy_setopt(curl, CURLOPT_RTSP_REQUEST, (long)CURL_RTSPREQ_OPTIONS);
  my_curl_easy_perform(curl);
}
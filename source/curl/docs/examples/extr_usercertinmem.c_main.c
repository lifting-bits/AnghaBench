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
typedef  scalar_t__ CURLcode ;
typedef  int /*<<< orphan*/  CURL ;

/* Variables and functions */
 scalar_t__ CURLE_OK ; 
 int /*<<< orphan*/  CURLOPT_HEADER ; 
 int /*<<< orphan*/  CURLOPT_HEADERDATA ; 
 int /*<<< orphan*/  CURLOPT_HEADERFUNCTION ; 
 int /*<<< orphan*/  CURLOPT_NOPROGRESS ; 
 int /*<<< orphan*/  CURLOPT_NOSIGNAL ; 
 int /*<<< orphan*/  CURLOPT_SSLCERTTYPE ; 
 int /*<<< orphan*/  CURLOPT_SSLKEYTYPE ; 
 int /*<<< orphan*/  CURLOPT_SSL_CTX_FUNCTION ; 
 int /*<<< orphan*/  CURLOPT_SSL_VERIFYHOST ; 
 int /*<<< orphan*/  CURLOPT_SSL_VERIFYPEER ; 
 int /*<<< orphan*/  CURLOPT_URL ; 
 int /*<<< orphan*/  CURLOPT_VERBOSE ; 
 int /*<<< orphan*/  CURLOPT_WRITEDATA ; 
 int /*<<< orphan*/  CURLOPT_WRITEFUNCTION ; 
 int /*<<< orphan*/  CURL_GLOBAL_ALL ; 
 int /*<<< orphan*/  curl_easy_cleanup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * curl_easy_init () ; 
 scalar_t__ curl_easy_perform (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  curl_easy_setopt (int /*<<< orphan*/ *,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  curl_global_cleanup () ; 
 int /*<<< orphan*/  curl_global_init (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*) ; 
 char** sslctx_function ; 
 char* stderr ; 
 char* stdout ; 
 char* writefunction ; 

int main(void)
{
  CURL *ch;
  CURLcode rv;

  curl_global_init(CURL_GLOBAL_ALL);
  ch = curl_easy_init();
  curl_easy_setopt(ch, CURLOPT_VERBOSE, 0L);
  curl_easy_setopt(ch, CURLOPT_HEADER, 0L);
  curl_easy_setopt(ch, CURLOPT_NOPROGRESS, 1L);
  curl_easy_setopt(ch, CURLOPT_NOSIGNAL, 1L);
  curl_easy_setopt(ch, CURLOPT_WRITEFUNCTION, writefunction);
  curl_easy_setopt(ch, CURLOPT_WRITEDATA, stdout);
  curl_easy_setopt(ch, CURLOPT_HEADERFUNCTION, writefunction);
  curl_easy_setopt(ch, CURLOPT_HEADERDATA, stderr);
  curl_easy_setopt(ch, CURLOPT_SSLCERTTYPE, "PEM");

  /* both VERIFYPEER and VERIFYHOST are set to 0 in this case because there is
     no CA certificate*/

  curl_easy_setopt(ch, CURLOPT_SSL_VERIFYPEER, 0L);
  curl_easy_setopt(ch, CURLOPT_SSL_VERIFYHOST, 0L);
  curl_easy_setopt(ch, CURLOPT_URL, "https://www.example.com/");
  curl_easy_setopt(ch, CURLOPT_SSLKEYTYPE, "PEM");

  /* first try: retrieve page without user certificate and key -> will fail
   */
  rv = curl_easy_perform(ch);
  if(rv == CURLE_OK) {
    printf("*** transfer succeeded ***\n");
  }
  else {
    printf("*** transfer failed ***\n");
  }

  /* second try: retrieve page using user certificate and key -> will succeed
   * load the certificate and key by installing a function doing the necessary
   * "modifications" to the SSL CONTEXT just before link init
   */
  curl_easy_setopt(ch, CURLOPT_SSL_CTX_FUNCTION, *sslctx_function);
  rv = curl_easy_perform(ch);
  if(rv == CURLE_OK) {
    printf("*** transfer succeeded ***\n");
  }
  else {
    printf("*** transfer failed ***\n");
  }

  curl_easy_cleanup(ch);
  curl_global_cleanup();
  return rv;
}
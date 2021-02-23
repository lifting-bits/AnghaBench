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
typedef  int /*<<< orphan*/ * xmlParserInputPtr ;
typedef  int /*<<< orphan*/ * xmlParserInputBufferPtr ;
typedef  int /*<<< orphan*/ * xmlParserCtxtPtr ;
typedef  int /*<<< orphan*/ * xmlInputReadCallback ;
typedef  int /*<<< orphan*/  (* xmlInputCloseCallback ) (void*) ;
typedef  int /*<<< orphan*/ * xmlDocPtr ;

/* Variables and functions */
 int /*<<< orphan*/  XML_CHAR_ENCODING_NONE ; 
 int /*<<< orphan*/  inputPush (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xmlCtxtReset (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * xmlDoRead (int /*<<< orphan*/ *,char const*,char const*,int,int) ; 
 int /*<<< orphan*/  xmlFreeParserInputBuffer (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xmlInitParser () ; 
 int /*<<< orphan*/ * xmlNewIOInputStream (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * xmlParserInputBufferCreateIO (int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (void*),void*,int /*<<< orphan*/ ) ; 

xmlDocPtr
xmlCtxtReadIO(xmlParserCtxtPtr ctxt, xmlInputReadCallback ioread,
              xmlInputCloseCallback ioclose, void *ioctx,
	      const char *URL,
              const char *encoding, int options)
{
    xmlParserInputBufferPtr input;
    xmlParserInputPtr stream;

    if (ioread == NULL)
        return (NULL);
    if (ctxt == NULL)
        return (NULL);
    xmlInitParser();

    xmlCtxtReset(ctxt);

    input = xmlParserInputBufferCreateIO(ioread, ioclose, ioctx,
                                         XML_CHAR_ENCODING_NONE);
    if (input == NULL) {
        if (ioclose != NULL)
            ioclose(ioctx);
        return (NULL);
    }
    stream = xmlNewIOInputStream(ctxt, input, XML_CHAR_ENCODING_NONE);
    if (stream == NULL) {
        xmlFreeParserInputBuffer(input);
        return (NULL);
    }
    inputPush(ctxt, stream);
    return (xmlDoRead(ctxt, URL, encoding, options, 1));
}
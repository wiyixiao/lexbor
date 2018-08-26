/*
 * Copyright (C) 2018 Alexander Borisov
 *
 * Author: Alexander Borisov <lex.borisov@gmail.com>
 */

/*
 * Caution!!! Important!!!
 * This file is generated by the script "utils/lexbor/tag_ns/tags.py"!
 * Do not change this file!
 */


#include <unit/test.h>

#include <lexbor/tag/tag.h>

#define LXB_HTML_TAG_RES_DATA
#define LXB_HTML_TAG_RES_SHS_DATA
#include <lexbor/html/tag_res.h>


TEST_BEGIN(names)
{
    const lxb_tag_data_t *entry;

    lxb_tag_heap_t *tag_heap = lxb_tag_heap_create();
    lxb_status_t status = lxb_tag_heap_init(tag_heap, 32, lxb_html_tag_res_data,
                                            lxb_html_tag_res_shs_data, 0);
    test_eq(status, LXB_STATUS_OK);

%%TEST_NAMES%%
    lxb_tag_heap_destroy(tag_heap, true);
}
TEST_END

int
main(int argc, const char * argv[])
{
    TEST_INIT();

    TEST_ADD(names);

    TEST_RUN("lexbor/tag/res");
    TEST_RELEASE();
}



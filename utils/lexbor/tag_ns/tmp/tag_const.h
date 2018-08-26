/*
 * Copyright (C) 2018 Alexander Borisov
 *
 * Author: Alexander Borisov <lex.borisov@gmail.com>
 */

/*
 * Caution!!! Important!!!
 * This file generated by the script "utils/lexbor/tag_ns/tags.py"!
 * Do not change this file!
 */


#ifndef LXB_TAG_CONST_H
#define LXB_TAG_CONST_H

#define LXB_TAG_CONST_VERSION "%%HASH%%"
#define LXB_TAG_CONST_VERSION_%%HASH%%


typedef unsigned int lxb_tag_id_t;

typedef enum {
    LXB_TAG_CATEGORY__UNDEF          = 0x0000,
    LXB_TAG_CATEGORY_ORDINARY        = 0x0001,
    LXB_TAG_CATEGORY_SPECIAL         = 0x0002,
    LXB_TAG_CATEGORY_FORMATTING      = 0x0004,
    LXB_TAG_CATEGORY_SCOPE           = 0x0008,
    LXB_TAG_CATEGORY_SCOPE_LIST_ITEM = 0x0010,
    LXB_TAG_CATEGORY_SCOPE_BUTTON    = 0x0020,
    LXB_TAG_CATEGORY_SCOPE_TABLE     = 0x0040,
    LXB_TAG_CATEGORY_SCOPE_SELECT    = 0x0080,
}
lxb_tag_category_t;

%%BODY%%


#endif /* LXB_TAG_CONST_H */

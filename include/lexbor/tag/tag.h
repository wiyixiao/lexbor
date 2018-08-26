/*
 * Copyright (C) 2018 Alexander Borisov
 *
 * Author: Alexander Borisov <lex.borisov@gmail.com>
 */

#ifndef LEXBOR_TAG_H
#define LEXBOR_TAG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <lexbor/core/shbst.h>
#include <lexbor/core/shs.h>
#include <lexbor/core/dobject.h>
#include <lexbor/core/str.h>

#include <lexbor/ns/const.h>
#include <lexbor/tag/const.h>
#include <lexbor/html/interface.h>


typedef void *
(*lxb_tag_interface_creation_f)(void *document);


typedef struct {
    const lxb_char_t             *name;
    size_t                       name_len;
    lxb_tag_id_t                 tag_id;

    lxb_tag_category_t           cats[LXB_NS__LAST_ENTRY];
    lxb_tag_interface_creation_f interface[LXB_NS__LAST_ENTRY];
    lexbor_str_t                 *fixname[LXB_NS__LAST_ENTRY];
}
lxb_tag_data_t;

typedef struct {
    lexbor_shbst_t           *heap;
    lexbor_dobject_t         *data;

    const lxb_tag_data_t     *static_data;
    const lexbor_shs_entry_t *static_heap;

    lxb_tag_category_t       default_cats;

    size_t                   ref_count;
}
lxb_tag_heap_t;


LXB_API lxb_tag_heap_t *
lxb_tag_heap_create(void);

LXB_API lxb_status_t
lxb_tag_heap_init(lxb_tag_heap_t *tag_heap, size_t table_size,
                  const lxb_tag_data_t *static_data,
                  const lexbor_shs_entry_t *static_heap,
                  lxb_tag_category_t default_cats);

LXB_API lxb_tag_heap_t *
lxb_tag_heap_ref(lxb_tag_heap_t *tag_heap);

LXB_API lxb_tag_heap_t *
lxb_tag_heap_unref(lxb_tag_heap_t *tag_heap, bool self_destroy);

LXB_API void
lxb_tag_heap_clean(lxb_tag_heap_t *tag_heap);

LXB_API lxb_tag_heap_t *
lxb_tag_heap_destroy(lxb_tag_heap_t *tag_heap, bool self_destroy);


LXB_API lxb_tag_data_t *
lxb_tag_append(lxb_tag_heap_t *tag_heap, const lxb_char_t *name, size_t len);

/*
 * Append a tag without name copying.
 * Name should always be created only using the local 'mraw'.
 * For get local 'mraw' use 'lxb_tag_heap_mraw' function.
 */
LXB_API lxb_tag_data_t *
lxb_tag_append_wo_copy(lxb_tag_heap_t *tag_heap, lxb_char_t *name, size_t len);


LXB_API const lxb_tag_data_t *
lxb_tag_data_by_id(lxb_tag_heap_t *tag_heap, lxb_tag_id_t tag_id);

LXB_API const lxb_tag_data_t *
lxb_tag_data_by_name(lxb_tag_heap_t *tag_heap,
                     const lxb_char_t *name, size_t len);

LXB_API const lxb_char_t *
lxb_tag_name_by_id(lxb_tag_heap_t *tag_heap,
                   lxb_tag_id_t tag_id, lxb_ns_id_t ns, size_t *len);

LXB_API lxb_tag_id_t
lxb_tag_id_by_name(lxb_tag_heap_t *tag_heap,
                   const lxb_char_t *name, size_t len);

LXB_API bool
lxb_tag_is_void(lxb_tag_id_t tag_id);


/*
 * Inline functions
 */
lxb_inline size_t
lxb_tag_heap_ref_count(lxb_tag_heap_t *tag_heap)
{
    return tag_heap->ref_count;
}

lxb_inline lexbor_mraw_t *
lxb_tag_heap_mraw(lxb_tag_heap_t *tag_heap)
{
    return lexbor_shbst_keys(tag_heap->heap);
}

lxb_inline bool
lxb_tag_is_category(lxb_tag_heap_t *tag_heap,
                    lxb_tag_id_t tag_id, lxb_ns_id_t ns, lxb_tag_category_t cat)
{
    const lxb_tag_data_t *data = lxb_tag_data_by_id(tag_heap, tag_id);

    if (data == NULL) {
        return false;
    }

    return data->cats[ns] & cat;
}


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* LEXBOR_TAG_H */

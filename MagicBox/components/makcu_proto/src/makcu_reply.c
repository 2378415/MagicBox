/* Reply framing - see include/makcu_reply.h for the wire format evidence. */
#include "makcu_reply.h"

#include <string.h>

static makcu_write_fn s_writer;
static char s_frame[MAKCU_REPLY_MAX];

void makcu_reply_set_writer(makcu_write_fn fn)
{
    s_writer = fn;
}

size_t makcu_reply_format(char *out, size_t out_size, const char *content, size_t content_len)
{
    const size_t prefix = sizeof(MAKCU_REPLY_PREFIX) - 1;
    const size_t suffix = sizeof(MAKCU_REPLY_SUFFIX) - 1;
    const size_t total = prefix + content_len + suffix;

    if (out == NULL || total + 1 > out_size) {
        return 0;
    }
    memcpy(out, MAKCU_REPLY_PREFIX, prefix);
    if (content != NULL && content_len != 0) {
        memcpy(out + prefix, content, content_len);
    }
    memcpy(out + prefix + content_len, MAKCU_REPLY_SUFFIX, suffix);
    out[total] = '\0';
    return total;
}

size_t makcu_reply(const char *content, size_t content_len)
{
    const size_t n = makcu_reply_format(s_frame, sizeof(s_frame), content, content_len);
    if (n == 0 || s_writer == NULL) {
        return 0;
    }
    s_writer(s_frame, n);
    return n;
}

size_t makcu_reply_echo(const char *buf, int len)
{
    if (buf == NULL || len <= 0) {
        return 0;
    }
    return makcu_reply(buf, (size_t)len);
}

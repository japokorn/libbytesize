#ifndef _BS_SIZE_H
#define _BS_SIZE_H

#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS

#define BS_TYPE_SIZE            (bs_size_get_type())
#define BS_SIZE(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), BS_TYPE_SIZE, BSSize))
#define BS_IS_SIZE(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj)), BS_TYPE_SIZE)
#define BS_SIZE_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), BS_TYPE_SIZE, BSSizeClass))
#define BS_IS_SIZE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BS_TYPE_SIZE))
#define BS_SIZE_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), BS_TYPE_SIZE, BSSizeClass))

#define BS_SIZE_ERROR bs_size_error_quark ()
typedef enum {
    BS_SIZE_ERROR_INVALID_SPEC,
    BS_SIZE_ERROR_OVER,
    BS_SIZE_ERROR_ZERO_DIV,
} BSSizeError;

typedef enum {
    BS_BUNIT_B = 0, BS_BUNIT_KiB, BS_BUNIT_MiB, BS_BUNIT_GiB, BS_BUNIT_TiB,
    BS_BUNIT_PiB, BS_BUNIT_EiB, BS_BUNIT_ZiB, BS_BUNIT_YiB, BS_BUNIT_UNDEF,
} BSBUnit;

typedef enum {
    BS_DUNIT_B = 0, BS_DUNIT_KB, BS_DUNIT_MB, BS_DUNIT_GB, BS_DUNIT_TB,
    BS_DUNIT_PB, BS_DUNIT_EB, BS_DUNIT_ZB, BS_DUNIT_YB, BS_DUNIT_UNDEF,
} BSDunit;

/* use 256 bits of precision for floating point numbets, that should be more
   than enough */
#define BS_FLOAT_PREC_BITS 256

typedef struct _BSSize        BSSize;
typedef struct _BSSizeClass   BSSizeClass;
typedef struct _BSSizePrivate BSSizePrivate;

GType bs_size_get_type (void);

/* Constructors */
BSSize* bs_size_new_from_bytes (guint64 bytes, GError **error);
BSSize* bs_size_new_from_str (const gchar *size_str, GError **error);
BSSize* bs_size_new_from_size (BSSize *size, GError **error);
BSSize* bs_size_new (void);

/* Query functions */
guint64 bs_size_get_bytes (BSSize *size, GError **error);
gchar* bs_size_get_bytes_str (BSSize *size, GError **error);

/* Arithmetic */
BSSize* bs_size_add (BSSize *size1, BSSize *size2);
BSSize* bs_size_add_bytes (BSSize *size, guint64 bytes);
BSSize* bs_size_sub (BSSize *size1, BSSize *size2);
BSSize* bs_size_sub_bytes (BSSize *size, guint64 bytes);
BSSize* bs_size_mul_int (BSSize *size, guint64 times);
BSSize* bs_size_mul_float_str (BSSize *size, gchar *float_str, GError **error);
guint64 bs_size_div (BSSize *size1, BSSize *size2, GError **error);
BSSize* bs_size_div_int (BSSize *size, guint64 divisor, GError **error);

G_END_DECLS

#endif  /* _BS_SIZE_H */
#include "../include/var.h"
#include <stdlib.h>
#include <string.h>

static Var create_int_value(const int i)
{
    Var v;
    v.type = INT;
    v.data.i = i;
    return v;
}

static Var create_float_value(const float f)
{
    Var v;
    v.type = FLOAT;
    v.data.f = f;
    return v;
}

static Var create_double_value(const double d)
{
    Var v;
    v.type = DOUBLE;
    v.data.d = d;
    return v;
}

static Var create_string_var(const char *s)
{
    Var v;
    v.type = STRING;
    v.data.s = strdup(s);
    return v;
}

static void free_value(Var *v)
{
    if (v->type == STRING && v->data.s != NULL)
    {
        free(v->data.s);
        v->data.s = NULL;
    }
}

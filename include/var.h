#ifndef VAR_H
#define VAR_H

typedef enum
{
    INT,
    FLOAT,
    DOUBLE,
    STRING
} VarType;

/**
 *
 */
typedef struct
{
    VarType type;

    union
    {
        int i;
        float f;
        double d;
        char *s;
    } data;
} Var;

static Var create_int_var(int i);

static Var create_float_var(float f);

static Var create_double_var(double d);

static Var create_string_var(const char *s);

static void free_var(Var *var);

Var parse_var(const char *input);

#endif  // VAR_H

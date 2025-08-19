#include "../include/var.h"
#include <stdlib.h>
#include <string.h>

/**
 * Creates an integer variable.
 *
 * @param i The integer.
 * @return the variable as an integer.
 */
static Var create_int_var(const int i)
{
    Var var;
    var.type = INT;
    var.data.i = i;
    return var;
}


/**
 * Creates a float variable.
 *
 * @param f the float.
 * @return the variable as a float.
 */
static Var create_float_var(const float f)
{
    Var var;
    var.type = FLOAT;
    var.data.f = f;
    return var;
}


/**
 * Creates a double variable.
 *
 * @param d the double.
 * @return the variable as a double.
 */
static Var create_double_var(const double d)
{
    Var var;
    var.type = DOUBLE;
    var.data.d = d;
    return var;
}


/**
 * Creates a string variable.
 *
 * @param s the string.
 * @return the variable as a string.
 */
static Var create_string_var(const char *s)
{
    Var var;
    var.type = STRING;
    var.data.s = strdup(s);
    return var;
}


/**
 * Frees the variable, if it is a string.
 *
 * @param var the variable.
 */
static void free_var(Var *var)
{
    if (var->type == STRING && var->data.s != NULL)
    {
        free(var->data.s);
        var->data.s = NULL;
    }
}


/**
 * Takes the input and converts in the following order:
 * int -> double -> float -> string
 *
 * @param input the string.
 * @return the variable as its intended data type.
 */
Var parse_var(const char *input)
{
    char *endptr;

    // Try to convert to int
    const long int i = strtol(input, &endptr, 10);
    if (*endptr == '\0')
        return create_int_var((int) i);

    // Try to convert to double
    const double d = strtod(input, &endptr);
    if (*endptr == '\0')
        return create_double_var(d);

    // Try to convert to float
    const float f = strtof(input, &endptr);
    if (*endptr == '\0')
        return create_float_var(f);

    // Return string
    return create_string_var(input);
}

/*
    module  : do_add.c
    version : 1.2
    date    : 10/26/20
*/
#include <stdio.h>
#include <assert.h>
#include "data.h"
#include "ident.h"

/*
+  :  M I  ->  N
Numeric N is the result of adding integer I to numeric M.
Also supports float.
*/
void do_add()
{
    data_t *cur, *node;

    DEBUG(__FUNCTION__);
    assert(stack && stack->next && (stack->op == typ_integer ||
	   stack->op == typ_float));
    cur = get(1);
    node = stack->next;
    switch (stack->op) {
    case typ_float :
	switch (node->op) {
	case typ_float :
	    cur->dbl = node->dbl + stack->dbl;
	    break;

	default :
	    cur->dbl = node->num + stack->dbl;
	    break;
	}
	cur->op = typ_float;
	break;

    default :
	switch (node->op) {
	case typ_float :
	    cur->dbl = node->dbl + stack->num;
	    break;

	default :
	    cur->num = node->num + stack->num;
	    break;
	}
	cur->op = node->op;
	break;
    }
    cur->next = node->next;
    stack = cur;
}

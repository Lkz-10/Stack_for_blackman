#include "CDtor.h"

void StackCtor(Stk_t* stk)
{
    assert(stk);

    stk->data = (stk_el_t*) ((char*) calloc(1, CAPACITY_MIN * sizeof(stk_el_t) ON_BIRDS(+ 2 * CANARY_ADDED_SIZE)));

    stk->sz       = 0;
    stk->capacity = CAPACITY_MIN;
    stk->err_code = NO_ERR;

    #ifdef CANARIES_MODE
        assert(stk->data);

        stk->data = (stk_el_t*) ((char*) stk->data + CANARY_ADDED_SIZE);

        *((canary_t*)((char*) stk->data - CANARY_ADDED_SIZE)) = CANARY;

        *((canary_t*)(stk->data + stk->capacity)) = CANARY;
    #endif

    ON_BIRDS(stk->canary2 = CANARY;)

    FillPoison(stk);

    #ifdef HASH_MODE
        assert(stk->data);

        stk->data_hash = CalculateHash((const char*) stk->data, CAPACITY_MIN * sizeof(stk_el_t));

        stk->stk_hash  = CalculateHash((char*) stk + STK_PTR_SHIFT, STK_SIZE);
    #endif

    HASH_VERIFY(stk)
}

void StackDtor(Stk_t* stk)
{
    assert(stk);

    free((char*) stk->data ON_BIRDS(- CANARY_ADDED_SIZE));

    stk->data     = NULL;
    stk->capacity = CAPACITY_MIN;
    stk->sz       = 0;
}

int FillPoison (Stk_t* stk)
{
    for (size_t i = stk->sz; i < stk->capacity; ++i) {
        (stk->data)[i] = POISON;
    }

    return 0;
}

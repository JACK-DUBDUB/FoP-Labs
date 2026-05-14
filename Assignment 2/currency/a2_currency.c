#include "a2_currency.h"

// Known currency types
const Currency USD_DATA = 
{
    .code = USD_S,
    .id = USD_ID,
    .coins = {50, 25, 10, 1}
};

const Currency AUD_DATA = 
{
    .code = AUD_S,
    .id = AUD_ID,
    .coins = {50, 20, 10, 5}
};

const Currency EUR_DATA = 
{
    .code = EUR_S,
    .id = EUR_ID,
    .coins = {20, 10, 5, 1}
};
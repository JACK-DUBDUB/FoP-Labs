#include "a2_currency.h"

const Currency USD_DATA = 
{
    .code = "US$",
    .id = USD_ID,
    .count = MAX_COIN_VARIANTS,
    .coins = {50, 25, 10, 1}
};

const Currency AUD_DATA = 
{
    .code = "AU$",
    .id = AUD_ID,
    .count = MAX_COIN_VARIANTS,
    .coins = {50, 20, 10, 5}
};

const Currency EUR_DATA = 
{
    .code = "EUR",
    .id = EUR_ID,
    .count = MAX_COIN_VARIANTS,
    .coins = {20, 10, 5, 1}
};

// could keep adding different currencies if i wanted to




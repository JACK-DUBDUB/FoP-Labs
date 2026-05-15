#ifndef A2_CURRENCY_H
#define A2_CURRENCY_H

enum CURRENCY_TYPES {USD_ID, AUD_ID, EUR_ID};

// ---- Currency Values ----
#define MAX_CURRENCY_TYPES  3   // USD, AUD, EUR
#define MAX_COIN_VARIANTS   4   // C1, C2, C3, C4

// ---- Strings ----
#define USD_S               "$USD"
#define AUD_S               "$AUD"
#define EUR_S               "$EUR"

// ======== STRUCT ========

typedef struct 
{
    char    code[5];                    // Currency code ex: "$USD" + '\0'
    int     id;                         // 0 = USD, 1 = AUD, 2 = EUR
    int     coins[MAX_COIN_VARIANTS];   // C1, C2, C3, C4
} Currency;


// ---- Declared Currencies ----
extern const Currency USD_DATA;
extern const Currency AUD_DATA;
extern const Currency EUR_DATA;

// NOTES:
// -> The last array in a struct can be flexible but its a bitch to sort that out as i won't know the exact size without memory implementation
// -> We can safely add additional currency types ASSUMING that it also has a maximum of 4 coin variants
#endif /* A2_CURRENCY_H */
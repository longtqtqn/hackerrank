###
 # Code by longtqtqn
###
awk ' \
NR % 2 == 0 { \
    n = $0
} \
NR % 2 == 1 && NR > 1 { \
    split ($0, prices, " "); \
    curMax = prices[n]; \
    rs = 0; \
    for (i = n - 1; i > 0; --i) { \
        if (prices[i] < curMax) { \
            rs += curMax - prices[i]; \
        } else { \
            curMax = prices[i]; \
        } \
    } \
    print rs; \
}\
'
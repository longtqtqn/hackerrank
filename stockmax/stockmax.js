/**
 * Code by longtqtqn
 */

process.stdin.resume();
process.stdin.setEncoding('utf-8');

_input = '';

process.stdin.on('data', function(inputStdin) {
    _input += inputStdin;
});

process.stdin.on('end', function() {
    main(_input);
});

function main(input) {
    var inputArr, 
        prices = [],
        n,
        curLine = 0;
    
    inputArr = input.split('\n');
    
    t = parseInt(inputArr[curLine++]);
    
    for (it = 0; it < t; ++it) {
        n = parseInt(inputArr[curLine++])
        prices = inputArr[curLine++].split(' ').map(function(n) {
            return parseInt(n, 10);
        })
        solve(n, prices);
    }
}

function solve(n, prices) {
    var curMax = prices[n - 1];
    var rs = 0;
    var i = n - 2;
    for (; i >= 0; --i) {
        if (prices[i] < curMax) {
            rs += curMax - prices[i];
        } else {
            curMax = prices[i];
        }
    }
    console.log(rs);
}

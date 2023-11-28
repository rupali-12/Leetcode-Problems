/**
 * @param {string} corridor
 * @return {number}
 */
var numberOfWays = function(corridor) {
    let mod = 1e9 + 7
    let seatS = []
    for(let i = 0; i < corridor.length; i++) {
        if(corridor[i] == 'S')
            seatS.push(i)
    }
    if(seatS.length % 2 != 0 || seatS.length == 0)
        return 0
    let result = 1
    for(let i = 2; i < seatS.length; i += 2) {
        result = (result * (seatS[i] - seatS[i-1])) % mod
    }
    return result
};
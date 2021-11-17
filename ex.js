bestSum = function (numbers, target, memo = {}) {
    if (target in memo) return memo[target];
    
    if (target === 0) return 1;
    
    if (target < 0) return null;
    
    let re = 0;
    
    for (let number in numbers) {
        const remainder = target - number;
        const te = bestSum(numbers, remainder, memo);
        if (te !== null) {
            re += te;
        }
    }
    
    memo[target] = re;
    return re;
}

console.log(bestSum([3, 4, 7], 7));
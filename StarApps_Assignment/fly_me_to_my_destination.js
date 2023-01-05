/*
function jump(nums) {
  return solve(nums, 0);
}

function solve(nums, pos) {
  let minJumps = Number.MAX_SAFE_INTEGER;
  if (pos >= nums.length - 1) {
    return 0;
  }

  for (let j = 1; j <= nums[pos]; j++) {
    minJumps = Math.min(minJumps, 1 + solve(nums, pos + j));
  }
  return minJumps;
}
*/

function min(nums) {
  const memo = new Array(nums.length).fill(Number.MAX_SAFE_INTEGER);
  return solve(nums, memo, 0);
}

function solve(nums, memo, pos) {
  if (pos >= nums.length - 1) {
    return 0;
  }
  if (memo[pos] !== Number.MAX_SAFE_INTEGER) {
    return memo[pos];
  }
  for (let j = 1; j <= nums[pos]; j++) {
    memo[pos] = Math.min(memo[pos], 1 + solve(nums, memo, pos + j));
  }
  return memo[pos];
}

// const nums = [2, 1, 2, 3, 1];
const nums = [1, 6, 3, 4, 5, 0, 0, 0, 6];
console.log(jump(nums));

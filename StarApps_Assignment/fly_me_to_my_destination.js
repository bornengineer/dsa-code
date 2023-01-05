// this is required to run "prompt" in node environment
const prompt = require("prompt-sync")({ sigint: true });

// It took me 2 hours to think and write the whole solution code

// #1
/*  
    I will be approaching this by trying all the cases of reaching to the last plane
    which will be possible by using recursion
*/

// /*
function minPlanes(planes) {
  let ans = solve(planes, 0);
  // if the ans has returned max value it means no solution exists hence return -1, else return ans
  return ans === Number.MAX_SAFE_INTEGER ? -1 : ans;
}

function solve(planes, index) {
  let currMin = Number.MAX_SAFE_INTEGER;

  // if the index is has reached to last index return 0;
  if (index >= planes.length - 1) {
    return 0;
  }

  // here we will be checking for each index's fuel level and keep the answer, which does the work using least planes
  for (let j = 1; j <= planes[index]; j++) {
    currMin = Math.min(currMin, 1 + solve(planes, index + j));
  }
  return currMin;
}
// */
// this approach will be processing all the possible solutions answers
// Hence the time complexity will be O(n!) (n factorial)

// #2
// Now to improve it we can use Dynamic programming by maintaining a memo array to store the answers and avoid overlapping solutions
// else is same as that of previous solution
// /*
function minPlanes(planes) {
  const memo = new Array(planes.length).fill(Number.MAX_SAFE_INTEGER);
  let ans = solve(planes, memo, 0);
  return ans === Number.MAX_SAFE_INTEGER ? -1 : ans;
}

function solve(planes, memo, index) {
  if (index >= planes.length - 1) {
    return 0;
  }
  if (memo[index] !== Number.MAX_SAFE_INTEGER) {
    return memo[index];
  }
  for (let j = 1; j <= planes[index]; j++) {
    memo[index] = Math.min(memo[index], 1 + solve(planes, memo, index + j));
  }
  return memo[index];
}
// */
// this approach will have a time complexity of O(n^2) cause we will be checking atmost n planes for each plane

// #3
// also we can solve this question in O(n) using Greedy approach

// here we will look for every possibility from each index's value
// and use the farthest we can go through any index's value (greedy way)
// for eg [2,1,2,3,1]
//    firstly we can go to 2nd index (0+2) by 0th index value
//    but we wont update the ans till we reach the 2nd index
//    when we reach 2nd index and if we got a more far value (farthest = (2+2 = 4))  we will update it
//    and do the same till (n-2)th index (n-1 th is not considered because it's the end point)

// this code is written assuming the planes can reach the end, i can write a function to check it also
// because the complexity of this whole js file will further increase if I write the function

//also it is not giving right output when input is taken by using prompt
// /*
function minPlanes(planes) {
  let farthest = 0;
  let currFarthest = 0;
  let ans = 0;
  for (let i = 0; i < planes.length - 1; i++) {
    farthest = Math.max(farthest, planes[i] + i);
    if (currFarthest === i) {
      currFarthest = farthest;
      ans++;
    }
  }
  return ans;
}
// the basic idea is that we are checking local optimal each time to check if it satisfies the global optimal
// and hence Greedy works here
// */

// const planes = [2, 1, 2, 3, 1];
// const planes = [1, 6, 3, 4, 5, 0, 0, 0, 6];

const noOfPlanes = prompt("Enter the number of planes/airports: ");
const planes = [];
for (let i = 0; i < noOfPlanes; i++) {
  planes[i] = prompt("Enter the plane " + (i + 1) + "'s fuel level: ");
}

console.log(
  "Minimum number of planes required to reach the last Airport is/are",
  minPlanes(planes)
);

/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    const newArr = new Set(nums)

    nums.length = 0;
    newArr.forEach((value)=> {
        nums.push(value)
    })

   return nums.length
};

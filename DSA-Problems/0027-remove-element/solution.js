/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
   const newArray =  nums.filter(e => e !== val)
   nums.length = 0;
   nums.push(...newArray)
   
    return newArray.length
};

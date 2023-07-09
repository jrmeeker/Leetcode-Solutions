
def bin_search(nums, target):
  mid_index = len(nums) // 2 
  mid_val = nums[mid_index]

  left, right = 0, len(nums) - 1
  while left <= right:
    if mid_val == target:
      return mid_index

    if target < mid_val:
      right = mid_index - 1
    else:
      left = mid_index + 1 
      
    mid_index = (right + left) // 2
    mid_val = nums[mid_index]

  return -1

if __name__ == '__main__':
  numbers = [1,3,4,7,9,10,11]
  t = 13
  print(bin_search(numbers, t))
	
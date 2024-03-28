# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
    for i in 0..nums.length-1
        for j in i+1..nums.length-1
            if nums[i] + nums[j] == target
                # return [i, j]
                puts "#{i} #{j}"
            end
        end 
      
    end
end

two_sum([2,7,11,15], 9) # [0, 1]
two_sum([3,2,4], 6) # [1, 2]
two_sum([3,3], 6) # [0, 1]
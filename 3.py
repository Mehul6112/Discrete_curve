# Function to find the all possible permutations
def permutations(res,nums,l,h):
    # Base case
    # Add the vector to result and return
    if l==h:
        res.append(nums[:])
        return


    # Permutations made
    for i in range(l,h+1):
        nums[l],nums[i]=nums[i],nums[l]
        # Calling permutations for
        # next greater value of l
        permutations(res,nums,l+1,h)
        nums[l],nums[i]=nums[i],nums[l]


# Function to get the all possible permutations
def permute(nums):
    res = []
    x = len(nums)-1
    # Calling permutations for the first
    # time by passing l
    # as 0 and h = nums.size()-1
    permutations(res,nums,0,x)
    return res


nums = [2,4,8]
res = permute(nums)
s = set()
for x in res:
    s.add(tuple(x))


print("there are ",len(s),"possible permutations")


for x in s:
    for y in x:
        print(y,end=" ")
    print()
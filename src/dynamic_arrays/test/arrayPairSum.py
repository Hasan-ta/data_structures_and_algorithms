import pdb

k = 10
array = [1,3,2,2,4,5,2,3,4,9,8,7,6,5,10,11]
array.sort()
firstItemLargerThanK_i = 14
subArray = array[0:firstItemLargerThanK_i]

def findFirstNumberLargerThanK(array, start, end, item):
	mid = int(start + (end-start)/2);
#	pdb.set_trace()
	if(mid != start and mid != end):
		if(item+array[mid] < k):
			mid = findFirstNumberLargerThanK(array, mid, end, item)
		else:
			mid = findFirstNumberLargerThanK(array, start,mid, item)
	return mid;

counter = 0;
for i in range(len(subArray)):
	mid = findFirstNumberLargerThanK(subArray, 0, len(subArray), subArray[i]);
	print mid
	print subArray[i:mid+2]
	for j in range(i,mid+2):
		if(subArray[i] + subArray[j] == k):
			counter += 1;

print(counter)

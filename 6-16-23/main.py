import re

arrTxt = input("provide a comma-separated array of values (of any type):\n")
arr = re.findall(r"([^,]+)", arrTxt)

prmTxt = input("provide a comma-separated permutation array of indices of the first array e.g. 2,1,0:\n")
prm = re.findall(r"([0-9]+)", prmTxt)

new = []
for n in prm:
	new.append(arr[int(n)])

print(new)

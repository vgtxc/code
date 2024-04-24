# lastEdit=>2024.04.23-11:28
# lastEdit=>2024.04.23-10:43

import random,os

def typeGame():
	aimNum = random.randint(1,100)
	print("Finish generate a random number!!!")
	print("\t->:",aimNum)
	while(True):
		inpNum = input("Please input a number:")
		try:
			inpNum = int(inpNum)
			if inpNum==aimNum:
				print("you are win!!!")
				os.system("pause")
				break
			print("lose try again")
		except:
			print("dataType error")

if __name__ == "__main__":
	typeGame()
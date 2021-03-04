def main():
  num = get_positive_int()
  print(num)


def get_positive_int():
  while True:   # Induce an infinite loop to have the loop run at least once, akin to a do-while loop in C
    n = int(input("Please enter a positive integer: "))
    if n > 0:
      break
  return n
    
main()

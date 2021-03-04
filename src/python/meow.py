def main():
  meow(3)

def meow(n):
  for i in range(n):
    print("meow")

if __name__ == "__main__":    # This line is only REALLY necessary when creating a library
  main()    ## Otherwise this line alone with suffice
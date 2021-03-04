import sys

## Using argv for command line arguments ##
if (len(sys.argv) > 1):
  for arg in sys.argv[1:]:
    print(arg, end=" ")   # Use the `end` parameter; default is \n
  print()
  sys.exit(0)   # Akin to the exit status in C
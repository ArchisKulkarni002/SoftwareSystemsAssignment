
# first we create a fifo file
mkfifo myTestFifo

# lets echo that fifo is created
echo "fifo created. it will be blocked till someone reads the contents of the fifo. use cat command to read!"

# then we write stuff to it
echo "hello there!" > myTestFifo

# we are done with the file, lets obliterate it
rm  myTestFifo

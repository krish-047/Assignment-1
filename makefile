hanoi: a1-5.cpp
	# write the command for compiling a1-5.cpp to a1-5.out
      default: a1-5.cpp
        g++ -Wall a1-5.cpp -o a1-5.out
      run:
        ./a1-5.out
	
median: a1-4.cpp
	# write the command for compiling a1-4.cpp to a1-4.out
        
      default: a1-4.cpp
        g++ -Wall a1-4.cpp -o a1-4.out
      run:
        ./a1-4.out


clean:
	rm *.out 

all: compile

compile: 
	verilator -cc --exe --build --trace -j 0 -CFLAGS "-g -O0" tb.cpp ../spram.sv 

run:
	./obj_dir/Vspram

clean:
	rm -rf ./obj_dir
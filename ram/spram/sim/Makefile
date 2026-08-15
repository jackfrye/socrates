all: compile

compile: 
	verilator -cc --exe --build -j 0 tb.cpp ../spram.sv 

run:
	./obj_dir/Vspram
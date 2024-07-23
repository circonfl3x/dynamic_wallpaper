cc = g++
files = $(wildcard *.cc)
bin = wall
default:
	${cc} ${files} -o ${bin}

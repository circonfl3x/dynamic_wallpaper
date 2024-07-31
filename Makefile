cc = g++
files = $(wildcard *.cc)
bin = dynwall_tw
default:
	${cc} ${files} -o ${bin}

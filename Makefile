r&c: node/*.c
	gcc -w node/processor.c -o temp/processor
	gcc -w node/receive.c -o temp/receive
	gcc -w node/sendto.c -o temp/sendto
	gcc -w node/node.c -c
support: support/*.c
	gcc -w support/hash.c -c
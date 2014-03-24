r&c: node/*.c
	gcc -w node/processor.c -o temp/processor
	gcc -w node/receiver.c -o temp/receiver
	gcc -w node/sender.c -o temp/sender
	gcc -w node/node.c -c 
support: support/*.c
	gcc -w support/hash.c -c
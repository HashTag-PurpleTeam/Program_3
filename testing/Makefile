run: build
	chmod u+x run_tests.sh
	./run_tests.sh

build: standard_test free_invalid free_already_freed free_not_first exit_no_free

standard_test: standard_test.c
	cc -o standard_test standard_test.c
	
free_invalid: free_invalid.c
	cc -o free_invalid free_invalid.c
	
free_already_freed: free_already_freed.c
	cc -o free_already-freed free_already_freed.c
	
free_not_first: free_not_first.c
	cc -o free_not_first free_not_first.c
	
exit_no_free: exit_no_free.c
	cc -o exit_no_free exit_no_free.c
	
clean:
	rm standard_test free_invalid free_already_freed free_not_first exit_no_free
#define SHMSZ 1024
#define KEY 1234
struct shared_stuff_st
{ 
	int written_by_you;
	char some_text[SHMSZ];

}; /* shared_stuff_st */

#include "src/list.h"

int main(){
	
	List list = lnew();

	lbpush(&list, 1);
	lbpush(&list, 2);
	lbpush(&list, 3);
	lbpush(&list, 4);
	lbpush(&list, 5);
	lbpush(&list, 6);

	// linsert(list, 11, 0);
	
	printf("List: \n");
	lprint(list);
	printf("\n");
}

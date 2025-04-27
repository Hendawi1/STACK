#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "01.stack.c"



char* get_vir(size_t *len){
    if(len){
        *len = 0;
        char* vir = (char*)malloc(sizeof(char) * (*len + 1));
        if(!vir) return NULL;
        char vir_unit = getchar();

        while (vir_unit != '\n'){
            vir[(*len)++] = vir_unit;
            vir = (char*)realloc(vir, sizeof(char) * (*len + 1));
                if(!vir) return NULL;
            vir_unit = getchar();
        }
        vir[*len] = '\0';
        return vir;
    }
    else return NULL;
}



bool is_operator(char  x){
	char opr[6]="+-*/%^";

	for (int i=0; i<6; i++){
		if (x == opr[i])
		return true;
	}
	return false;
}



bool is_operand(char x){
    if(x >= 'A' && x <= 'Z' || x >= 'a' && x <= 'z' || x >= '0' && x <= '9') return true;
    else return false;
}



int is_expression(char * vir, int len){
	if (vir && len > 0){
		// creat a stack:
		struct STACK* stack = creat_stack(len);

		// check the stack:
		if (!stack) return -1;

		// push to stack:
		char opr[2]="()", pop_res, top;
		int sskopki = 0;
		for (int i=0; *(vir+i)!='\0'; i++){
			if (*(vir+i) == opr[1])
				sskopki++;
			else if (*(vir+i) == opr[0]){
				if (sskopki>1)
					return 0;
				else
					sskopki--;
			}
			else
				if (!push(stack, *(vir+i))) return 0;
		}
		if (sskopki != 0)
			return 0;

		// check:
		while (stack->top>1){
			show_top(stack, &top);
			if (!is_operand(top))
				return 0;
			else{
				pop(stack, &pop_res);
				show_top(stack, &top);
				if (!is_operator(top))
					return -1;
				else{
					pop(stack, &pop_res);
				}
			}
			print(stack);
			printf("\0");
		}
		show_top(stack, &top);
		if (stack->top == 0 && is_operand(top))
			return 1;
		return 0;
	}
	//printf("\nI can not start, stacka net ..!\n");
	return -1;
}



int main(){

	size_t len;
	char* vir = get_vir(&len);

	if (!vir){
		printf("\nerror while getting vir\n");
		return 1;
	}


	int check = is_expression(vir, len);
        if (check == 1){
		printf("\n[+] TRUE\n");
		return 1;
	}
	else if (check == 0)
		printf("\n[-] FALSE\n");
	else if (check == -1)
		printf("\nI can not start, stacka net ..!\n");

	free(vir);
	return 1;


}

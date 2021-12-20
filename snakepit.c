#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct drink{
	unsigned long long amount_sugar;
	char name[30];
	int drink_price;

};

struct character{
	char name[30];
	int age;
	struct drink *beverage;
};

struct raffle_ticket{
	void(*prize_won)();
	int ticket_number;
	char ticket_colour[30];
};


struct character *bloggs = NULL;
struct character *bartender = NULL;
struct raffle_ticket *ticket = NULL;
struct drink *beverage = NULL;

void dead_code(){
	__asm__(
		"pop %rax\n"
		"pop %rdx\n"
		"ret\n"
		"pop %rcx\n"
		"ret\n"
		"syscall\n"
		"ret\n"
	);
	puts("/bin/sh");
};

void loser(){
	printf("Sorry mate, no leaving till the RSM says so\n");
};

void leave_mess(){
		char password[256];
		printf("What's the secret password mate?\n");
		fgets(password,sizeof(password)-1,stdin);
		if(!strcmp(password,"0p3n_s3s4me")){
			printf("Correct!\n");
			ticket->prize_won();
		}
		else{
			ticket->prize_won = &loser;
			ticket->prize_won();
		}

};

void rename_beverage(){
	printf("You've decided you want to give your drink a more interesting name, what do you call it?\n");
	fgets(beverage->name,0x200,stdin);
};

void view_nutrition(){
	if(beverage != NULL){
		printf("========%s========\n",beverage->name);
		printf("Grams of sugar: %lu\n",beverage->amount_sugar);
		printf("RRP: $%u\n",beverage->drink_price);
	}
	else{
		printf("You attempt to view the nutritional information of your hand\n");	
	};
};

void print_menu(){
	printf("===========================================================\n");
	printf("Welcome to The Snake Pit, what can I getcha?\n");
	printf("1)Buy Raffle Ticket \n");
	printf("2)Throw Away Raffle Ticket\n");
	printf("3)Buy a beverage\n");
	printf("4)Throw away beverage\n");
	printf("5)Look at nutritional information\n");
	printf("6)Give your beverage a nickname\n");
	printf("7)Ask for permission to leave the event\n");
	printf("8)Quit\n");
	printf("===========================================================\n");
};


void print_plot(){
	printf("Young PTE Bloggs has been invited to a dining in night at the Sgts mess,\nbut he wants to go hit the town with the boys, can you get him out?  \n");

};

int take_input(char* buffer,  unsigned int length) 
{
    unsigned int inlen = read(0, buffer, length-1);
    buffer[inlen] = '\0';
    return inlen;
}

void toss_ticket(){
	printf("You casually toss your raffle ticket on the ground\n");
	free(ticket);
};

void toss_drink(){
	printf("You casually toss your soft drink on the ground\n");
	free(beverage);
};


void init_players(){
	bloggs = malloc(sizeof(struct character));
	bartender = malloc(sizeof(struct character));
};

int main(int argc, char **argv){
	print_plot();
	init_players();
	getchar();
	printf("PTE Bloggs approaches the bar\n\n\n");
	char resp[64];
	int choice = 0;
	while(choice != 8 ){
		print_menu();
		take_input(resp,sizeof(resp));
		choice = strtoul(resp,0,10);
		switch(choice){
			case 1:
				ticket = malloc(sizeof(struct raffle_ticket));
				ticket->prize_won = &loser;
				printf("Good luck mate!\n");
			break;
			case 2:
				if(ticket == NULL){
					printf("Gonna need to buy a ticket before you throw it out champ.\n");
				}else{
					toss_ticket();
				};
                        break;
			case 3:
				beverage = malloc(sizeof(struct drink));
				beverage->drink_price = 2;
				strcpy(beverage->name,"Coca Cola");
                                printf("Enjoy your drink mate!\n");

                        break;
			case 4:
				if(beverage == NULL){
                                        printf("Gonna need to buy a drink before you throw it out champ.\n");
                                }else{
					toss_drink();
				};

                        break;
			case 5:
				view_nutrition();
                        break;

			case 6:
				if(beverage == NULL){
					printf("I mean, you could try give your hand a nickname if you wanted to\n");

				}else{
					rename_beverage();
				};
			break;
			case 7:

				 if(ticket == NULL){
                                        printf("Gonna need to buy a ticket before you throw it out champ.\n");
                                }else{
					leave_mess();
					
				};

                        break;

		};

	}
	return 0;
};

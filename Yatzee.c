#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#define AANTAL_DEMO_STENEN 5 //niet gebruikt buiten democode

int showDie(char i); //draws dice + returns value
int dice1(char i); //used in showdie (prints shape of die)
int dice2(char i); //used in showdie (prints shape of die)
int dice3(char i); //used in showdie (prints shape of die)
int dice4(char i); //used in showdie (prints shape of die)
int dice5(char i); //used in showdie (prints shape of die)
int dice6(char i); //used in showdie (prints shape of die)
int throwDie(); //used in showdi

char Player1[15] = ""; //naam speler 1
char Player2[15] = ""; //naam speler 2

int Dobbelstenen[5]= {0,0,0,0,0}; //array van de gewerpte dobbelstenen
int Sortdobbelstenen[5] = {0,0,0,0,0}; // sorteert de array van dobbelstenen in een nieuwe array.
int Keepers[5]; //array die niet keepers bij houdt
int Scorespeler1[20]= {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}; // Scorespeler 1 bijhouden
int Scorespeler2[20]= {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}; // Scorespeler 2 bijhouden
int worp = 1;
int game = 1;
int winsspeler1 =0;
int winsspeler2 =0;


void sortstreet();
void printIntro(void); //intro
void scorebord(void); //functie voor het scorebord weer te geven
void throw(void); //functie die de beurten uit werkt
void sortdobbelstenen();
void scoreinvullen1();
void scoreinvullen2();
void keepers(); //functies voor de keepers bij te houden

int welkeSpeler(int Turn); //modulu operator to get player 1/2

int aces(); //functie voor het aantal enen
int twos(); //functie voor het aantal twee'en
int threes(); // functie voor het aantal drie'en
int fours(); // functie voor het aantal vieren
int fives(); // functie voor het aantal vijven
int sixes(); // functie voor het aantal zessen
int threeOfAKind(); //functie voor three of a kind
int fourOfAKind(); // functie voor four of a kind
int fullHouse(); //functie voor fullhouse
int smStreet(); //functie voor kleine straat
int lgStreet(); // functie grote straat
int yahtzee(); //functie Yahtzee
int chance(); //functie chance



int main(void)
{


	typedef enum
	{
		Idle_State,
		player1_State,
		player2_State,
		result_State,
	}
		fsmState;	


		fsmState nextState = Idle_State;
		while(1)
		{
			
			switch(nextState)
			{
					case Idle_State:
						printIntro();
						srand(time(NULL)); //random nummers worden gebasseerd op het huidige tijdstip 
			
						printf("\nSpeler 1 wat is je naam? ");
						scanf("%s",Player1);
			
						printf("\nSpeler 2 wat is je naam? ");
						scanf("%s",Player2);
			
						printf("\n%s en %s laten we beginnen \n", Player1, Player2);
			
						for(int i=0; i<5; i++)
						{
							for(int i=0; i<20; i++)
							{
								Scorespeler1[i]= -1;
								Scorespeler2[i]= -1;
							}
							for(int i=0; i<5; i++)
							{
								Dobbelstenen[i]= 0;
							}
							
								Scorespeler1[6] = 0;
								Scorespeler1[6] = Scorespeler2[6] =0;
								Scorespeler1[7] = Scorespeler2[7] =0;
								Scorespeler1[8] = Scorespeler2[8] =0;
					
								Scorespeler1[17] = Scorespeler2[17] =0;
								Scorespeler1[18] = Scorespeler2[18] =0;
								Scorespeler1[19] = Scorespeler2[19] =0;
								
								nextState = player1_State;
								break;
						
						}
						
					
					
					case player1_State:				
						
							printf("\n%s is aan de beurt\n", Player1);
							throw();
							printf("\n%s kies een lege positie voor de score in te vullen. (getal tussen 1 en 13)\n", Player1);
						
							scorebord();
							scoreinvullen1();
							scorebord();
							Sleep(2500);
							
							nextState = player2_State;
							break;
							
					
					
					case player2_State:
					
						
							printf("\n%s is aan de beurt\n", Player2);
							throw();
							printf("\n%s kies een lege positie voor de score in te vullen. (getal tussen 1 en 13)\n", Player2);
						
							scorebord();
							scoreinvullen2();
							scorebord();
							Sleep(2500);
							
						
						if( worp == 12)
						{
							nextState = result_State;
						}
						else
						{
							nextState = player1_State;
						}
						worp++;
						break;	
					
					
					case result_State:
						if(Scorespeler1[19]>Scorespeler2[19])
						{
							printf("\n%s heeft gewonnen \n", Player1);
							winsspeler1++;
						}
						else
						{
							printf("\n%s heeft gewonnen \n", Player2);
							winsspeler2++;
						}	
						if( game == 5)
						{
							if(winsspeler1>winsspeler2)
							{
								printf(" %s heeft gewonnen",Player1);
							}
							else
							{
								printf(" %s heeft gewonnen", Player2);
							}
						}	
					
			}	
		}			
			
}		

void scoreinvullen1()
{
	int positie = 0;
	
	int x=0;
	
	while(x<1)
	{
		scanf("%d",&positie);
		if(positie>0&&positie<7)
		{
			if(Scorespeler1[positie-1]==-1)
			{
				switch (positie) //dobbelsteen opties
				{
					case 1:
							Scorespeler1[0]=aces();
							x++;
							break;
					case 2:
							Scorespeler1[1]=twos();
							x++;
							break;
					case 3:
							Scorespeler1[2]=threes();
							x++;
							break;
					case 4:
							Scorespeler1[3]=fours();
							x++;
							break;
					case 5:
							Scorespeler1[4]=fives();
							x++;
							break;
					case 6:
							Scorespeler1[5]=sixes();
							x++;
							break;
				}
			}
			
		
			else
			{
				printf("\nGelieve een positie tussen 1 en 13 op te geven zonder score.\n");
			}
		}
		else
		{
			if(Scorespeler1[positie+2]==-1)
			{
				switch (positie)
				{
					case 7:
							Scorespeler1[9]=threeOfAKind();
							x++;
							break;
					case 8:
							Scorespeler1[10]=fourOfAKind();
							x++;
							break;
					case 9:
							Scorespeler1[11]=fullHouse();
							x++;
							break;
					case 10:
							Scorespeler1[12]=smStreet();
							x++;
							break;
					case 11:
							Scorespeler1[13]=lgStreet();
							x++;
							break;						
					case 12:
							Scorespeler1[14]=yahtzee();
							x++;
							break;
					case 13:
							Scorespeler1[15]=chance();
							x++;
							break;
					default:
							printf("\nGelieve een positie tussen 1 en 13 op te geven zonder score.\n");
							x++;
							break;
				}
			}
			
			else if(positie==12)
			{
				Scorespeler1[16]=100;
			}
			
			
			else
			{
				printf("\nGelieve een positie tussen 1 en 13 op te geven zonder score.\n");
			}
		}
		
	}
	
	for(int i=0; i>6; i++)
	{
		Scorespeler1[6] = Scorespeler1[6] + Scorespeler1[i];
	}
	if(Scorespeler1[6]>63)
	{
		Scorespeler1[7] =35;
		
	}
	Scorespeler1[8] = Scorespeler1[6]+ Scorespeler1[7];
	
	Scorespeler1[17] = Scorespeler1[8];
	
	for(int i=0; i>6; i++)
	{
		Scorespeler1[18] = Scorespeler1[18] + Scorespeler1[i+9];
	}
	
	Scorespeler1[19] = Scorespeler1[17]+ Scorespeler1[18];
}


void scoreinvullen2()
{
	int positie = 0;
	int x=0;
	{
		scanf("%d",&positie);
		if(positie>0&&positie<7)
		{
			if(Scorespeler2[positie-1]==-1)
			{
				switch (positie) //dobbelsteen opties
				{
					case 1:
							Scorespeler2[0]=aces();
							x++;
							break;
					case 2:
							Scorespeler2[1]=twos();
							x++;
							break;
					case 3:
							Scorespeler2[2]=threes();
							x++;
							break;
					case 4:
							Scorespeler2[3]=fours();
							x++;
							break;
					case 5:
							Scorespeler2[4]=fives();
							x++;
							break;
					case 6:
							Scorespeler2[5]=sixes();
							x++;
							break;
				}
			}
			
		
			else
			{
				printf("\nGelieve een positie tussen 1 en 13 op te geven zonder score.\n");
			}
		}
		else
		{
			if(Scorespeler2[positie+2]==-1)
			{
				switch (positie)
				{
					case 7:
							Scorespeler2[9]=threeOfAKind();
							x++;
							break;
					case 8:
							Scorespeler2[10]=fourOfAKind();
							x++;
							break;
					case 9:
							Scorespeler2[11]=fullHouse();
							x++;
							break;
					case 10:
							Scorespeler2[12]=smStreet();
							x++;
							break;
					case 11:
							Scorespeler2[13]=lgStreet();
							x++;
							break;						
					case 12:
							Scorespeler2[14]=yahtzee();
							x++;
							break;
					case 13:
							Scorespeler2[15]=chance();
							x++;
							break;
					default:
							printf("\nGelieve een positie tussen 1 en 13 op te geven zonder score.\n");
							break;
				}
			}
			
			else if(positie==12)
			{
				Scorespeler2[16]=100;
			}
			
			
			else
			{
				printf("\nGelieve een positie tussen 1 en 13 op te geven zonder score.\n");
			}
		}
	}
	
	Scorespeler2[6] = 0;
	for(int i=0; i>6; i++)
	{
		Scorespeler2[6] = Scorespeler2[6] + Scorespeler2[i];
	}
	if(Scorespeler2[6]>63)
	{
		Scorespeler2[7] =35;
	}
	Scorespeler2[8] = Scorespeler2[6]+ Scorespeler2[7];
	
	Scorespeler2[17] = Scorespeler2[8];
	
	for(int i=0; i>6; i++)
	{
		Scorespeler2[18] = Scorespeler2[18] + Scorespeler2[i+9];
	}
	
	Scorespeler2[19] = Scorespeler2[17]+ Scorespeler2[18];
}


void throw()
{
	
	for(int i = 0; i<5; i++)
	{
		Dobbelstenen[i] = showDie(i+1); //waardes toekennen aan de dobbelstenen zonder waardes.
		Sleep(1000);
	}
	keepers();
	printf("\nWorp voltooid, de eind waarde van de dobbelstenen van 1 tot 5 zijn: %d %d %d %d %d \n", Dobbelstenen[0], Dobbelstenen[1], Dobbelstenen[2], Dobbelstenen[3], Dobbelstenen[4]);
	// score invullen met een switch
	
}


void keepers()
{
	int input = 1;
	int i = 0; 
	int x=0;
	
	printf("\nWaardes van de dobbelstenen 1 tot 5:  %d %d %d %d %d \nGeef de nummers van de dobbelstenen die je opnieuw wilt gooien (niet-keepers tussen 1-5), geef 0 in om te stoppen ", Dobbelstenen[0], Dobbelstenen[1], Dobbelstenen[2], Dobbelstenen[3], Dobbelstenen[4]);
	
	do
	{
		scanf("%d",&input);
		printf("\n");
		input = input -1;
		
		if(input<5&&input>-1)
		{
			Keepers[i] = input;
		}
		else if(input ==-1)
		{
			Keepers[i] = input;
		}
		else
		{
			printf("%d buiten bereik (keepers selecteren tussen 1-5)\n", input+1);
		}
		i++;		
	}
	while(input != -1 && i<5);

	while(x<(i))
	{
		if(Keepers[x]>=-1)
		{
			int j = Keepers[x];
			Dobbelstenen[j] = 0;
			x++;
		}
	}
	for(i = 0; i<5; i++)
	{
		if (Dobbelstenen[i]==0)
		{
			Dobbelstenen[i] = showDie(i+1); //waardes toekennen aan de dobbelstenen zonder waardes.
			Sleep(1000);
		}
	}
	printf("\n");
	if(Keepers[0]!=-1)
	{
		input = 1;
		i=0;
		printf("\nWaardes van de dobbelstenen 1 tot 5:  %d %d %d %d %d \nGeef de nummers van de dobbelstenen die je opnieuw wilt gooien (niet-keepers tussen 1-5), geef 0 in om te stoppen ", Dobbelstenen[0], Dobbelstenen[1], Dobbelstenen[2], Dobbelstenen[3], Dobbelstenen[4]);
		do
		{
			scanf("%d",&input);
			printf("\n");
			input = input -1;
			
			if(input<5)
			{
				Keepers[i] = input;
			}
			else if(input ==-1)
			{
				Keepers[i] = input;
			}
			else
			{
				printf("%d buiten bereik (keepers selecteren tussen 1-5)\n", input+1);
			}
			i++;		
		}
		while(input != -1 && i<5);
		x=0;
		while(x<(i))
		{
			if(Keepers[x]>=-1)
			{
				int j = Keepers[x];
				Dobbelstenen[j] = 0;
				x++;
			}
		}
		for(i = 0; i<5; i++)
		{
			if (Dobbelstenen[i]==0)
			{
				Dobbelstenen[i] = showDie(i+1); //waardes toekennen aan de dobbelstenen zonder waardes.
				Sleep(1000);
			}
		}
	}
	
	//niet keepers worden gelijkgesteld aan 0 en daardoor opnieuw gegooit.
}


void sortdobbelstenen()
{
	for(int i=0; i<5; i++)
	{
		Sortdobbelstenen[i] = Dobbelstenen[i];
	}
	for(int j = 0; j < 5-1; j++)
	{
		for(int x = 0; x < 5-1; x++)
		{
			if(Sortdobbelstenen[x+1] < Sortdobbelstenen[x])
			{
				int wissel = Sortdobbelstenen[x+1];
				Sortdobbelstenen[x+1] = Sortdobbelstenen[x];
				Sortdobbelstenen[x] = wissel;
			}
		}
	}
}


void scorebord()
{
		printf("                                				 Speler      Speler     \n");
		printf("   |------------------------------------|		|-------|	|-------|	\n");
		printf("   | Upper Section			|		|   	|	|   	|	\n");                                   
		printf("   |------------------------------------|		|-------|	|-------|	\n");
	
	if(Scorespeler1[0]==-1 && Scorespeler2[0]==-1)
	{
		printf("   | Count and add only Aces		|		|   	| 	|   	| Dit is keuze 1	\n");
	}
	else if(Scorespeler1[0]!=-1 && Scorespeler2[0]==-1)
	{
		printf("   | Count and add only Aces		|		|   %d	| 	|   	| Dit is keuze 1	\n", Scorespeler1[0]);
	}
	else if(Scorespeler1[0]==-1 && Scorespeler2[0]!=-1)
	{
		printf("   | Count and add only Aces		|		|   	| 	|   %d	| Dit is keuze 1	\n", Scorespeler2[0]);
	}
	else
	{
		printf("   | Count and add only Aces		|		|   %d	| 	|   %d	| Dit is keuze 1	\n", Scorespeler1[0],Scorespeler2[0]);
	}
	
		printf("   |------------------------------------|	    	|-------|	|-------|	\n");
	
	if(Scorespeler1[1]==-1 && Scorespeler2[1]==-1)
	{
		printf("   | Count and add only Twos 	 	|		|   	| 	|   	| Dit is keuze 2	\n");
	}
	else if(Scorespeler1[1]!=-1 && Scorespeler2[1]==-1)
	{
		printf("   | Count and add only Twos 	 	|		|   %d	| 	|   	| Dit is keuze 2	\n", Scorespeler1[1]);
	}
	else if(Scorespeler1[1]==-1 && Scorespeler2[1]!=-1)
	{
		printf("   | Count and add only Twos		|		|   	| 	|   %d	| Dit is keuze 2	\n", Scorespeler2[1]);
	}
	else
	{
		printf("   | Count and add only Twos  		|		|   %d	|	|   %d	| Dit is keuze 2	\n", Scorespeler1[1],Scorespeler2[1]);
	}
	
		printf("   |------------------------------------|   		|-------|	|-------|	\n"); 
	
	if(Scorespeler1[2]==-1 && Scorespeler2[2]==-1)
	{
		printf("   | Count and add only Threes		|		|   	|	|   	| Dit is keuze 3	\n");
	}
	else if(Scorespeler1[2]!=-1 && Scorespeler2[2]==-1)
	{
		printf("   | Count and add only Threes		|		|   %d	|	|   	| Dit is keuze 3	\n", Scorespeler1[2]);
	}
	else if(Scorespeler1[2]==-1 && Scorespeler2[2]!=-1)
	{
		printf("   | Count and add only Threes		|		|   	|	|   %d	| Dit is keuze 3	\n", Scorespeler2[2]);
	}
	else
	{
		printf("   | Count and add only Threes		|		|   %d	|	|   %d	| Dit is keuze 3	\n", Scorespeler1[2], Scorespeler2[2]);
	}

		printf("   |------------------------------------|    		|-------|	|-------|	\n");
	
	if(Scorespeler1[3]==-1 && Scorespeler2[3]==-1)
	{
		printf("   | Count and add only Fours		|	 	|   	|	|   	| Dit is keuze 4	\n");
	}
	else if(Scorespeler1[3]!=-1 && Scorespeler2[3]==-1)
	{
		printf("   | Count and add only Fours		|	 	|   %d 	|	|   	| Dit is keuze 4	\n", Scorespeler1[3]);
	}
	else if(Scorespeler1[3]==-1 && Scorespeler2[3]!=-1)
	{
		printf("   | Count and add only Fours 		|	 	|   	|	|   %d	| Dit is keuze 4	\n", Scorespeler2[3]);
	}
	else
	{	
		printf("   | Count and add only Fours 		|	 	|   %d 	|	|   %d	| Dit is keuze 4	\n", Scorespeler1[3], Scorespeler2[3]);
	}
	
		printf("   |------------------------------------|		|-------|	|-------|	\n");
	
	if(Scorespeler1[4]==-1 && Scorespeler2[4]==-1)
	{
		printf("   | Count and add only Fives	 	|	 	|   	|	|   	| Dit is keuze 5	\n");
	}
	else if(Scorespeler1[4]!=-1 && Scorespeler2[4]==-1)
	{
		printf("   | Count and add only Fives	 	|	 	|  %d	|	|   	| Dit is keuze 5	\n", Scorespeler1[4]);
	}
	else if(Scorespeler1[4]==-1 && Scorespeler2[4]!=-1)
	{
		printf("   | Count and add only Fives	 	|    		|   	|	|   %d	| Dit is keuze 5	\n", Scorespeler2[4]);
	}
	else
	{
		printf("   | Count and add only Fives		|   	 	|   %d	|	|   %d	| Dit is keuze 5	\n", Scorespeler1[4], Scorespeler2[4]); 
	}

		printf("   |------------------------------------|		|-------|	|-------|	\n"); 
	
	if(Scorespeler1[5]==-1 && Scorespeler2[5]==-1)
	{
		printf("   | Count and add only Sixes	 	|    		|   	|	|   	| Dit is keuze 6	\n");
	}
	else if(Scorespeler1[5]!=-1 && Scorespeler2[5]==-1)
	{
		printf("   | Count and add only Sixes		|    		|   %d	|	|   	| Dit is keuze 6	\n", Scorespeler1[5]);
	}
	else if(Scorespeler1[5]==-1 && Scorespeler2[5]!=-1)
	{
		printf("   | Count and add only Sixes		|    		|   	|	|   %d	| Dit is keuze 6	\n", Scorespeler2[5]);
	}
	else
	{
		printf("   | Count and add only Sixes 		|    		|   %d	|	|   %d	| Dit is keuze 6	\n", Scorespeler1[5], Scorespeler2[5]);
	}	

		printf("   |------------------------------------|    		|-------|	|-------|	\n");

		printf("   | Total  				|    		|   %d	|	|   %d	|	\n", Scorespeler1[6], Scorespeler2[6]); 

		printf("   |------------------------------------|		|-------|	|-------|	\n");

		printf("   | 63 + scores a 35 Bonus 	 	|		|   %d	|	|   %d	|	\n", Scorespeler1[7], Scorespeler2[7]);                                    

		printf("   |------------------------------------|		|-------|	|-------|	\n");  

		printf("   | Total of Upper Section 	 	|		|   %d	|	|   %d	|	\n", Scorespeler1[8], Scorespeler2[8]); 

		printf("   |____________________________________|		|_______|	|_______|	\n");
	
	if(Scorespeler1[9]==-1 && Scorespeler2[9]==-1)
	{
		printf("   | 3 of a kind   total of all dice 	|		|   	|	|   	| Dit is keuze 7	\n");
	}
	else if(Scorespeler1[9]!=-1 && Scorespeler2[9]==-1)
	{
		printf("   | 3 of a kind   total of all dice 	|		|   %d	|	|   	| Dit is keuze 7	\n", Scorespeler1[9]);
	}
	else if(Scorespeler1[9]==-1 && Scorespeler2[9]!=-1)
	{
		printf("   | 3 of a kind   total of all dice  	|		|   	|	|   %d	| Dit is keuze 7	\n", Scorespeler2[9]);
	}
	else
	{
		printf("   | 3 of a kind   total of all dice  	|		|   %d	|	|   %d	| Dit is keuze 7	\n", Scorespeler1[9], Scorespeler2[9]);
	}
	
		printf("   |------------------------------------|		|-------|	|-------|	\n");
	
	if(Scorespeler1[10]==-1 && Scorespeler2[10]==-1)
	{
		printf("   | 4 of a kind   total of all dice 	|		|   	|	|   	| Dit is keuze 8	\n");
	}
	else if(Scorespeler1[10]!=-1 && Scorespeler2[10]==-1)
	{
		printf("   | 4 of a kind   total of all dice 	|		|   %d	|	|   	| Dit is keuze 8	\n", Scorespeler1[10]);
	}
	else if(Scorespeler1[10]==-1 && Scorespeler2[10]!=-1)
	{
		printf("   | 4 of a kind   total of all dice 	|		|   	|	|   %d	| Dit is keuze 8	\n", Scorespeler2[10]);
	}
	else
	{
		printf("   | 4 of a kind   total of all dice 	|		|   %d	|	|   %d	| Dit is keuze 8	\n", Scorespeler1[10], Scorespeler2[10]);
	}
	
		printf("   |------------------------------------|		|-------|	|-------|	\n");
	
	if(Scorespeler1[11]==-1 && Scorespeler2[11]==-1)
	{
		printf("   | Full House                   25 	|		|   	|	|   	| Dit is keuze 9	\n");
	}
	else if(Scorespeler1[11]!=-1 && Scorespeler2[11]==-1)
	{
		printf("   | Full House                   25 	|		|   %d	|	|   	| Dit is keuze 9	\n", Scorespeler1[11]);
	}
	else if(Scorespeler1[11]==-1 && Scorespeler2[11]!=-1)
	{
		printf("   | Full House                   25 	|		|   	|	|   %d	| Dit is keuze 9	\n", Scorespeler2[11]);
	}
	else
	{
		printf("   | Full House                   25 	|		|   %d	|	|   %d	| Dit is keuze 9	\n", Scorespeler1[11], Scorespeler2[11]);
	}
	
		printf("   |------------------------------------|		|-------|	|-------|	\n");

	if(Scorespeler1[12]==-1 && Scorespeler2[12]==-1)
	{
		printf("   | Low straignt                 30 	|		|   	|	|   	| Dit is keuze 10	\n");
	}
	else if(Scorespeler1[12]!=-1 && Scorespeler2[12]==-1)
	{
		printf("   | Low straignt                 30 	|		|   %d	|	|   	| Dit is keuze 10	\n", Scorespeler1[12]);
	}
	else if(Scorespeler1[12]==-1 && Scorespeler2[12]!=-1)
	{
		printf("   | Low straignt                 30 	|		|   	|	|   %d	| Dit is keuze 10	\n", Scorespeler2[12]);
	}
	else
	{
		printf("   | Low straignt                 30 	|		|   %d	|	|   %d	| Dit is keuze 10	\n", Scorespeler1[12], Scorespeler2[12]);
	}
	
		printf("   |------------------------------------|		|-------|	|-------|	\n");
	
	if(Scorespeler1[13]==-1 && Scorespeler2[13]==-1)
	{
		printf("   | High Straight                40 	|		|   	|	|   	| Dit is keuze 11	\n");
	}
	else if(Scorespeler1[13]!=-1 && Scorespeler2[13]==-1)
	{
		printf("   | High Straight                40 	|		|   %d	|	|   	| Dit is keuze 11	\n", Scorespeler1[13]);
	}
	else if(Scorespeler1[13]==-1 && Scorespeler2[13]!=-1)
	{
		printf("   | High Straight                40 	|		|   	|	|   %d	| Dit is keuze 11	\n", Scorespeler2[13]);
	}
	else
	{
		printf("   | High Straight                40 	|		|   %d	|	|   %d	| Dit is keuze 11	\n", Scorespeler1[13], Scorespeler2[13]);
	}
		printf("   |------------------------------------|		|-------|	|-------|	\n");
	
	if(Scorespeler1[14]==-1 && Scorespeler2[14]==-1)
	{
		printf("   | Yahtzee                      50 	|		|   	|	|   	| Dit is keuze 12	\n");
	}
	else if(Scorespeler1[14]!=-1 && Scorespeler2[14]==-1)
	{
		printf("   | Yahtzee                      50 	|		|   %d	|	|   	| Dit is keuze 12	\n", Scorespeler1[14]);
	}
	else if(Scorespeler1[14]==-1 && Scorespeler2[14]!=-1)
	{
		printf("   | Yahtzee                      50 	|		|   	|	|   %d	| Dit is keuze 12	\n", Scorespeler2[14]);
	}
	else
	{
		printf("   | Yahtzee                      50 	|		|   %d	|	|   %d	| Dit is keuze 12	\n", Scorespeler1[14], Scorespeler2[14]);
	}
	
		printf("   |------------------------------------|		|-------|	|-------|	\n");
	
	if(Scorespeler1[15]==-1 && Scorespeler2[15]==-1)
	{
		printf("   | chance        Total of all dice 	|		|   	|	|   	| Dit is keuze 13	\n");
	}
	else if(Scorespeler1[15]!=-1 && Scorespeler2[15]==-1)
	{
		printf("   | chance        Total of all dice 	|		|   %d	|	|   	| Dit is keuze 13	\n", Scorespeler1[15]);
	}
	else if(Scorespeler1[15]==-1 && Scorespeler2[15]!=-1)
	{
		printf("   | chance        Total of all dice 	|		|   	|	|   %d	| Dit is keuze 13	\n", Scorespeler2[15]);
	}
	else
	{
		printf("   | chance        Total of all dice 	|		|   %d	|	|   %d	| Dit is keuze 13	\n", Scorespeler1[15], Scorespeler2[15]);
	}
	
		printf("   |------------------------------------|		|-------|	|-------|	\n");
	
	if(Scorespeler1[16]==-1 && Scorespeler2[16]==-1)
	{
		printf("   | Yahtzee Bonus               100 	|		|   	|	|   	|	\n");
	}
	else if(Scorespeler1[16]!=-1 && Scorespeler2[16]==-1)
	{
		printf("   | Yahtzee Bonus               100 	|		|   %d	|	|   	|	\n", Scorespeler1[16]);
	}
	else if(Scorespeler1[16]==-1 && Scorespeler2[16]!=-1)
	{
		printf("   | Yahtzee Bonus               100 	|		|   	|	|   %d	|	\n", Scorespeler2[16]);
	}
	else
	{
		printf("   | Yahtzee Bonus               100 	|		|   %d	|	|   %d	|	\n", Scorespeler1[16], Scorespeler2[16]);
	}
	
		printf("   |------------------------------------|		|-------|	|-------|	\n");

		printf("   |          Total of Lower Section 	|		|   %d	|	|   %d	|	\n", Scorespeler1[17], Scorespeler2[17]); 

		printf("   |------------------------------------|		|-------|	|-------|	\n");

		printf("   |          Total of Upper Section 	|		|   %d	|	|   %d	|	\n", Scorespeler1[18], Scorespeler2[18]); 

		printf("   |------------------------------------|		|-------|	|-------|	\n");

		printf("   |                     Grand Total 	|		|   %d	|	|   %d	|	\n", Scorespeler1[19], Scorespeler2[19]); 

		printf("   |------------------------------------|		|-------|	|-------|	\n");

printf("\n");
printf("\n");
	
}


int aces()
{
	int aantal =0;
	for(int i=0; i<5; i++)
	{
		if(Dobbelstenen[i]==1)
		{
			aantal++;
		}
	}
	int score1 = aantal;
	return score1;
}


int twos()
{
	int aantal =0;
	for(int i=0; i<5; i++)
	{
		if(Dobbelstenen[i]==2)
		{
			aantal++;
		}
		
	}
	int score2 = aantal *2;
	return score2;
}


int threes()
{
	int aantal =0;
	for(int i=0; i<5; i++)
	{
		if(Dobbelstenen[i]==3)
		{
			aantal++;
		}
	}
	int score3 = aantal *3;
	return score3;
}


int fours()
{
	int aantal =0;
	for(int i=0; i<5; i++)
	{
		if(Dobbelstenen[i]==4)
		{
			aantal++;
		}
	}
	int score4 = aantal *4;
	return score4;
}


int fives()
{
	int aantal =0;
	for(int i=0; i<5; i++)
	{
		if(Dobbelstenen[i]==5)
		{
			aantal++;
		}
	}
	int score5 = aantal *5;
	return score5;
}


int sixes()
{
	int aantal =0;
	for(int i=0; i<5; i++)
	{
		if(Dobbelstenen[i]==6)
		{
			aantal++;
		}
	}
	int score6 = aantal *6;
	return score6;
}


int threeOfAKind()
{
	sortdobbelstenen();
	int score = 0;
	
	
	if(((Sortdobbelstenen[0] == Sortdobbelstenen[1]) && (Sortdobbelstenen[0] == Sortdobbelstenen[2])) || ((Sortdobbelstenen[1] == Sortdobbelstenen[2]) && (Sortdobbelstenen[1] == Sortdobbelstenen[3])) || ((Sortdobbelstenen[2] == Sortdobbelstenen[3]) && (Sortdobbelstenen[3]==Sortdobbelstenen[4])))
	{
		for(int i=0; i<5; i++)
		{
			score = score + Dobbelstenen[i];
		}
	}
	return score;
}


int fourOfAKind()
{
	sortdobbelstenen();
	int score = 0;
	
	if(((Sortdobbelstenen[0] == Sortdobbelstenen[1]) && (Sortdobbelstenen[0] == Sortdobbelstenen[2]) && (Sortdobbelstenen[0] == Sortdobbelstenen[3])) || ((Sortdobbelstenen[1] == Sortdobbelstenen[2]) && (Sortdobbelstenen[1] == Sortdobbelstenen[3]) && (Sortdobbelstenen[1] == Sortdobbelstenen[4])))
	{
		score =30;
	}
	return score;
}


int fullHouse()
{
	sortdobbelstenen();
	int scoreFull = 0;
	
	if(((Sortdobbelstenen[0] == Sortdobbelstenen[1]) && (Sortdobbelstenen[2] == Sortdobbelstenen[3] && Sortdobbelstenen[2] == Sortdobbelstenen[4])) || ((Sortdobbelstenen[0] == Sortdobbelstenen[1] && Sortdobbelstenen[0] == Sortdobbelstenen[2])  && (Sortdobbelstenen[3] == Sortdobbelstenen[4])))
	{
		scoreFull =25;
	}
	
	
	return scoreFull;
}


int smStreet()
{
	int scoreSmStreet = 0;
	sortstreet();
	
	if(((Sortdobbelstenen[0]==(Sortdobbelstenen[1]-1)) && (Sortdobbelstenen[1] == (Sortdobbelstenen[2]-1)) && (Sortdobbelstenen[2] == (Sortdobbelstenen[3]-1))) || ((Sortdobbelstenen[1]==(Sortdobbelstenen[2]-1)) && (Sortdobbelstenen[2] == (Sortdobbelstenen[3]-1)) && (Sortdobbelstenen[3] == (Sortdobbelstenen[4]-1))))
	{
		scoreSmStreet = 30;
	}
	
	return scoreSmStreet;
}

void sortstreet()
{
	int f=4;
	for(int i=0; i<5; i++)
	{
		Sortdobbelstenen[i] = Dobbelstenen[i];
	}
	
	for(int j = 0; j < 4; j++)
	{
		for(int x = 0; x < f; x++)
		{
			if(Sortdobbelstenen[x+1] < Sortdobbelstenen[x])
			{
				int wissel = Sortdobbelstenen[x+1];
				Sortdobbelstenen[x+1] = Sortdobbelstenen[x];
				Sortdobbelstenen[x] = wissel;
				
			}
			else if(Sortdobbelstenen[x+1] == Sortdobbelstenen[x])
			{
				int wissel = Sortdobbelstenen[x+1];
				Sortdobbelstenen[x+1] = Sortdobbelstenen[4];
				Sortdobbelstenen[4] = wissel;
				f--;
			}
		}
	}
}

int lgStreet() 
{
	int scoreLgStreet = 0;	
	sortdobbelstenen();

	if((Sortdobbelstenen[0] == (Sortdobbelstenen[1]-1)) && ((Sortdobbelstenen[1]-1) == (Sortdobbelstenen[2]-2)) && ((Sortdobbelstenen[2]-2) == (Sortdobbelstenen[3]-3)) && ((Sortdobbelstenen[3]-3) == (Sortdobbelstenen[4]-4)))
	{
		scoreLgStreet = 40;
	}
	
	return scoreLgStreet;
}


int yahtzee()
{
	int scoreYathzee = 0;
	sortdobbelstenen();
	
	if((Sortdobbelstenen[0] == Sortdobbelstenen[1]) && (Sortdobbelstenen[1] == Sortdobbelstenen[2]) && (Sortdobbelstenen[2] == Sortdobbelstenen[3]) && (Sortdobbelstenen[3]==Sortdobbelstenen[4]))
	{
		scoreYathzee =50;
	}
	
	return scoreYathzee;
}


int chance()
{
	int scoreChance = 0;
	int som =0;
	
	for(int i=0; i<5; i++)
	{
		som = som + Dobbelstenen[i];
	}
	scoreChance = som;	
	
	return scoreChance;
}


int welkeSpeler(int Turn)
{
	int rest = 0;
	rest = Turn%2;
	return rest;
}


int showDie(char i)
{
    int die = throwDie(); //die number AND VALUE
    int eyes = 0;
	
    switch (die) //dobbelsteen opties
    {
		case 1:
				eyes = dice1(i);
				break;
		case 2:
				eyes = dice2(i);
				break;
		case 3:
				eyes = dice3(i);
				break;
		case 4:
				eyes = dice4(i);
				break;
		case 5:
				eyes = dice5(i);
				break;
		case 6:
				eyes = dice6(i);
				break;                
		default: //De default voorkomt het breken van de code, dit is geen mogelijke optie
				eyes = 0;
				printf("\nDie off the tabel! Try again!\n"); 
				break;
        }
		
    return eyes;
}


int throwDie()
{
        int getal = (rand() % 6) +1; //random number between 0 and 5 we add one to make it between 1 and 6
        return getal;
}


int dice1(char i)
{
        int a=1;
        printf("      .-------------.    \n");
		printf("     /             /|    \n");
		printf("    /      o      / |    \n");
		printf("   /_____________/  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  /     \n");
		printf("   |             | /     \n");
		printf("   |             |/       \n");
		printf("%d. '-------------'        \n",i);
        return a;
}


int dice2(char i)
{
        int a=2;
        printf("      .-------------.    \n");
		printf("     /  o          /|    \n");
		printf("    /             / |    \n");
		printf("   /__________o__/  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  /     \n");
		printf("   |             | /     \n");
		printf("   |             |/       \n");
		printf("%d. '-------------'        \n",i);
        return a;
}


int dice3(char i)
{
        int a=3;
        printf("      .-------------.    \n");
		printf("     /  o          /|    \n");
		printf("    /      o      / |    \n");
		printf("   /___________o_/  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  /     \n");
		printf("   |             | /     \n");
		printf("   |             |/       \n");
		printf("%d. '-------------'        \n",i);
        return a;
}


int dice4(char i)
{
        int a=4;
        printf("      .-------------.    \n");
		printf("     /  o       o  /|    \n");
		printf("    /             / |    \n");
		printf("   /__o________o_/  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  /     \n");
		printf("   |             | /     \n");
		printf("   |             |/       \n");
		printf("%d. '-------------'        \n",i);
        return a;
}


int dice5(char i)
{
        int a=5;
        printf("      .-------------.    \n");
		printf("     /  o       o  /|    \n");
		printf("    /      o      / |    \n");
		printf("   /__o_______o__/  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  /     \n");
		printf("   |             | /     \n");
		printf("   |             |/       \n");
		printf("%d. '-------------'        \n",i);
        return a;
}


int dice6(char i)
{
        int a=6;
        printf("      .-------------.    \n");
		printf("     /  o       o  /|    \n");
		printf("    /  o       o  / |    \n");
		printf("   /__o_______o__/  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  /     \n");
		printf("   |             | /     \n");
		printf("   |             |/       \n");
		printf("%d. '-------------'        \n",i);
        return a;
}


void printIntro(void)
{
printf(" .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.   \n");
printf("| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |  \n");
printf("| | _____  _____ | || |  _________   | || |   _____      | || |     ______   | || |     ____     | || | ____    ____ | || |  _________   | |  \n");
printf("| ||_   _||_   _|| || | |_   ___  |  | || |  |_   _|     | || |   .' ___  |  | || |   .'    `.   | || ||_   \\  /   _|| || | |_   ___  |  | |  \n");
printf("| |  | | /\\ | |  | || |   | |_  \\_|  | || |    | |       | || |  / .'   \\_|  | || |  /  .--.  \\  | || |  |   \\/   |  | || |   | |_  \\_|  | |  \n");
printf("| |  | |/  \\| |  | || |   |  _|  _   | || |    | |   _   | || |  | |         | || |  | |    | |  | || |  | |\\  /| |  | || |   |  _|  _   | |  \n");
printf("| |  |   /\\   |  | || |  _| |___/ |  | || |   _| |__/ |  | || |  \\ `.___.'\\  | || |  \\  `--'  /  | || | _| |_\\/_| |_ | || |  _| |___/ |  | |  \n");
printf("| |  |__/  \\__|  | || | |_________|  | || |  |________|  | || |   `._____.'  | || |   `.____.'   | || ||_____||_____|| || | |_________|  | |  \n");
printf("| |              | || |              | || |              | || |              | || |              | || |              | || |              | |  \n");
printf("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |  \n");
printf(" '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'   \n");
printf(" .----------------.  .----------------.                                                                                                       \n");
printf("| .--------------. || .--------------. |                                                                                                      \n");
printf("| |  _________   | || |     ____     | |                                                                                                      \n");
printf("| | |  _   _  |  | || |   .'    `.   | |                                                                                                      \n");
printf("| | |_/ | | \\_|  | || |  /  .--.  \\  | |                                                                                                      \n");
printf("| |     | |      | || |  | |    | |  | |                                                                                                      \n");
printf("| |    _| |_     | || |  \\  `--'  /  | |                                                                                                      \n");
printf("| |   |_____|    | || |   `.____.'   | |                                                                                                      \n");
printf("| |              | || |              | |                                                                                                      \n");
printf("| '--------------' || '--------------' |                                                                                                      \n");
printf(" '----------------'  '----------------'                                                                                                       \n");
printf(" .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.   \n");
printf("| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |  \n");
printf("| |  ____  ____  | || |      __      | || |  ____  ____  | || |  _________   | || |   ________   | || |  _________   | || |  _________   | |  \n");
printf("| | |_  _||_  _| | || |     /  \\     | || | |_   ||   _| | || | |  _   _  |  | || |  |  __   _|  | || | |_   ___  |  | || | |_   ___  |  | |  \n");
printf("| |   \\ \\  / /   | || |    / /\\ \\    | || |   | |__| |   | || | |_/ | | \\_|  | || |  |_/  / /    | || |   | |_  \\_|  | || |   | |_  \\_|  | |  \n");
printf("| |    \\ \\/ /    | || |   / ____ \\   | || |   |  __  |   | || |     | |      | || |     .'.' _   | || |   |  _|  _   | || |   |  _|  _   | |  \n");
printf("| |    _|  |_    | || | _/ /    \\ \\_ | || |  _| |  | |_  | || |    _| |_     | || |   _/ /__/ |  | || |  _| |___/ |  | || |  _| |___/ |  | |  \n");
printf("| |   |______|   | || ||____|  |____|| || | |____||____| | || |   |_____|    | || |  |________|  | || | |_________|  | || | |_________|  | |  \n");
printf("| |              | || |              | || |              | || |              | || |              | || |              | || |              | |  \n");
printf("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |  \n");
printf(" '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'   \n\n");


printf("<< Uitleg voeg je hier toe>>\n");
}

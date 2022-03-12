#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NALIMENTI 10
#define NBIBITE 5
#define NSCONTRINO 20

int main()
{
	typedef char string[20]; 
	float totscontrino;
	float totpagamento;
	int menu;
	int quantita;
	int x;

	int n;
	int cond;
	
	string scontrino[NSCONTRINO];
	float costo[NSCONTRINO];
	
	
	float prezzoalimenti[NALIMENTI];
	string nomealimenti[NALIMENTI];
	int alimenti[NALIMENTI];
	int i;

	string nomebibite[NBIBITE];
	float prezzobibite[NBIBITE];
	int bibite[NBIBITE];
	
	strcpy(nomealimenti[0],"Big mac");
	prezzoalimenti[0]= 4.53;
	strcpy(nomealimenti[1],"Cheeseburger");
	prezzoalimenti[1]=1.44;
	strcpy(nomealimenti[2],"MyselectionBBQ");
	prezzoalimenti[2]=6.09;
	strcpy(nomealimenti[3],"Myselectionbacon");
	prezzoalimenti[3]=6.14;
	strcpy(nomealimenti[4],"Crispymcbacon");
	prezzoalimenti[4]=4.74;
	strcpy(nomealimenti[5],"Mcchicken");
	prezzoalimenti[5]=4.53;
	strcpy(nomealimenti[6],"Chickenmcnuggets");
	prezzoalimenti[6]=4.56;
	strcpy(nomealimenti[7],"Insalata mista");
	prezzoalimenti[7]=4.60;
	strcpy(nomealimenti[8],"Patatine");
	prezzoalimenti[8]=1.52;
	strcpy(nomealimenti[9],"Gelato");
	prezzoalimenti[9]=2.50;
	
	strcpy(nomebibite[0],"Coca Cola");
	prezzobibite[0]=1.70;
	strcpy(nomebibite[1],"Sprite");
	prezzobibite[1]=1.70;
	strcpy(nomebibite[2],"Acqua naturale");
	prezzobibite[2]=1.05;
	strcpy(nomebibite[3],"Acqua frizzante");
	prezzobibite[3]=1.05;
	strcpy(nomebibite[4],"Fanta");
	prezzobibite[4]=1.70;
	
	printf("Inserisci la quantita' per ogni alimento\n");
	
	for(i=0; i<NALIMENTI; i++)
	{
		printf("%s\n", nomealimenti[i]);
		scanf("%d", &alimenti[i]);
	}
	printf("Inserisci la quantita' della bibita\n");
	
	for(i=0; i<NBIBITE; i++)
	{
		printf("%s\n", nomebibite[i]);
		scanf("%d", &bibite[i]);
	}
	
	while(1>0)
	{
		n=0;
		
		do
		{
			printf("Inserisci 0 se vuoi uno/piu' alimento/i,\n inserisci 1 se vuoi una/piu' bibita/e,\n 2 per stampare lo scontrino e\n 3 per riassortire il magazzino\n");
			scanf("%d", &menu);
			
			if(menu==0)
			{
				for(i=0; i<NALIMENTI; i++)
				{
					printf("%d %s Sono disponibili: %d\n", i, nomealimenti[i], alimenti[i]);
				}
				
				printf("Inserisci un numero per selezionare l'alimento: ");
				scanf("%d", &cond);
				
				if(cond<NALIMENTI && alimenti[cond]>0)
				{
					printf("Inserisci la quantita': ");
					scanf("%d", &quantita);
					if(quantita<=alimenti[cond] && quantita>0)
					{
						strcpy(scontrino[n],nomealimenti[cond]);
						costo[n]=prezzoalimenti[cond]*quantita;
						alimenti[cond]=alimenti[cond]-quantita;
						n=n+1;
						printf("Acquisto effettuato\n");
						if(alimenti[cond]==0)
						{
							printf("%s E' finito/a\n", nomealimenti[cond]);
						}
					}
					else
					{
						printf("Non ci sono abbastanza scorte\n");
					}
				}
                else
				{
					printf("Il numero che lei ha inserito non e' disponibile\n");
				}
			}
			else if(menu==1)
			{
				for(i=0; i<NBIBITE; i++)
				{
					printf("%d %s Sono disponibili: %d\n", i, nomebibite[i], bibite[i]);
				}
							
				printf("Inserisci un numero per selezionare la bibita: ");
			    scanf("%d", &cond);
							
				if(cond<NBIBITE && bibite[cond]>0)
				{
					printf("Inserisci la quantita': ");
					scanf("%d", &quantita);
					if(quantita<=bibite[cond]&& quantita>0)
					{
						strcpy(scontrino[n],nomebibite[cond]);
						costo[n]=prezzobibite[cond]*quantita;
						bibite[cond]=bibite[cond]-quantita;
						n=n+1;
						printf("Acquisto effettuato\n");
						if(bibite[cond]==0)
						{
							printf("%s E' finito/a\n", nomebibite[cond]);
						}
					}
					else
					{
						printf("Non ci sono abbastanza scorte\n");
					}
			    }
				else
				{
					printf("Il numero che lei ha inserito non e' disponibile\n");
				}
			}
		    else if(menu==3)
			{
				printf("Inserisci per la quantita' per ogni alimento\n");
				for(i=0; i<NALIMENTI; i++)
				{
					printf("%s\n", nomealimenti[i]);
					scanf("%d", &x);
					alimenti[i]=alimenti[i]+x;
				}
			    printf("Inserisci la quantita' della bibita: \n");
										
				for(i=0; i<NBIBITE; i++)
				{
					printf("%s\n", nomebibite[i]);
					scanf("%d", &x);
					bibite[i]=bibite[i]+x;
				}
			}
		}while(menu!=2 && n<NSCONTRINO);
		
		totscontrino=0;
							
		for(i=0; i<n; i++)
		{
			totscontrino=totscontrino+costo[i];
		}
							
		printf("Hai un coupon? Inserisci 0 se non ce l'hai o un altro numero se ce l'hai\n");
	    scanf("%d", &cond);
							
		if(cond!=0)
		{
			printf("Inserisci il coupon: ");
			scanf("%d", &cond);
								
			if(cond==2020)
			{
				printf("Lo sconto e' stato applicato\n");
				totpagamento=totscontrino-(totscontrino*10)/100;
			}
			else if(cond==12345)
			{
				printf("Lo sconto e' stato applicato\n");
				totpagamento=totscontrino-(totscontrino*20)/100;
			}
			else if(cond==987)
			{
				printf("Lo sconto e' stato applicato\n");
				totpagamento=totscontrino-(totscontrino*50)/100;
			}
			else
			{
				printf("Il coupon non e' valido");
				totpagamento=totscontrino;
			}	
		}
		else
		{
			totpagamento=totscontrino;
		}
		printf("Ecco a lei lo scontrino\n");
								
		for(i=0; i<n; i++)
		{
			printf("%s %f\n", scontrino[i],costo[i]);
		}
		printf("Totale prodotti %f\n", totscontrino);
		printf("Totale da pagare %f\n", totpagamento);
	   	printf("Grazie e arrivederci\n");
	}
}



#include "gassp72.h"


void timer_callback(void);
int var = 0;
int Periode_en_Tck = 100;

extern int TabSin;
extern int TabCos;
extern int dft(short *, int);
extern short TabSigMine;
int somme(int);


 int main(void){
			
	/*		int max=0;
			int min=0x40000000;
			int S;
			for (int i=0;i<64; i++){
				S=somme(i);
				if(S>max){
					max=S;
				}
				if(S<min){
					min=S;
				}
			}*/
			int tab_res[64];
			for (int i=0;i<64;i++){
				tab_res[i]=dft(&TabSigMine,i);
			}
			
			// activation de la PLL qui multiplie la fr�quence du quartz par 9
			CLOCK_Configure();
			// config port PB1 pour �tre utilis� en sortie
			GPIO_Configure(GPIOB, 1, OUTPUT, OUTPUT_PPULL);
			// initialisation du timer 4
			// Periode_en_Tck doit fournir la dur�e entre interruptions,
			// exprim�e en p�riodes Tck de l'horloge principale du STM32 (72 MHz)
			Timer_1234_Init_ff( TIM4, Periode_en_Tck );
			// enregistrement de la fonction de traitement de l'interruption timer
			// ici le 2 est la priorit�, timer_callback est l'adresse de cette fonction, a cr��r en asm,
			// cette fonction doit �tre conforme � l'AAPCS
			Active_IT_Debordement_Timer( TIM4, 2, timer_callback );
			// lancement du timer
			Run_Timer( TIM4 );
while	(1)
	{
	}
}

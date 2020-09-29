#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
	double inhalationTime;
	double lungVolumetric;
	double particleSize;
}lung;

void loadMenu();
void inputData();
void scanInput(char text[30], double* inhalationTime);
void printCalc();
double getFlow();

//calcuulation


lung lungData;

int main() {

	printf("\n\n\n\n----------------Welcome to the particle deposition simulator!----------------");
	
	inputData();
	loadMenu();

	return 0;
}

void inputData() {
	
	printf("\nGive me the parameters of the lung!\n");
	scanInput("Inhalation time (seconds): ", &lungData.inhalationTime);
	scanInput("Volumetric of lung (ml): ", &lungData.lungVolumetric);
	scanInput("Particles size (mm): ", &lungData.particleSize);
	

	printf("\nParameters: inh: %f, vol: %f, size: %f\n\n", lungData.inhalationTime, lungData.lungVolumetric, lungData.particleSize);
	printCalc();
}

void scanInput(char text[30], double* inhalationTime){
	double b = 0.0;
	while ( !(b > 0) ){
		printf("%s", text);
		char s[10];
		scanf("\n%s", &s);
		b = atof(s);
		if (!(b > 0)){
			printf("\nWrong input! Try again!\n");
		}
	}
	*inhalationTime = b;
	//printf("Success: %f\n", *inhalationTime);
}

void printCalc(){
	printf("Flow (ml/s): %f\n", getFlow());
}

double getFlow(){
	return lungData.lungVolumetric/lungData.inhalationTime;
}

void loadMenu() {
	char s = 0;
	printMenu();
	while (s != 5) {

		scanf("\n%c", &s);
		switch (s) {
		case '1':
			// addApplicant(applicantList, size);
			// size++;
			// writeToFile(applicantList, size, fileName);
			sleep(2);
			printMenu();
			break;
		 case '2':
			printCalc();
			sleep(2);
			printMenu();
			break;
		// case '3':
		// 	if (deleteApplicant(applicantList, size)) {
		// 		size--;
		// 		writeToFile(applicantList, size, fileName);
		// 	}
		// 	sleep(2);
		// 	printMenu();
		// 	break;
		// case '4':
		// 	getApplicantsByPlace(applicantList, size);
		// 	sleep(2);
		// 	printMenu();
		// 	break;
		case '5':
			printf("\nViszont latasra!\n");
			exit(1);
		default:
			printf("Rossz szamot adott meg! Probalja ujra!\n");
		}
	}
}




//char* convertNumberIntoArray(unsigned int number) {
//	unsigned int length = (int)(log10((float)number)) + 1;
//	char* arr = (char*)malloc(length * sizeof(char)), * curr = arr;
//	do {
//		*curr++ = number % 10;
//		number /= 10;
//	} while (number != 0);
//	return arr;
//}


void printMenu() {
	printf("\n\n\n\n--------------------MENU--------------------\n\n");
	printf("\nChoose a function! Give me a number!\n\n");
	printf("1.)	Uj jelentkezo felvetele\n");
	printf("2.)	Jelentkezo modositasa\n");
	printf("3.)	Jelentkezes torlese\n");
	printf("4.)	Jelentkezok listazasa nap szerint\n");
	printf("5.)     Kilepes\n\nValasztott funkcio: ");
}



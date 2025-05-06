//author: Gwynevere Lee
//Project 10

#include<stdio.h>
void captolow(int guesscount, char wordguess[6][6]);
void lowtocap(int guesscount, char mystword[6], char wordguess[6][6]);
void guessfunc(int guesscount, char mystword[6], char wordguess[6][6]);
void savecorrect(int guesscount, char mystword[6], char wordguess[6][6], char lettptrs[6][6]);
int iscorrect(int guesscount, char mystword[6], char wordguess[6][6]);

int main(){
	int index, guesscount;
	char mystword[6], wordguess[6][6], lettptrs[6][6], placeptrs[6][6];
	
	FILE* wordptr;
	wordptr = fopen("mystery.txt", "r");
	if(wordptr == NULL){
	printf("could not open file, goodbye.\n");
	return 0;
	}
	
	fscanf(wordptr, "%s", mystword);
	
	for(guesscount = 0; guesscount < 6; guesscount++){
	guessfunc(guesscount, mystword, wordguess);
	captolow(guesscount, wordguess);
	int correct = iscorrect(guesscount, mystword, wordguess);
	savecorrect(guesscount, mystword, wordguess, lettptrs);
	if(correct == 1 && guesscount == 0){
	printf("		%s\n	You won in 1 guess!\n		GOATED!\n", wordguess[guesscount]);
	fclose(wordptr);
	return 0;
	}
	else if(correct == 1 && guesscount != 0){
	printf("		%s\n	You won in %d guess!\n		Amazing!\n", wordguess[guesscount], guesscount+1);
	fclose(wordptr);
	return 0;
	}
		for(int index = 0; index <= guesscount+1; index++){
		printf("%s\n", wordguess[index]);
		printf("%s\n", lettptrs[index]);
		}
	}
	printf("You lost, better luck next time!\n");
	fclose(wordptr);
	return 0;
}

void captolow(int guesscount, char wordguess[6][6]){
	for(int index = 0; index < 5; index++){
	if(wordguess[guesscount][index] >= 'A' && wordguess[guesscount][index] <= 'Z'){
	char lettcontrl;
	lettcontrl = 'a';
		for(char lettind = 'A'; lettind != wordguess[guesscount][index]; lettind++){
		lettcontrl++;
		}
		wordguess[guesscount][index] = lettcontrl;
	}
	}
}
void lowtocap(int guesscount, char mystword[6], char wordguess[6][6]){//ISSUES
	for(int index = 0; index < 5; index++){
	if(wordguess[guesscount][index] == mystword[index]){
	char lettcontrl;
	lettcontrl = 'A';
	for(char lettind = 'a'; lettind != wordguess[guesscount][index]; lettind++){
	lettcontrl++;
	}
	wordguess[guesscount][index] = lettcontrl;
	}//END IF
	}
}
void guessfunc(int guesscount, char mystword[6], char wordguess[6][6]){
	char throwaway;
	if(guesscount != 5){
	printf("GUESS %d! Enter your guess:", guesscount+1);
	}
	else{
	printf("FINAL GUESS:");
	}
	if(guesscount != 0){
	scanf("%c", &throwaway);
	}
	fgets(wordguess[guesscount], 6, stdin);
	printf("================================\n");
}
void savecorrect(int guesscount, char mystword[6], char wordguess[6][6], char lettptrs[6][6]){
	for(int index = 0; index < 5; index++){
	int rightletter;
	rightletter = 0;
	lowtocap(guesscount, mystword, wordguess);
		for(int letterid = 0; letterid < 5; letterid++){
	if (wordguess[guesscount][index] == mystword[letterid]){
		rightletter = 1;
	}
	}
	if(rightletter == 1){
	lettptrs[guesscount][index] = '^';
	}
	else{
	lettptrs[guesscount][index] = ' ';
	}
	}
}
int iscorrect(int guesscount, char mystword[6], char wordguess[6][6]){
	int correct = 0;
	int rightlett = 0;
	for(int index = 0; index < 5; index++){
	if(wordguess[guesscount][index] == mystword[index]){
	rightlett++;
	}
	}
	if (rightlett == 5){
	correct = 1;
	}
	return correct;
}











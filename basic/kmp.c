#include <stdio.h>
#include <string.h>
#define MAXL 100001
char major[MAXL];
char patt[MAXL];
int failure[MAXL], mL, pL;
int matchPositions[MAXL];

int stringMatch();
void makeFailure(int);

int main () {
	int k, matchNum;
	scanf("%s %s", major, patt);
	mL = strlen(major);
	pL = strlen(patt);
	matchNum = stringMatch();
	if(matchNum)
	printf("YES\n");
	else
	printf("NO\n");
	return 0;
}
int stringMatch() {
	int mk = 0, pk = 0, foundCnt = 0;
	
	makeFailure(pL);
	
	while(mk < mL) {
		
		if(patt[pk] == major[mk]) {
			
			// found the patt
			if(pk == pL - 1) {
				matchPositions[foundCnt] = mk - pk;
				foundCnt++;
				
				pk = failure[pk];
				
				if(pk == -1)
					pk++, mk++;
			}
			else
				pk++, mk++;
		}
		
		else {
			pk = failure[pk];
			
			if(pk == -1)
				pk++, mk++;
		}
	}
	
	return foundCnt;
}

void makeFailure(int pL) {
	int curLen = 0;
	int k = 1;
	
	failure[0] = -1;
	failure[1] = 0;
	
	while(k < pL) {
		
		if(patt[k] == patt[curLen]) {
			curLen++;
			failure[k + 1] = curLen;
			k++;
		}
		
		else {
			if(curLen == 0) {
				failure[k + 1] = 0;
				k++;
			}
			
			else
				curLen = failure[curLen];
		}
	}
	
	return;
}

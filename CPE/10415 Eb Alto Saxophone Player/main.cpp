//uva10415
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n ;
	cin >> n;
	while(n--){
		int i, j, finger[11] = {0}, ans[11] = {0} ;
		string note;
		cin >> note;		
		for(i = 0 ; i < note.size() ; i++){
			int temp[11] = {0} ;
			if(note[i] == 'c')
				temp[2] = temp[3] = temp[4] = temp[7] = temp[8] = temp[9] = temp[10] = 1 ;
			if(note[i] == 'd')
				temp[2] = temp[3] = temp[4] = temp[7] = temp[8] = temp[9] = 1 ;
			if(note[i] == 'e')
				temp[2] = temp[3] = temp[4] = temp[7] = temp[8] = 1 ;
			if(note[i] == 'f')
				temp[2] = temp[3] = temp[4] = temp[7] = 1 ;
			if(note[i] == 'g')
				temp[2] = temp[3] = temp[4] = 1 ;															
			if(note[i] == 'a')
				temp[2] = temp[3] = 1 ;
			if(note[i] == 'b')
				temp[2] = 1 ;								
			if(note[i] == 'C')
				temp[3] = 1 ;					
			if(note[i] == 'D')
				temp[1] = temp[2] = temp[3] = temp[4] = temp[7] = temp[8] = temp[9] = 1 ;
			if(note[i] == 'E')
				temp[1] = temp[2] = temp[3] = temp[4] = temp[7] = temp[8] = 1 ;				
			if(note[i] == 'F')
				temp[1] = temp[2] = temp[3] = temp[4] = temp[7] = 1 ;					
			if(note[i] == 'G')
				temp[1] = temp[2] = temp[3] = temp[4] = 1 ;	
			if(note[i] == 'A')
				temp[1] = temp[2] = temp[3] = 1 ;					
			if(note[i] == 'B')
				temp[1] = temp[2] = 1 ;					
			for(j = 1 ; j <= 10 ; j++){
				if((temp[j] == 1) && (finger[j] != 1))
					ans[j] ++ ;
				finger[j] = temp[j] ;
			}
		}
		for(i = 1 ; i <= 9 ; i++)
			printf("%d ", ans[i]) ;
		printf("%d\n", ans[10]) ;
	}
	return 0 ;
}
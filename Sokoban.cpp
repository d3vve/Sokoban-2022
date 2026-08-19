#include<iostream>
#include<iomanip>


using namespace std;

struct znaki{
	char sciana = '#', gracz = '@', skrzynia = '%', cel = '*', pole = '  ', skrzyniaw = '$';
	char tab[7][7], tab2[9][9], tab3[10][10];
	int ruchy = 0, ruchy2 = 0, ruchy3 = 0, poziom = 0;
	int pozycjax, pozycjay;
	bool stop = false;
};



void powitanie(){
	cout << setw(150) << "SOKOBAN" << endl;
	cout << setw(155) << "Marcel Sokolowski" << endl;
	cout << setw(150) << "188983" << endl << endl << endl;
}



void wyswietlanie(znaki& zn){
	for( int i = 0; i < 7; i++){
		for( int j = 0; j < 7; j++){
			cout << zn.tab[i][j];
		}
		cout << endl;
	}
}



void lvlone(znaki& zn){
	
   
   for( int i = 0; i < 7; i++ )
{
    for( int j = 0; j < 7; j++ )
    {
        if( i == 0 or i == 6 or j == 0 or j == 6) zn.tab[i][j] = zn.sciana;
        else if( i == 1 and j == 5) zn.tab[i][j] = zn.cel;
        else if( i == 1 and j == 3) zn.tab[i][j] = zn.gracz;
        else if( i == 2 and j == 3) zn.tab[i][j] = zn.skrzynia;
        else if( i == 1 and j == 4 or i == 2 and j== 4 or i == 3 and j== 4) zn.tab[i][j] = zn.sciana;
        else zn.tab[i][j] = zn.pole;
        
    }
    
}
      wyswietlanie(zn);
}




void czytanieone(znaki& zn){
	
	for( int i = 0; i < 7; i++ ){
		for( int j = 0; j < 7; j++){
			if( zn.tab[i][j] == zn.gracz) {
				zn.pozycjax = j;
				zn.pozycjay = i;
			}
		}
	}
}

void menu(znaki zn);
void poruszanie(znaki& zn, int maxruchow = 12){
	char n;
	bool wygrana = false;
	zn.poziom = 1;
	while ( zn.ruchy < maxruchow and wygrana == false and zn.stop == false ){
		czytanieone(zn);
		cout << "ruch " << endl;
	    cin >> n;
	    if ( n == 'w' and zn.tab[zn.pozycjay - 1][zn.pozycjax] != zn.sciana and zn.tab[zn.pozycjay - 1][zn.pozycjax] != zn.skrzynia ){
	    	zn.tab[zn.pozycjay - 1][zn.pozycjax] = zn.gracz;
	    	zn.tab[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjay--;
	    	
		}
		else if ( n == 'w' and zn.tab[zn.pozycjay - 1][zn.pozycjax] != zn.sciana and zn.tab[zn.pozycjay - 1][zn.pozycjax] == zn.skrzynia and zn.tab[zn.pozycjay - 2][zn.pozycjax] != zn.sciana ){
	    	zn.tab[zn.pozycjay - 1][zn.pozycjax] = zn.gracz;
	    	zn.tab[zn.pozycjay - 2][zn.pozycjax] = zn.skrzynia;
	    	zn.tab[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjay--;
	    	
		}
		else if ( n == 's' and zn.tab[zn.pozycjay + 1][zn.pozycjax] != zn.sciana and zn.tab[zn.pozycjay + 1][zn.pozycjax] != zn.skrzynia ){
	    	zn.tab[zn.pozycjay + 1][zn.pozycjax] = zn.gracz;
	    	zn.tab[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjay++;
	    	
		}
		else if ( n == 's' and zn.tab[zn.pozycjay + 1][zn.pozycjax] != zn.sciana and zn.tab[zn.pozycjay + 1][zn.pozycjax] == zn.skrzynia and zn.tab[zn.pozycjay + 2][zn.pozycjax] != zn.sciana ){
	    	zn.tab[zn.pozycjay + 1][zn.pozycjax] = zn.gracz;
	    	zn.tab[zn.pozycjay + 2][zn.pozycjax] = zn.skrzynia;
	    	zn.tab[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjay++;
	    	
		}
		else if ( n == 'a' and zn.tab[zn.pozycjay][zn.pozycjax - 1] != zn.sciana and zn.tab[zn.pozycjay][zn.pozycjax - 1] != zn.skrzynia ){
	    	zn.tab[zn.pozycjay][zn.pozycjax - 1] = zn.gracz;
	    	zn.tab[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjax--;
	    	
		}
		else if ( n == 'a' and zn.tab[zn.pozycjay][zn.pozycjax - 1] != zn.sciana and zn.tab[zn.pozycjay][zn.pozycjax - 1] == zn.skrzynia and zn.tab[zn.pozycjay][zn.pozycjax - 2] != zn.sciana ){
	    	zn.tab[zn.pozycjay][zn.pozycjax - 1] = zn.gracz;
	    	zn.tab[zn.pozycjay][zn.pozycjax - 2] = zn.skrzynia;
	    	zn.tab[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjax--;
	    	
		}
		else if ( n == 'd' and zn.tab[zn.pozycjay][zn.pozycjax + 1] != zn.sciana and zn.tab[zn.pozycjay][zn.pozycjax + 1] != zn.skrzynia ){
	    	zn.tab[zn.pozycjay][zn.pozycjax + 1] = zn.gracz;
	    	zn.tab[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjax++;
	    	
		}
		else if ( n == 'd' and zn.tab[zn.pozycjay][zn.pozycjax + 1] != zn.sciana and zn.tab[zn.pozycjay][zn.pozycjax + 1] == zn.skrzynia and zn.tab[zn.pozycjay][zn.pozycjax + 2] != zn.sciana ){
	    	zn.tab[zn.pozycjay][zn.pozycjax + 1] = zn.gracz;
	    	zn.tab[zn.pozycjay][zn.pozycjax + 2] = zn.skrzynia;
	    	zn.tab[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjax++;
	    	
		}
		else if ( n == 'q'){
			 menu(zn);
			 zn.stop = true;	 
		}
		else cout << "sciana" << endl;
		wyswietlanie(zn);
		zn.ruchy++;
		cout << "pozostale ruchy: " << maxruchow - zn.ruchy<< endl;
		if( zn.tab[1][5] == zn.skrzynia){
		cout << "WYGRANA" << endl;
		zn.tab[1][5] = zn.skrzyniaw;
		wygrana = true;
		wyswietlanie(zn);
	    }

	}
	
}

void wyswietlanie2(znaki& zn){
	for( int i = 0; i < 9; i++){
		for( int j = 0; j < 9; j++){
			cout << zn.tab2[i][j];
		}
		cout << endl;
	}
}

void lvltwo(znaki& zn){

	
   
   for( int i = 0; i < 9; i++ )
{
    for( int j = 0; j < 9; j++ )
    {
        if( i == 0 or i == 8 or j == 0 or j == 8) zn.tab2[i][j] = zn.sciana;
        else if( i == 3 and j == 5) zn.tab2[i][j] = zn.cel;
        else if( i == 7 and j == 4) zn.tab2[i][j] = zn.gracz;
        else if( i == 6 and j == 3) zn.tab2[i][j] = zn.skrzynia;
        else if( i == 3 and j == 4 or i == 4 and j== 5 or i == 4 and j== 4) zn.tab2[i][j] = zn.sciana;
        else zn.tab2[i][j] = zn.pole;
        
    }
    
  }
     wyswietlanie2(zn);
}

void czytanietwo(znaki& zn){
	
	for( int i = 0; i < 9; i++ ){
		for( int j = 0; j < 9; j++){
			if( zn.tab2[i][j] == zn.gracz) {
				zn.pozycjax = j;
				zn.pozycjay = i;
			}
		}
	}
}

void poruszanie2(znaki& zn, int maxruchow = 20){
	char n;
	bool wygrana = false;
	zn.poziom = 2;
	while ( zn.ruchy2 < maxruchow and wygrana == false and zn.stop == false ){
		czytanietwo(zn);
		cout << "ruch " << endl;
	    cin >> n;
	    if ( n == 'w' and zn.tab2[zn.pozycjay - 1][zn.pozycjax] != zn.sciana and zn.tab2[zn.pozycjay - 1][zn.pozycjax] != zn.skrzynia ){
	    	zn.tab2[zn.pozycjay - 1][zn.pozycjax] = zn.gracz;
	    	zn.tab2[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjay--;
	    	
		}
		else if ( n == 'w' and zn.tab2[zn.pozycjay - 1][zn.pozycjax] != zn.sciana and zn.tab2[zn.pozycjay - 1][zn.pozycjax] == zn.skrzynia and zn.tab2[zn.pozycjay - 2][zn.pozycjax] != zn.sciana ){
	    	zn.tab2[zn.pozycjay - 1][zn.pozycjax] = zn.gracz;
	    	zn.tab2[zn.pozycjay - 2][zn.pozycjax] = zn.skrzynia;
	    	zn.tab2[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjay--;
	    	
		}
		else if ( n == 's' and zn.tab2[zn.pozycjay + 1][zn.pozycjax] != zn.sciana and zn.tab2[zn.pozycjay + 1][zn.pozycjax] != zn.skrzynia ){
	    	zn.tab2[zn.pozycjay + 1][zn.pozycjax] = zn.gracz;
	    	zn.tab2[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjay++;
	    	
		}
		else if ( n == 's' and zn.tab2[zn.pozycjay + 1][zn.pozycjax] != zn.sciana and zn.tab2[zn.pozycjay + 1][zn.pozycjax] == zn.skrzynia and zn.tab2[zn.pozycjay + 2][zn.pozycjax] != zn.sciana ){
	    	zn.tab2[zn.pozycjay + 1][zn.pozycjax] = zn.gracz;
	    	zn.tab2[zn.pozycjay + 2][zn.pozycjax] = zn.skrzynia;
	    	zn.tab2[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjay++;
	    	
		}
		else if ( n == 'a' and zn.tab2[zn.pozycjay][zn.pozycjax - 1] != zn.sciana and zn.tab2[zn.pozycjay][zn.pozycjax - 1] != zn.skrzynia ){
	    	zn.tab2[zn.pozycjay][zn.pozycjax - 1] = zn.gracz;
	    	zn.tab2[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjax--;
	    	
		}
		else if ( n == 'a' and zn.tab2[zn.pozycjay][zn.pozycjax - 1] != zn.sciana and zn.tab2[zn.pozycjay][zn.pozycjax - 1] == zn.skrzynia and zn.tab2[zn.pozycjay][zn.pozycjax - 2] != zn.sciana ){
	    	zn.tab2[zn.pozycjay][zn.pozycjax - 1] = zn.gracz;
	    	zn.tab2[zn.pozycjay][zn.pozycjax - 2] = zn.skrzynia;
	    	zn.tab2[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjax--;
	    	
		}
		else if ( n == 'd' and zn.tab2[zn.pozycjay][zn.pozycjax + 1] != zn.sciana and zn.tab2[zn.pozycjay][zn.pozycjax + 1] != zn.skrzynia ){
	    	zn.tab2[zn.pozycjay][zn.pozycjax + 1] = zn.gracz;
	    	zn.tab2[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjax++;
	    	
		}
		else if ( n == 'd' and zn.tab2[zn.pozycjay][zn.pozycjax + 1] != zn.sciana and zn.tab2[zn.pozycjay][zn.pozycjax + 1] == zn.skrzynia and zn.tab2[zn.pozycjay][zn.pozycjax + 2] != zn.sciana ){
	    	zn.tab2[zn.pozycjay][zn.pozycjax + 1] = zn.gracz;
	    	zn.tab2[zn.pozycjay][zn.pozycjax + 2] = zn.skrzynia;
	    	zn.tab2[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjax++;
	    	
		}
		else if ( n == 'q') {
			menu(zn);
			zn.stop = true;
		}
		else cout << "sciana" << endl;
		wyswietlanie2(zn);
		zn.ruchy2++;
		cout << "pozostale ruchy: " << maxruchow - zn.ruchy2<< endl;
		if( zn.tab2[3][5] == zn.skrzynia){
		cout << "WYGRANA" << endl;
		zn.tab2[3][5] = zn.skrzyniaw;
		wygrana = true;
		wyswietlanie2(zn);
	    }

	}
	
}

void wyswietlanie3(znaki& zn){
	for( int i = 0; i < 10; i++){
		for( int j = 0; j < 10; j++){
			cout << zn.tab3[i][j];
		}
		cout << endl;
	}
}

void lvlthree(znaki& zn){

	
   
   for( int i = 0; i < 10; i++ )
{
    for( int j = 0; j < 10; j++ )
    {
        if( i == 0 or i == 9 or j == 0 or j == 9) zn.tab3[i][j] = zn.sciana;
        else if( i == 3 and j == 2 or i == 6 and j == 7) zn.tab3[i][j] = zn.cel;
        else if( i == 7 and j == 4) zn.tab3[i][j] = zn.gracz;
        else if( i == 6 and j == 3 or i == 6 and j == 5) zn.tab3[i][j] = zn.skrzynia;
        else if( i == 4 and j == 1 or i == 4 and j== 2 or i == 3 and j== 3 or i == 4 and j == 3 or i == 5 and j== 8 or i == 5 and j== 7 or i == 5 and j == 6 or i == 6 and j == 6) zn.tab3[i][j] = zn.sciana;
        else zn.tab3[i][j] = zn.pole;
        
    }
    
  }
     wyswietlanie3(zn);
}

void czytaniethree(znaki& zn){
	
	for( int i = 0; i < 10; i++ ){
		for( int j = 0; j < 10; j++){
			if( zn.tab3[i][j] == zn.gracz) {
				zn.pozycjax = j;
				zn.pozycjay = i;
			}
		}
	}
}

void poruszanie3(znaki& zn, int maxruchow = 40){
	char n;
	bool wygrana = false, skrzynia = false, skrzynia2 = false;
	
	zn.poziom = 3;
	while ( zn.ruchy3 < maxruchow and wygrana == false and zn.stop == false ){
		czytaniethree(zn);
		cout << "ruch " << endl;
	    cin >> n;
	    if ( n == 'w' and zn.tab3[zn.pozycjay - 1][zn.pozycjax] != zn.sciana and zn.tab3[zn.pozycjay - 1][zn.pozycjax] != zn.skrzynia ){
	    	zn.tab3[zn.pozycjay - 1][zn.pozycjax] = zn.gracz;
	    	zn.tab3[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjay--;
	    	
		}
		else if ( n == 'w' and zn.tab3[zn.pozycjay - 1][zn.pozycjax] != zn.sciana and zn.tab3[zn.pozycjay - 1][zn.pozycjax] == zn.skrzynia and zn.tab3[zn.pozycjay - 2][zn.pozycjax] != zn.sciana ){
	    	zn.tab3[zn.pozycjay - 1][zn.pozycjax] = zn.gracz;
	    	zn.tab3[zn.pozycjay - 2][zn.pozycjax] = zn.skrzynia;
	    	zn.tab3[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjay--;
	    	
		}
		else if ( n == 's' and zn.tab3[zn.pozycjay + 1][zn.pozycjax] != zn.sciana and zn.tab3[zn.pozycjay + 1][zn.pozycjax] != zn.skrzynia ){
	    	zn.tab3[zn.pozycjay + 1][zn.pozycjax] = zn.gracz;
	    	zn.tab3[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjay++;
	    	
		}
		else if ( n == 's' and zn.tab3[zn.pozycjay + 1][zn.pozycjax] != zn.sciana and zn.tab3[zn.pozycjay + 1][zn.pozycjax] == zn.skrzynia and zn.tab3[zn.pozycjay + 2][zn.pozycjax] != zn.sciana ){
	    	zn.tab3[zn.pozycjay + 1][zn.pozycjax] = zn.gracz;
	    	zn.tab3[zn.pozycjay + 2][zn.pozycjax] = zn.skrzynia;
	    	zn.tab3[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjay++;
	    	
		}
		else if ( n == 'a' and zn.tab3[zn.pozycjay][zn.pozycjax - 1] != zn.sciana and zn.tab3[zn.pozycjay][zn.pozycjax - 1] != zn.skrzynia ){
	    	zn.tab3[zn.pozycjay][zn.pozycjax - 1] = zn.gracz;
	    	zn.tab3[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjax--;
	    	
		}
		else if ( n == 'a' and zn.tab3[zn.pozycjay][zn.pozycjax - 1] != zn.sciana and zn.tab3[zn.pozycjay][zn.pozycjax - 1] == zn.skrzynia and zn.tab3[zn.pozycjay][zn.pozycjax - 2] != zn.sciana ){
	    	zn.tab3[zn.pozycjay][zn.pozycjax - 1] = zn.gracz;
	    	zn.tab3[zn.pozycjay][zn.pozycjax - 2] = zn.skrzynia;
	    	zn.tab3[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjax--;
	    	
		}
		else if ( n == 'd' and zn.tab3[zn.pozycjay][zn.pozycjax + 1] != zn.sciana and zn.tab3[zn.pozycjay][zn.pozycjax + 1] != zn.skrzynia ){
	    	zn.tab3[zn.pozycjay][zn.pozycjax + 1] = zn.gracz;
	    	zn.tab3[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjax++;
	    	
		}
		else if ( n == 'd' and zn.tab3[zn.pozycjay][zn.pozycjax + 1] != zn.sciana and zn.tab3[zn.pozycjay][zn.pozycjax + 1] == zn.skrzynia and zn.tab3[zn.pozycjay][zn.pozycjax + 2] != zn.sciana ){
	    	zn.tab3[zn.pozycjay][zn.pozycjax + 1] = zn.gracz;
	    	zn.tab3[zn.pozycjay][zn.pozycjax + 2] = zn.skrzynia;
	    	zn.tab3[zn.pozycjay][zn.pozycjax] = zn.pole;
	    	zn.pozycjax++;
	    	
		}
		else if ( n == 'q') {
			menu(zn);
			zn.stop = true;
		}
		else cout << "sciana" << endl;
		wyswietlanie3(zn);
		zn.ruchy3++;
		cout << "pozostale ruchy: " << maxruchow - zn.ruchy3<< endl;
	    if( zn.tab3[3][2] == zn.skrzynia ){
	    	zn.tab3[3][2] = zn.skrzyniaw;
	    	skrzynia = true;
	    	wyswietlanie3(zn);
		}
		if( zn.tab3[6][7] == zn.skrzynia ){
	    	zn.tab3[6][7] = zn.skrzyniaw;
	    	skrzynia2 = true;
	    	wyswietlanie3(zn);
		}
		if ( skrzynia == true and skrzynia2 == true){
			cout << "WYGRANA" << endl;
			wygrana = true;
			wyswietlanie3(zn);
		}
	    


	}
	
}



void poziom1(znaki& zn){
	lvlone(zn);
	poruszanie(zn);
	
}

void poziom2(znaki zn){
	lvltwo(zn);
	poruszanie2(zn);
	
}

void poziom3(znaki zn){
	lvlthree(zn);
	poruszanie3(zn);
	
}


void jakipoziom(znaki& zn){
	if( zn.poziom == 1) {
		zn.ruchy = 0;
		poziom1(zn);
		poziom2(zn);
		poziom3(zn);
	} 
	else if( zn.poziom == 2){
		zn.ruchy2 = 0;
		poziom2(zn);
	}
	else if( zn.poziom == 3){
		zn.ruchy3 = 0;
		poziom3(zn);
	}
}

int wyjdz(){
	 return 0;
	
}

void menu(znaki zn){
	int numer, nr;
	cout << " MENU" << endl << " 1. Nowy poziom" << endl << " 2. Restart" << endl << " 3. Wyjdz" << endl;
	cin >> numer;
	if( numer == 1 ){
		cout << "Wybierz poziom" << endl << " 1. lvl 1" << endl << " 2. lvl 2" << endl << " 3. lvl 3" << endl;
		cin >> nr;
		if( nr == 1) {
			zn.ruchy = 0;
			poziom1(zn);
			poziom2(zn);
			poziom3(zn);
			
		} 
		else if( nr == 2) {
			zn.ruchy2 = 0;
			poziom2(zn);
			poziom3(zn);
			
		}
		else if( nr == 3){
			zn.ruchy3 = 0;
			poziom3(zn);
			
		}
	}
	else if( numer == 2 ){
		jakipoziom(zn);
	}
	else if( numer == 3){
		wyjdz();
	}
	
}

int main(){

	znaki zn;
	powitanie();
	menu(zn);
	
	
	return 0;
}

//
//Mariana Castro Payns - A01706038
//Act Int 1
//Archivo txt obtenido del sitio web Kaggle.com
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>


using namespace std;


bool getContent(string fName, vector<string> & vect){
    ifstream in("FileP.txt");
	
    if(!in)
    {
        cerr << "No es posible abrir el archivo : "<<fName<<endl;
        return false;
    }
    string str;

    while (getline(in, str))
    {
        if(str.size() > 0)
            vect.push_back(str);
    }
    in.close();
    return true;
}

int main(int argc, char* argv[]){
	int option;
	
	cout<<"----- MENU ------"<<endl;
	cout<<"1.Leer Archivo"<<endl;
	cout<<"2.Ordenar por anio"<<endl;
	cout<<"3.Busqueda "<<endl;
	cout<< "Introduzca la opcion: "<<endl;; 
	cin >> option;
	
	switch(option){
		
		case 1:{
			vector<string> ve;
			bool result = getContent("content.cpp", ve);
			if(result){
			for(string & line : ve)
            cout<<line<<endl;
			}
		}
		break;
		
		case 2:{
		    vector<string> numid;
			ifstream is("FileP.txt");
			if(!is.is_open())
			cout << "No es posible abrir el archivo"<<endl;

			string word;
			while(getline(is, word))
            numid.push_back(word);

			sort(numid.begin(), numid.end());
			
			cout<<"La informacion ordenada se encontrara en un nuevo archivo llamado 'ordenado.txt'"<<endl;
		
			ofstream newfile ("ordenado.txt");
			for(string &f : numid){
				newfile<<f<<endl;
			}break;
		
	
		}
		
		case 3:{
			string search;
			cout<<"La informacion disponible se encuentra en las siguientes categorias: "<<endl;
			cout<<"Tipo de video - Movie or TV Show "<<endl;
			cout<<"Genero - Comedies, Dramas, Musicals, etc.."<<endl; 
			cout<<"Anio - 2009 a 2018"<<endl;
			cout<<"Titulo"<<endl;
			cout<<"Ingrese el criterio de su busqueda: "<<endl;
			cin>>search;
			ifstream s("FileP.txt");
			if(!s.is_open())
			cout << "No es posible abrir el archivo"<<endl;

			string word;
			while(getline(s, word)){
				if(word.find(search) != string::npos){
					cout<<word<<endl;
				}
				
			}
		}break;
		}
					
	}
	
/*
Casos de prueba:
Case 1: 
output esperado - Lectura correcta del archivo
(agregar opcion para selecionar archivo externo para mayor funcionalidad)
Case 2:
output esperado - Nuevo archivo con fechas por orden descendiente
(agregar mas opciones de ordenamiento para mas funcionalidad)
Case 3:
output esperado - Menu con opciones de categorias, al escrinir el criterio de busqueda se hace la busqueda 
(agregar una funcion para el caso donde no se encuentra nada con el criterio dado)

Casos de prueba:
Case 1: 
Output:
release_year    type    title   listed_in       show_id
2019    Movie   Norm of the North: King Sized Adventure Children & Family Movies, Comedies  81145628
2016    Movie   Jandino: Whatever it Takes      Stand-Up Comedy 80117401
2013    TV Show Transformers Prime      Kids' TV        70234439
2016    TV Show Transformers: Robots in Disguise        Kids' TV        80058654
2017    Movie   #realityhigh    Comedies        80125979
2016    TV Show Apaches Crime TV Shows, International TV Shows, Spanish-Language TV Shows   80163890
2014    Movie   Automata        International Movies, Sci-Fi & Fantasy, Thrillers
        70304989
2017    Movie   Fabrizio Copano: Solo pienso en mi      Stand-Up Comedy 80164077
2017    TV Show Fire Chasers    Docuseries, Science & Nature TV 80117902
2014    Movie   Good People     Action & Adventure, Thrillers   70304990
2017    Movie   Joaqu├â┬¡n Reyes: Una y no m├â┬ís       Stand-Up Comedy 80169755
2015    Movie   Kidnapping Mr. Heineken Action & Adventure, Dramas, International Movies    70299204
2009    Movie   Krish Trish and Baltiboy        Children & Family Movies        80182480
2013    Movie   Krish Trish and Baltiboy: Battle of Wits        Children & Family Movies    80182483
2016    Movie   Krish Trish and Baltiboy: Best Friends Forever  Children & Family Movies    80182596
2012    Movie   Krish Trish and Baltiboy: Comics of India       Children & Family Movies    80182482
2017    Movie   Krish Trish and Baltiboy: Oversmartness Never Pays      Children & Family Movies    80182597
2010    Movie   Krish Trish and Baltiboy: Part II       Children & Family Movies
        80182481
2013    Movie   Krish Trish and Baltiboy: The Greatest Trick    Children & Family Movies    80182621
2015    Movie   Love    Cult Movies, Dramas, Independent Movies 80057969
2014    Movie   Manhattan Romance       Comedies, Independent Movies, Romantic Movies       80060297
2015    Movie   Moonwalkers     Action & Adventure, Comedies, International Movies
        80046728
2015    Movie   Rolling Papers  Documentaries   80046727
2014    Movie   Stonehearst Asylum      Horror Movies, Thrillers        70304988
2015    Movie   The Runner      Dramas, Independent Movies      80057700
2015    Movie   6 Years Dramas, Independent Movies, Romantic Movies     80045922
2015    TV Show Castle of Stars International TV Shows, Romantic TV Shows, TV Comedies      80244601
2018    Movie   City of Joy     Documentaries   80203094
2018    TV Show First and Last  Docuseries      80190843
2011    Movie   Laddaland       Horror Movies, International Movies     70241607
2018    Movie   Next Gen        Children & Family Movies, Comedies, Sci-Fi & Fantasy        80988892
2018    Movie   Sierra Burgess Is A Loser       Comedies, Romantic Movies       80239639
2018    Movie   The Most Assassinated Woman in the World        Dramas, International Movies, Thrillers     80159586
2016    Movie   C├â┬®zanne et moi       Dramas, Independent Movies, International Movies    80152447
2019    TV Show Archibald's Next Big Thing      Kids' TV, TV Comedies   80221550
2019    Movie   Article 15      Dramas, International Movies, Thrillers 81154455
2018    Movie   Care of Kancharapalem   Comedies, Dramas, Independent Movies    81113928
2018    Movie   Ee Nagaraniki Emaindi   Comedies, International Movies  81052275
2019    Movie   Kill Me If You Dare     Comedies, International Movies, Romantic Movies     81132437
2019    TV Show The Spy International TV Shows, TV Dramas, TV Thrillers 80178151
2015    Movie   Hell and Back   Action & Adventure, Comedies, Independent Movies
        80058026
2014    Movie   PK      Comedies, Dramas, International Movies  70303496
2015    Movie   Hard Tide       Dramas, Independent Movies      80162141
2015    Movie   Elstree 1976    Documentaries   80095641
2019    Movie   American Factory: A Conversation with the Obamas        Documentaries       81176188
2012    Movie   ATM     Comedies, International Movies, Romantic Movies 80159880
2009    Movie   Bangkok Traffic (Love) Story    Comedies, International Movies, Romantic Movies     81016044
2014    Movie   I Fine... Thank You... Love You Comedies, International Movies, Romantic Movies     80158838
2016    Movie   One Day Dramas, International Movies, Romantic Movies   81016045

Case 2:
Achivo Ordenado.txt con la sig inf:
2009	Movie	Bangkok Traffic (Love) Story	Comedies, International Movies, Romantic Movies	81016044
2009	Movie	Krish Trish and Baltiboy	Children & Family Movies	80182480
2010	Movie	Krish Trish and Baltiboy: Part II	Children & Family Movies	80182481
2011	Movie	Laddaland	Horror Movies, International Movies	70241607
2012	Movie	ATM	Comedies, International Movies, Romantic Movies	80159880
2012	Movie	Krish Trish and Baltiboy: Comics of India	Children & Family Movies	80182482
2013	Movie	Krish Trish and Baltiboy: Battle of Wits	Children & Family Movies	80182483
2013	Movie	Krish Trish and Baltiboy: The Greatest Trick	Children & Family Movies	80182621
2013	TV Show	Transformers Prime	Kids' TV	70234439
2014	Movie	Automata	International Movies, Sci-Fi & Fantasy, Thrillers	70304989
2014	Movie	Good People	Action & Adventure, Thrillers	70304990
2014	Movie	I Fine... Thank You... Love You	Comedies, International Movies, Romantic Movies	80158838
2014	Movie	Manhattan Romance	Comedies, Independent Movies, Romantic Movies	80060297
2014	Movie	PK	Comedies, Dramas, International Movies	70303496
2014	Movie	Stonehearst Asylum	Horror Movies, Thrillers	70304988
2015	Movie	6 Years	Dramas, Independent Movies, Romantic Movies	80045922
2015	Movie	Elstree 1976	Documentaries	80095641
2015	Movie	Hard Tide	Dramas, Independent Movies	80162141
2015	Movie	Hell and Back	Action & Adventure, Comedies, Independent Movies	80058026
2015	Movie	Kidnapping Mr. Heineken	Action & Adventure, Dramas, International Movies	70299204
2015	Movie	Love	Cult Movies, Dramas, Independent Movies	80057969
2015	Movie	Moonwalkers	Action & Adventure, Comedies, International Movies	80046728
2015	Movie	Rolling Papers	Documentaries	80046727
2015	Movie	The Runner	Dramas, Independent Movies	80057700
2015	TV Show	Castle of Stars	International TV Shows, Romantic TV Shows, TV Comedies	80244601
2016	Movie	CÃ©zanne et moi	Dramas, Independent Movies, International Movies	80152447
2016	Movie	Jandino: Whatever it Takes	Stand-Up Comedy	80117401
2016	Movie	Krish Trish and Baltiboy: Best Friends Forever	Children & Family Movies	80182596
2016	Movie	One Day	Dramas, International Movies, Romantic Movies	81016045
2016	TV Show	Apaches	Crime TV Shows, International TV Shows, Spanish-Language TV Shows	80163890
2016	TV Show	Transformers: Robots in Disguise	Kids' TV	80058654
2017	Movie	#realityhigh	Comedies	80125979
2017	Movie	Fabrizio Copano: Solo pienso en mi	Stand-Up Comedy	80164077
2017	Movie	JoaquÃ­n Reyes: Una y no mÃ¡s	Stand-Up Comedy	80169755
2017	Movie	Krish Trish and Baltiboy: Oversmartness Never Pays	Children & Family Movies	80182597
2017	TV Show	Fire Chasers	Docuseries, Science & Nature TV	80117902
2018	Movie	Care of Kancharapalem	Comedies, Dramas, Independent Movies	81113928
2018	Movie	City of Joy	Documentaries	80203094
2018	Movie	Ee Nagaraniki Emaindi	Comedies, International Movies	81052275
2018	Movie	Next Gen	Children & Family Movies, Comedies, Sci-Fi & Fantasy	80988892
2018	Movie	Sierra Burgess Is A Loser	Comedies, Romantic Movies	80239639
2018	Movie	The Most Assassinated Woman in the World	Dramas, International Movies, Thrillers	80159586
2018	TV Show	First and Last	Docuseries	80190843
2019	Movie	American Factory: A Conversation with the Obamas	Documentaries	81176188
2019	Movie	Article 15	Dramas, International Movies, Thrillers	81154455
2019	Movie	Kill Me If You Dare	Comedies, International Movies, Romantic Movies	81132437
2019	Movie	Norm of the North: King Sized Adventure	Children & Family Movies, Comedies	81145628
2019	TV Show	Archibald's Next Big Thing	Kids' TV, TV Comedies	80221550
2019	TV Show	The Spy	International TV Shows, TV Dramas, TV Thrillers	80178151

case 3:
input - TV Show
Output esperado:
2013    TV Show Transformers Prime      Kids' TV        70234439
2016    TV Show Transformers: Robots in Disguise        Kids' TV        80058654
2016    TV Show Apaches Crime TV Shows, International TV Shows, Spanish-Language TV Shows   80163890
2017    TV Show Fire Chasers    Docuseries, Science & Nature TV 80117902
2015    TV Show Castle of Stars International TV Shows, Romantic TV Shows, TV Comedies      80244601
2018    TV Show First and Last  Docuseries      80190843
2019    TV Show Archibald's Next Big Thing      Kids' TV, TV Comedies   80221550
2019    TV Show The Spy International TV Shows, TV Dramas, TV Thrillers 80178151

input - 2018
Output esperado:
2018    Movie   City of Joy     Documentaries   80203094
2018    TV Show First and Last  Docuseries      80190843
2018    Movie   Next Gen        Children & Family Movies, Comedies, Sci-Fi & Fantasy        80988892
2018    Movie   Sierra Burgess Is A Loser       Comedies, Romantic Movies       80239639
2018    Movie   The Most Assassinated Woman in the World        Dramas, International Movies, Thrillers     80159586
2018    Movie   Care of Kancharapalem   Comedies, Dramas, Independent Movies    81113928
2018    Movie   Ee Nagaraniki Emaindi   Comedies, International Movies  81052275

input - comedies
output esperado:
2019    Movie   Norm of the North: King Sized Adventure Children & Family Movies, Comedies  81145628
2017    Movie   #realityhigh    Comedies        80125979
2014    Movie   Manhattan Romance       Comedies, Independent Movies, Romantic Movies       80060297
2015    Movie   Moonwalkers     Action & Adventure, Comedies, International Movies
        80046728
2015    TV Show Castle of Stars International TV Shows, Romantic TV Shows, TV Comedies      80244601
2018    Movie   Next Gen        Children & Family Movies, Comedies, Sci-Fi & Fantasy        80988892
2018    Movie   Sierra Burgess Is A Loser       Comedies, Romantic Movies       80239639
2019    TV Show Archibald's Next Big Thing      Kids' TV, TV Comedies   80221550
2018    Movie   Care of Kancharapalem   Comedies, Dramas, Independent Movies    81113928
2018    Movie   Ee Nagaraniki Emaindi   Comedies, International Movies  81052275
2019    Movie   Kill Me If You Dare     Comedies, International Movies, Romantic Movies     81132437
2015    Movie   Hell and Back   Action & Adventure, Comedies, Independent Movies
        80058026
2014    Movie   PK      Comedies, Dramas, International Movies  70303496
2012    Movie   ATM     Comedies, International Movies, Romantic Movies 80159880
2009    Movie   Bangkok Traffic (Love) Story    Comedies, International Movies, Romantic Movies     81016044
2014    Movie   I Fine... Thank You... Love You Comedies, International Movies, Romantic Movies     80158838
*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <ctime> 
#include <thread>
#include <Windows.h>
#include <cstdio>
#include <conio.h>

#include "dice.h"
#include "lancer.h"
#include "player.h"


using namespace std;


int KEY_DOWN = 80;
int KEY_UP = 72;
int RED = 12;
int WHITE = 7;
string START_GAME = "- Start Game.";
string HELP = "- Help / How to play !";
string EXIT_MENU = "- Exit Menu ";
string FACILE = "- Facile ";
string MOYEN = "- Moyen";
string DIFFICILE = "- Difficile ";


//================================================================================================


//================================================================================================


bool compare_strings(const string& input_choice, const string& possible_choice) {
	return input_choice.compare(possible_choice) == 0;
}


//================================================================================================


//================================================================================================

void color(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//================================================================================================


//================================================================================================

void gotoxy(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//================================================================================================


//================================================================================================


void update_console() {
	std::this_thread::sleep_for(std::chrono::milliseconds(300));
	LockWindowUpdate(GetConsoleWindow());
	system("cls");
	LockWindowUpdate(NULL);
	color(7);
}


//================================================================================================


//================================================================================================


bool game_isEnd(const vector<player> pps) {

	int tester = 0;
	for (auto _p : pps) {
		if (!_p.grille_isFill()) {
			tester = 1;
		}
		if (tester == 1) {
			return false;
		}
	}
	return true;

}

//================================================================================================


//================================================================================================


void change_cursor_position() {

	COORD coord = { 0, 8 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//================================================================================================


//================================================================================================

void print_scores(const player& _p) {

	size_t l = strlen(("player : " + _p.m_name).c_str());
	//calcul le nombre de - à afficher :).
	size_t val = 30 - l;

	cout << "Player : " << _p.m_name << " ";
	for (size_t i = 0; i < val; i++)
		cout << "-";
	cout << "\n|" << setw(15) << "score : " << _p.m_score << setw(15) << "|\n";
	cout << " ";
	for (size_t i = 0; i < 30; i++)
		cout << "-";


}

//================================================================================================


//================================================================================================

int generate_random_choice(player& _p) {//level : difficile.

	bool choice_isAvailabe;
	int random;
	do {
		srand((unsigned)time(0));
		random = (rand() % 13) + 1;
		switch (random)
		{
		case 1:
			choice_isAvailabe = _p.get_Grille().get_total_1_isAvailable();
			break;
		case 2:
			choice_isAvailabe = _p.get_Grille().get_total_2_isAvailable();
			break;
		case 3:
			choice_isAvailabe = _p.get_Grille().get_total_3_isAvailable();
			break;
		case 4:
			choice_isAvailabe = _p.get_Grille().get_total_4_isAvailable();
			break;
		case 5:
			choice_isAvailabe = _p.get_Grille().get_total_5_isAvailable();
			break;
		case 6:
			choice_isAvailabe = _p.get_Grille().get_total_6_isAvailable();
			break;
		case 7:
			choice_isAvailabe = _p.get_Grille().get_berlan_isAvailable();
			break;
		case 8:
			choice_isAvailabe = _p.get_Grille().get_carre_isAvailable();
			break;
		case 9:
			choice_isAvailabe = _p.get_Grille().get_psuite_isAvailable();
			break;
		case 10:
			choice_isAvailabe = _p.get_Grille().get_gsuite_isAvailable();
			break;
		case 11:
			choice_isAvailabe = _p.get_Grille().get_fullHouse_isAvailable();
			break;
		case 12:
			choice_isAvailabe = _p.get_Grille().get_yahtzee_isAvailable();
			break;
		case 13:
			choice_isAvailabe = _p.get_Grille().get_chance_isAvailable();
			break;
		}
	} while (!choice_isAvailabe);
	return random;
}


//================================================================================================


//================================================================================================


void commencer_jeu(int x, int y, int couleur) {
	gotoxy(x, y);
	color(couleur);
	cout << START_GAME;
}

//================================================================================================


//================================================================================================

void how_to_play(int x, int y, int couleur) {
	gotoxy(x, y);
	color(couleur);
	cout << HELP;
}

//================================================================================================


//================================================================================================

void exit_menu(int x, int y, int couleur) {

	gotoxy(x, y);
	color(couleur);
	cout << EXIT_MENU;
}

//================================================================================================


//================================================================================================

void level_facile(int x, int y, int couleur) {
	gotoxy(x, y);
	color(couleur);
	cout << FACILE;
}

//================================================================================================


//================================================================================================

void level_moyen(int x, int y, int couleur) {
	gotoxy(x, y);
	color(couleur);
	cout << MOYEN;
}


//================================================================================================


//================================================================================================


void level_difficile(int x, int y, int couleur) {
	gotoxy(x, y);
	color(couleur);
	cout << DIFFICILE;
}


//================================================================================================


//================================================================================================

void error_input() {
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "Invalid input. Try again. " << endl;
}

//================================================================================================
//------------------------------------------------------------------------------------------------
//----------------------------------------> MAIN <------------------------------------------------
//------------------------------------------------------------------------------------------------
//================================================================================================


void game(int);

int main() {
	int Set[] = { WHITE,WHITE,WHITE };//DEFAULT COLORS
	int counter = 2;
	char key;


	string help = "\n"
		" ---------------------------\n"
		"|    Objet du jeu :         |\n"
		" ---------------------------\n\n"
		" Lancez des des pour obtenir le meilleur score apres les 13 tours !\n"
		"\n\n"
		" ---------------------------\n"
		"|    Scenario du jeu :      |\n"
		" ---------------------------\n\n"
		" Chaque joueur, a son tour, place les 5 des dans le gobelet,\n"
		" secoue le gobelet et lance les des. Chaque tour consiste en un maximum de trois lancers.\n\n"
		" Le premier lancer doit etre effectue avec les cinq des. \n"
		" Si le joueur choisit de lancer une deuxieme et, \n"
		" si desire, une troisieme fois, il peut prendre un ou tous les des et relancer. \n\n"
		" C'est l'utilisation habile de ces deux jets de des optionnels \n"
		" qui peut transformer un premier ou deuxieme jet malchanceux en un tour a fort score.\n"
		" Un score doit etre inscrit apres le dernier jet dans la case appropriee \n"
		" ou un zero doit etre inscrit dans une case au choix du joueur.\n\n"
		"\n\n"
		" ---------------------------\n"
		"|    Systeme de points :    |\n"
		" ---------------------------\n\n"
		" A chaque tour termine, le joueur doit marquer dans l'une des 13 cases de score.\n"
		" Les cases peuvent etre remplies dans n'importe quel ordre, selon joueur.\n"
		" La carte de score comporte une section superieure et une section inferieure :\n"
		" Lorsqu'un joueur choisit de marquer des points dans la section superieure,\n"
		" il ne compte et n'additionne que les des ayant le meme numero \n"
		" et inscrit le total de ces des dans la case appropriee.\n"
		" Dans la section inferieure, vous marquez des points pour diverses combinaisons et\n"
		" elles sont jouees exactement comme indique.\n"
		" 3 of a kind ,"
		" 4 of a kind ,"
		" Full House,"
		" Small Straight ,"
		" Large Straight ,"
		" Chance,"
		" Yahtzee. "
		"\n\n"
		" ---------------------------\n"
		"|     Fin du jeu:           |\n"
		" ---------------------------\n\n"
		"Le joueur ayant le plus grand total a la fin des 13 tours est le gagnant.\n"
		"\n\n"
		"                    -------------------------------------------\n"
		"                   |                                           |\n"
		"                   |              Bonne chance !               |\n"
		"                   |                                           |\n"
		"                    -------------------------------------------\n";

	bool isPageAccueil = true;

	string menu =
		"           --------------------------                \n"
		"          |                          |               \n"
		"          |          YAHTZEE         |               \n"
		"          |           GAME           |               \n"
		"          |                          |               \n"
		"          |--------------------------|               \n"
		"          |   Created by : E.Mehdi   |               \n"
		"          |       And A.Ossama       |               \n"
		"          |--------------------------|               \n"
		"          |   Let's Roll the dice !  |               \n"
		"          |   ________     ________  |               \n"
		"          |  |        |   |        | |               \n"
		"          |  |  °     |   |  °  °  | |               \n"
		"          |  |        |   |        | |               \n"
		"          |  |     °  |   |  °  °  | |               \n"
		"          |  |________|   |________| |               \n"
		"          |                          |               \n"
		"           --------------------------                \n";

	cout << menu;
	// Start Menu 
	for (int i = 0;;) {
		if (isPageAccueil) {

			Set[0] = WHITE;
			Set[1] = WHITE;
			Set[2] = WHITE;
			Set[counter - 1] = RED;

			int x = 13;
			int y = 20;

			commencer_jeu(x,y, Set[0]);

			how_to_play(x, y + 1, Set[1]);

			exit_menu(x, y + 2, Set[2]);
			
		}
		
		key = _getch();
		if (key == KEY_UP && (counter >= 2 && counter <= 3) && isPageAccueil) { // 72 up arrow key
			counter--;
		}
		if (key == KEY_DOWN && (counter >= 1 && counter <= 2) && isPageAccueil) { // 80 down arrow key
			counter++;
		}
		if (key == '\r') {
			if (isPageAccueil) {
				isPageAccueil = false;
				if (counter == 1) {
					//*******************************************
					// Mettre ici le début du code du jeu
					//*******************************************
					update_console();

					cout << "-Veuillez choisir un niveau parmis la liste choisie :";
					for (int i = 0;;) {
						Set[0] = WHITE;
						Set[1] = WHITE;
						Set[2] = WHITE;
						Set[counter - 1] = RED;
						
						int x = 10;
						int y = 2;

						level_facile(x, y, Set[0]);

						level_moyen(x, y + 1, Set[1]);

						level_difficile(x, y + 2, Set[2]);
						

						key = _getch();
						if (key == KEY_UP && (counter >= 2 && counter <= 3)) { // 72 up arrow key
							counter--;
						}
						if (key == KEY_DOWN && (counter >= 1 && counter <= 2)) { // 80 down arrow key
							counter++;
						}
						if (key == '\r') {
							update_console();

							game(counter); // debut du jeu.
						}
					}
				}
				if (counter == 2) {
					//*******************************************
					// Afficher help menu
					//*******************************************
					system("cls");
					cout << help;

				}
				if (counter == 3) {
					return EXIT_SUCCESS;
				}

			}
			else {
				system("cls");
				cout << menu;
				isPageAccueil = true;
			}

		}

	}
	return 0;
}

//================================================================================================


//================================================================================================

void game(const int level) {
	int choice = 0;
	int random_choice = -1;
	cout << "- Enter number of players : ";
	size_t number_players = 0;

	while (!(cin >> number_players) || number_players == 0) {
		error_input();
	}

	vector<player> players;
	for (size_t i = 0; i < number_players; i++) {
		cout << "- Enter a name for player " << i + 1 << " : ";
		string name;
		cin >> name;
		player p(name);
		players.push_back(p);

	}
	//to catch enter key.
	string press;
	getline(cin, press);
	string choix_a_remplir;
	while (true) {

		if (game_isEnd(players)) {//test si la grille de chaque joueur est terminée. (NB : )
			break;
		}
		int counter = 1;
		for (auto& _player : players) {
			_player.write_in_grille(choix_a_remplir);
			counter++;
			do {
				cout << "- Press enter to roll dices. " << endl;
				string press;
				getline(cin, press);
			} while (!press.empty());

			int nombre_lancement_dice = 0;
			if (press == "") {
				int choix = 1;
				do {
					nombre_lancement_dice++;
					if (choix == 1) {
						srand((unsigned)time(0));
						for (size_t i = 0; i < 5; i++) {
							dice _dice;
							lancer _lancer(_dice);
							
							//jet de dès.
							_lancer.lancerDice();
							_player.addDice(_dice);
						}
						
					}
					else if (choix == 2) {
						cout << "- Combien de dè voulez vous changer ? " << endl;
						int nombre_de_des;
						cin >> nombre_de_des;
						cout << "- Entrez les rangs à changer : (entre 1 et 5)." << endl;
						size_t i = 0;
						vector<int> rangs;
						while (i < nombre_de_des) {

							int rang;

							while (!(cin >> rang)
									|| (rang != 1 && rang != 2 && rang != 3 && rang != 4 && rang != 5))
							{

								error_input();
							}
							if (rang >= 1 && rang < 6) {
								if (rangs.size() == 0) {
									
									rangs.push_back(rang);
									i++;
								}
								else if (std::find(rangs.begin(), rangs.end(), rang) != rangs.end()) {
									cout << "- Vous avez deja choisi ce dè. essayez encore :" << endl;
								}
								else {
									rangs.push_back(rang);
									i++;
								}
							}
							else {
								cout << "- Vous devez choisir un nombre entre 1 et 5. Essayez encore : " << endl;
							}
						}
						for (size_t i = 0; i < rangs.size(); i++) {
							cout << rangs.at(i) << endl;
							dice _dice = _player.get_specific_dice(rangs.at(i) - 1);
							lancer _lancer(_dice);
							_lancer.lancerDice();
							_player.change_dice(rangs.at(i) - 1, _dice);

						}
					}
					else if (choix == 3 || choix == 4) {
						break;
					}

					cout << "[ ";
					_player.printDices();
					Sleep(200);
					cout << " ]" << endl;
					cout
						<< " ----------------------------------\n"
						<< "|    Les possibilités a choisir    |\n"
						<< "-----------------------------------\n";
					if (level == 1) {//facile. //sup = true, inf = true.
						_player.calcul_possibilities(true, true, 0);
					}
					else if (level == 2) {//moyen. //sup = true jusqu'à la fin(tous les cases de sup sont rempli) et on passe au inf.
						if (!_player.sup_isFill()) {
							_player.calcul_possibilities(true, false, 0);
						}
						else {
							_player.calcul_possibilities(false, true, 0);
						}
					}
					else if (level == 3) {//dificile. // random.
						if (random_choice == -1)
							random_choice = generate_random_choice(_player);
						_player.calcul_possibilities(false, false, random_choice);

					}

					if (nombre_lancement_dice == 3) {
						cout << " Tour est termine." << endl;
					}
					else {
						Sleep(300);
						cout << "---------------------------------------------------------\n" <<
							"|   1. Si vous voulez changer tous les dès : Press 1.     | \n"
							"|   2. Si vous voulez changer quelques dès : Press 2.     | \n"
							"|   3. Si vous voulez garder cette combinaison : Press 3. | \n"
							" ---------------------------------------------------------" << endl;
						while (!(cin >> choix) || (choix != 1 && choix != 2 && choix != 3)) {
							error_input();
						}

						if (choix == 1 || choix == 2) {
							update_console();
							_player.write_in_grille(choix_a_remplir);

							if (choix == 2) {
								cout << "[ ";
								_player.printDices();
								Sleep(200);
								cout << " ]" << endl;
							}
						}
					}
				} while (nombre_lancement_dice < 3);
			}
			int temp_test = -1;
			cout << "- Tapez votre choix : ";
			if (level == 1) { // niveau : facile.

				while (!(cin >> choix_a_remplir) || (!compare_strings(choix_a_remplir, "brelan") || !_player.get_Grille().get_berlan_isAvailable())
					&& (!compare_strings(choix_a_remplir, "carre") || !_player.get_Grille().get_carre_isAvailable())
					&& (!compare_strings(choix_a_remplir, "full") || !_player.get_Grille().get_fullHouse_isAvailable())
					&& (!compare_strings(choix_a_remplir, "psuite") || !_player.get_Grille().get_psuite_isAvailable())
					&& (!compare_strings(choix_a_remplir, "gsuite") || !_player.get_Grille().get_gsuite_isAvailable())
					&& (!compare_strings(choix_a_remplir, "yahtzee") || !_player.get_Grille().get_yahtzee_isAvailable())
					&& (!compare_strings(choix_a_remplir, "chance") || !_player.get_Grille().get_chance_isAvailable())
					&& (!compare_strings(choix_a_remplir, "1") || !_player.get_Grille().get_total_1_isAvailable())
					&& (!compare_strings(choix_a_remplir, "2") || !_player.get_Grille().get_total_2_isAvailable())
					&& (!compare_strings(choix_a_remplir, "3") || !_player.get_Grille().get_total_3_isAvailable())
					&& (!compare_strings(choix_a_remplir, "4") || !_player.get_Grille().get_total_4_isAvailable())
					&& (!compare_strings(choix_a_remplir, "5") || !_player.get_Grille().get_total_5_isAvailable())
					&& (!compare_strings(choix_a_remplir, "6") || !_player.get_Grille().get_total_6_isAvailable()))


				{
					error_input();
				}

			}
			else if (level == 2) { // niveau : moyen.

				if (!_player.sup_isFill()) {

					while (!(cin >> choix_a_remplir) || (!compare_strings(choix_a_remplir, "1") || !_player.get_Grille().get_total_1_isAvailable())
						&& (!compare_strings(choix_a_remplir, "2") || !_player.get_Grille().get_total_2_isAvailable())
						&& (!compare_strings(choix_a_remplir, "3") || !_player.get_Grille().get_total_3_isAvailable())
						&& (!compare_strings(choix_a_remplir, "4") || !_player.get_Grille().get_total_4_isAvailable())
						&& (!compare_strings(choix_a_remplir, "5") || !_player.get_Grille().get_total_5_isAvailable())
						&& (!compare_strings(choix_a_remplir, "6") || !_player.get_Grille().get_total_6_isAvailable()))
					{
						error_input();
					}
				}
				else {

					while (!(cin >> choix_a_remplir) || (!compare_strings(choix_a_remplir, "brelan") || !_player.get_Grille().get_berlan_isAvailable())
						&& (!compare_strings(choix_a_remplir, "carre") || !_player.get_Grille().get_carre_isAvailable())
						&& (!compare_strings(choix_a_remplir, "full") || !_player.get_Grille().get_fullHouse_isAvailable())
						&& (!compare_strings(choix_a_remplir, "psuite") || !_player.get_Grille().get_psuite_isAvailable())
						&& (!compare_strings(choix_a_remplir, "gsuite") || !_player.get_Grille().get_gsuite_isAvailable())
						&& (!compare_strings(choix_a_remplir, "yahtzee") || !_player.get_Grille().get_yahtzee_isAvailable())
						&& (!compare_strings(choix_a_remplir, "chance") || !_player.get_Grille().get_chance_isAvailable()))
					{
						error_input();
					}
				}
			}
			else if (level == 3) {

				switch (random_choice)
				{

				case 1:
					while (!(cin >> choix_a_remplir) || (!compare_strings(choix_a_remplir, "1") || !_player.get_Grille().get_total_1_isAvailable())) {
						error_input();
					}
					break;
				case 2:
					while (!(cin >> choix_a_remplir) || (!compare_strings(choix_a_remplir, "2") || !_player.get_Grille().get_total_2_isAvailable())) {
						error_input();
					}
					break;
				case 3:
					while (!(cin >> choix_a_remplir) || (!compare_strings(choix_a_remplir, "3") || !_player.get_Grille().get_total_3_isAvailable())) {
						error_input();
					}
					break;
				case 4:
					while (!(cin >> choix_a_remplir) || (!compare_strings(choix_a_remplir, "4") || !_player.get_Grille().get_total_4_isAvailable())) {
						error_input();
					}
					break;
				case 5:
					while (!(cin >> choix_a_remplir) || (!compare_strings(choix_a_remplir, "5") || !_player.get_Grille().get_total_5_isAvailable())) {
						error_input();
					}
					break;
				case 6:
					while (!(cin >> choix_a_remplir) || (!compare_strings(choix_a_remplir, "6") || !_player.get_Grille().get_total_6_isAvailable())) {
						error_input();
					}
					break;
				case 7:
					while (!(cin >> choix_a_remplir) || (!compare_strings(choix_a_remplir, "brelan") || !_player.get_Grille().get_berlan_isAvailable())) {
						error_input();
					}
					break;
				case 8:
					while (!(cin >> choix_a_remplir) || (!compare_strings(choix_a_remplir, "carre") || !_player.get_Grille().get_carre_isAvailable())) {
						error_input();
					}
					break;
				case 9:
					while (!(cin >> choix_a_remplir) || (!compare_strings(choix_a_remplir, "psuite") || !_player.get_Grille().get_psuite_isAvailable())) {
						error_input();
					}
					break;
				case 10:
					while (!(cin >> choix_a_remplir) || (!compare_strings(choix_a_remplir, "gsuite") || !_player.get_Grille().get_gsuite_isAvailable())) {
						error_input();
					}
					break;
				case 11:
					while (!(cin >> choix_a_remplir) || (!compare_strings(choix_a_remplir, "full") || !_player.get_Grille().get_fullHouse_isAvailable())) {
						error_input();
					}
					break;
				case 12:
					while (!(cin >> choix_a_remplir) || (!compare_strings(choix_a_remplir, "yahtzee") || !_player.get_Grille().get_yahtzee_isAvailable())) {
						error_input();
					}
					break;
				case 13:
					while (!(cin >> choix_a_remplir) || (!compare_strings(choix_a_remplir, "chance") || !_player.get_Grille().get_chance_isAvailable())) {
						error_input();
					}
					break;

				}
			}
			string pressEnter;
			getline(cin, pressEnter);
			_player.write_in_grille(choix_a_remplir);
			_player.change_availibilities(choix_a_remplir);
			choix_a_remplir = -1;
			random_choice = -1;
			update_console();
		}

	}
	update_console();
	change_cursor_position();
	
	cout << "Results : ==================================" << endl;
	Sleep(500);
	cout << "\n\n\n";
	for (auto _player : players) {
		print_scores(_player);
		Sleep(500);

		cout << "\n\n\n";
	}
	cout << "============================================" << endl;
	cout << "\n";
	cout << "- Nouvelle partie : a. - Menu : b." << endl;
	string enter;
	while (!(cin >> enter) || (enter != "a" && enter != "b")) {
		error_input();
	}
	if (enter == "a") {
		update_console();
		players.clear();
		system("pause");
	}
	else if (enter == "b") {
		update_console();
		players.clear();
		main();
	}
}

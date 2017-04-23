//
// pickem_v1.cpp
// CS 120 B - Project 1
// Version 1
//
// Mark Kulhowvick
// Created on:  1/24/2017
// Edited  on:  1/26/2017
//
// As a Counter-Strike: Global Offensive Major Tournament
// is currently under way, I decided to make a pseudo-pickem
// for keeping track of your team picks for the different days.
//
// This doesn't necessarily keep track of matchups and actual
// games between two teams, but is moreso to keep track of your
// own personal progress towards your pickem as the matches finish.
// I'm sure the program could be easily expanded to accomodate more.
// The code isn't the most effecient, but it gets the job done.
//
// Things this program does:
//		Gathers input from the user to formulate a team pickem
//		Strict input up until the user enters their picks
//		More relaxed input when they are actually writing to the file
//		A pickem template, and your own picks can be read
//		Error checking exists if the file for your own picks (!exist)
//		Primary console output (teams) is formatted
//		Secondary console output (picks) is gathered through getline()
//
// Copyright © 2017, Mark Kulhowvick
// All Rights Reserved
//

//-------------------------------------------------------------------
//	  S E L F   C H E C K L I S T   O F   R E Q U I R E M E N T S   
//-------------------------------------------------------------------
//	Receive User Input			[1/1]		Completed on: 1/25/2017
//	Check For Bad Input			[1/1]		Completed on: 1/25/2017
//	Write To File				[1/1]		Completed on: 1/25/2017
//	Read From File				[1/1]		Completed on: 1/25/2017
//	Output Manipulations x4		[4/4]		Completed on: 1/25/2017
//				setfill()		Line 63
//				setw()			Line 67 and others
//				fixed			Line 72 and others
//				setprecision()	Line 72 and others
//-------------------------------------------------------------------

//	Inclusions
	#include <iostream>
	#include <iomanip>
	#include <fstream>
	#include <string>
	#include <vector>
	using namespace std;

int main() {
	/*	T E A M   I N F O R M A T I O N
	 *	This section serves to output some information to the console.
	 *	It lists the teams in Legend status, and Challenger status.
	 *	Additionally, it displays the amount of titles each team has won.
	 *	Major Titles carry more weight than Championship Titles.
	 */
		//	Line Break
			string line_break = { "-------------------------------------------------------------" };
		//	Legend Teams
			vector <string> legend_headers		= { "   Legend Teams    ", "Major Titles", "Championship Titles" };
			vector <string> legend_teams		= { "Astralis", "FlipSid3 Tactics", "fnatic", "Gambit Gaming", "Natus Vincere", "SK Gaming", "Team Liquid", "Virtus.pro" };
			vector <double>	legend_major		= { 0, 0, 3, 0, 0, 1, 0, 1 };
			vector <double>	legend_championship = { 0, 0, 0, 0, 0, 0, 0, 1 };
		//	Challenger Teams
			vector <string> challenger_headers		= { "   Challenger Teams", "Major Titles", "Championship Titles" };
			vector <string> challenger_teams		= { "Team EnVyUs", "FaZe Clan", "G2 Esports", "GODSENT", "HellRaisers", "mousesports", "North", "OpTic Gaming" };
			vector <double>	challenger_major		= { 1, 0, 0, 0, 0, 0, 0, 0 };
			vector <double>	challenger_championship = { 0, 0, 0, 0, 0, 0, 0, 1 };
		//	Set Fill
			cout << setfill(' ');
		//	Display Legend Teams
			cout << line_break << endl;
			cout << legend_headers[0];
			cout << setw(17) << legend_headers[1];
			cout << setw(22) << legend_headers[2] << endl;
			cout << line_break << endl;
			for (size_t i = 0; i < legend_teams.size(); ++i) {
				cout << "   " + legend_teams[i];
				cout << setw(28 - legend_teams[i].length()) << fixed << setprecision(1) << legend_major[i];
				cout << setw(22) << legend_championship[i]	<< fixed << setprecision(1) << endl;
			}
			cout << line_break << endl << endl;
		//	Display Challenger Teams
			cout << line_break << endl;
			cout << challenger_headers[0];
			cout << setw(17) << challenger_headers[1];
			cout << setw(22) << challenger_headers[2] << endl;
			cout << line_break << endl;
			for (size_t i = 0; i < challenger_teams.size(); ++i) {
				cout << "   " + challenger_teams[i];
				cout << setw(28 - challenger_teams[i].length()) << fixed << setprecision(1) << challenger_major[i];
				cout << setw(22) << challenger_championship[i]	<< fixed << setprecision(1) << endl;
			}
			cout << line_break << endl << endl;

	/*	C R E A T E   B A S E   T E M P L A T E   F I L E
	 *	This section serves to make a base template of what the bracket formatting looks like.
	 *	It writes this to a file "pickem_template.txt" which the user can later choose to display.
	 */
		//	Create Output Stream
			ofstream template_output;
			template_output.open("pickem_template.txt");
		//	Populate File
			if (template_output) {
				template_output << "Playoff Teams      : Team1, Team2, Team3, Team4, Team5, Team6, Team7, Team8" << endl;
				template_output << "Advance 3-0        : Team1" << endl;
				template_output << "Eliminated 0-3     : Team2" << endl;
				template_output << "Quarterfinal Teams : Team1, Team2, Team3, Team4" << endl;
				template_output << "Semifinal Teams    : Team1, Team2" << endl;
				template_output << "Grand Final Team   : Team1" << endl;
			}
		//	Close File
			template_output.close();

	/*	U S E R   I N P U T
	 *	This section serves as the bulk of the user input.
	 *	The user is walked through a series of choices.
	 *	First, they're asked if they want to enter their own pickem information.
	 *	If not, they're asked if they want to view the pickem information.
	 *	They have another choice after that to view either the template, or their own picks.
	 *	If their own picks haven't been entered yet it has a message that the picks don't exist.
	 */
		//	Variables
			char input;
			bool continue_program = true;
			bool pass_first = false;
			bool pass_second = false;
			bool pass_third = false;
			bool pass_edit = false;
			string junk;
			string playoffs;
			string undefeated;
			string winless;
			string quarterfinals;
			string semifinals;
			string grandfinals;

		//	Ask for input until otherwise
			while (continue_program == true) {
			//	Reset values for next loop through
				pass_first = false;
				pass_second = false;
				pass_third = false;
				pass_edit = false;
				cout << "   Would you like to run the program (Y/N): ";
				cin >> input;
				if (toupper(input) == 'Y') {

					/*	Y E S   -   P R O G R A M   R A N
					 *	Program runs until next iteration.
					 */
					cout << endl;
					cout << "   Would you like to enter pickem information (Y/N): ";
					cin >> input;
					while (pass_first == false) {

						/*	Y E S   -   F I R S T   Q U E S T I O N
						 *	The user can then choose what to enter/edit.
						 */
						if (toupper(input) == 'Y') {
							pass_first = true;
							cout << endl;

							while (pass_edit == false) {
								cout << "   What do you want to enter:" << endl;
								cout << "     [1] Playoff Teams" << endl;
								cout << "     [2] Undefeated Team" << endl;
								cout << "     [3] Winless Team" << endl;
								cout << "     [4] Quarterfinal Teams" << endl;
								cout << "     [5] Semifinal Teams" << endl;
								cout << "     [6] Grandfinal Team" << endl;
								cout << "     [7] Everything" << endl;
								cout << "     [0] Nothing" << endl;
								cout << "   Answer: ";
								cin >> input;

								//	Create Input Stream
								ifstream file_input;
								file_input.open("pickem.txt");
								//	Read File
								if (file_input) {
									//	Get Information
									getline(file_input, playoffs);
									getline(file_input, undefeated);
									getline(file_input, winless);
									getline(file_input, quarterfinals);
									getline(file_input, semifinals);
									getline(file_input, grandfinals);
								} // END NESTED-IF (get previous pickem entries)

							/*	C A S E   -   P L A Y O F F
							 *	If the user wants to change the playoff entry.
							 */
								if (input == '1') {
									pass_first = true;
									pass_edit = true;
									cout << endl;
									//	Junk String
									getline(cin, junk);
									// Playoff Teams
									cout << "   Enter the teams that make the playoffs (8): ";
									getline(cin, playoffs);
									//	Create Output Stream
									ofstream file_output;
									file_output.open("pickem.txt");
									//	Populate File
									if (file_output) {
										file_output << "Playoff Teams      : " + playoffs << endl;
										file_output << undefeated << endl;
										file_output << winless << endl;
										file_output << quarterfinals << endl;
										file_output << semifinals << endl;
										file_output << grandfinals << endl;
										//	Task Complete
										cout << endl;
										cout << "   Task complete. Restarting the program..." << endl << endl;
									} // END NESTED-IF (edit PLAYOFF)
								//	Close File
									file_output.close();
								} // END IF (what to edit. PLAYOFF)

							/*	C A S E   -   U N D E F E A T E D
							 *	If the user wants to change the undefeated entry.
							 */
								else if (input == '2') {
									pass_first = true;
									pass_edit = true;
									cout << endl;
									//	Junk String
									getline(cin, junk);
									// Undefeated Team
									cout << "   Enter the team that will advance undefeated (1): ";
									getline(cin, undefeated);
									//	Create Output Stream
									ofstream file_output;
									file_output.open("pickem.txt");
									//	Populate File
									if (file_output) {
										file_output << playoffs << endl;
										file_output << "Advance 3-0        : " + undefeated << endl;
										file_output << winless << endl;
										file_output << quarterfinals << endl;
										file_output << semifinals << endl;
										file_output << grandfinals << endl;
										//	Task Complete
										cout << endl;
										cout << "   Task complete. Restarting the program..." << endl << endl;
									} // END NESTED-IF (edit UNDEFEATED)
								//	Close File
									file_output.close();
								} // END ELSE-IF (what to edit. UNDEFEATED)

							/*	C A S E   -   W I N L E S S
							 *	If the user wants to change the winless entry.
							 */
								else if (input == '3') {
									pass_first = true;
									pass_edit = true;
									cout << endl;
									//	Junk String
									getline(cin, junk);
									// Winless Team
									cout << "   Enter the team that doesn't win any matches (1): ";
									getline(cin, winless);
									//	Create Output Stream
									ofstream file_output;
									file_output.open("pickem.txt");
									//	Populate File
									if (file_output) {
										file_output << playoffs << endl;
										file_output << undefeated << endl;
										file_output << "Eliminated 0-3     : " + winless << endl;
										file_output << quarterfinals << endl;
										file_output << semifinals << endl;
										file_output << grandfinals << endl;
										//	Task Complete
										cout << endl;
										cout << "   Task complete. Restarting the program..." << endl << endl;
									} // END NESTED-IF (edit WINLESS)
								//	Close File
									file_output.close();
								} // END ELSE-IF (what to edit. WINLESS)

							/*	C A S E   -   Q U A R T E R F I N A L
							 *	If the user wants to change the quarterfinal entry.
							 */
								else if (input == '4') {
									pass_first = true;
									pass_edit = true;
									cout << endl;
									//	Junk String
									getline(cin, junk);
									// Quarterfinal Teams
									cout << "   Enter the teams that make the quarterfinals (4): ";
									getline(cin, quarterfinals);
									//	Create Output Stream
									ofstream file_output;
									file_output.open("pickem.txt");
									//	Populate File
									if (file_output) {
										file_output << playoffs << endl;
										file_output << undefeated << endl;
										file_output << winless << endl;
										file_output << "Quarterfinal Teams : " + quarterfinals << endl;
										file_output << semifinals << endl;
										file_output << grandfinals << endl;
										//	Task Complete
										cout << endl;
										cout << "   Task complete. Restarting the program..." << endl << endl;
									} // END NESTED-IF (edit QUARTERFINAL)
								//	Close File
									file_output.close();
								} // END ELSE-IF (what to edit. QUARTERFINAL)

							/*	C A S E   -   S E M I F I N A L
							 *	If the user wants to change the semifinal entry.
							 */
								else if (input == '5') {
									pass_first = true;
									pass_edit = true;
									cout << endl;
									//	Junk String
									getline(cin, junk);
									// Semifinal Teams
									cout << "   Enter the teams that make the semifinals (2): ";
									getline(cin, semifinals);
									//	Create Output Stream
									ofstream file_output;
									file_output.open("pickem.txt");
									//	Populate File
									if (file_output) {
										file_output << playoffs << endl;
										file_output << undefeated << endl;
										file_output << winless << endl;
										file_output << quarterfinals << endl;
										file_output << "Semifinal Teams    : " + semifinals << endl;
										file_output << grandfinals << endl;
										//	Task Complete
										cout << endl;
										cout << "   Task complete. Restarting the program..." << endl << endl;
									} // END NESTED-IF (edit SEMIFINAL)
								//	Close File
									file_output.close();
								} // END ELSE-IF (what to edit. SEMIFINAL)

							/*	C A S E   -   G R A N D F I N A L
							 *	If the user wants to change the grandfinal entry.
							 */
								else if (input == '6') {
									pass_first = true;
									pass_edit = true;
									cout << endl;
									//	Junk String
									getline(cin, junk);
									// Grandfinal Team
									cout << "   Enter the team that wins the Major (1): ";
									getline(cin, grandfinals);
									//	Create Output Stream
									ofstream file_output;
									file_output.open("pickem.txt");
									//	Populate File
									if (file_output) {
										file_output << playoffs << endl;
										file_output << undefeated << endl;
										file_output << winless << endl;
										file_output << quarterfinals << endl;
										file_output << semifinals << endl;
										file_output << "Grand Final Team   : " + grandfinals << endl;
										//	Task Complete
										cout << endl;
										cout << "   Task complete. Restarting the program..." << endl << endl;
									} // END NESTED-IF (edit GRANDFINAL)
								//	Close File
									file_output.close();
								} // END ELSE-IF (what to edit. GRANDFINAL)

								/*	C A S E   -   E V E R Y T H I N G
								 *	If the user wants to change all entries.
								 */
								else if (input == '7') {
									pass_first = true;
									pass_edit = true;
									cout << endl;
									//	Junk String
									getline(cin, junk);
									//	Playoff Teams
									cout << "   Enter the teams that make the playoffs (8): ";
									getline(cin, playoffs);
									//	Undefeated Team
									cout << "   Enter the team that will advance undefeated (1): ";
									getline(cin, undefeated);
									//	Winless Team
									cout << "   Enter the team that doesn't win any matches (1): ";
									getline(cin, winless);
									//	Quarterfinal Teams
									cout << "   Enter the teams that make the quarterfinals (4): ";
									getline(cin, quarterfinals);
									//	Semifinal Teams
									cout << "   Enter the teams that make the semifinals (2): ";
									getline(cin, semifinals);
									//	Grand Final Team
									cout << "   Enter the team that wins the Major (1): ";
									getline(cin, grandfinals);
									//	Create Output Stream
									ofstream file_output;
									file_output.open("pickem.txt");
									//	Populate File
									if (file_output) {
										file_output << "Playoff Teams      : " + playoffs << endl;
										file_output << "Advance 3-0        : " + undefeated << endl;
										file_output << "Eliminated 0-3     : " + winless << endl;
										file_output << "Quarterfinal Teams : " + quarterfinals << endl;
										file_output << "Semifinal Teams    : " + semifinals << endl;
										file_output << "Grand Final Team   : " + grandfinals << endl;
										//	Task Complete
										cout << endl;
										cout << "   Task complete. Restarting the program..." << endl << endl;
									} // END NESTED-IF (edit EVERYTHING)
								//	Close File
									file_output.close();
								} // END ELSE-IF (what to edit. EVERYTHING)

							/*	C A S E   -   N O T H I N G
							 *	If the user wants nothing changed.
							 */
								else if (input == '0') {
									pass_first = true;
									pass_edit = true;
									cout << endl;
									cout << "   Nothing changed. Restarting the program..." << endl << endl;
								} // END ELSE-IF (what to edit. NOTHING)

							/*	C A S E   -   I N V A L I D
							 *	The user is asked to input something different.
							 */
								else {
									pass_first = true;
									pass_edit = false;
									cout << "   Sorry that's not a valid input. Please try again." << endl << endl;
								} // END ELSE (what to edit. INVALID)
							} // END WHILE-LOOP (enter/edit picks)
						} // END IF (want to enter pickem information? YES)

					/*	N O   -   F I R S T   Q U E S T I O N
					 *	The user is asked for more input on a different question.
					 */
						else if (toupper(input) == 'N') {
							pass_first = true;
							while (pass_second == false) {
								cout << "   Do you want to view the pickem information (Y/N): ";
								cin >> input;

								/*	Y E S   -   S E C O N D   Q U E S T I O N
								 *	The user is asked for more input on a different question.
								 */
								if (toupper(input) == 'Y') {
									pass_second = true;
									pass_first = true;
									while (pass_third == false) {
										cout << endl;
										cout << "   Do you want to view:" << endl;
										cout << "     [1] The Template" << endl;
										cout << "     [2] Your Picks" << endl;
										cout << "   Answer: ";
										cin >> input;

										/*	T E M P L A T E   -   T H I R D   Q U E S T I O N
										*	The base template for picks is displayed.
										*/
										if (input == '1') {
											pass_third = true;
											pass_second = true;
											pass_first = true;
											cout << endl;
											//	Create Input Stream
											ifstream file_input;
											file_input.open("pickem_template.txt");
											//	Read File
											if (file_input) {
												//	Get Information
												getline(file_input, playoffs);
												getline(file_input, undefeated);
												getline(file_input, winless);
												getline(file_input, quarterfinals);
												getline(file_input, semifinals);
												getline(file_input, grandfinals);
												//	Print Information
												cout << playoffs << endl;
												cout << undefeated << endl;
												cout << winless << endl;
												cout << quarterfinals << endl;
												cout << semifinals << endl;
												cout << grandfinals << endl;
												//	Task Complete
												cout << endl;
												cout << "   Task complete. Restarting the program..." << endl << endl;
											} // END NESTED IF (display pickem: TEMPLATE)
										} // END IF (what do you want to view? TEMPLATE)

									/*	P I C K S   -   T H I R D   Q U E S T I O N
									*	Your own picks are displayed, if present.
									*/
										else if (input == '2') {
											pass_third = true;
											pass_second = true;
											pass_first = true;
											cout << endl;
											//	Create Input Stream
											ifstream file_input;
											file_input.open("pickem.txt");
											//	Read File
											if (file_input) {
												//	Get Information
												getline(file_input, playoffs);
												getline(file_input, undefeated);
												getline(file_input, winless);
												getline(file_input, quarterfinals);
												getline(file_input, semifinals);
												getline(file_input, grandfinals);
												//	Print Information
												cout << playoffs << endl;
												cout << undefeated << endl;
												cout << winless << endl;
												cout << quarterfinals << endl;
												cout << semifinals << endl;
												cout << grandfinals << endl;
												//	Task Complete
												cout << endl;
												cout << "   Task complete. Restarting the program..." << endl << endl;
											} // END NESTED IF (display pickem: PICKS)
										//	If file doesn't exist
											else {
												cout << "   Sorry, that file doesn't exist. Restarting program..." << endl << endl;
											} // END NESTED IF-ELSE (display pickem: PICKS)
										} // END ELSE-IF (what do you want to view? PICKS)

									/*	I N V A L I D   -   T H I R D   Q U E S T I O N
									 *	The user is asked to input something different.
									 */
										else {
											pass_third = false;
											pass_second = true;
											pass_first = true;
											cout << "   Sorry that's not a valid input. Please try again." << endl << endl;
											cout << "   Do you want to view:" << endl;
											cout << "     [0] The Template" << endl;
											cout << "     [1] Your Picks" << endl;
											cout << "   Answer: ";
											cin >> input;
										} // END ELSE (what do you want to view? INVALID)
									} // END WHILE-LOOP (template or picks)
								} // END IF (want to display pickem information? YES)

							/*	N O   -   S E C O N D   Q U E S T I O N
							 *	The program exits
							 */
								else if (toupper(input) == 'N') {
									pass_third = true;
									pass_second = true;
									pass_first = true;
									continue_program = false;
									cout << endl;
									cout << "   Exiting the program..." << endl << endl;
								} // END ELSE-IF (want to display pickem information? NO)

							/*	I N V A L I D   -   S E C O N D   Q U E S T I O N
							 *	The user is asked to input something different.
							 */
								else {
									pass_second = false;
									pass_first = true;
									cout << "   Sorry that's not a valid input. Please try again." << endl << endl;
								} // END ELSE (want to display pickem information? INVALID)
							} // END WHILE-LOOP (want to view pickem information?)
						} // END ELSE-IF (want to enter pickem information? NO)

					/*	I N V A L I D   -   F I R S T   Q U E S T I O N
					 *	The user is asked to input something different.
					 */
						else {
							pass_first = false;
							cout << "   Sorry that's not a valid input. Please try again." << endl << endl;
							cout << "   Would you like to enter pickem information (Y/N): ";
							cin >> input;
						} // END ELSE (want to enter pickem information? INVALID)
					} // END WHILE-LOOP (want to enter pickem information?)
				}

				/*	N O   -   P R O G R A M   S T O P P E D
				 *	Program exits.
				 */
				else if (toupper(input) == 'N') {
					continue_program = false;
					cout << endl;
					cout << "   You've chosen to exit the program. Exiting now..." << endl << endl;
				}

				/*	I N V A L I D   -   P R O G R A M   P A U S E D
				 *	The user is asked to input something different.
				 */
				else {
					continue_program = true;
					cout << "   Sorry that's not a valid input. Please try again." << endl << endl;
				}
			}

	//	END PROGRAM
		return 0;
}// END MAIN
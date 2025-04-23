/*
 * Course: CS216-005
 * Project: Lab 5 (as second part of Project 1)
 * Purpose: it reads data from an input file which passes as command line argument
 *          then stores in an object of IMDB class (to represent imdb database)
 *          two movies are from the user-input, then performs case insensitive matching
 *          and match the movie titles from the database
 *          it then allowes the user to input an actor/actress name, to search for co-actors in each movie which this actor/actress was in, in a well-formatted display
 * Author: Anthony Wang
 */

 // g++ Project_1.cpp imdb.cpp -o Project_1
 // ./Project_1 actor_movies.txt

#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include <cctype>
#include <set>
#include <map>
#include <sstream>
#include "imdb.h"

using namespace std;

void analyzeCoActors(const IMDB& imdb);

void analyzeMovies(const IMDB& imdb);

int main(int argc, char* argv[])
{
    const int COMM_NUM = 1;
    // Check whether the number of command line arguments is exactly one 
    if (argc != COMM_NUM + 1)
    {
        cout << "Warning: need exactly " << COMM_NUM << " command line argument." << endl;
        cout << "Usage: " << argv[0] << " inputfile_name" << endl;
        return 1;
    }
    
    ifstream in_file;
    in_file.open(argv[1]);

    // Check whether the input file can be open successfully or not
    if (!in_file.good())
    {
        cout << "Warning: cannot open file named " << argv[1] << "!" << endl;
        return 2;
    }

    // Read data from the input file, assume "good data" from the input file
    // each line of the input file: actor name; movie1; movie2; ...; movieN;
    // read one line at a time then tokenize it:
    // create a pair <actor_name, the set of movieTitles which the actor was in>
    //        and insert to IMDB object
    IMDB cs216_imdb;

    while (!in_file.eof())
    {
        string line;
        getline(in_file, line);
        string actorName, movieTitle;
        // check if the text line is not empty then tokenize it
        if (line.length() != 0)
        {
            istringstream iss(line);
            getline(iss, actorName,';');
            // Extract extra white space
            iss>>ws;

            // Create a new set of movies associated with name
            set<string> movies;

            while (getline(iss, movieTitle, ';'))
            {
                movies.insert(movieTitle);
                // extract white space 
                iss>>ws;
            }
            // insert the pair to IMDB object: cs216_imdb
            cs216_imdb.insert_an_actor(actorName, movies);
        }
    }
    // close the input file
    in_file.close();

    int option;
    while (true)
    {
        bool validInput = true;
        cout << "Welcome to the CS216 IMDB APP!" << endl;
        cout << "This application stores information about Actors and their Movies, please choose your option (Enter Q or q to quit):" << endl;
        cout << "1. Actors in Movies" << endl;
        cout << "2. Actors and co-actors" << endl;

        // let user choose from main manu
        cin >> option;

        if (cin.fail())
        {
            cin.clear();
            string input_to_check;
            cin >> input_to_check;
            // quit program if input == Q || q
            if (input_to_check == "Q" || input_to_check == "q")
                break;
            else{
                cout << "Expecting a number as the option!" << endl;
                validInput = false;
            }
        }
        // get rid of anything left in the input stream
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // if there is a valid input option
        if (validInput)
        {
            switch (option)
            {
                case 1: analyzeMovies(cs216_imdb);
                        break;
                case 2:  analyzeCoActors(cs216_imdb);
                        break;
                default:
                        cout << "Invalid option number!" << endl;
            }
        }
    }
    cout << "Thank you for using my program, bye..." << endl;
    return 0;
}

/*
 * Purpose: this function asks the user to type an actor's name
 * then check if the user-input name is valid(it is valid if it is in the database stored in the passing in object
 * if it is valid, display each movie which this actor is in, the co-actors who appeared in the same movie
 *@param imdb, the object of IMDB class: stores all information to look up (const call by reference)
 *@return void function
 */
void analyzeCoActors(const IMDB& imdb)
{
    string actor_name;
    cout << "Finding the co-actors for (please enter the actor's name) -->  ";
    getline(cin, actor_name);
    if (!imdb.isExistingActor(actor_name))
    {
        cout << "The actor name you entered is not in the database." << endl;
        return;
    }   

    set<string> movies_of_actor;
    movies_of_actor = imdb.find_movies_for_an_actor(actor_name);
    for (set<string>::iterator im = movies_of_actor.begin(); im != movies_of_actor.end(); im++)
    {
        cout << "The co-actors of " << actor_name << " in the movie \"" << *im << "\" are: " << endl;
        // Display all the co-actors in one movie
        set<string> coactors = imdb.find_actors_in_a_movie(*im);
        for (set<string>::iterator ia = coactors.begin(); ia != coactors.end(); ia++)
        {
                if(*ia != actor_name){
                    cout << *ia << endl;
                }
        }    
        cout << "***********************************" << endl;
    }
}    

void analyzeMovies(const IMDB& imdb){
    // Ask the user to input two movie titles to search for
    string movie1, movie2;
    cout << "Please input the first movie title: ";
    getline(cin,movie1);
    cout << "Please input the second movie title: ";
    getline(cin,movie2);
    // Check if both movie1 and movie2 can be matched with movies in the database
    // If either one is not, quit the program
    // Otherwise display all the actors in either of two movies
    //                   which are actually the union of two sets
    string matchedMovie1, matchedMovie2;
    matchedMovie1 = imdb.matchExistingMovie(movie1);
    matchedMovie2 = imdb.matchExistingMovie(movie2);
    // decide which one movie title is not valid
    bool notValid = false;
    if (matchedMovie1.length() == 0)
    {
        cout << "\" " << movie1 << " \"" << " is not a VALID movie title!" << endl;
        notValid = true;
    }
    if (matchedMovie2.length() == 0)
    {
        cout << "\" " << movie2 << " \"" << " is not a VALID movie title!" << endl;
        notValid = true;
    }
    if (notValid)
        return;
    // both movie titles are valid
    if (imdb.isExistingMovie(matchedMovie1) && imdb.isExistingMovie(matchedMovie2))
    {
        cout << "Your input matches the following two movies: " <<endl;
        cout << matchedMovie1 << endl;
        cout << matchedMovie2 << endl;
        cout << "Both movies are in the database, searching actors..." << endl;

        string userInput;
        int option;
        bool searchCon;
        while(true){

            cout << 
            "This is written by Anthony Wang. Enjoy THREE further searches. \n"   <<
            "Please input your menu option (enter Q or q to quit) \n"        <<
            "A -- to print all the actors in either of the two movies. \n"   <<
            "C -- to print all the common actors in both movies. \n"         <<
            "O -- to print all the actors who are in only one movie, but not in both." << endl; 

            // repeat this function if input is invalid
            cin >> userInput;
            if(cin.fail()){
                cout << "Invalid input!" << endl;
                cin.clear();
                searchCon = false;
            }
            else{
                // quit if input == Q
                userInput = userInput.substr(0,1);
                if(userInput == "Q" || userInput == "q"){
                    break;
                }
                // set option to real value by input
                else if(userInput == "A" || userInput == "a"){
                    option = 1;
                    searchCon = true;
                }
                else if(userInput == "C" || userInput == "c"){
                    option = 2;
                    searchCon = true;
                }
                else if(userInput == "O" || userInput == "o"){
                    option = 3;
                    searchCon = true;
                }
                else{
                    cout << "Invalid Option!" << endl;
                }
            }
            cin.ignore(1000,'\n');

            if(searchCon){

                set<string> actorInMovie_1 = imdb.find_actors_in_a_movie(matchedMovie1); // set of actor from movie 1
                set<string> actorInMovie_2 = imdb.find_actors_in_a_movie(matchedMovie2); // set of actor from movie 2
                set<string> allActors;
                set<string> inteActors;
                set<string> symDiffActors;
                for(string it:actorInMovie_1){
                    allActors.insert(it);
                }
                for(string it:actorInMovie_2){
                    allActors.insert(it);
                }
                set<string> resultActors;

                switch (option){
                    // set resultActor to corresponding actor set
                    case 1:
                        cout << "All the actors in either of the movies" << endl;
                        resultActors = allActors;
                        break;

                    case 2: 
                        cout << "Common actors in both movies:" << endl;
                        // creat intersection actor set, set resultActor to it
                        for(string it:actorInMovie_1){
                            if(actorInMovie_2.find(it) != actorInMovie_2.end()){
                                inteActors.insert(it);
                            }
                        }
                        resultActors = inteActors;
                        break;

                    case 3:
                        cout << "Actirs only in one of two movies" << endl;
                        // creat Symmetric Difference actor set, set resultActor to it
                        for(string it:allActors){
                            if(actorInMovie_1.find(it) == actorInMovie_1.end()){
                                symDiffActors.insert(it);
                            }
                            if(actorInMovie_2.find(it) == actorInMovie_2.end()){
                                symDiffActors.insert(it);
                            }
                        }
                        resultActors = symDiffActors;
                        break;

                    default:
                        cout << "Invalid option value" << endl;
                        break;
                }
                // cout resultActors
                for(string it : resultActors){
                    cout << it << endl;
                }
                resultActors.clear();
            }
        }
    }
}

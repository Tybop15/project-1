/**
 * This file contains the implementations of the builtin functions provided by
 * the shell (or will, once you've finished implementing them all).
 */

#include "shell.h"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

vector<vector<string> > history;

int Shell::com_ls(vector<string>& argv) {
  history.push_back(argv);
  if (argv.size() < 2)
    system("dir");
  else if (argv.size() == 2){ //TODO: Implement ls <directory> functionality
    //char dir = argv[1];
    //chdir(dir);
    system("dir");
  }
  else
    cout << "Too many arguments" << endl; // delete when implemented
  return 0;
}


int Shell::com_cd(vector<string>& argv) {
  history.push_back(argv);
  // TODO: YOUR CODE GOES HERE
  cout << "cd called" << endl; // delete when implemented
  return 0;
}


int Shell::com_pwd(vector<string>& argv) {
  history.push_back(argv);
  char cwd[1024];
  cout << getcwd(cwd, sizeof(cwd)) << endl;
  return 0;
}


int Shell::com_alias(vector<string>& argv) {
  history.push_back(argv);
  // TODO: YOUR CODE GOES HERE
  cout << "alias called" << endl; // delete when implemented
  return 0;
}


int Shell::com_unalias(vector<string>& argv) {
  history.push_back(argv);
  // TODO: YOUR CODE GOES HERE
  cout << "unalias called" << endl; // delete when implemented
  return 0;
}


int Shell::com_echo(vector<string>& argv) {
  history.push_back(argv);
  if (argv.size() < 2){
    cout << "Echo will print to the screen any arguments placed after it e.g. \necho words\nwords\n";
    return 0;
  }
  for (int i = 1; i < argv.size(); i++)
    cout << argv[i] << " "; // delete when implemented
  cout << endl;
  return 0;
}


int Shell::com_history(vector<string>& argv) {
  history.push_back(argv);
  for (int i = 0; i < history.size(); i++){
    cout << i;
    for (int j = 0; j < history[i].size(); j++){
      cout << " " << history[i][j];
    }
    cout << endl;
  }
  return 0;
}


int Shell::com_exit(vector<string>& argv) {
  history.push_back(argv);
  exit(0); //Exit Success
  return 0;
}
